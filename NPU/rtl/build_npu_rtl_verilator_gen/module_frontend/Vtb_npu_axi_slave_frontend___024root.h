// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_npu_axi_slave_frontend.h for the primary calling header

#ifndef VERILATED_VTB_NPU_AXI_SLAVE_FRONTEND___024ROOT_H_
#define VERILATED_VTB_NPU_AXI_SLAVE_FRONTEND___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_npu_axi_slave_frontend__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_npu_axi_slave_frontend___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__clk_i;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__reset_n;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awid;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awlen;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awsize;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awburst;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awlock;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awvalid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awready;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_wstrb;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_wlast;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_wvalid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_wready;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_bresp;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_bvalid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_bready;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_arid;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_arlen;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_arsize;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_arburst;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_arlock;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_arvalid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_arready;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_rid;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_rresp;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_rlast;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_rvalid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_rready;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cmd_valid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cmd_ready;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cmd_first;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cmd_last;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__reg_req_valid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__reg_req_ready;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__reg_rsp_ready;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__l1_req_valid;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__l1_req_ready;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__l1_rsp_ready;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cfe_enable;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__cfe_have_low_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__reg_pending_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__l1_pending_q;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__reg_rsp_status_q;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__protocol_error;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__protocol_error_clear;
        CData/*3:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
        CData/*3:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q;
        CData/*4:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_wptr_q;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_rptr_q;
        CData/*3:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q;
        CData/*2:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q;
    };
    struct {
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_cmd_format_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_csr_format_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_l1_format_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_csr_format_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_l1_format_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w;
        CData/*7:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_inflight_q;
        CData/*1:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q;
        CData/*0:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0;
        CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__Vfuncout;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__size;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__addr_low;
        CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__Vfuncout;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__size;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__addr_low;
        CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__Vfuncout;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__size;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__addr_low;
        CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__Vfuncout;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__size;
        CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__addr_low;
        CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__base;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__reset_n__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ tb_npu_axi_slave_frontend__DOT__reg_req_addr;
        SData/*8:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q;
        SData/*8:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q;
        SData/*8:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q;
        SData/*8:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q;
        IData/*23:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_awaddr;
        IData/*23:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_araddr;
        IData/*19:0*/ tb_npu_axi_slave_frontend__DOT__l1_req_addr;
        IData/*31:0*/ tb_npu_axi_slave_frontend__DOT__cfe_command_count_q;
        IData/*31:0*/ tb_npu_axi_slave_frontend__DOT__byte_index;
        IData/*23:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q;
        IData/*23:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q;
        IData/*23:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q;
        IData/*31:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__value;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_wdata;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__s_axi_rdata;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__cmd_data;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__cmd_rsp_data;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__cfe_low_q;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__reg_rsp_data_q;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__l1_rsp_data_q;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__fifo_status_w;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q;
    };
    struct {
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q;
        QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q;
        VlUnpacked<QData/*63:0*/, 32> tb_npu_axi_slave_frontend__DOT__csr_mem;
        VlUnpacked<QData/*63:0*/, 256> tb_npu_axi_slave_frontend__DOT__l1_mem;
        VlUnpacked<QData/*63:0*/, 16> tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem;
        VlUnpacked<QData/*63:0*/, 16> tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem;
        VlUnpacked<QData/*63:0*/, 8> tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h4a2ae8f4__0;
    VlTriggerScheduler __VtrigSched_h4a2ae8b1__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_npu_axi_slave_frontend__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_npu_axi_slave_frontend___024root(Vtb_npu_axi_slave_frontend__Syms* symsp, const char* v__name);
    ~Vtb_npu_axi_slave_frontend___024root();
    VL_UNCOPYABLE(Vtb_npu_axi_slave_frontend___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
