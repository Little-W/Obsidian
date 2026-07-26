// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines___024root.h"

VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__2(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___stl_sequent__TOP__2\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__active_columns_fp;
    tb_npu_engines__DOT__u_complex__DOT__active_columns_fp = 0;
    IData/*31:0*/ __Vfunc_fp32_div__401__numerator_value;
    __Vfunc_fp32_div__401__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__401__denominator_value;
    __Vfunc_fp32_div__401__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__401__normalize_count;
    __Vfunc_fp32_div__401__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__402__unused_sign;
    __Vfunc_fp32_is_nan__402__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__403__unused_sign;
    __Vfunc_fp32_is_nan__403__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__404__unused_sign;
    __Vfunc_fp32_is_zero__404__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__405__unused_sign;
    __Vfunc_fp32_is_zero__405__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__406__unused_sign;
    __Vfunc_fp32_is_inf__406__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__407__unused_sign;
    __Vfunc_fp32_is_inf__407__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__408__unused_sign;
    __Vfunc_fp32_is_inf__408__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__409__unused_sign;
    __Vfunc_fp32_is_zero__409__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__410__unused_sign;
    __Vfunc_fp32_is_zero__410__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__411__unused_sign;
    __Vfunc_fp32_is_inf__411__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_div__412__numerator_value;
    __Vfunc_fp32_div__412__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__412__denominator_value;
    __Vfunc_fp32_div__412__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__412__normalize_count;
    __Vfunc_fp32_div__412__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__413__unused_sign;
    __Vfunc_fp32_is_nan__413__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__414__unused_sign;
    __Vfunc_fp32_is_nan__414__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__415__unused_sign;
    __Vfunc_fp32_is_zero__415__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__416__unused_sign;
    __Vfunc_fp32_is_zero__416__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__417__unused_sign;
    __Vfunc_fp32_is_inf__417__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__418__unused_sign;
    __Vfunc_fp32_is_inf__418__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__419__unused_sign;
    __Vfunc_fp32_is_inf__419__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__420__unused_sign;
    __Vfunc_fp32_is_zero__420__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__421__unused_sign;
    __Vfunc_fp32_is_zero__421__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__422__unused_sign;
    __Vfunc_fp32_is_inf__422__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__423__lhs;
    __Vfunc_fp32_mul__423__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__423__rhs;
    __Vfunc_fp32_mul__423__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__423__normalize_count;
    __Vfunc_fp32_mul__423__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__424__unused_sign;
    __Vfunc_fp32_is_nan__424__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__425__unused_sign;
    __Vfunc_fp32_is_nan__425__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__426__unused_sign;
    __Vfunc_fp32_is_inf__426__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__427__unused_sign;
    __Vfunc_fp32_is_zero__427__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__428__unused_sign;
    __Vfunc_fp32_is_inf__428__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__429__unused_sign;
    __Vfunc_fp32_is_zero__429__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__430__unused_sign;
    __Vfunc_fp32_is_inf__430__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__431__unused_sign;
    __Vfunc_fp32_is_inf__431__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__432__unused_sign;
    __Vfunc_fp32_is_zero__432__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__433__unused_sign;
    __Vfunc_fp32_is_zero__433__unused_sign = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__646__Vfuncout;
    __Vfunc_store_element_strb__646__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_store_element_strb__646__byte_lane;
    __Vfunc_store_element_strb__646__byte_lane = 0;
    CData/*1:0*/ __Vfunc_store_element_strb__646__dtype;
    __Vfunc_store_element_strb__646__dtype = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__646__result;
    __Vfunc_store_element_strb__646__result = 0;
    // Body
    tb_npu_engines__DOT__u_complex__DOT__active_columns_fp 
        = vlSelfRef.__Vfunc_fp32_from_int__369__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 0U;
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q;
    if ((((0U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q)) 
          & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 0U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (1U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (2U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 2U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 2U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 2U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 2U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (3U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 3U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 3U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 3U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 3U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (4U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 4U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 4U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 4U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 4U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 5U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 5U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 5U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 5U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (0U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 0U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (2U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 2U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 2U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 2U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 2U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (3U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 3U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 3U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 3U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 3U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (4U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 4U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 4U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 4U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 4U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (5U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 5U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 5U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 5U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 5U;
    }
    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wstrb = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wstrb 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT____VdfgExtracted_ha467d4d5__0;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wstrb 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT____VdfgExtracted_h8e2aa811__0;
                        vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr 
                                                    >> 3U)) 
                                           << 3U));
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                if ((1U & (~ vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x2cU]))) {
                    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
            vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_addr 
                                        >> 3U)) << 3U));
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr = 0U;
    __Vfunc_store_element_strb__646__dtype = (3U & 
                                              (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                                               >> 6U));
    __Vfunc_store_element_strb__646__byte_lane = (7U 
                                                  & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr));
    __Vfunc_store_element_strb__646__result = 0U;
    __Vfunc_store_element_strb__646__result = ((2U 
                                                & (IData)(__Vfunc_store_element_strb__646__dtype))
                                                ? (0xffU 
                                                   & ((1U 
                                                       & (IData)(__Vfunc_store_element_strb__646__dtype))
                                                       ? 
                                                      ((IData)(3U) 
                                                       << (IData)(__Vfunc_store_element_strb__646__byte_lane))
                                                       : 
                                                      ((IData)(0xfU) 
                                                       << (IData)(__Vfunc_store_element_strb__646__byte_lane))))
                                                : ((IData)(__Vfunc_store_element_strb__646__result) 
                                                   | (0xffU 
                                                      & ((IData)(1U) 
                                                         << (IData)(__Vfunc_store_element_strb__646__byte_lane)))));
    __Vfunc_store_element_strb__646__Vfuncout = __Vfunc_store_element_strb__646__result;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT____VdfgExtracted_h20747776__0 
        = __Vfunc_store_element_strb__646__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_high_nibble = 0U;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr 
                                                    >> 3U)) 
                                           << 3U));
                        vlSelfRef.__Vfunc_store_element_data__532__dtype 
                            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_store_element_data__532__high_nibble 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_high_nibble;
                        vlSelfRef.__Vfunc_store_element_data__532__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr));
                        vlSelfRef.__Vfunc_store_element_data__532__value 
                            = (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q);
                        vlSelfRef.__Vfunc_store_element_data__532__old_beat 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rmw_beat_q;
                        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
                        vlSelf->__Vfunc_store_element_data__532__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12932204710354151735ull);
                        vlSelfRef.__Vfunc_store_element_data__532__result 
                            = vlSelfRef.__Vfunc_store_element_data__532__old_beat;
                        if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__532__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__532__result 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__532__dtype))
                                    ? (((~ (0xffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__532__result) 
                                       | ((QData)((IData)(
                                                          (0xffffU 
                                                           & vlSelfRef.__Vfunc_store_element_data__532__value))) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U))))
                                    : (((~ (0xffffffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__532__result) 
                                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__532__value)) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U)))));
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__532__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__532__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__532__result) 
                                   | ((QData)((IData)(
                                                      (0xffU 
                                                       & vlSelfRef.__Vfunc_store_element_data__532__value))) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U))));
                        } else {
                            vlSelfRef.__Vfunc_store_element_data__532__byte_value 
                                = (0xffU & (IData)(
                                                   (vlSelfRef.__Vfunc_store_element_data__532__old_beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U)))));
                            vlSelfRef.__Vfunc_store_element_data__532__byte_value 
                                = ((IData)(vlSelfRef.__Vfunc_store_element_data__532__high_nibble)
                                    ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_value)) 
                                       | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__532__value 
                                                   << 4U)))
                                    : ((0xf0U & (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_value)) 
                                       | (0xfU & vlSelfRef.__Vfunc_store_element_data__532__value)));
                            vlSelfRef.__Vfunc_store_element_data__532__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__532__result) 
                                   | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_value)) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__532__byte_lane), 3U))));
                        }
                        vlSelfRef.__Vfunc_store_element_data__532__Vfuncout 
                            = vlSelfRef.__Vfunc_store_element_data__532__result;
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wdata 
                            = vlSelfRef.__Vfunc_store_element_data__532__Vfuncout;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
            vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr 
                                        >> 3U)) << 3U));
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_src_dtype 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__124__opcode 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__124__Vfuncout 
                    = ((0x24U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__124__opcode)) 
                       | (0x25U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__124__opcode)));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__124__Vfuncout))
            ? 1U : (3U & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU]));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__125__opcode 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__125__Vfuncout 
                    = ((0x24U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__125__opcode)) 
                       | (0x25U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__125__opcode)));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__125__Vfuncout))
            ? 1U : (3U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU] 
                          >> 6U)));
    if ((0x24U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q))) {
        if ((0U != (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU] 
                    >> 0x10U))) {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset 
                = ((VL_DIV_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))) 
                    * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2bU]))) 
                   + VL_MODDIV_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))));
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
        }
    } else if ((0x25U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q))) {
        if ((0U != (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU] 
                    >> 0x10U))) {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset 
                = ((VL_DIV_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))) 
                    * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2bU]))) 
                   + VL_MODDIV_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))));
        }
    } else if ((0x23U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q))) {
        if ((0U == (3U & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU]))) {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset 
                = ((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_row 
                    * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x18U]))) 
                   + VL_SHIFTR_QQI(64,64,32, (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_col 
                                              + (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                                                                    >> 0x10U))))), 1U));
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset 
                = ((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_col 
                    * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x1eU]))) 
                   + VL_SHIFTR_QQI(64,64,32, (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_row 
                                              + (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                                                                    >> 0x18U))))), 1U));
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_high_nibble 
                = (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_col) 
                         ^ (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                            >> 0x10U)));
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble 
                = (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_row) 
                         ^ (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                            >> 0x18U)));
        } else {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____VdfgExtracted_h5b28d49a__0;
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____VdfgExtracted_hb6bd6506__0;
        }
    } else {
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__start_nibble 
            = (1U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                     >> 0x10U));
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dtype 
            = (3U & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU]);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[0U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x18U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[1U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x19U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[2U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x1aU];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[3U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x1bU];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[4U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x1cU];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[0U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[1U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[2U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[3U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[4U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value 
            = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__linear 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
        for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
            vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 705146290332542116ull);
        }
        vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4923162864705795472ull);
        vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 239284413512978659ull);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__linear;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[0U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[1U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[2U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[3U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[4U] = 0ULL;
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[4U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[4U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
            }
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[3U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[3U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
            }
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[2U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[2U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
            }
        }
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[1U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[1U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
            }
        }
        if ((0U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__shapes[0U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes[0U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dimension_size_wide);
            }
        }
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result = 0ULL;
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes
                      [0U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[0U]))));
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes
                      [1U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[1U]))));
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes
                      [2U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[2U]))));
        }
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes
                      [3U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__strides[3U]))));
        }
        if (((1U <= (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value)) 
             & (5U >= (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value)))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dtype))
                    ? (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                       + VL_SHIFTR_QQI(64,64,32, ((
                                                   (4U 
                                                    >= 
                                                    (7U 
                                                     & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value) 
                                                        - (IData)(1U))))
                                                    ? 
                                                   vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes
                                                   [
                                                   (7U 
                                                    & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value) 
                                                       - (IData)(1U)))]
                                                    : 0ULL) 
                                                  + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__start_nibble))), 1U))
                    : (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result 
                       + (((4U >= (7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value) 
                                         - (IData)(1U))))
                            ? vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__indexes
                           [(7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__rank_value) 
                                   - (IData)(1U)))]
                            : 0ULL) * VL_EXTEND_QI(64,3, 
                                                   ([&]() {
                                    vlSelfRef.__Vfunc_dtype_bytes__127__dtype 
                                        = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__dtype;
                                    vlSelfRef.__Vfunc_dtype_bytes__127__Vfuncout 
                                        = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__127__dtype))
                                            ? 1U : 
                                           ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__127__dtype))
                                             ? 4U : 
                                            ((3U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__127__dtype))
                                              ? 2U : 0U)));
                                }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__127__Vfuncout))))));
        }
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__Vfuncout 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__result;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__126__Vfuncout;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__start_nibble 
            = (1U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                     >> 0x18U));
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dtype 
            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU] 
                     >> 6U));
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[0U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x1eU];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[1U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x1fU];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[2U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x20U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[3U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x21U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[4U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x22U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[0U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[1U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[2U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[3U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[4U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value 
            = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__linear 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
        for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
            vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5898720126178521780ull);
        }
        vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13361743058333896719ull);
        vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13827341858341662330ull);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__linear;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[0U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[1U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[2U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[3U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[4U] = 0ULL;
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[4U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[4U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
            }
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[3U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[3U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
            }
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[2U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[2U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
            }
        }
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[1U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[1U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
            }
        }
        if ((0U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__shapes[0U];
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size)) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes[0U] 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__remainder, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dimension_size_wide);
            }
        }
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result = 0ULL;
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes
                      [0U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[0U]))));
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes
                      [1U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[1U]))));
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes
                      [2U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[2U]))));
        }
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes
                      [3U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__strides[3U]))));
        }
        if (((1U <= (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value)) 
             & (5U >= (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value)))) {
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dtype))
                    ? (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                       + VL_SHIFTR_QQI(64,64,32, ((
                                                   (4U 
                                                    >= 
                                                    (7U 
                                                     & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value) 
                                                        - (IData)(1U))))
                                                    ? 
                                                   vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes
                                                   [
                                                   (7U 
                                                    & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value) 
                                                       - (IData)(1U)))]
                                                    : 0ULL) 
                                                  + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__start_nibble))), 1U))
                    : (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result 
                       + (((4U >= (7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value) 
                                         - (IData)(1U))))
                            ? vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__indexes
                           [(7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__rank_value) 
                                   - (IData)(1U)))]
                            : 0ULL) * VL_EXTEND_QI(64,3, 
                                                   ([&]() {
                                    vlSelfRef.__Vfunc_dtype_bytes__129__dtype 
                                        = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__dtype;
                                    vlSelfRef.__Vfunc_dtype_bytes__129__Vfuncout 
                                        = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__129__dtype))
                                            ? 1U : 
                                           ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__129__dtype))
                                             ? 4U : 
                                            ((3U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__129__dtype))
                                              ? 2U : 0U)));
                                }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__129__Vfuncout))))));
        }
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__Vfuncout 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__result;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_byte_offset__128__Vfuncout;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__dtype 
            = (3U & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU]);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__start_nibble 
            = (1U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                     >> 0x10U));
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__shapes[0U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__shapes[1U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__shapes[2U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__shapes[3U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__shapes[4U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value 
            = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__linear 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
        vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__inner_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4435566870731845793ull);
        {
            if ((((0U != (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__dtype)) 
                  | (0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value))) 
                 | (5U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value)))) {
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__Vfuncout = 0U;
                goto __Vlabel0;
            }
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__inner_size 
                = ((0x9fU >= (0xffU & VL_SHIFTL_III(8,32,32, 
                                                    ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value) 
                                                     - (IData)(1U)), 5U)))
                    ? (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, 
                                                      ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value) 
                                                       - (IData)(1U)), 5U)))
                         ? 0U : (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__shapes[
                                 (((IData)(0x1fU) + 
                                   (0xffU & VL_SHIFTL_III(8,32,32, 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value) 
                                                           - (IData)(1U)), 5U))) 
                                  >> 5U)] << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(8,32,32, 
                                                                 ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value) 
                                                                  - (IData)(1U)), 5U))))) 
                       | (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__shapes[
                          (7U & (VL_SHIFTL_III(8,32,32, 
                                               ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value) 
                                                - (IData)(1U)), 5U) 
                                 >> 5U))] >> (0x1fU 
                                              & VL_SHIFTL_III(8,32,32, 
                                                              ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__rank_value) 
                                                               - (IData)(1U)), 5U))))
                    : 0U);
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__Vfuncout 
                = (((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__inner_size) 
                    & (IData)(VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__linear, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__inner_size))))) 
                   ^ (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__start_nibble));
            __Vlabel0: ;
        }
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_high_nibble 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__130__Vfuncout;
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__dtype 
            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU] 
                     >> 6U));
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__start_nibble 
            = (1U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                     >> 0x18U));
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__shapes[0U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__shapes[1U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__shapes[2U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__shapes[3U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__shapes[4U] 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value 
            = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__linear 
            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
        vlSelf->__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__inner_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2285686862230364915ull);
        {
            if ((((0U != (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__dtype)) 
                  | (0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value))) 
                 | (5U < (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value)))) {
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__Vfuncout = 0U;
                goto __Vlabel1;
            }
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__inner_size 
                = ((0x9fU >= (0xffU & VL_SHIFTL_III(8,32,32, 
                                                    ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value) 
                                                     - (IData)(1U)), 5U)))
                    ? (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, 
                                                      ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value) 
                                                       - (IData)(1U)), 5U)))
                         ? 0U : (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__shapes[
                                 (((IData)(0x1fU) + 
                                   (0xffU & VL_SHIFTL_III(8,32,32, 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value) 
                                                           - (IData)(1U)), 5U))) 
                                  >> 5U)] << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(8,32,32, 
                                                                 ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value) 
                                                                  - (IData)(1U)), 5U))))) 
                       | (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__shapes[
                          (7U & (VL_SHIFTL_III(8,32,32, 
                                               ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value) 
                                                - (IData)(1U)), 5U) 
                                 >> 5U))] >> (0x1fU 
                                              & VL_SHIFTL_III(8,32,32, 
                                                              ((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__rank_value) 
                                                               - (IData)(1U)), 5U))))
                    : 0U);
            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__Vfuncout 
                = (((0U != vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__inner_size) 
                    & (IData)(VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__linear, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__inner_size))))) 
                   ^ (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__start_nibble));
            __Vlabel1: ;
        }
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble 
            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_dma__DOT__nd_high_nibble__131__Vfuncout;
    }
    __Vfunc_fp32_div__401__denominator_value = tb_npu_engines__DOT__u_complex__DOT__active_columns_fp;
    __Vfunc_fp32_div__401__numerator_value = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_div__401__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8021635293133068378ull);
    vlSelf->__Vfunc_fp32_div__401__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14583698372246594630ull);
    vlSelf->__Vfunc_fp32_div__401__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4868081168297609358ull);
    vlSelf->__Vfunc_fp32_div__401__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 374405835131616865ull);
    vlSelf->__Vfunc_fp32_div__401__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 1041599284051114982ull);
    vlSelf->__Vfunc_fp32_div__401__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18372227605019738636ull);
    vlSelf->__Vfunc_fp32_div__401__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4792075800067596504ull);
    vlSelf->__Vfunc_fp32_div__401__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 8439235744515556859ull);
    vlSelf->__Vfunc_fp32_div__401__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4085838308715233732ull);
    vlSelf->__Vfunc_fp32_div__401__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1770232794029647059ull);
    vlSelf->__Vfunc_fp32_div__401__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16142849805375099869ull);
    vlSelf->__Vfunc_fp32_div__401__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10937911963459150438ull);
    vlSelf->__Vfunc_fp32_div__401__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2745179560511115695ull);
    __Vfunc_fp32_div__401__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__402__bits 
                                    = __Vfunc_fp32_div__401__numerator_value;
                                __Vfunc_fp32_is_nan__402__unused_sign = 0;
                                __Vfunc_fp32_is_nan__402__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__402__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__402__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__402__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__402__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__402__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__403__bits 
                                    = __Vfunc_fp32_div__401__denominator_value;
                                __Vfunc_fp32_is_nan__403__unused_sign = 0;
                                __Vfunc_fp32_is_nan__403__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__403__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__403__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__403__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__403__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__403__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__404__bits 
                                    = __Vfunc_fp32_div__401__numerator_value;
                                __Vfunc_fp32_is_zero__404__unused_sign = 0;
                                __Vfunc_fp32_is_zero__404__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__404__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__404__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__404__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__404__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__405__bits 
                                    = __Vfunc_fp32_div__401__denominator_value;
                                __Vfunc_fp32_is_zero__405__unused_sign = 0;
                                __Vfunc_fp32_is_zero__405__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__405__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__405__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__405__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__405__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__406__bits 
                                = __Vfunc_fp32_div__401__numerator_value;
                            __Vfunc_fp32_is_inf__406__unused_sign = 0;
                            __Vfunc_fp32_is_inf__406__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__406__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__406__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__406__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__406__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__407__bits 
                                = __Vfunc_fp32_div__401__denominator_value;
                            __Vfunc_fp32_is_inf__407__unused_sign = 0;
                            __Vfunc_fp32_is_inf__407__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__407__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__407__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__407__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__407__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__401__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_div__401__result_sign 
            = ((__Vfunc_fp32_div__401__numerator_value 
                ^ __Vfunc_fp32_div__401__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__408__bits 
                            = __Vfunc_fp32_div__401__numerator_value;
                        __Vfunc_fp32_is_inf__408__unused_sign = 0;
                        __Vfunc_fp32_is_inf__408__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__408__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__408__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__408__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__408__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__409__bits 
                            = __Vfunc_fp32_div__401__denominator_value;
                        __Vfunc_fp32_is_zero__409__unused_sign = 0;
                        __Vfunc_fp32_is_zero__409__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__409__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__409__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__409__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__409__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__401__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__401__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__410__bits 
                            = __Vfunc_fp32_div__401__numerator_value;
                        __Vfunc_fp32_is_zero__410__unused_sign = 0;
                        __Vfunc_fp32_is_zero__410__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__410__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__410__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__410__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__410__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__411__bits 
                            = __Vfunc_fp32_div__401__denominator_value;
                        __Vfunc_fp32_is_inf__411__unused_sign = 0;
                        __Vfunc_fp32_is_inf__411__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__411__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__411__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__411__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__411__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__401__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__401__result_sign) 
                   << 0x1fU);
            goto __Vlabel2;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__401__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__401__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__401__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__401__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__401__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__401__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__401__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__401__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__401__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__401__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__401__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__401__normalize_count = 1U;
        __Vfunc_fp32_div__401__normalize_count = 2U;
        __Vfunc_fp32_div__401__normalize_count = 3U;
        __Vfunc_fp32_div__401__normalize_count = 4U;
        __Vfunc_fp32_div__401__normalize_count = 5U;
        __Vfunc_fp32_div__401__normalize_count = 6U;
        __Vfunc_fp32_div__401__normalize_count = 7U;
        __Vfunc_fp32_div__401__normalize_count = 8U;
        __Vfunc_fp32_div__401__normalize_count = 9U;
        __Vfunc_fp32_div__401__normalize_count = 0xaU;
        __Vfunc_fp32_div__401__normalize_count = 0xbU;
        __Vfunc_fp32_div__401__normalize_count = 0xcU;
        __Vfunc_fp32_div__401__normalize_count = 0xdU;
        __Vfunc_fp32_div__401__normalize_count = 0xeU;
        __Vfunc_fp32_div__401__normalize_count = 0xfU;
        __Vfunc_fp32_div__401__normalize_count = 0x10U;
        __Vfunc_fp32_div__401__normalize_count = 0x11U;
        __Vfunc_fp32_div__401__normalize_count = 0x12U;
        __Vfunc_fp32_div__401__normalize_count = 0x13U;
        __Vfunc_fp32_div__401__normalize_count = 0x14U;
        __Vfunc_fp32_div__401__normalize_count = 0x15U;
        __Vfunc_fp32_div__401__normalize_count = 0x16U;
        __Vfunc_fp32_div__401__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__401__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__401__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__401__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__401__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__401__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__401__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__401__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__401__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__401__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__401__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__401__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__401__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__401__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__401__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__401__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__401__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__401__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__401__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__401__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__401__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__401__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__401__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__401__quotient_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_div__401__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__401__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__401__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__401__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__401__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__401__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__401__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__401__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__401__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__401__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__401__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__401__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__401__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__401__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__401__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__401__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__401__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__401__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__401__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__401__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__401__result_sign) 
                   << 0x1fU);
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_div__401__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_div__401__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_div__401__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__401__mantissa)));
        __Vlabel2: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean 
        = vlSelfRef.__Vfunc_fp32_div__401__Vfuncout;
    __Vfunc_fp32_div__412__denominator_value = tb_npu_engines__DOT__u_complex__DOT__active_columns_fp;
    __Vfunc_fp32_div__412__numerator_value = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sumsq_q;
    vlSelf->__Vfunc_fp32_div__412__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13215326937388791539ull);
    vlSelf->__Vfunc_fp32_div__412__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12661764419704266124ull);
    vlSelf->__Vfunc_fp32_div__412__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12601855976712566461ull);
    vlSelf->__Vfunc_fp32_div__412__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 11006881762105081579ull);
    vlSelf->__Vfunc_fp32_div__412__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 11720836608922910716ull);
    vlSelf->__Vfunc_fp32_div__412__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4518338707582543966ull);
    vlSelf->__Vfunc_fp32_div__412__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3127990587914025601ull);
    vlSelf->__Vfunc_fp32_div__412__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 5847704136441215995ull);
    vlSelf->__Vfunc_fp32_div__412__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14694223156261302288ull);
    vlSelf->__Vfunc_fp32_div__412__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3802427062216784918ull);
    vlSelf->__Vfunc_fp32_div__412__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18423245845654835122ull);
    vlSelf->__Vfunc_fp32_div__412__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6239949129316917759ull);
    vlSelf->__Vfunc_fp32_div__412__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12483253241669280794ull);
    __Vfunc_fp32_div__412__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__413__bits 
                                    = __Vfunc_fp32_div__412__numerator_value;
                                __Vfunc_fp32_is_nan__413__unused_sign = 0;
                                __Vfunc_fp32_is_nan__413__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__413__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__413__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__413__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__413__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__413__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__414__bits 
                                    = __Vfunc_fp32_div__412__denominator_value;
                                __Vfunc_fp32_is_nan__414__unused_sign = 0;
                                __Vfunc_fp32_is_nan__414__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__414__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__414__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__414__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__414__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__414__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__415__bits 
                                    = __Vfunc_fp32_div__412__numerator_value;
                                __Vfunc_fp32_is_zero__415__unused_sign = 0;
                                __Vfunc_fp32_is_zero__415__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__415__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__415__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__415__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__415__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__416__bits 
                                    = __Vfunc_fp32_div__412__denominator_value;
                                __Vfunc_fp32_is_zero__416__unused_sign = 0;
                                __Vfunc_fp32_is_zero__416__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__416__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__416__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__416__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__416__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__417__bits 
                                = __Vfunc_fp32_div__412__numerator_value;
                            __Vfunc_fp32_is_inf__417__unused_sign = 0;
                            __Vfunc_fp32_is_inf__417__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__417__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__417__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__417__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__417__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__418__bits 
                                = __Vfunc_fp32_div__412__denominator_value;
                            __Vfunc_fp32_is_inf__418__unused_sign = 0;
                            __Vfunc_fp32_is_inf__418__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__418__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__418__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__418__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__418__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__412__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__412__result_sign 
            = ((__Vfunc_fp32_div__412__numerator_value 
                ^ __Vfunc_fp32_div__412__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__419__bits 
                            = __Vfunc_fp32_div__412__numerator_value;
                        __Vfunc_fp32_is_inf__419__unused_sign = 0;
                        __Vfunc_fp32_is_inf__419__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__419__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__419__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__419__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__419__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__420__bits 
                            = __Vfunc_fp32_div__412__denominator_value;
                        __Vfunc_fp32_is_zero__420__unused_sign = 0;
                        __Vfunc_fp32_is_zero__420__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__420__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__420__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__420__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__420__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__412__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__412__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__421__bits 
                            = __Vfunc_fp32_div__412__numerator_value;
                        __Vfunc_fp32_is_zero__421__unused_sign = 0;
                        __Vfunc_fp32_is_zero__421__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__421__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__421__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__421__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__421__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__422__bits 
                            = __Vfunc_fp32_div__412__denominator_value;
                        __Vfunc_fp32_is_inf__422__unused_sign = 0;
                        __Vfunc_fp32_is_inf__422__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__422__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__422__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__422__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__422__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__412__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__412__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__412__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__412__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__412__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__412__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__412__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__412__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__412__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__412__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__412__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__412__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__412__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__412__normalize_count = 1U;
        __Vfunc_fp32_div__412__normalize_count = 2U;
        __Vfunc_fp32_div__412__normalize_count = 3U;
        __Vfunc_fp32_div__412__normalize_count = 4U;
        __Vfunc_fp32_div__412__normalize_count = 5U;
        __Vfunc_fp32_div__412__normalize_count = 6U;
        __Vfunc_fp32_div__412__normalize_count = 7U;
        __Vfunc_fp32_div__412__normalize_count = 8U;
        __Vfunc_fp32_div__412__normalize_count = 9U;
        __Vfunc_fp32_div__412__normalize_count = 0xaU;
        __Vfunc_fp32_div__412__normalize_count = 0xbU;
        __Vfunc_fp32_div__412__normalize_count = 0xcU;
        __Vfunc_fp32_div__412__normalize_count = 0xdU;
        __Vfunc_fp32_div__412__normalize_count = 0xeU;
        __Vfunc_fp32_div__412__normalize_count = 0xfU;
        __Vfunc_fp32_div__412__normalize_count = 0x10U;
        __Vfunc_fp32_div__412__normalize_count = 0x11U;
        __Vfunc_fp32_div__412__normalize_count = 0x12U;
        __Vfunc_fp32_div__412__normalize_count = 0x13U;
        __Vfunc_fp32_div__412__normalize_count = 0x14U;
        __Vfunc_fp32_div__412__normalize_count = 0x15U;
        __Vfunc_fp32_div__412__normalize_count = 0x16U;
        __Vfunc_fp32_div__412__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__412__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__412__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__412__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__412__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__412__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__412__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__412__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__412__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__412__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__412__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__412__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__412__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__412__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__412__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__412__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__412__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__412__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__412__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__412__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__412__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__412__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__412__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__412__quotient_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_div__412__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__412__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__412__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__412__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__412__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__412__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__412__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__412__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__412__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__412__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__412__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__412__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__412__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__412__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__412__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__412__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__412__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__412__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__412__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__412__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__412__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__412__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_div__412__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_div__412__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__412__mantissa)));
        __Vlabel3: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean_square 
        = vlSelfRef.__Vfunc_fp32_div__412__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__l1_req_ready = 0U;
    if (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h08238727__0 = 1U;
        if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
            vlSelfRef.tb_npu_engines__DOT__l1_req_ready 
                = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) 
                    & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)) 
                   | (0x3fU & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h08238727__0) 
                               << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))));
        }
    }
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wstrb = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wstrb 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT____VdfgExtracted_h20747776__0;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[3U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[2U]))) 
           + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[8U]))) 
           + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset);
    __Vfunc_fp32_mul__423__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean;
    __Vfunc_fp32_mul__423__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean;
    vlSelf->__Vfunc_fp32_mul__423__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12019196470894682938ull);
    vlSelf->__Vfunc_fp32_mul__423__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2961078907560178931ull);
    vlSelf->__Vfunc_fp32_mul__423__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1376357362019319957ull);
    vlSelf->__Vfunc_fp32_mul__423__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 5480222938107668763ull);
    vlSelf->__Vfunc_fp32_mul__423__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11298530927575735694ull);
    vlSelf->__Vfunc_fp32_mul__423__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9842338694120606745ull);
    vlSelf->__Vfunc_fp32_mul__423__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15702538960974458655ull);
    vlSelf->__Vfunc_fp32_mul__423__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 11704909168728808439ull);
    vlSelf->__Vfunc_fp32_mul__423__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15610710724799293425ull);
    vlSelf->__Vfunc_fp32_mul__423__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17287474703911681977ull);
    vlSelf->__Vfunc_fp32_mul__423__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12867200073725768564ull);
    vlSelf->__Vfunc_fp32_mul__423__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16392815303048493988ull);
    vlSelf->__Vfunc_fp32_mul__423__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10006606866874067871ull);
    __Vfunc_fp32_mul__423__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__424__bits 
                                = __Vfunc_fp32_mul__423__lhs;
                            __Vfunc_fp32_is_nan__424__unused_sign = 0;
                            __Vfunc_fp32_is_nan__424__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__424__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__424__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__424__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__424__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__424__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__425__bits 
                                = __Vfunc_fp32_mul__423__rhs;
                            __Vfunc_fp32_is_nan__425__unused_sign = 0;
                            __Vfunc_fp32_is_nan__425__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__425__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__425__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__425__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__425__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__425__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__426__bits 
                                    = __Vfunc_fp32_mul__423__lhs;
                                __Vfunc_fp32_is_inf__426__unused_sign = 0;
                                __Vfunc_fp32_is_inf__426__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__426__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__426__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__426__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__426__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__427__bits 
                                    = __Vfunc_fp32_mul__423__rhs;
                                __Vfunc_fp32_is_zero__427__unused_sign = 0;
                                __Vfunc_fp32_is_zero__427__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__427__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__427__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__427__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__427__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__428__bits 
                                    = __Vfunc_fp32_mul__423__rhs;
                                __Vfunc_fp32_is_inf__428__unused_sign = 0;
                                __Vfunc_fp32_is_inf__428__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__428__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__428__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__428__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__428__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__429__bits 
                                    = __Vfunc_fp32_mul__423__lhs;
                                __Vfunc_fp32_is_zero__429__unused_sign = 0;
                                __Vfunc_fp32_is_zero__429__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__429__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__429__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__429__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__429__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout = 0x7fc00000U;
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_mul__423__result_sign 
            = ((__Vfunc_fp32_mul__423__lhs ^ __Vfunc_fp32_mul__423__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__430__bits 
                            = __Vfunc_fp32_mul__423__lhs;
                        __Vfunc_fp32_is_inf__430__unused_sign = 0;
                        __Vfunc_fp32_is_inf__430__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__430__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__430__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__430__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__430__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__431__bits 
                            = __Vfunc_fp32_mul__423__rhs;
                        __Vfunc_fp32_is_inf__431__unused_sign = 0;
                        __Vfunc_fp32_is_inf__431__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__431__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__431__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__431__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__431__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                                  << 0x1fU));
            goto __Vlabel4;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__432__bits 
                            = __Vfunc_fp32_mul__423__lhs;
                        __Vfunc_fp32_is_zero__432__unused_sign = 0;
                        __Vfunc_fp32_is_zero__432__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__432__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__432__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__432__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__432__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__433__bits 
                            = __Vfunc_fp32_mul__423__rhs;
                        __Vfunc_fp32_is_zero__433__unused_sign = 0;
                        __Vfunc_fp32_is_zero__433__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__433__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__433__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__433__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__433__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                   << 0x1fU);
            goto __Vlabel4;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__423__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__423__lhs);
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__423__lhs));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__423__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__423__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__423__rhs);
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__423__rhs));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__423__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__423__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__423__normalize_count = 1U;
        __Vfunc_fp32_mul__423__normalize_count = 2U;
        __Vfunc_fp32_mul__423__normalize_count = 3U;
        __Vfunc_fp32_mul__423__normalize_count = 4U;
        __Vfunc_fp32_mul__423__normalize_count = 5U;
        __Vfunc_fp32_mul__423__normalize_count = 6U;
        __Vfunc_fp32_mul__423__normalize_count = 7U;
        __Vfunc_fp32_mul__423__normalize_count = 8U;
        __Vfunc_fp32_mul__423__normalize_count = 9U;
        __Vfunc_fp32_mul__423__normalize_count = 0xaU;
        __Vfunc_fp32_mul__423__normalize_count = 0xbU;
        __Vfunc_fp32_mul__423__normalize_count = 0xcU;
        __Vfunc_fp32_mul__423__normalize_count = 0xdU;
        __Vfunc_fp32_mul__423__normalize_count = 0xeU;
        __Vfunc_fp32_mul__423__normalize_count = 0xfU;
        __Vfunc_fp32_mul__423__normalize_count = 0x10U;
        __Vfunc_fp32_mul__423__normalize_count = 0x11U;
        __Vfunc_fp32_mul__423__normalize_count = 0x12U;
        __Vfunc_fp32_mul__423__normalize_count = 0x13U;
        __Vfunc_fp32_mul__423__normalize_count = 0x14U;
        __Vfunc_fp32_mul__423__normalize_count = 0x15U;
        __Vfunc_fp32_mul__423__normalize_count = 0x16U;
        __Vfunc_fp32_mul__423__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__423__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__423__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__423__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__423__product, vlSelfRef.__Vfunc_fp32_mul__423__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__423__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__423__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__423__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__423__product 
               & vlSelfRef.__Vfunc_fp32_mul__423__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__423__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__423__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__423__rounded = vlSelfRef.__Vfunc_fp32_mul__423__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__423__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__423__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__423__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__423__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__423__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__423__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__423__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__423__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__423__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__423__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                                  << 0x1fU));
            goto __Vlabel4;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                   << 0x1fU);
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__423__mantissa)));
        __Vlabel4: ;
    }
}

VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__3(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___stl_sequent__TOP__3\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared;
    tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_variance;
    tb_npu_engines__DOT__u_complex__DOT__fp_variance = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon;
    tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__342__unused_sign;
    __Vfunc_fp32_is_nan__342__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__343__unused_sign;
    __Vfunc_fp32_is_nan__343__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__345__unused_sign;
    __Vfunc_fp32_is_nan__345__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__346__unused_sign;
    __Vfunc_fp32_is_nan__346__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__347__unused_sign;
    __Vfunc_fp32_is_zero__347__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__348__unused_sign;
    __Vfunc_fp32_is_zero__348__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__350__unused_sign;
    __Vfunc_fp32_is_nan__350__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__351__unused_sign;
    __Vfunc_fp32_is_nan__351__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__353__unused_sign;
    __Vfunc_fp32_is_nan__353__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__354__unused_sign;
    __Vfunc_fp32_is_nan__354__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__355__unused_sign;
    __Vfunc_fp32_is_zero__355__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__356__unused_sign;
    __Vfunc_fp32_is_zero__356__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__358__normalize_count;
    __Vfunc_fp32_add__358__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__360__unused_sign;
    __Vfunc_fp32_is_nan__360__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__361__unused_sign;
    __Vfunc_fp32_is_nan__361__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__362__unused_sign;
    __Vfunc_fp32_is_inf__362__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__363__unused_sign;
    __Vfunc_fp32_is_inf__363__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__364__unused_sign;
    __Vfunc_fp32_is_inf__364__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__365__unused_sign;
    __Vfunc_fp32_is_inf__365__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__366__unused_sign;
    __Vfunc_fp32_is_inf__366__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__367__unused_sign;
    __Vfunc_fp32_is_zero__367__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__368__unused_sign;
    __Vfunc_fp32_is_zero__368__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__370__lhs;
    __Vfunc_fp32_add__370__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__370__rhs;
    __Vfunc_fp32_add__370__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__370__normalize_count;
    __Vfunc_fp32_add__370__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__371__unused_sign;
    __Vfunc_fp32_is_nan__371__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__372__unused_sign;
    __Vfunc_fp32_is_nan__372__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__373__unused_sign;
    __Vfunc_fp32_is_inf__373__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__374__unused_sign;
    __Vfunc_fp32_is_inf__374__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__375__unused_sign;
    __Vfunc_fp32_is_inf__375__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__376__unused_sign;
    __Vfunc_fp32_is_inf__376__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__377__unused_sign;
    __Vfunc_fp32_is_inf__377__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__378__unused_sign;
    __Vfunc_fp32_is_zero__378__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__379__unused_sign;
    __Vfunc_fp32_is_zero__379__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__434__Vfuncout;
    __Vfunc_fp32_sub__434__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__434__lhs;
    __Vfunc_fp32_sub__434__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__434__rhs;
    __Vfunc_fp32_sub__434__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__435__lhs;
    __Vfunc_fp32_add__435__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__435__rhs;
    __Vfunc_fp32_add__435__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__435__normalize_count;
    __Vfunc_fp32_add__435__normalize_count = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__436__Vfuncout;
    __Vfunc_fp32_neg__436__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__436__value;
    __Vfunc_fp32_neg__436__value = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__437__unused_sign;
    __Vfunc_fp32_is_nan__437__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__438__unused_sign;
    __Vfunc_fp32_is_nan__438__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__439__unused_sign;
    __Vfunc_fp32_is_inf__439__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__440__unused_sign;
    __Vfunc_fp32_is_inf__440__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__441__unused_sign;
    __Vfunc_fp32_is_inf__441__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__442__unused_sign;
    __Vfunc_fp32_is_inf__442__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__443__unused_sign;
    __Vfunc_fp32_is_inf__443__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__444__unused_sign;
    __Vfunc_fp32_is_zero__444__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__445__unused_sign;
    __Vfunc_fp32_is_zero__445__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__446__lhs;
    __Vfunc_fp32_add__446__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__446__rhs;
    __Vfunc_fp32_add__446__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__446__normalize_count;
    __Vfunc_fp32_add__446__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__447__unused_sign;
    __Vfunc_fp32_is_nan__447__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__448__unused_sign;
    __Vfunc_fp32_is_nan__448__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__449__unused_sign;
    __Vfunc_fp32_is_inf__449__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__450__unused_sign;
    __Vfunc_fp32_is_inf__450__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__451__unused_sign;
    __Vfunc_fp32_is_inf__451__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__452__unused_sign;
    __Vfunc_fp32_is_inf__452__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__453__unused_sign;
    __Vfunc_fp32_is_inf__453__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__454__unused_sign;
    __Vfunc_fp32_is_zero__454__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__455__unused_sign;
    __Vfunc_fp32_is_zero__455__unused_sign = 0;
    VlWide<4>/*127:0*/ __Vtemp_4;
    // Body
    tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared 
        = vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_handshake 
        = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found) 
           & ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
              & (((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
                  >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                 & ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                    & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready) 
                       >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_end_addr 
        = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__132__dtype 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_src_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__132__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__132__Vfuncout = 1U;
                            goto __Vlabel0;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__133__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__132__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__133__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__133__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__133__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__133__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__132__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__133__Vfuncout;
                        __Vlabel0: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__132__Vfuncout))));
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr = 0ULL;
    if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr);
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
        }
    }
    if ((8U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_end_addr 
        = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__134__dtype 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__134__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__134__Vfuncout = 1U;
                            goto __Vlabel1;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__135__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__134__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__135__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__135__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__135__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__135__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__134__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__135__Vfuncout;
                        __Vlabel1: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__134__Vfuncout))));
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr 
                                        >> 3U)) << 3U));
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata = 0ULL;
    if ((8U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.__Vfunc_store_element_strb__139__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__139__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__139__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__139__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__139__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__139__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__139__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__139__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__139__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__139__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__139__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__139__result;
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__139__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__138__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__138__high_nibble 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__138__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__138__value 
                = (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__138__old_beat 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q;
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
            vlSelf->__Vfunc_store_element_data__138__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9708337680819306562ull);
            vlSelfRef.__Vfunc_store_element_data__138__result 
                = vlSelfRef.__Vfunc_store_element_data__138__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__138__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__138__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__138__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__138__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__138__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__138__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__138__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__138__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__138__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__138__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__138__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__138__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__138__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__138__value)));
                vlSelfRef.__Vfunc_store_element_data__138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__138__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__138__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__138__result;
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__138__Vfuncout;
        }
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
            vlSelfRef.__Vfunc_store_element_strb__137__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__137__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__137__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__137__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__137__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__137__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__137__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__137__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__137__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__137__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__137__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__137__result;
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__137__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__136__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__136__high_nibble 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__136__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__136__value 
                = (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__136__old_beat 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q;
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
            vlSelf->__Vfunc_store_element_data__136__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15356923196557265986ull);
            vlSelfRef.__Vfunc_store_element_data__136__result 
                = vlSelfRef.__Vfunc_store_element_data__136__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__136__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__136__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__136__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__136__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__136__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__136__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__136__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__136__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__136__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__136__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__136__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__136__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__136__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__136__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__136__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__136__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__136__value)));
                vlSelfRef.__Vfunc_store_element_data__136__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__136__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__136__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__136__result;
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__136__Vfuncout;
        }
    }
    __Vfunc_fp32_sub__434__rhs = tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared;
    __Vfunc_fp32_sub__434__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean_square;
    __Vfunc_fp32_neg__436__value = __Vfunc_fp32_sub__434__rhs;
    __Vfunc_fp32_neg__436__Vfuncout = (((~ (__Vfunc_fp32_neg__436__value 
                                            >> 0x1fU)) 
                                        << 0x1fU) | 
                                       (0x7fffffffU 
                                        & __Vfunc_fp32_neg__436__value));
    __Vfunc_fp32_add__435__rhs = __Vfunc_fp32_neg__436__Vfuncout;
    __Vfunc_fp32_add__435__lhs = __Vfunc_fp32_sub__434__lhs;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_add__435__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4938517534005985283ull);
    vlSelf->__Vfunc_fp32_add__435__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11117266972080675029ull);
    vlSelf->__Vfunc_fp32_add__435__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8004103920994450513ull);
    vlSelf->__Vfunc_fp32_add__435__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13616730923292901522ull);
    vlSelf->__Vfunc_fp32_add__435__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17299530486266738730ull);
    vlSelf->__Vfunc_fp32_add__435__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6668407757464548892ull);
    vlSelf->__Vfunc_fp32_add__435__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2257046443573167039ull);
    vlSelf->__Vfunc_fp32_add__435__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15084403507230797525ull);
    vlSelf->__Vfunc_fp32_add__435__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10360277396037447057ull);
    vlSelf->__Vfunc_fp32_add__435__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11684965685300817308ull);
    vlSelf->__Vfunc_fp32_add__435__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18132458286291189482ull);
    vlSelf->__Vfunc_fp32_add__435__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8151327107639461428ull);
    vlSelf->__Vfunc_fp32_add__435__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13279679469688035440ull);
    vlSelf->__Vfunc_fp32_add__435__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5411743807519286711ull);
    vlSelf->__Vfunc_fp32_add__435__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 1030764701846290299ull);
    vlSelf->__Vfunc_fp32_add__435__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13079870302321298902ull);
    vlSelf->__Vfunc_fp32_add__435__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5771626209241536758ull);
    vlSelf->__Vfunc_fp32_add__435__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 12922771249817461923ull);
    vlSelf->__Vfunc_fp32_add__435__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10315717551383854503ull);
    vlSelf->__Vfunc_fp32_add__435__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 10884009952232145663ull);
    vlSelf->__Vfunc_fp32_add__435__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11995595712351745153ull);
    vlSelf->__Vfunc_fp32_add__435__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9151003695076360734ull);
    vlSelf->__Vfunc_fp32_add__435__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9914341361751087933ull);
    vlSelf->__Vfunc_fp32_add__435__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6627999922962605367ull);
    __Vfunc_fp32_add__435__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__437__bits 
                            = __Vfunc_fp32_add__435__lhs;
                        __Vfunc_fp32_is_nan__437__unused_sign = 0;
                        __Vfunc_fp32_is_nan__437__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__437__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__437__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__437__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__437__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__437__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__438__bits 
                            = __Vfunc_fp32_add__435__rhs;
                        __Vfunc_fp32_is_nan__438__unused_sign = 0;
                        __Vfunc_fp32_is_nan__438__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__438__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__438__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__438__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__438__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__438__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__439__bits 
                            = __Vfunc_fp32_add__435__lhs;
                        __Vfunc_fp32_is_inf__439__unused_sign = 0;
                        __Vfunc_fp32_is_inf__439__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__439__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__439__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__439__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__439__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__440__bits 
                            = __Vfunc_fp32_add__435__rhs;
                        __Vfunc_fp32_is_inf__440__unused_sign = 0;
                        __Vfunc_fp32_is_inf__440__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__440__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__440__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__440__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__440__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__441__bits 
                                    = __Vfunc_fp32_add__435__lhs;
                                __Vfunc_fp32_is_inf__441__unused_sign = 0;
                                __Vfunc_fp32_is_inf__441__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__441__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__441__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__441__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__441__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__442__bits 
                                    = __Vfunc_fp32_add__435__rhs;
                                __Vfunc_fp32_is_inf__442__unused_sign = 0;
                                __Vfunc_fp32_is_inf__442__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__442__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__442__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__442__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__442__Vfuncout))) 
                 & ((__Vfunc_fp32_add__435__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__435__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 0x7fc00000U;
                goto __Vlabel2;
            }
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__443__bits 
                            = __Vfunc_fp32_add__435__lhs;
                        __Vfunc_fp32_is_inf__443__unused_sign = 0;
                        __Vfunc_fp32_is_inf__443__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__443__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__443__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__443__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__443__Vfuncout))
                    ? __Vfunc_fp32_add__435__lhs : __Vfunc_fp32_add__435__rhs);
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__444__bits 
                        = __Vfunc_fp32_add__435__lhs;
                    __Vfunc_fp32_is_zero__444__unused_sign = 0;
                    __Vfunc_fp32_is_zero__444__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__444__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__444__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__444__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__444__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = __Vfunc_fp32_add__435__rhs;
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__445__bits 
                        = __Vfunc_fp32_add__435__rhs;
                    __Vfunc_fp32_is_zero__445__unused_sign = 0;
                    __Vfunc_fp32_is_zero__445__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__445__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__445__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__445__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__445__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = __Vfunc_fp32_add__435__lhs;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__435__lhs_sign = 
            (__Vfunc_fp32_add__435__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__435__rhs_sign = 
            (__Vfunc_fp32_add__435__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__435__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__435__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__435__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__435__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__435__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__435__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__435__lhs)));
        vlSelfRef.__Vfunc_fp32_add__435__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__435__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__435__rhs)));
        vlSelfRef.__Vfunc_fp32_add__435__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__435__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__435__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__435__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__435__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__435__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__435__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__435__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__435__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__435__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__435__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__435__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__435__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__435__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__small_ext, vlSelfRef.__Vfunc_fp32_add__435__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__435__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__435__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__435__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__435__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__435__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__435__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__435__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__435__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__435__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__435__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__435__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__435__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__435__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__435__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__435__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__435__work_ext);
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__435__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__435__sticky))));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__435__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__435__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__435__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 0U;
                goto __Vlabel2;
            }
            __Vfunc_fp32_add__435__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__435__normalize_count = 1U;
            __Vfunc_fp32_add__435__normalize_count = 2U;
            __Vfunc_fp32_add__435__normalize_count = 3U;
            __Vfunc_fp32_add__435__normalize_count = 4U;
            __Vfunc_fp32_add__435__normalize_count = 5U;
            __Vfunc_fp32_add__435__normalize_count = 6U;
            __Vfunc_fp32_add__435__normalize_count = 7U;
            __Vfunc_fp32_add__435__normalize_count = 8U;
            __Vfunc_fp32_add__435__normalize_count = 9U;
            __Vfunc_fp32_add__435__normalize_count = 0xaU;
            __Vfunc_fp32_add__435__normalize_count = 0xbU;
            __Vfunc_fp32_add__435__normalize_count = 0xcU;
            __Vfunc_fp32_add__435__normalize_count = 0xdU;
            __Vfunc_fp32_add__435__normalize_count = 0xeU;
            __Vfunc_fp32_add__435__normalize_count = 0xfU;
            __Vfunc_fp32_add__435__normalize_count = 0x10U;
            __Vfunc_fp32_add__435__normalize_count = 0x11U;
            __Vfunc_fp32_add__435__normalize_count = 0x12U;
            __Vfunc_fp32_add__435__normalize_count = 0x13U;
            __Vfunc_fp32_add__435__normalize_count = 0x14U;
            __Vfunc_fp32_add__435__normalize_count = 0x15U;
            __Vfunc_fp32_add__435__normalize_count = 0x16U;
            __Vfunc_fp32_add__435__normalize_count = 0x17U;
            __Vfunc_fp32_add__435__normalize_count = 0x18U;
            __Vfunc_fp32_add__435__normalize_count = 0x19U;
            __Vfunc_fp32_add__435__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__435__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__435__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__435__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__435__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__435__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__435__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__435__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__435__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__435__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__435__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__435__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__435__mantissa));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__435__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__435__mantissa)));
        __Vlabel2: ;
    }
    __Vfunc_fp32_sub__434__Vfuncout = vlSelfRef.__Vfunc_fp32_add__435__Vfuncout;
    tb_npu_engines__DOT__u_complex__DOT__fp_variance 
        = __Vfunc_fp32_sub__434__Vfuncout;
    __Vtemp_4[0U] = (IData)((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr)) 
                              << 0x28U) | (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_addr)))));
    __Vtemp_4[1U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr)))) 
                      << 0x1cU) | (IData)(((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr)) 
                                             << 0x28U) 
                                            | (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr)) 
                                                << 0x14U) 
                                               | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_addr)))) 
                                           >> 0x20U)));
    __Vtemp_4[2U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr)))) 
                      >> 4U) | ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                           << 0x14U) 
                                          | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr))) 
                                         >> 0x20U)) 
                                << 0x1cU));
    __Vtemp_4[3U] = ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr))) 
                              >> 0x20U)) >> 4U);
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
        = ((0x77U >= (0x7fU & ((IData)(0x14U) * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))
            ? (0xfffffU & (((0U == (0x1fU & ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))
                             ? 0U : (__Vtemp_4[(((IData)(0x13U) 
                                                 + 
                                                 (0x7fU 
                                                  & ((IData)(0x14U) 
                                                     * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)))) 
                                                >> 5U)] 
                                     << ((IData)(0x20U) 
                                         - (0x1fU & 
                                            ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)))))) 
                           | (__Vtemp_4[(3U & (((IData)(0x14U) 
                                                * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                                               >> 5U))] 
                              >> (0x1fU & ((IData)(0x14U) 
                                           * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))))
            : 0U);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb = (
                                                   ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wstrb)) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wstrb) 
                                                                        << 0x18U) 
                                                                       | ((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wstrb) 
                                                                          << 0x10U)) 
                                                                      | (((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wstrb) 
                                                                          << 8U) 
                                                                         | (IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb))))));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[0U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[1U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[2U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[3U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[4U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[5U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[6U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[7U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[8U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[9U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[0xaU] = 0U;
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[0xbU] = 0U;
    __Vfunc_fp32_add__446__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x24U];
    __Vfunc_fp32_add__446__lhs = ((5U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x13U])
                                   ? ((tb_npu_engines__DOT__u_complex__DOT__fp_variance 
                                       >> 0x1fU) ? 0U
                                       : tb_npu_engines__DOT__u_complex__DOT__fp_variance)
                                   : vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean_square);
    vlSelf->__Vfunc_fp32_add__446__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16904255823309399070ull);
    vlSelf->__Vfunc_fp32_add__446__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12123330368211358472ull);
    vlSelf->__Vfunc_fp32_add__446__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10967870315375116304ull);
    vlSelf->__Vfunc_fp32_add__446__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6028063520691358477ull);
    vlSelf->__Vfunc_fp32_add__446__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1330527397616622174ull);
    vlSelf->__Vfunc_fp32_add__446__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6743352812600753530ull);
    vlSelf->__Vfunc_fp32_add__446__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1043640227901866890ull);
    vlSelf->__Vfunc_fp32_add__446__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4075121582292662115ull);
    vlSelf->__Vfunc_fp32_add__446__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6866051757362854875ull);
    vlSelf->__Vfunc_fp32_add__446__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14699926927163397112ull);
    vlSelf->__Vfunc_fp32_add__446__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3319279733729695887ull);
    vlSelf->__Vfunc_fp32_add__446__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2561961523944946676ull);
    vlSelf->__Vfunc_fp32_add__446__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13530462243085905084ull);
    vlSelf->__Vfunc_fp32_add__446__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3020302678090155831ull);
    vlSelf->__Vfunc_fp32_add__446__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 127389205812672471ull);
    vlSelf->__Vfunc_fp32_add__446__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3606802074951781100ull);
    vlSelf->__Vfunc_fp32_add__446__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5406164153122920547ull);
    vlSelf->__Vfunc_fp32_add__446__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7677289732281827187ull);
    vlSelf->__Vfunc_fp32_add__446__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5837341528815444422ull);
    vlSelf->__Vfunc_fp32_add__446__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 12130318307312720436ull);
    vlSelf->__Vfunc_fp32_add__446__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9675971317425714056ull);
    vlSelf->__Vfunc_fp32_add__446__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11477145388416044289ull);
    vlSelf->__Vfunc_fp32_add__446__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16871856848338628344ull);
    vlSelf->__Vfunc_fp32_add__446__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14906144235570366269ull);
    __Vfunc_fp32_add__446__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__447__bits 
                            = __Vfunc_fp32_add__446__lhs;
                        __Vfunc_fp32_is_nan__447__unused_sign = 0;
                        __Vfunc_fp32_is_nan__447__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__447__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__447__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__447__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__447__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__447__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__448__bits 
                            = __Vfunc_fp32_add__446__rhs;
                        __Vfunc_fp32_is_nan__448__unused_sign = 0;
                        __Vfunc_fp32_is_nan__448__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__448__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__448__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__448__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__448__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__448__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__449__bits 
                            = __Vfunc_fp32_add__446__lhs;
                        __Vfunc_fp32_is_inf__449__unused_sign = 0;
                        __Vfunc_fp32_is_inf__449__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__449__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__449__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__449__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__449__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__450__bits 
                            = __Vfunc_fp32_add__446__rhs;
                        __Vfunc_fp32_is_inf__450__unused_sign = 0;
                        __Vfunc_fp32_is_inf__450__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__450__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__450__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__450__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__450__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__451__bits 
                                    = __Vfunc_fp32_add__446__lhs;
                                __Vfunc_fp32_is_inf__451__unused_sign = 0;
                                __Vfunc_fp32_is_inf__451__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__451__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__451__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__451__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__451__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__452__bits 
                                    = __Vfunc_fp32_add__446__rhs;
                                __Vfunc_fp32_is_inf__452__unused_sign = 0;
                                __Vfunc_fp32_is_inf__452__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__452__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__452__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__452__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__452__Vfuncout))) 
                 & ((__Vfunc_fp32_add__446__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__446__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 0x7fc00000U;
                goto __Vlabel3;
            }
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__453__bits 
                            = __Vfunc_fp32_add__446__lhs;
                        __Vfunc_fp32_is_inf__453__unused_sign = 0;
                        __Vfunc_fp32_is_inf__453__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__453__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__453__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__453__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__453__Vfuncout))
                    ? __Vfunc_fp32_add__446__lhs : __Vfunc_fp32_add__446__rhs);
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__454__bits 
                        = __Vfunc_fp32_add__446__lhs;
                    __Vfunc_fp32_is_zero__454__unused_sign = 0;
                    __Vfunc_fp32_is_zero__454__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__454__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__454__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__454__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__454__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = __Vfunc_fp32_add__446__rhs;
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__455__bits 
                        = __Vfunc_fp32_add__446__rhs;
                    __Vfunc_fp32_is_zero__455__unused_sign = 0;
                    __Vfunc_fp32_is_zero__455__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__455__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__455__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__455__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__455__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = __Vfunc_fp32_add__446__lhs;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__446__lhs_sign = 
            (__Vfunc_fp32_add__446__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__446__rhs_sign = 
            (__Vfunc_fp32_add__446__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__446__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__446__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__446__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__446__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__446__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__446__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__446__lhs)));
        vlSelfRef.__Vfunc_fp32_add__446__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__446__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__446__rhs)));
        vlSelfRef.__Vfunc_fp32_add__446__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__446__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__446__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__446__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__446__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__446__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__446__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__446__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__446__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__446__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__446__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__446__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__446__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__446__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__small_ext, vlSelfRef.__Vfunc_fp32_add__446__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__446__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__446__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__446__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__446__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__446__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__446__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__446__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__446__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__446__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__446__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__446__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__446__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__446__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__446__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__446__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__446__work_ext);
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__446__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__446__sticky))));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__446__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__446__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__446__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 0U;
                goto __Vlabel3;
            }
            __Vfunc_fp32_add__446__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__446__normalize_count = 1U;
            __Vfunc_fp32_add__446__normalize_count = 2U;
            __Vfunc_fp32_add__446__normalize_count = 3U;
            __Vfunc_fp32_add__446__normalize_count = 4U;
            __Vfunc_fp32_add__446__normalize_count = 5U;
            __Vfunc_fp32_add__446__normalize_count = 6U;
            __Vfunc_fp32_add__446__normalize_count = 7U;
            __Vfunc_fp32_add__446__normalize_count = 8U;
            __Vfunc_fp32_add__446__normalize_count = 9U;
            __Vfunc_fp32_add__446__normalize_count = 0xaU;
            __Vfunc_fp32_add__446__normalize_count = 0xbU;
            __Vfunc_fp32_add__446__normalize_count = 0xcU;
            __Vfunc_fp32_add__446__normalize_count = 0xdU;
            __Vfunc_fp32_add__446__normalize_count = 0xeU;
            __Vfunc_fp32_add__446__normalize_count = 0xfU;
            __Vfunc_fp32_add__446__normalize_count = 0x10U;
            __Vfunc_fp32_add__446__normalize_count = 0x11U;
            __Vfunc_fp32_add__446__normalize_count = 0x12U;
            __Vfunc_fp32_add__446__normalize_count = 0x13U;
            __Vfunc_fp32_add__446__normalize_count = 0x14U;
            __Vfunc_fp32_add__446__normalize_count = 0x15U;
            __Vfunc_fp32_add__446__normalize_count = 0x16U;
            __Vfunc_fp32_add__446__normalize_count = 0x17U;
            __Vfunc_fp32_add__446__normalize_count = 0x18U;
            __Vfunc_fp32_add__446__normalize_count = 0x19U;
            __Vfunc_fp32_add__446__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__446__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__446__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__446__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__446__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__446__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__446__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__446__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__446__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__446__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__446__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__446__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__446__mantissa));
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__446__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__446__mantissa)));
        __Vlabel3: ;
    }
    tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon 
        = vlSelfRef.__Vfunc_fp32_add__446__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_fp;
    if (((0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x25U]) 
         | (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x26U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__341__rhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x25U];
                    vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__342__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__341__lhs;
                                            __Vfunc_fp32_is_nan__342__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__342__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__342__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__342__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__342__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__342__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__342__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__343__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__341__rhs;
                                            __Vfunc_fp32_is_nan__343__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__343__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__343__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__343__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__343__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__343__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__343__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__344__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__341__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__344__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__341__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__345__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__lhs;
                                                            __Vfunc_fp32_is_nan__345__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__345__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__345__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__345__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__345__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__345__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__345__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__346__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__rhs;
                                                            __Vfunc_fp32_is_nan__346__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__346__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__346__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__346__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__346__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__346__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__346__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout = 0U;
                                                goto __Vlabel5;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__347__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__lhs;
                                                            __Vfunc_fp32_is_zero__347__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__347__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__347__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__347__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__347__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__347__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__348__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__rhs;
                                                            __Vfunc_fp32_is_zero__348__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__348__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__348__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__348__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__348__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__348__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout = 1U;
                                                goto __Vlabel5;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__344__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__344__rhs);
                                            __Vlabel5: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout = 0U;
                            goto __Vlabel4;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__341__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                                   >> 0x1fU);
                            goto __Vlabel4;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__rhs));
                            goto __Vlabel4;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__rhs));
                        __Vlabel4: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout))) {
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp 
                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x25U];
        } else if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__349__rhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
                    vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x26U];
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__350__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__349__lhs;
                                            __Vfunc_fp32_is_nan__350__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__350__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__350__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__350__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__350__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__350__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__350__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__351__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__349__rhs;
                                            __Vfunc_fp32_is_nan__351__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__351__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__351__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__351__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__351__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__351__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__351__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__352__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__349__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__352__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__349__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__353__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__lhs;
                                                            __Vfunc_fp32_is_nan__353__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__353__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__353__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__353__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__353__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__353__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__353__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__354__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__rhs;
                                                            __Vfunc_fp32_is_nan__354__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__354__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__354__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__354__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__354__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__354__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__354__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout = 0U;
                                                goto __Vlabel7;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__355__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__lhs;
                                                            __Vfunc_fp32_is_zero__355__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__355__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__355__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__355__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__355__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__355__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__356__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__rhs;
                                                            __Vfunc_fp32_is_zero__356__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__356__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__356__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__356__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__356__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__356__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout = 1U;
                                                goto __Vlabel7;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__352__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__352__rhs);
                                            __Vlabel7: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout = 0U;
                            goto __Vlabel6;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__349__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                                   >> 0x1fU);
                            goto __Vlabel6;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__rhs));
                            goto __Vlabel6;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__rhs));
                        __Vlabel6: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout))) {
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp 
                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x26U];
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation = 0U;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand0 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand1 = 0U;
    if ((0x80U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))) {
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation 
            = (0xfU & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x13U]);
    } else if (((0x81U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                & ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q)) 
                   | (3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))))) {
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation = 4U;
        vlSelfRef.__Vfunc_fp32_sub__357__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_max_q;
        vlSelfRef.__Vfunc_fp32_sub__357__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
        vlSelfRef.__Vfunc_fp32_neg__359__value = vlSelfRef.__Vfunc_fp32_sub__357__rhs;
        vlSelfRef.__Vfunc_fp32_neg__359__Vfuncout = 
            (((~ (vlSelfRef.__Vfunc_fp32_neg__359__value 
                  >> 0x1fU)) << 0x1fU) | (0x7fffffffU 
                                          & vlSelfRef.__Vfunc_fp32_neg__359__value));
        vlSelfRef.__Vfunc_fp32_add__358__rhs = vlSelfRef.__Vfunc_fp32_neg__359__Vfuncout;
        vlSelfRef.__Vfunc_fp32_add__358__lhs = vlSelfRef.__Vfunc_fp32_sub__357__lhs;
        vlSelf->__Vfunc_fp32_add__358__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12357816617576699716ull);
        vlSelf->__Vfunc_fp32_add__358__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2187474271696273207ull);
        vlSelf->__Vfunc_fp32_add__358__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4616157096033996866ull);
        vlSelf->__Vfunc_fp32_add__358__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7672925474375130569ull);
        vlSelf->__Vfunc_fp32_add__358__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15567874151846056033ull);
        vlSelf->__Vfunc_fp32_add__358__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4809447690133794810ull);
        vlSelf->__Vfunc_fp32_add__358__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4629559466962478022ull);
        vlSelf->__Vfunc_fp32_add__358__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7747429333882706735ull);
        vlSelf->__Vfunc_fp32_add__358__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10476106725219153555ull);
        vlSelf->__Vfunc_fp32_add__358__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14711335289242396170ull);
        vlSelf->__Vfunc_fp32_add__358__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7496892776784653902ull);
        vlSelf->__Vfunc_fp32_add__358__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16686584434067255023ull);
        vlSelf->__Vfunc_fp32_add__358__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14041815251292564609ull);
        vlSelf->__Vfunc_fp32_add__358__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15981769937323591630ull);
        vlSelf->__Vfunc_fp32_add__358__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4862429517230824099ull);
        vlSelf->__Vfunc_fp32_add__358__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11711442985796269593ull);
        vlSelf->__Vfunc_fp32_add__358__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 2794087385592660653ull);
        vlSelf->__Vfunc_fp32_add__358__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5864616337728289586ull);
        vlSelf->__Vfunc_fp32_add__358__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13118868916467938864ull);
        vlSelf->__Vfunc_fp32_add__358__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6471430345777264352ull);
        vlSelf->__Vfunc_fp32_add__358__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9283844089444321695ull);
        vlSelf->__Vfunc_fp32_add__358__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1590877298983930133ull);
        vlSelf->__Vfunc_fp32_add__358__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10285672262123973656ull);
        vlSelf->__Vfunc_fp32_add__358__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6098172023920162203ull);
        __Vfunc_fp32_add__358__normalize_count = 0;
        {
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__360__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                            __Vfunc_fp32_is_nan__360__unused_sign = 0;
                            __Vfunc_fp32_is_nan__360__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__360__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__360__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__360__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__360__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__360__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__361__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                            __Vfunc_fp32_is_nan__361__unused_sign = 0;
                            __Vfunc_fp32_is_nan__361__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__361__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__361__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__361__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__361__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__361__Vfuncout)))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout = 0x7fc00000U;
                goto __Vlabel8;
            }
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__362__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                            __Vfunc_fp32_is_inf__362__unused_sign = 0;
                            __Vfunc_fp32_is_inf__362__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__362__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__362__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__362__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__362__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__363__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                            __Vfunc_fp32_is_inf__363__unused_sign = 0;
                            __Vfunc_fp32_is_inf__363__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__363__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__363__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__363__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__363__Vfuncout)))) {
                if (((([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__364__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                                    __Vfunc_fp32_is_inf__364__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__364__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__364__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__364__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__364__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__364__Vfuncout)) 
                      & ([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__365__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                                    __Vfunc_fp32_is_inf__365__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__365__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__365__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__365__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__365__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__365__Vfuncout))) 
                     & ((vlSelfRef.__Vfunc_fp32_add__358__lhs 
                         >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_add__358__rhs 
                                       >> 0x1fU)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__Vfuncout = 0x7fc00000U;
                    goto __Vlabel8;
                }
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__366__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                            __Vfunc_fp32_is_inf__366__unused_sign = 0;
                            __Vfunc_fp32_is_inf__366__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__366__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__366__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__366__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__366__Vfuncout))
                        ? vlSelfRef.__Vfunc_fp32_add__358__lhs
                        : vlSelfRef.__Vfunc_fp32_add__358__rhs);
                goto __Vlabel8;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__367__bits 
                            = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                        __Vfunc_fp32_is_zero__367__unused_sign = 0;
                        __Vfunc_fp32_is_zero__367__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__367__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__367__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__367__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__367__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                goto __Vlabel8;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__368__bits 
                            = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                        __Vfunc_fp32_is_zero__368__unused_sign = 0;
                        __Vfunc_fp32_is_zero__368__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__368__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__368__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__368__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__368__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                goto __Vlabel8;
            }
            vlSelfRef.__Vfunc_fp32_add__358__lhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__358__lhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__358__rhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__358__rhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__358__lhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__358__lhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__358__rhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__358__rhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__358__lhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__lhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__lhs)));
            vlSelfRef.__Vfunc_fp32_add__358__rhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__rhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__rhs)));
            vlSelfRef.__Vfunc_fp32_add__358__lhs_larger 
                = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                      ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp)) 
                    > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))) 
                   | (((IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp) 
                       == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp)) 
                      & (vlSelfRef.__Vfunc_fp32_add__358__lhs_mant 
                         >= vlSelfRef.__Vfunc_fp32_add__358__rhs_mant)));
            if (vlSelfRef.__Vfunc_fp32_add__358__lhs_larger) {
                vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_sign;
                vlSelfRef.__Vfunc_fp32_add__358__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_sign;
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_sign;
                vlSelfRef.__Vfunc_fp32_add__358__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_sign;
            }
            vlSelfRef.__Vfunc_fp32_add__358__large_ext 
                = (vlSelfRef.__Vfunc_fp32_add__358__large_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__358__small_ext 
                = (vlSelfRef.__Vfunc_fp32_add__358__small_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__358__shift_amount 
                = ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                   - (IData)(vlSelfRef.__Vfunc_fp32_add__358__small_exp));
            if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__358__shift_amount)) {
                vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__358__small_ext)
                        ? 0U : 1U);
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__small_ext, vlSelfRef.__Vfunc_fp32_add__358__shift_amount));
                vlSelfRef.__Vfunc_fp32_add__358__discarded_mask 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__358__shift_amount)
                        ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__358__shift_amount) 
                                              - (IData)(1U))));
                vlSelfRef.__Vfunc_fp32_add__358__sticky 
                    = (0U != (vlSelfRef.__Vfunc_fp32_add__358__small_ext 
                              & vlSelfRef.__Vfunc_fp32_add__358__discarded_mask));
                vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__358__aligned_small) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__358__sticky))));
            }
            vlSelfRef.__Vfunc_fp32_add__358__result_sign 
                = vlSelfRef.__Vfunc_fp32_add__358__large_sign;
            if (((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_sign) 
                 == (IData)(vlSelfRef.__Vfunc_fp32_add__358__small_sign))) {
                vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__358__large_ext 
                                     + vlSelfRef.__Vfunc_fp32_add__358__aligned_small));
                if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__358__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__358__sticky 
                        = (1U & vlSelfRef.__Vfunc_fp32_add__358__work_ext);
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__358__work_ext) 
                           | (1U & (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                                    | (IData)(vlSelfRef.__Vfunc_fp32_add__358__sticky))));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)));
                }
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__358__large_ext 
                                     - vlSelfRef.__Vfunc_fp32_add__358__aligned_small));
                if ((0U == vlSelfRef.__Vfunc_fp32_add__358__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__358__Vfuncout = 0U;
                    goto __Vlabel8;
                }
                __Vfunc_fp32_add__358__normalize_count = 0U;
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                __Vfunc_fp32_add__358__normalize_count = 1U;
                __Vfunc_fp32_add__358__normalize_count = 2U;
                __Vfunc_fp32_add__358__normalize_count = 3U;
                __Vfunc_fp32_add__358__normalize_count = 4U;
                __Vfunc_fp32_add__358__normalize_count = 5U;
                __Vfunc_fp32_add__358__normalize_count = 6U;
                __Vfunc_fp32_add__358__normalize_count = 7U;
                __Vfunc_fp32_add__358__normalize_count = 8U;
                __Vfunc_fp32_add__358__normalize_count = 9U;
                __Vfunc_fp32_add__358__normalize_count = 0xaU;
                __Vfunc_fp32_add__358__normalize_count = 0xbU;
                __Vfunc_fp32_add__358__normalize_count = 0xcU;
                __Vfunc_fp32_add__358__normalize_count = 0xdU;
                __Vfunc_fp32_add__358__normalize_count = 0xeU;
                __Vfunc_fp32_add__358__normalize_count = 0xfU;
                __Vfunc_fp32_add__358__normalize_count = 0x10U;
                __Vfunc_fp32_add__358__normalize_count = 0x11U;
                __Vfunc_fp32_add__358__normalize_count = 0x12U;
                __Vfunc_fp32_add__358__normalize_count = 0x13U;
                __Vfunc_fp32_add__358__normalize_count = 0x14U;
                __Vfunc_fp32_add__358__normalize_count = 0x15U;
                __Vfunc_fp32_add__358__normalize_count = 0x16U;
                __Vfunc_fp32_add__358__normalize_count = 0x17U;
                __Vfunc_fp32_add__358__normalize_count = 0x18U;
                __Vfunc_fp32_add__358__normalize_count = 0x19U;
                __Vfunc_fp32_add__358__normalize_count = 0x1aU;
            }
            vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                                >> 3U));
            vlSelfRef.__Vfunc_fp32_add__358__increment 
                = (1U & ((vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                          >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                                      >> 1U) | vlSelfRef.__Vfunc_fp32_add__358__work_ext) 
                                    | vlSelfRef.__Vfunc_fp32_add__358__mantissa)));
            vlSelfRef.__Vfunc_fp32_add__358__rounded 
                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                                 + (IData)(vlSelfRef.__Vfunc_fp32_add__358__increment)));
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__358__rounded)) {
                vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                    = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__358__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)));
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                    = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__358__rounded);
            }
            if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__358__result_sign) 
                                      << 0x1fU));
                goto __Vlabel8;
            }
            if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)) 
                 & (~ (vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                       >> 0x17U)))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = (((IData)(vlSelfRef.__Vfunc_fp32_add__358__result_sign) 
                        << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__mantissa));
                goto __Vlabel8;
            }
            vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__358__result_sign) 
                    << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                                 << 0x17U)) 
                                 | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__mantissa)));
            __Vlabel8: ;
        }
        vlSelfRef.__Vfunc_fp32_sub__357__Vfuncout = vlSelfRef.__Vfunc_fp32_add__358__Vfuncout;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand0 
            = vlSelfRef.__Vfunc_fp32_sub__357__Vfuncout;
    } else if ((((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                 & (4U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) 
                & (0xfU == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation = 5U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand0 
            = tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon;
    }
    __Vfunc_fp32_add__370__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    __Vfunc_fp32_add__370__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q;
    vlSelf->__Vfunc_fp32_add__370__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15213926388715331619ull);
    vlSelf->__Vfunc_fp32_add__370__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3258411075118387734ull);
    vlSelf->__Vfunc_fp32_add__370__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14003246457556343670ull);
    vlSelf->__Vfunc_fp32_add__370__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6147051951079717057ull);
    vlSelf->__Vfunc_fp32_add__370__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15974968843297371169ull);
    vlSelf->__Vfunc_fp32_add__370__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 10145752427607283957ull);
    vlSelf->__Vfunc_fp32_add__370__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4626923053648079414ull);
    vlSelf->__Vfunc_fp32_add__370__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12811625543509382466ull);
    vlSelf->__Vfunc_fp32_add__370__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3565999384018226675ull);
    vlSelf->__Vfunc_fp32_add__370__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7633493998731312708ull);
    vlSelf->__Vfunc_fp32_add__370__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 672673366685093983ull);
    vlSelf->__Vfunc_fp32_add__370__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12001657451231805156ull);
    vlSelf->__Vfunc_fp32_add__370__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 750009648555705730ull);
    vlSelf->__Vfunc_fp32_add__370__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 676426075047787248ull);
    vlSelf->__Vfunc_fp32_add__370__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4279987332065587923ull);
    vlSelf->__Vfunc_fp32_add__370__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8580117586318726884ull);
    vlSelf->__Vfunc_fp32_add__370__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 2752659866841023791ull);
    vlSelf->__Vfunc_fp32_add__370__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10635576355835676249ull);
    vlSelf->__Vfunc_fp32_add__370__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 18123799807665656154ull);
    vlSelf->__Vfunc_fp32_add__370__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 8796194152577538886ull);
    vlSelf->__Vfunc_fp32_add__370__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6161775843116432723ull);
    vlSelf->__Vfunc_fp32_add__370__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17936629515587624680ull);
    vlSelf->__Vfunc_fp32_add__370__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7970739767535070142ull);
    vlSelf->__Vfunc_fp32_add__370__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10464496639897320079ull);
    __Vfunc_fp32_add__370__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__371__bits 
                            = __Vfunc_fp32_add__370__lhs;
                        __Vfunc_fp32_is_nan__371__unused_sign = 0;
                        __Vfunc_fp32_is_nan__371__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__371__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__371__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__371__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__371__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__371__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__372__bits 
                            = __Vfunc_fp32_add__370__rhs;
                        __Vfunc_fp32_is_nan__372__unused_sign = 0;
                        __Vfunc_fp32_is_nan__372__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__372__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__372__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__372__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__372__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__372__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 0x7fc00000U;
            goto __Vlabel9;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__373__bits 
                            = __Vfunc_fp32_add__370__lhs;
                        __Vfunc_fp32_is_inf__373__unused_sign = 0;
                        __Vfunc_fp32_is_inf__373__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__373__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__373__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__373__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__373__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__374__bits 
                            = __Vfunc_fp32_add__370__rhs;
                        __Vfunc_fp32_is_inf__374__unused_sign = 0;
                        __Vfunc_fp32_is_inf__374__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__374__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__374__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__374__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__374__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__375__bits 
                                    = __Vfunc_fp32_add__370__lhs;
                                __Vfunc_fp32_is_inf__375__unused_sign = 0;
                                __Vfunc_fp32_is_inf__375__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__375__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__375__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__375__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__375__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__376__bits 
                                    = __Vfunc_fp32_add__370__rhs;
                                __Vfunc_fp32_is_inf__376__unused_sign = 0;
                                __Vfunc_fp32_is_inf__376__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__376__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__376__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__376__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__376__Vfuncout))) 
                 & ((__Vfunc_fp32_add__370__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__370__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 0x7fc00000U;
                goto __Vlabel9;
            }
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__377__bits 
                            = __Vfunc_fp32_add__370__lhs;
                        __Vfunc_fp32_is_inf__377__unused_sign = 0;
                        __Vfunc_fp32_is_inf__377__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__377__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__377__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__377__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__377__Vfuncout))
                    ? __Vfunc_fp32_add__370__lhs : __Vfunc_fp32_add__370__rhs);
            goto __Vlabel9;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__378__bits 
                        = __Vfunc_fp32_add__370__lhs;
                    __Vfunc_fp32_is_zero__378__unused_sign = 0;
                    __Vfunc_fp32_is_zero__378__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__378__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__378__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__378__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__378__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = __Vfunc_fp32_add__370__rhs;
            goto __Vlabel9;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__379__bits 
                        = __Vfunc_fp32_add__370__rhs;
                    __Vfunc_fp32_is_zero__379__unused_sign = 0;
                    __Vfunc_fp32_is_zero__379__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__379__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__379__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__379__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__379__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = __Vfunc_fp32_add__370__lhs;
            goto __Vlabel9;
        }
        vlSelfRef.__Vfunc_fp32_add__370__lhs_sign = 
            (__Vfunc_fp32_add__370__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__370__rhs_sign = 
            (__Vfunc_fp32_add__370__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__370__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__370__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__370__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__370__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__370__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__370__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__370__lhs)));
        vlSelfRef.__Vfunc_fp32_add__370__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__370__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__370__rhs)));
        vlSelfRef.__Vfunc_fp32_add__370__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__370__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__370__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__370__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__370__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__370__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__370__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__370__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__370__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__370__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__370__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__370__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__370__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__370__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__small_ext, vlSelfRef.__Vfunc_fp32_add__370__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__370__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__370__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__370__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__370__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__370__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__370__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__370__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__370__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__370__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__370__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__370__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__370__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__370__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__370__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__370__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__370__work_ext);
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__370__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__370__sticky))));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__370__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__370__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__370__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 0U;
                goto __Vlabel9;
            }
            __Vfunc_fp32_add__370__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__370__normalize_count = 1U;
            __Vfunc_fp32_add__370__normalize_count = 2U;
            __Vfunc_fp32_add__370__normalize_count = 3U;
            __Vfunc_fp32_add__370__normalize_count = 4U;
            __Vfunc_fp32_add__370__normalize_count = 5U;
            __Vfunc_fp32_add__370__normalize_count = 6U;
            __Vfunc_fp32_add__370__normalize_count = 7U;
            __Vfunc_fp32_add__370__normalize_count = 8U;
            __Vfunc_fp32_add__370__normalize_count = 9U;
            __Vfunc_fp32_add__370__normalize_count = 0xaU;
            __Vfunc_fp32_add__370__normalize_count = 0xbU;
            __Vfunc_fp32_add__370__normalize_count = 0xcU;
            __Vfunc_fp32_add__370__normalize_count = 0xdU;
            __Vfunc_fp32_add__370__normalize_count = 0xeU;
            __Vfunc_fp32_add__370__normalize_count = 0xfU;
            __Vfunc_fp32_add__370__normalize_count = 0x10U;
            __Vfunc_fp32_add__370__normalize_count = 0x11U;
            __Vfunc_fp32_add__370__normalize_count = 0x12U;
            __Vfunc_fp32_add__370__normalize_count = 0x13U;
            __Vfunc_fp32_add__370__normalize_count = 0x14U;
            __Vfunc_fp32_add__370__normalize_count = 0x15U;
            __Vfunc_fp32_add__370__normalize_count = 0x16U;
            __Vfunc_fp32_add__370__normalize_count = 0x17U;
            __Vfunc_fp32_add__370__normalize_count = 0x18U;
            __Vfunc_fp32_add__370__normalize_count = 0x19U;
            __Vfunc_fp32_add__370__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__370__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__370__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__370__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__370__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__370__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__370__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__370__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__370__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__370__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__370__result_sign) 
                                  << 0x1fU));
            goto __Vlabel9;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__370__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__370__mantissa));
            goto __Vlabel9;
        }
        vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__370__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__370__mantissa)));
        __Vlabel9: ;
    }
}
