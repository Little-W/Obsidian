// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__2(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__2\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 0U;
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [0U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [1U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [2U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [3U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [4U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [4U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [5U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [5U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 5U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 0U;
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [0U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [1U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [2U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [3U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [4U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [4U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [5U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [5U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 5U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [6U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [6U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [6U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [6U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [6U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [6U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 6U;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [6U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [6U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 6U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 0U;
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [0U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [0U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [1U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [1U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [2U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [2U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [3U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [3U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [4U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [4U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [5U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [5U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 5U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [6U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [6U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [6U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [6U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [6U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [6U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 6U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [7U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [7U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [7U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [7U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [7U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [7U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 7U;
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [7U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [7U])) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [7U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = 7U;
                        }
                    }
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [7U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 7U;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [7U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [7U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = 7U;
                        }
                    }
                }
            }
        }
    }
}

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___eval_triggers__stl(Vtb_inline_scheduler_smoke___024root* vlSelf);
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___eval_stl(Vtb_inline_scheduler_smoke___024root* vlSelf);

VL_ATTR_COLD bool Vtb_inline_scheduler_smoke___024root___eval_phase__stl(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_phase__stl\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_inline_scheduler_smoke___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_inline_scheduler_smoke___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___dump_triggers__act(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___dump_triggers__act\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_inline_scheduler_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_inline_scheduler_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge tb_inline_scheduler_smoke.clk)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @( (3'h2 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])))\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @( ((3'h0 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])) & (4'h1 == (tb_inline_scheduler_smoke.dut.event_generation_q[8'h7]))))\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @( (((((~ tb_inline_scheduler_smoke.dut.dma_active_q) & tb_inline_scheduler_smoke.dut.dma_select_found) & ((~ tb_inline_scheduler_smoke.dut.matrix_active_q) & tb_inline_scheduler_smoke.dut.matrix_select_found)) & ((~ tb_inline_scheduler_smoke.dut.vector_active_q) & tb_inline_scheduler_smoke.dut.vector_select_found)) & ((~ tb_inline_scheduler_smoke.dut.complex_active_q) & tb_inline_scheduler_smoke.dut.complex_select_found)))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___dump_triggers__nba(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___dump_triggers__nba\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_inline_scheduler_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_inline_scheduler_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge tb_inline_scheduler_smoke.clk)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @( (3'h2 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])))\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @( ((3'h0 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])) & (4'h1 == (tb_inline_scheduler_smoke.dut.event_generation_q[8'h7]))))\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @( (((((~ tb_inline_scheduler_smoke.dut.dma_active_q) & tb_inline_scheduler_smoke.dut.dma_select_found) & ((~ tb_inline_scheduler_smoke.dut.matrix_active_q) & tb_inline_scheduler_smoke.dut.matrix_select_found)) & ((~ tb_inline_scheduler_smoke.dut.vector_active_q) & tb_inline_scheduler_smoke.dut.vector_select_found)) & ((~ tb_inline_scheduler_smoke.dut.complex_active_q) & tb_inline_scheduler_smoke.dut.complex_select_found)))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___ctor_var_reset(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___ctor_var_reset\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_inline_scheduler_smoke__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16151220919115400863ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6889954166970762426ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11390593901064694845ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_inline_scheduler_smoke__DOT__cfe_cmd, __VscopeHash, 7502013429588796731ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__df_fetch_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6115237121365062680ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__lookup_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17351832908228504198ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__task_query_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7158869049016392520ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__task_occupancy = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9254798520975956338ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_inline_scheduler_smoke__DOT__decode_cmd, __VscopeHash, 7166066516989258734ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dfu_request_count = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4328646819373297773ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_addr_q[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10511741548441930336ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 11025685150911211148ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15547053116732414377ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5285285837170956924ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16225564514311286611ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16945521753920963270ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10896109321645861770ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_signal_q[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 9152027601430335088ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5582162239703765946ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(2048, vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q[__Vi0], __VscopeHash, 15511282775900550003ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16719411553702466532ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_fault_addr_q[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15867859946918841514ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_progress_q[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12861021327184617399ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_error_info_q[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1822734251440100477ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_done_flags_q[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16751081991644228903ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14364701480963580879ull);
    }
    for (int __Vi0 = 0; __Vi0 < 255; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16771882017699761617ull);
    }
    for (int __Vi0 = 0; __Vi0 < 255; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11980026963845981543ull);
    }
    for (int __Vi0 = 0; __Vi0 < 255; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__event_producer_q[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 11201212945426843388ull);
    }
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__submit_seq_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7377313876722716799ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9029483690502645753ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__dma_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11307352895543076463ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2393935586366326310ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__vector_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1713516980200539866ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__complex_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1341230484215745857ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11853684551910896082ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_op_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14512685027105458927ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8077960250262004229ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg1_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6047056854771912682ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_count_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11686156650512540468ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_rsp_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9044815573764698398ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_rsp_data_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4429024376790924905ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_ack_release_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11100489689336274060ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_ack_slot_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1183854622431745804ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2210906197423811166ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10443839572192381917ull);
    }
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_status_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12115363772324439786ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_failure_seq_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1758784184563959758ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2063983379714766273ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16688645512021309181ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__lookup_busy_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3343428062124506112ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11401556847146844915ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9356626374072323680ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17245810784564892536ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14527173978277135171ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13945342022737849801ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1741588793612066869ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6252991249759001238ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7661086793821140560ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7539593870470308186ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3465906001914719823ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5922817170469183968ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12565100126003465997ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5419961550628296097ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6700270709577214099ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14191146576860374769ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4378858222891983583ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6122265055195434565ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11782251592744985234ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17338626077258536558ull);
    }
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_static_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7107593069949550177ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8949408703308950669ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_terminal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7434925416653516564ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9009842875163573961ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_producer = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4724390776192731450ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14419138742880179128ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10561294156390287015ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12425053369957385353ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_command_id = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16600545390741464478ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_engine = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12723447085009880096ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_opcode = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4253013419812426721ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_header_flags = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17060150237638960036ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 933656596205756826ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 13091257266113828456ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17998643740414877523ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0_resolved = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 7557416553072113405ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1_resolved = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10207532391517449092ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16627172236723979717ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_is_inline_rearm = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9929860929424377728ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved, __VscopeHash, 3917079818865598089ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT__unnamedblk13__DOT__event_idx = 0;
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h0a2df4ca__0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4855930971950106959ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h496575a3__0 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17949620689194956581ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h2233453d__0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13378608885996930496ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h2fa16ab9__0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16597582516072546697ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_ha16e251e__0 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 3978732047938048406ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h046bb140__0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18168135051556154507ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h046bb140__1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5229520543078568910ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_ha0a524a9__0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13986916531119645164ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_haf1f49ed__0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15194129741140079552ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h1fd80602__0 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8108050305396679865ull);
    vlSelf->tb_inline_scheduler_smoke__DOT__dut__DOT____VdfgExtracted_hf6182e41__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10550146016742020538ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout, __VscopeHash, 13178945328415201509ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2775759770346344153ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 80021656243299537ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6111345849601553555ull);
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload, __VscopeHash, 4179910773541211014ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout, __VscopeHash, 3587007572457095150ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13876569180989886546ull);
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelf->__Vfunc_npu_v2_engine__2__Vfuncout = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10582945318498118461ull);
    vlSelf->__Vfunc_npu_v2_engine__2__compact_opcode = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1485376101604086268ull);
    vlSelf->__Vfunc_npu_v2_opcode__3__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9730276003952936908ull);
    vlSelf->__Vfunc_npu_v2_opcode__3__compact_opcode = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6725671963885860241ull);
    vlSelf->__Vfunc_npu_v2_engine__4__Vfuncout = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11974654436470847400ull);
    vlSelf->__Vfunc_npu_v2_engine__4__compact_opcode = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1977944431614424097ull);
    vlSelf->__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9740439860165835518ull);
    vlSelf->__Vfunc_npu_desc_bytes_for_engine__5__engine = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13595570962792155367ull);
    vlSelf->__Vfunc_npu_v2_engine__6__Vfuncout = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15468449924591084742ull);
    vlSelf->__Vfunc_npu_v2_engine__6__compact_opcode = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8219337308609140344ull);
    vlSelf->__Vfunc_npu_cmd_header_flags__30__Vfuncout = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16086442446522661265ull);
    vlSelf->__Vfunc_npu_cmd_header_flags__30__flags = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17311288755175545044ull);
    vlSelf->__Vfunc_npu_v2_event_ref__32__Vfuncout = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 18063285545812308736ull);
    vlSelf->__Vfunc_npu_v2_event_ref__32__event_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16525147085851532701ull);
    vlSelf->__Vfunc_npu_v2_event_ref__34__Vfuncout = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4476477526052092733ull);
    vlSelf->__Vfunc_npu_v2_event_ref__34__event_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7128178753539002679ull);
    vlSelf->__Vfunc_npu_v2_event_ref__36__Vfuncout = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 18131092862681330260ull);
    vlSelf->__Vfunc_npu_v2_event_ref__36__event_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17564693064238656177ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4239201079578917682ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2155591488964673162ull);
    vlSelf->__Vfunc_npu_opcode_engine_valid__40__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9826164904663633195ull);
    vlSelf->__Vfunc_npu_opcode_engine_valid__40__engine = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3016847284451514068ull);
    vlSelf->__Vfunc_npu_opcode_engine_valid__40__opcode = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10582134435668432630ull);
    vlSelf->__Vfunc_npu_event_ref_valid__41__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 479599723293847369ull);
    vlSelf->__Vfunc_npu_event_ref_valid__41__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17123681086992388401ull);
    vlSelf->__Vfunc_npu_event_ref_valid__42__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13971193188376688083ull);
    vlSelf->__Vfunc_npu_event_ref_valid__42__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 13065038789560265490ull);
    vlSelf->__Vfunc_npu_event_ref_valid__43__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1860376293674745982ull);
    vlSelf->__Vfunc_npu_event_ref_valid__43__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 6494999068011174375ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10670463233970791803ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17024735279066761895ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13717153233254792040ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17076750134085904154ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5844190277059659536ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14992729129547223485ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4711675155290016985ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12777377123798325577ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10510552607716246794ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16988694360058684342ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9969882970389490226ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 5512498902160342065ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9025044914850286861ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 7337006791411468547ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1181819982208517663ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 7727980086582330387ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6902710865131631362ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10176596798578294393ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10946626425275533217ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6702021376436374257ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 549049849915583279ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16799243016388346682ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3244978381644495261ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13524722603865378701ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__Vfuncout = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18046071538087047140ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11236830685550085119ull);
    vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10794466795540053355ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_inline_scheduler_smoke__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7668097848585275914ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_inline_scheduler_smoke__DOT__reset_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10986546738934538866ull);
    vlSelf->__Vtrigprevexpr_ha64895be__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12357279094828833405ull);
    vlSelf->__Vtrigprevexpr_h5500e8de__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2938101698645455671ull);
    vlSelf->__Vtrigprevexpr_h0d5889ad__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17398705869415997322ull);
    vlSelf->__VactDidInit = 0;
}
