// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__5(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__5\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__base = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset = 0;
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
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2673__lhs;
    __Vfunc_fp32_mul__2673__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2673__rhs;
    __Vfunc_fp32_mul__2673__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2673__normalize_count;
    __Vfunc_fp32_mul__2673__normalize_count = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__2674__value;
    __Vfunc_fp32_from_int__2674__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__2674__bit_index;
    __Vfunc_fp32_from_int__2674__bit_index = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2675__unused_sign;
    __Vfunc_fp32_is_nan__2675__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2676__unused_sign;
    __Vfunc_fp32_is_nan__2676__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2677__unused_sign;
    __Vfunc_fp32_is_inf__2677__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2678__unused_sign;
    __Vfunc_fp32_is_zero__2678__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2679__unused_sign;
    __Vfunc_fp32_is_inf__2679__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2680__unused_sign;
    __Vfunc_fp32_is_zero__2680__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2681__unused_sign;
    __Vfunc_fp32_is_inf__2681__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2682__unused_sign;
    __Vfunc_fp32_is_inf__2682__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2683__unused_sign;
    __Vfunc_fp32_is_zero__2683__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2684__unused_sign;
    __Vfunc_fp32_is_zero__2684__unused_sign = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q;
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q;
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][1U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][2U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][3U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][4U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][5U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][6U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][7U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][8U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][9U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0xaU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0xbU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0xcU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0xdU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0xeU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0xfU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x10U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x11U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x12U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x13U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x14U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x15U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x16U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x17U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x18U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x19U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x1aU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x1bU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x1cU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x1dU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x1eU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x1fU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x20U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x21U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x22U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x23U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x24U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x25U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x26U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x27U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x28U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x29U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x2aU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x2bU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x2cU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x2dU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x2eU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x2fU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x30U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x31U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x32U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x33U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x34U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x35U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x36U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x37U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x38U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x39U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x3aU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x3bU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x3cU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x3dU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x3eU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1][0x3fU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[0x3fU];
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][1U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][2U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][3U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][4U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][5U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][6U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][7U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][8U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][9U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0xaU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0xbU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0xcU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0xdU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0xeU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0xfU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x10U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x11U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x12U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x13U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x14U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x15U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x16U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x17U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x18U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x19U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x1aU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x1bU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x1cU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x1dU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x1eU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x1fU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x20U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x21U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x22U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x23U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x24U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x25U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x26U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x27U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x28U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x29U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x2aU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x2bU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x2cU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x2dU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x2eU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x2fU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x30U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x31U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x32U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x33U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x34U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x35U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x36U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x37U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x38U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x39U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x3aU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x3bU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x3cU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x3dU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x3eU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2][0x3fU] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[0x3fU];
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v40) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[0U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[1U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[2U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[3U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[4U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[5U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[6U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][1U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][2U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][3U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][4U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][5U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][6U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][7U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][8U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][9U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0xaU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0xbU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0xcU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0xdU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0xeU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0xfU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x10U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x11U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x12U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x13U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x14U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x15U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x16U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x17U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x18U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x19U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x1aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x1bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x1cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x1dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x1eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x1fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x20U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x21U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x22U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x23U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x24U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x25U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x26U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x27U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x28U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x29U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x2aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x2bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x2cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x2dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x2eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x2fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x30U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x31U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x32U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x33U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x34U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x35U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x36U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x37U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x38U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x39U] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x3aU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x3bU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x3cU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x3dU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x3eU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q[7U][0x3fU] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[0x3fU];
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v0;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v1;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[0U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[1U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[2U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[3U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[4U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q[5U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v0;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v1;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v2] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v2;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v3) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q[5U] = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q;
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_high_nibble 
        = (IData)(((0U == (0xc0U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU])) 
                   & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q 
                      ^ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                         >> 0x10U))));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU])) 
           & ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U])
               ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q
               : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_high_nibble 
        = (IData)(((0U == (0xc0U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_is_tiled 
        = ((2U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                            >> 8U))) | ((3U == (0xffU 
                                                & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                                                   >> 8U))) 
                                        | (6U == (0xffU 
                                                  & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                                                     >> 8U)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr 
        = (0xffffffffffffULL & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_addr_q 
                                + (QData)((IData)(((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q) 
                                                   << 3U)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_desc_addr 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q
        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select];
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_ready 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_rsp_valid 
        = (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU] 
                 >> 6U));
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
    if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_col = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_row = 0ULL;
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_col 
            = VL_MODDIV_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q, (QData)((IData)(
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U])));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_row 
            = VL_DIV_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q, (QData)((IData)(
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U])));
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_clear) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q = 0U;
        }
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) {
                    if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_rsp_valid) 
                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_rsp_ready))) {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 0U;
                    }
                } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i) 
                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bready_o))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q 
                        = ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bid_i))
                            ? 5U : ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response 
                                    = vlSelfRef.tb_npu_single_core__DOT__m_axi_bresp_i;
                                {
                                    if ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response))) {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__Vfuncout = 0U;
                                        goto __Vlabel0;
                                    } else if ((2U 
                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response))) {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__Vfuncout = 3U;
                                        goto __Vlabel0;
                                    } else if ((3U 
                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response))) {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__Vfuncout = 4U;
                                        goto __Vlabel0;
                                    } else {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__Vfuncout = 5U;
                                        goto __Vlabel0;
                                    }
                                    if (VL_UNLIKELY((
                                                     (1U 
                                                      & (~ 
                                                         VL_ONEHOT_I(
                                                                     (((3U 
                                                                        == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response)) 
                                                                       << 2U) 
                                                                      | (((2U 
                                                                           == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response)) 
                                                                          << 1U) 
                                                                         | (0U 
                                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response)))))))))) {
                                        if ((0U != 
                                             (((3U 
                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response)) 
                                               << 2U) 
                                              | (((2U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response)) 
                                                  << 1U) 
                                                 | (0U 
                                                    == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response)))))) {
                                            if (VL_UNLIKELY((
                                                             vlSymsp->_vm_contextp__->assertOn()))) {
                                                VL_WRITEF_NX("[%0t] %%Error: npu_axi_mif_master.sv:116: Assertion failed in %Ntb_npu_single_core.dut.u_axi_mif_master.axi_resp_status: unique case, but multiple matches found for '2'h%x'\n",0,
                                                             64,
                                                             VL_TIME_UNITED_Q(1000),
                                                             -9,
                                                             vlSymsp->name(),
                                                             2,
                                                             (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__response));
                                                VL_STOP_MT("memory/npu_axi_mif_master.sv", 116, "");
                                            }
                                        }
                                    }
                                    __Vlabel0: ;
                                }
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4642__Vfuncout)));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_handshake) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q = 1U;
                }
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_handshake) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q = 1U;
                }
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__write_channels_done) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 6U;
                }
            } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rready_o))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q 
                    = vlSelfRef.tb_npu_single_core__DOT__m_axi_rdata_i;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q 
                    = ((1U & ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rid_i)) 
                              | (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rlast_i))))
                        ? 5U : ([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response 
                                = vlSelfRef.tb_npu_single_core__DOT__m_axi_rresp_i;
                            {
                                if ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response))) {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__Vfuncout = 0U;
                                    goto __Vlabel1;
                                } else if ((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response))) {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__Vfuncout = 3U;
                                    goto __Vlabel1;
                                } else if ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response))) {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__Vfuncout = 4U;
                                    goto __Vlabel1;
                                } else {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__Vfuncout = 5U;
                                    goto __Vlabel1;
                                }
                                if (VL_UNLIKELY(((1U 
                                                  & (~ 
                                                     VL_ONEHOT_I(
                                                                 (((3U 
                                                                    == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response)) 
                                                                   << 2U) 
                                                                  | (((2U 
                                                                       == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response)) 
                                                                      << 1U) 
                                                                     | (0U 
                                                                        == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response)))))))))) {
                                    if ((0U != (((3U 
                                                  == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response)) 
                                                 << 2U) 
                                                | (((2U 
                                                     == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response)) 
                                                    << 1U) 
                                                   | (0U 
                                                      == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response)))))) {
                                        if (VL_UNLIKELY((
                                                         vlSymsp->_vm_contextp__->assertOn()))) {
                                            VL_WRITEF_NX("[%0t] %%Error: npu_axi_mif_master.sv:116: Assertion failed in %Ntb_npu_single_core.dut.u_axi_mif_master.axi_resp_status: unique case, but multiple matches found for '2'h%x'\n",0,
                                                         64,
                                                         VL_TIME_UNITED_Q(1000),
                                                         -9,
                                                         vlSymsp->name(),
                                                         2,
                                                         (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__response));
                                            VL_STOP_MT("memory/npu_axi_mif_master.sv", 116, "");
                                        }
                                    }
                                }
                                __Vlabel1: ;
                            }
                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__axi_resp_status__4643__Vfuncout)));
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 7U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) {
                if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_arvalid_o) 
                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_arready_i))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 4U;
                }
            } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_rsp_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
                    = (0xffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_addr_q);
                if ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q 
                        = ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q))
                            ? ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q))
                                ? 5U : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q))
                            : ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q))
                                ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q)
                                : ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q))
                                    ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q)
                                    : 5U)));
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 7U;
                } else if ((0ULL == (0xffffffffffffULL 
                                     & VL_SHIFTR_QQI(48,48,32, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_addr_q, 0x28U)))) {
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_write_q) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q = 0U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 5U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 3U;
                    }
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q = 1U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 7U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) {
            if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_valid) 
                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 2U;
            }
        } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_valid) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_ready))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_write_q 
                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w) 
                   && (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_write));
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_addr;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wdata;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wstrb;
            } else {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q = 0U;
            }
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__stream_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_stream_id_q;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__substream_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_substream_id_q;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q = 0ULL;
            if ((0U != (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_addr)))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 7U;
            } else {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 1U;
            }
        }
        if ((((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
              & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q))) 
             & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q)) 
                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_clear)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_status_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q;
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_write_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__stream_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__substream_id_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_addr_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_status_q = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__scheduler_idle 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q)) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q)) 
                       & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q)))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__norm_parameter_phase 
        = ((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q)));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_high_nibble 
        = (IData)(((0U == (0x30U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x31U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x30U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x32U]))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x19U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x18U]))) 
                                + (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q)) 
                                    * (QData)((IData)(
                                                      vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1aU]))) 
                                   + (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble 
        = (IData)((((0U == (0xc0U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
                    & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                   & (7U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[8U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x17U]))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 6U));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x17U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[8U])));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset 
        = ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row)) 
           * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__2342__dtype 
                            = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2342__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__Vfuncout)))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout 
        = ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base 
            + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset) 
           + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__normal_dst_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout;
    __Vfunc_fp32_mul__2673__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1eU];
    __Vfunc_fp32_from_int__2674__value = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_value_q 
                                          - (((QData)((IData)(
                                                              (- (IData)(
                                                                         (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x22U] 
                                                                          >> 0x1fU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x22U]))));
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_from_int__2674__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4305783727576925133ull);
    vlSelf->__Vfunc_fp32_from_int__2674__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3501636320521562658ull);
    vlSelf->__Vfunc_fp32_from_int__2674__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17669944297504789151ull);
    vlSelf->__Vfunc_fp32_from_int__2674__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10579900057149268282ull);
    vlSelf->__Vfunc_fp32_from_int__2674__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 670560698169395296ull);
    vlSelf->__Vfunc_fp32_from_int__2674__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10026636171683768370ull);
    vlSelf->__Vfunc_fp32_from_int__2674__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 13416100474595597551ull);
    vlSelf->__Vfunc_fp32_from_int__2674__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8839677210556453702ull);
    vlSelf->__Vfunc_fp32_from_int__2674__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8460141436954743481ull);
    vlSelf->__Vfunc_fp32_from_int__2674__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 506528000175917233ull);
    vlSelf->__Vfunc_fp32_from_int__2674__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1555238835906288318ull);
    __Vfunc_fp32_from_int__2674__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__2674__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout = 0U;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2674__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__2674__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__2674__value))
                : __Vfunc_fp32_from_int__2674__value);
        vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0U;
        __Vfunc_fp32_from_int__2674__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__2674__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__2674__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude, vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__2674__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__2674__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__2674__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__2674__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__2674__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__2674__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__2674__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__2674__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__2674__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__2674__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__2674__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__2674__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__2674__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__2674__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__2674__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__2674__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2674__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__2674__fraction));
        __Vlabel2: ;
    }
    __Vfunc_fp32_mul__2673__lhs = vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout;
    vlSelf->__Vfunc_fp32_mul__2673__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11924592379695937229ull);
    vlSelf->__Vfunc_fp32_mul__2673__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8333149821433885813ull);
    vlSelf->__Vfunc_fp32_mul__2673__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12842757615863037581ull);
    vlSelf->__Vfunc_fp32_mul__2673__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11601252661773846804ull);
    vlSelf->__Vfunc_fp32_mul__2673__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 7692099731219814740ull);
    vlSelf->__Vfunc_fp32_mul__2673__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13543198430249221645ull);
    vlSelf->__Vfunc_fp32_mul__2673__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11781868779845198201ull);
    vlSelf->__Vfunc_fp32_mul__2673__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4468126067709306060ull);
    vlSelf->__Vfunc_fp32_mul__2673__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10640003147816190933ull);
    vlSelf->__Vfunc_fp32_mul__2673__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8185606933892408290ull);
    vlSelf->__Vfunc_fp32_mul__2673__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15741770250884972902ull);
    vlSelf->__Vfunc_fp32_mul__2673__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 54278704876743577ull);
    vlSelf->__Vfunc_fp32_mul__2673__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9976173162612916383ull);
    __Vfunc_fp32_mul__2673__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2675__bits 
                                = __Vfunc_fp32_mul__2673__lhs;
                            __Vfunc_fp32_is_nan__2675__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2675__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2675__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2675__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2675__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2675__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2675__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2676__bits 
                                = __Vfunc_fp32_mul__2673__rhs;
                            __Vfunc_fp32_is_nan__2676__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2676__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2676__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2676__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2676__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2676__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2676__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2677__bits 
                                    = __Vfunc_fp32_mul__2673__lhs;
                                __Vfunc_fp32_is_inf__2677__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2677__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2677__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2677__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2677__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2677__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2678__bits 
                                    = __Vfunc_fp32_mul__2673__rhs;
                                __Vfunc_fp32_is_zero__2678__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2678__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2678__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2678__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2678__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2678__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2679__bits 
                                    = __Vfunc_fp32_mul__2673__rhs;
                                __Vfunc_fp32_is_inf__2679__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2679__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2679__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2679__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2679__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2679__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2680__bits 
                                    = __Vfunc_fp32_mul__2673__lhs;
                                __Vfunc_fp32_is_zero__2680__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2680__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2680__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2680__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2680__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2680__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_mul__2673__result_sign 
            = ((__Vfunc_fp32_mul__2673__lhs ^ __Vfunc_fp32_mul__2673__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2681__bits 
                            = __Vfunc_fp32_mul__2673__lhs;
                        __Vfunc_fp32_is_inf__2681__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2681__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2681__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2681__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2681__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2681__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2682__bits 
                            = __Vfunc_fp32_mul__2673__rhs;
                        __Vfunc_fp32_is_inf__2682__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2682__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2682__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2682__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2682__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2682__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2683__bits 
                            = __Vfunc_fp32_mul__2673__lhs;
                        __Vfunc_fp32_is_zero__2683__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2683__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2683__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2683__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2683__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2683__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2684__bits 
                            = __Vfunc_fp32_mul__2673__rhs;
                        __Vfunc_fp32_is_zero__2684__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2684__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2684__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2684__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2684__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2684__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2673__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2673__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2673__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2673__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2673__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2673__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2673__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2673__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2673__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2673__normalize_count = 1U;
        __Vfunc_fp32_mul__2673__normalize_count = 2U;
        __Vfunc_fp32_mul__2673__normalize_count = 3U;
        __Vfunc_fp32_mul__2673__normalize_count = 4U;
        __Vfunc_fp32_mul__2673__normalize_count = 5U;
        __Vfunc_fp32_mul__2673__normalize_count = 6U;
        __Vfunc_fp32_mul__2673__normalize_count = 7U;
        __Vfunc_fp32_mul__2673__normalize_count = 8U;
        __Vfunc_fp32_mul__2673__normalize_count = 9U;
        __Vfunc_fp32_mul__2673__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2673__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2673__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2673__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2673__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2673__product, vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2673__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2673__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2673__product 
               & vlSelfRef.__Vfunc_fp32_mul__2673__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2673__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2673__rounded = vlSelfRef.__Vfunc_fp32_mul__2673__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2673__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2673__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2673__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2673__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2673__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2673__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2673__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2673__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2673__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2673__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2673__mantissa)));
        __Vlabel3: ;
    }
}
