// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cmd_dfu_smoke.h for the primary calling header

#include "Vtb_cmd_dfu_smoke__pch.h"
#include "Vtb_cmd_dfu_smoke__Syms.h"
#include "Vtb_cmd_dfu_smoke___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__stl(Vtb_cmd_dfu_smoke___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___eval_triggers__stl(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_triggers__stl\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_cmd_dfu_smoke___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___stl_sequent__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___stl_sequent__TOP__0\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd;
    VL_ZERO_W(128, tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd);
    CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0;
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0 = 0;
    SData/*11:0*/ __Vfunc_npu_cmd_command_id__23__Vfuncout;
    __Vfunc_npu_cmd_command_id__23__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__23__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_command_id__23__command);
    CData/*0:0*/ __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout;
    __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode;
    __Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode = 0;
    SData/*15:0*/ __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout;
    __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_npu_desc_bytes_for_engine__34__engine;
    __Vfunc_npu_desc_bytes_for_engine__34__engine = 0;
    // Body
    if ((1U & (~ VL_ONEHOT_I((((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                               << 1U) | (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))))))) {
        if ((0U != (((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     << 1U) | (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: npu_cmd_frontend.sv:134: Assertion failed in %Ntb_cmd_dfu_smoke.u_cfe: unique case, but multiple matches found for '3'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),3,
                             (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
                VL_STOP_MT("control/npu_cmd_frontend.sv", 134, "");
            }
        }
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_rsp_valid 
        = (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now 
        = (4U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_ready = 
        (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_rsp_valid 
        = (4U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_valid = 
        ((~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q)) 
         & (3U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__input_handshake 
        = (((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
            | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) 
           & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake 
        = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready) 
           & (0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_request_handshake 
        = ((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_ready));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_response_handshake 
        = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_valid) 
           & (2U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_addr = 
        (0xffffffffffffULL & (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_addr_q 
                              + (QData)((IData)(((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q) 
                                                 << 3U)))));
    __Vfunc_npu_desc_bytes_for_engine__34__engine = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q;
    __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout 
        = ((8U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
            ? 0U : ((4U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                     ? ((2U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                         ? 0U : ((1U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                                  ? 0U : 0x100U)) : 
                    ((2U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                      ? ((1U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                          ? 0xc0U : 0x100U) : ((1U 
                                                & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                                                ? 0x100U
                                                : 0x40U))));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes 
        = __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout;
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[0U] 
        = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q);
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[1U] 
        = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q 
                   >> 0x20U));
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[2U] 
        = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q);
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[3U] 
        = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                   >> 0x20U));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__prefix_valid 
        = ((((((1U == (0xffU & vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U])) 
               & ((0xffU & (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                            >> 8U)) == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q))) 
              & ((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                  >> 0x10U) == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes))) 
             & (0x40U <= (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                          >> 0x10U))) & (0x100U >= 
                                         (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                                          >> 0x10U))) 
           & ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q))
               ? (0U == vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xeU])
               : ([&]() {
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xeU];
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__dtype_fields_valid 
                        = (((([&]() {
                                        vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype 
                                            = (3U & vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg);
                                        vlSelfRef.__Vfunc_npu_dtype_valid__36__Vfuncout 
                                            = ((((0U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype))) 
                                                | (2U 
                                                   == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype))) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype)));
                                    }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__Vfuncout)) 
                             & ([&]() {
                                        vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype 
                                            = (3U & 
                                               (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                                                >> 2U));
                                        vlSelfRef.__Vfunc_npu_dtype_valid__37__Vfuncout 
                                            = ((((0U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype))) 
                                                | (2U 
                                                   == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype))) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype)));
                                    }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__Vfuncout))) 
                            & ([&]() {
                                    vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype 
                                        = (3U & (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                                                 >> 4U));
                                    vlSelfRef.__Vfunc_npu_dtype_valid__38__Vfuncout 
                                        = ((((0U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype)) 
                                             | (1U 
                                                == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype))) 
                                            | (2U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype))) 
                                           | (3U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype)));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__Vfuncout))) 
                           & ([&]() {
                                vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype 
                                    = (3U & (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                                             >> 6U));
                                vlSelfRef.__Vfunc_npu_dtype_valid__39__Vfuncout 
                                    = ((((0U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype)) 
                                         | (1U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype))) 
                                        | (2U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype))) 
                                       | (3U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype)));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__Vfuncout)));
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__Vfuncout 
                        = ((IData)(vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__dtype_fields_valid) 
                           & (0U == (0xfffe0300U & vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg)));
                }(), (IData)(vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__Vfuncout))));
    __Vfunc_npu_cmd_command_id__23__command[0U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[0U];
    __Vfunc_npu_cmd_command_id__23__command[1U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[1U];
    __Vfunc_npu_cmd_command_id__23__command[2U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[2U];
    __Vfunc_npu_cmd_command_id__23__command[3U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[3U];
    __Vfunc_npu_cmd_command_id__23__Vfuncout = (0xfffU 
                                                & ((__Vfunc_npu_cmd_command_id__23__command[3U] 
                                                    >> 0x1fU)
                                                    ? 
                                                   (0x3ffU 
                                                    & (__Vfunc_npu_cmd_command_id__23__command[3U] 
                                                       >> 0x10U))
                                                    : 
                                                   ((__Vfunc_npu_cmd_command_id__23__command[1U] 
                                                     << 0x10U) 
                                                    | (__Vfunc_npu_cmd_command_id__23__command[1U] 
                                                       >> 0x10U))));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id 
        = __Vfunc_npu_cmd_command_id__23__Vfuncout;
    __Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode 
        = (0x1fU & (tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[3U] 
                    >> 0x1aU));
    __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout 
        = ((0x1cU != (IData)(__Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode)) 
           & (0x1eU != (IData)(__Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode)));
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0 
        = __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 0U;
    if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
         & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
            == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 1U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 2U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 3U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 4U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 5U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 6U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 7U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((1U & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                       >> 0x3fU)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__header_format_valid = 1U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__opcode_format_valid 
            = tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0;
    } else {
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode 
            = (0xffU & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q));
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__header_format_valid 
            = ((((IData)(((0ULL == (0x3fULL & vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q)) 
                          & (0x100000000000000ULL == 
                             (0xff000000000c0000ULL 
                              & vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q)))) 
                 & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__25__event_ref 
                                = (0xfffU & (IData)(
                                                    (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                                                     >> 0x14U)));
                            vlSelfRef.__Vfunc_npu_event_ref_valid__25__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__25__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__25__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__25__Vfuncout))) 
                & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__26__event_ref 
                            = (0xfffU & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                                                 >> 0x20U)));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__26__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__26__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__26__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__26__Vfuncout))) 
               & ([&]() {
                    vlSelfRef.__Vfunc_npu_event_ref_valid__27__event_ref 
                        = (0xfffU & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                                             >> 0x2cU)));
                    vlSelfRef.__Vfunc_npu_event_ref_valid__27__Vfuncout 
                        = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__27__event_ref)) 
                           | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__27__event_ref))));
                }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__27__Vfuncout)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine 
            = (0xfU & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q 
                               >> 0x3cU)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__Vfuncout 
            = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine) 
                         >> 3U))) && ((4U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                       ? ((1U & (~ 
                                                 ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine) 
                                                  >> 1U))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))) 
                                              && (((((0x80U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                     | (0x81U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (0x82U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x84U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x86U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))))
                                       : ((2U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                           ? ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                               ? ((
                                                   ((((((((0x60U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                          | (0x61U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                         | (0x62U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                        | (0x63U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                       | (0x64U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                      | (0x65U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                     | (0x66U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (0x67U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x68U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x69U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))
                                               : ((
                                                   ((0x40U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                    | (0x41U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x42U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x43U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))))
                                           : ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                               ? ((
                                                   ((((0x20U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                      | (0x21U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                     | (0x22U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (0x23U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x24U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x25U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))
                                               : ((
                                                   (((0U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                     | (1U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (2U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (4U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))))));
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__opcode_format_valid 
            = vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__Vfuncout;
    }
}
