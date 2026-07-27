`timescale 1ns/1ps

module npu_single_core_top #(
    parameter int unsigned AXI_S_ID_W   = 8,
    parameter int unsigned AXI_S_ADDR_W = 24,
    parameter int unsigned AXI_M_ID_W   = 8,
    parameter int unsigned AXI_M_ADDR_W = 40,
    parameter int unsigned L1_BYTES     = 1 << 20,
    parameter int unsigned L1_BANKS     = 16,
    parameter int unsigned TASK_SLOTS   = 16,
    parameter int unsigned EVENT_COUNT  = 255
) (
    input  logic                       core_clk_i,
    input  logic                       noc_clk_i,
    input  logic                       reset_n,

    input  logic                       dvfs_prepare_req_i,
    output logic                       dvfs_prepare_ack_o,
    input  logic                       soft_reset_req_i,
    output logic                       soft_reset_done_o,
    input  logic                       power_down_req_i,
    output logic                       power_down_ack_o,
    output logic                       accept_new_cmd_o,
    output logic                       core_idle_o,
    output logic [7:0]                 module_clk_active_o,
    output logic                       wdt_reset_req_o,
    output logic                       irq_done_o,
    output logic                       irq_exception_o,
    output logic                       irq_error_o,

    input  logic [AXI_S_ID_W-1:0]      s_axi_awid_i,
    input  logic [AXI_S_ADDR_W-1:0]    s_axi_awaddr_i,
    input  logic [7:0]                 s_axi_awlen_i,
    input  logic [2:0]                 s_axi_awsize_i,
    input  logic [1:0]                 s_axi_awburst_i,
    input  logic                       s_axi_awlock_i,
    input  logic [3:0]                 s_axi_awcache_i,
    input  logic [2:0]                 s_axi_awprot_i,
    input  logic [3:0]                 s_axi_awqos_i,
    input  logic                       s_axi_awvalid_i,
    output logic                       s_axi_awready_o,
    input  logic [63:0]                s_axi_wdata_i,
    input  logic [7:0]                 s_axi_wstrb_i,
    input  logic                       s_axi_wlast_i,
    input  logic                       s_axi_wvalid_i,
    output logic                       s_axi_wready_o,
    output logic [AXI_S_ID_W-1:0]      s_axi_bid_o,
    output logic [1:0]                 s_axi_bresp_o,
    output logic                       s_axi_bvalid_o,
    input  logic                       s_axi_bready_i,

    input  logic [AXI_S_ID_W-1:0]      s_axi_arid_i,
    input  logic [AXI_S_ADDR_W-1:0]    s_axi_araddr_i,
    input  logic [7:0]                 s_axi_arlen_i,
    input  logic [2:0]                 s_axi_arsize_i,
    input  logic [1:0]                 s_axi_arburst_i,
    input  logic                       s_axi_arlock_i,
    input  logic [3:0]                 s_axi_arcache_i,
    input  logic [2:0]                 s_axi_arprot_i,
    input  logic [3:0]                 s_axi_arqos_i,
    input  logic                       s_axi_arvalid_i,
    output logic                       s_axi_arready_o,
    output logic [AXI_S_ID_W-1:0]      s_axi_rid_o,
    output logic [63:0]                s_axi_rdata_o,
    output logic [1:0]                 s_axi_rresp_o,
    output logic                       s_axi_rlast_o,
    output logic                       s_axi_rvalid_o,
    input  logic                       s_axi_rready_i,

    output logic [AXI_M_ID_W-1:0]      m_axi_awid_o,
    output logic [AXI_M_ADDR_W-1:0]    m_axi_awaddr_o,
    output logic [7:0]                 m_axi_awlen_o,
    output logic [2:0]                 m_axi_awsize_o,
    output logic [1:0]                 m_axi_awburst_o,
    output logic                       m_axi_awlock_o,
    output logic [3:0]                 m_axi_awcache_o,
    output logic [2:0]                 m_axi_awprot_o,
    output logic [3:0]                 m_axi_awqos_o,
    output logic                       m_axi_awvalid_o,
    input  logic                       m_axi_awready_i,
    output logic [63:0]                m_axi_wdata_o,
    output logic [7:0]                 m_axi_wstrb_o,
    output logic                       m_axi_wlast_o,
    output logic                       m_axi_wvalid_o,
    input  logic                       m_axi_wready_i,
    input  logic [AXI_M_ID_W-1:0]      m_axi_bid_i,
    input  logic [1:0]                 m_axi_bresp_i,
    input  logic                       m_axi_bvalid_i,
    output logic                       m_axi_bready_o,

    output logic [AXI_M_ID_W-1:0]      m_axi_arid_o,
    output logic [AXI_M_ADDR_W-1:0]    m_axi_araddr_o,
    output logic [7:0]                 m_axi_arlen_o,
    output logic [2:0]                 m_axi_arsize_o,
    output logic [1:0]                 m_axi_arburst_o,
    output logic                       m_axi_arlock_o,
    output logic [3:0]                 m_axi_arcache_o,
    output logic [2:0]                 m_axi_arprot_o,
    output logic [3:0]                 m_axi_arqos_o,
    output logic                       m_axi_arvalid_o,
    input  logic                       m_axi_arready_i,
    input  logic [AXI_M_ID_W-1:0]      m_axi_rid_i,
    input  logic [63:0]                m_axi_rdata_i,
    input  logic [1:0]                 m_axi_rresp_i,
    input  logic                       m_axi_rlast_i,
    input  logic                       m_axi_rvalid_i,
    output logic                       m_axi_rready_o
);

    import npu_rtl_pkg::*;

    localparam int unsigned L1_CLIENTS = 6;

    logic crg_core_reset_n;
    logic crg_noc_reset_n;
    logic core_clk_gated;
    logic noc_clk_gated;
    logic internal_soft_reset_pulse;
    logic internal_soft_reset_done_q;
    logic functional_reset_n;
    logic [7:0] module_clk_enable;
    logic [7:0] module_idle;

    logic cmd_valid;
    logic cmd_ready;
    logic [63:0] cmd_data;
    logic cmd_first;
    logic cmd_last;
    logic cmd_rsp_valid;
    logic cmd_rsp_ready;
    logic [63:0] cmd_rsp_data;
    logic cmd_ingress_idle;
    logic s_axi_idle;
    logic protocol_error;
    logic interface_error_clear;

    logic reg_req_valid;
    logic reg_req_ready;
    logic reg_req_write;
    logic reg_req_space;
    logic [15:0] reg_req_addr;
    logic [63:0] reg_req_wdata;
    logic [7:0] reg_req_wstrb;
    logic reg_rsp_valid;
    logic reg_rsp_ready;
    logic [63:0] reg_rsp_rdata;
    logic [1:0] reg_rsp_status;

    logic fe_l1_req_valid;
    logic fe_l1_req_ready;
    logic fe_l1_req_write;
    logic [19:0] fe_l1_req_addr;
    logic [63:0] fe_l1_req_wdata;
    logic [7:0] fe_l1_req_wstrb;
    logic fe_l1_rsp_valid;
    logic fe_l1_rsp_ready;
    logic [63:0] fe_l1_rsp_rdata;
    logic [2:0] fe_l1_rsp_status;

    logic cfe_ts_cmd_valid;
    logic cfe_ts_cmd_ready;
    logic [127:0] cfe_ts_cmd;
    logic lookup_valid;
    logic lookup_ready;
    logic [9:0] lookup_id;
    logic lookup_rsp_valid;
    logic lookup_busy;
    logic cfe_idle;
    logic cfe_error;
    logic cmd_accepted;
    logic cfe_quiesce;
    logic ts_quiesce;

    logic dma_task_valid;
    logic dma_task_ready;
    logic [7:0] dma_task_opcode;
    logic [11:0] dma_task_command_id;
    logic [2047:0] dma_task_desc;
    logic dma_done_valid;
    logic dma_done_ready;
    logic [7:0] dma_done_status;
    logic [47:0] dma_done_fault_addr;
    logic [63:0] dma_done_progress;
    logic [11:0] dma_active_id_q;

    logic matrix_task_valid;
    logic matrix_task_ready;
    logic [7:0] matrix_task_opcode;
    logic [11:0] matrix_task_command_id;
    logic [2047:0] matrix_task_desc;
    logic matrix_done_valid;
    logic matrix_done_ready;
    logic [7:0] matrix_done_status;
    logic [47:0] matrix_done_fault_addr;
    logic [63:0] matrix_done_progress;
    logic [11:0] matrix_active_id_q;

    logic vector_task_valid;
    logic vector_task_ready;
    logic [7:0] vector_task_opcode;
    logic [11:0] vector_task_command_id;
    logic [2047:0] vector_task_desc;
    logic vector_done_valid;
    logic vector_done_ready;
    logic [7:0] vector_done_status;
    logic [47:0] vector_done_fault_addr;
    logic [63:0] vector_done_progress;
    logic [11:0] vector_active_id_q;

    logic complex_task_valid;
    logic complex_task_ready;
    logic [7:0] complex_task_opcode;
    logic [11:0] complex_task_command_id;
    logic [2047:0] complex_task_desc;
    logic complex_done_valid;
    logic complex_done_ready;
    logic [7:0] complex_done_status;
    logic [47:0] complex_done_fault_addr;
    logic [63:0] complex_done_progress;
    logic [11:0] complex_active_id_q;

    logic [3:0] eng_abort;

    logic dma_l1_req_valid;
    logic dma_l1_req_ready;
    logic dma_l1_req_write;
    logic [19:0] dma_l1_req_addr;
    logic [63:0] dma_l1_req_wdata;
    logic [7:0] dma_l1_req_wstrb;
    logic dma_l1_rsp_valid;
    logic dma_l1_rsp_ready;
    logic [63:0] dma_l1_rsp_rdata;
    logic [2:0] dma_l1_rsp_status;

    logic matrix_l1_req_valid;
    logic matrix_l1_req_ready;
    logic matrix_l1_req_write;
    logic [19:0] matrix_l1_req_addr;
    logic [63:0] matrix_l1_req_wdata;
    logic [7:0] matrix_l1_req_wstrb;
    logic matrix_l1_rsp_valid;
    logic matrix_l1_rsp_ready;
    logic [63:0] matrix_l1_rsp_rdata;
    logic [2:0] matrix_l1_rsp_status;

    logic vector_l1_req_valid;
    logic vector_l1_req_ready;
    logic vector_l1_req_write;
    logic [19:0] vector_l1_req_addr;
    logic [63:0] vector_l1_req_wdata;
    logic [7:0] vector_l1_req_wstrb;
    logic vector_l1_rsp_valid;
    logic vector_l1_rsp_ready;
    logic [63:0] vector_l1_rsp_rdata;
    logic [2:0] vector_l1_rsp_status;

    logic complex_l1_req_valid;
    logic complex_l1_req_ready;
    logic complex_l1_req_write;
    logic [19:0] complex_l1_req_addr;
    logic [63:0] complex_l1_req_wdata;
    logic [7:0] complex_l1_req_wstrb;
    logic complex_l1_rsp_valid;
    logic complex_l1_rsp_ready;
    logic [63:0] complex_l1_rsp_rdata;
    logic [2:0] complex_l1_rsp_status;

    logic [L1_CLIENTS-1:0] l1_req_valid;
    logic [L1_CLIENTS-1:0] l1_req_ready;
    logic [L1_CLIENTS-1:0] l1_req_write;
    logic [L1_CLIENTS*20-1:0] l1_req_addr;
    logic [L1_CLIENTS*64-1:0] l1_req_wdata;
    logic [L1_CLIENTS*8-1:0] l1_req_wstrb;
    logic [L1_CLIENTS-1:0] l1_rsp_valid;
    logic [L1_CLIENTS-1:0] l1_rsp_ready;
    logic [L1_CLIENTS*64-1:0] l1_rsp_rdata;
    logic [L1_CLIENTS*3-1:0] l1_rsp_status;
    logic l1_idle;

    logic dma_mem_req_valid;
    logic dma_mem_req_ready;
    logic dma_mem_req_write;
    logic [47:0] dma_mem_req_addr;
    logic [63:0] dma_mem_req_wdata;
    logic [7:0] dma_mem_req_wstrb;
    logic dma_mem_rsp_valid;
    logic dma_mem_rsp_ready;
    logic [63:0] dma_mem_rsp_rdata;
    logic [2:0] dma_mem_rsp_status;

    logic mif_idle;
    logic mif_error_valid;
    logic [47:0] mif_error_addr;
    logic [2:0] mif_error_status;

    logic scheduler_idle;
    logic [15:0] task_occupancy;
    logic completion_valid;
    logic completion_ready;
    logic [11:0] completion_command_id;
    logic [3:0] completion_engine;
    logic [7:0] completion_opcode;
    logic [7:0] completion_status;
    logic [47:0] completion_fault_addr;
    logic [63:0] completion_progress;
    logic completion_irq_success;
    logic completion_irq_error;

    logic ctl_req_valid;
    logic ctl_req_ready;
    logic [1:0] ctl_req_op;
    logic [63:0] ctl_req_arg0;
    logic [63:0] ctl_req_arg1;
    logic ctl_cancel;
    logic ctl_rsp_valid;
    logic ctl_rsp_ready;
    logic [63:0] ctl_rsp_data;
    logic event_query_found;
    logic [2:0] event_query_state;
    logic [11:0] event_query_producer;

    logic task_query_valid;
    logic [11:0] task_query_command_id;
    logic task_query_found;
    logic [3:0] task_query_state;
    logic [7:0] task_query_status;
    logic [47:0] task_query_fault_addr;
    logic [63:0] task_query_progress;
    logic [31:0] task_query_user_tag;
    logic [11:0] task_query_signal_event;
    logic [31:0] task_query_error_info;
    logic [15:0] task_query_done_flags;
    logic task_ack_valid;
    logic [11:0] task_ack_command_id;
    logic task_ack_ready;

    logic [47:0] input_base;
    logic [47:0] weight_base;
    logic [47:0] work_base;
    logic [47:0] output_base;
    logic [47:0] kv_base;
    logic [47:0] m_axi_addr_base;
    logic [47:0] m_axi_addr_limit;
    logic [19:0] param_l1_base;
    logic [19:0] param_l1_limit;
    logic param_lock;
    logic l1_host_access_enable;
    logic single_step_pulse;
    logic wdt_enable;
    logic [31:0] wdt_timeout_cycles;
    logic wdt_kick;
    logic wdt_timeout;
    logic core_progress;
    logic interface_error_valid;
    logic [7:0] interface_error_status;
    logic [47:0] interface_error_addr;
    logic unused_config;

    assign functional_reset_n = crg_core_reset_n &&
                                !internal_soft_reset_pulse;

    assign module_idle = {
        mif_idle,
        l1_idle,
        complex_task_ready,
        vector_task_ready,
        matrix_task_ready,
        dma_task_ready,
        scheduler_idle,
        cfe_idle
    };

    assign core_progress =
        cmd_accepted ||
        (completion_valid && completion_ready) ||
        (dma_mem_req_valid && dma_mem_req_ready) ||
        (dma_mem_rsp_valid && dma_mem_rsp_ready) ||
        (|(l1_req_valid & l1_req_ready));

    always_comb begin
        interface_error_valid = 1'b0;
        interface_error_status = NPU_STATUS_SUCCESS;
        interface_error_addr = 48'd0;
        if (protocol_error) begin
            interface_error_valid = 1'b1;
            interface_error_status = NPU_STATUS_BAD_DESC;
        end else if (mif_error_valid) begin
            interface_error_valid = 1'b1;
            interface_error_status = npu_mem_to_task_status(
                mif_error_status
            );
            interface_error_addr = mif_error_addr;
        end else if (cfe_error) begin
            interface_error_valid = 1'b1;
            interface_error_status = NPU_STATUS_BAD_DESC;
        end
    end

    assign unused_config = ^{
        core_clk_gated,
        noc_clk_gated,
        crg_noc_reset_n,
        input_base,
        weight_base,
        work_base,
        output_base,
        kv_base,
        param_l1_base,
        param_l1_limit,
        param_lock,
        single_step_pulse,
        task_occupancy,
        task_query_valid,
        task_query_command_id,
        task_query_found,
        task_query_state,
        task_query_status,
        task_query_fault_addr,
        task_query_progress,
        task_query_user_tag,
        task_query_signal_event,
        task_query_error_info,
        task_query_done_flags,
        event_query_found,
        event_query_state,
        event_query_producer,
        task_ack_valid,
        task_ack_command_id,
        task_ack_ready,
        completion_progress,
        l1_req_ready[5],
        l1_rsp_valid[5],
        l1_rsp_rdata[5*64 +: 64],
        l1_rsp_status[5*3 +: 3]
    };

    always_ff @(posedge core_clk_i) begin
        if (!crg_core_reset_n) begin
            internal_soft_reset_done_q <= 1'b0;
            dma_active_id_q <= 12'd0;
            matrix_active_id_q <= 12'd0;
            vector_active_id_q <= 12'd0;
            complex_active_id_q <= 12'd0;
        end else begin
            internal_soft_reset_done_q <= internal_soft_reset_pulse;
            if (dma_task_valid && dma_task_ready) begin
                dma_active_id_q <= dma_task_command_id;
            end
            if (matrix_task_valid && matrix_task_ready) begin
                matrix_active_id_q <= matrix_task_command_id;
            end
            if (vector_task_valid && vector_task_ready) begin
                vector_active_id_q <= vector_task_command_id;
            end
            if (complex_task_valid && complex_task_ready) begin
                complex_active_id_q <= complex_task_command_id;
            end
        end
    end

    npu_crg u_crg (
        .core_clk_i(core_clk_i),
        .noc_clk_i(noc_clk_i),
        .reset_n(reset_n),
        .dvfs_prepare_req_i(dvfs_prepare_req_i),
        .dvfs_prepare_ack_o(dvfs_prepare_ack_o),
        .core_idle_i(core_idle_o),
        .axi_idle_i(s_axi_idle && mif_idle),
        .module_clk_en_i(module_clk_enable),
        .module_idle_i(module_idle),
        .module_clk_active_o(module_clk_active_o),
        .core_clk_gated_o(core_clk_gated),
        .noc_clk_gated_o(noc_clk_gated),
        .core_reset_n_o(crg_core_reset_n),
        .noc_reset_n_o(crg_noc_reset_n)
    );

    npu_axi_slave_frontend #(
        .AXI_ID_W(AXI_S_ID_W),
        .AXI_ADDR_W(AXI_S_ADDR_W),
        .INGRESS_DEPTH(16),
        .RSP_DEPTH(8)
    ) u_axi_slave_frontend (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .s_axi_awid_i(s_axi_awid_i),
        .s_axi_awaddr_i(s_axi_awaddr_i),
        .s_axi_awlen_i(s_axi_awlen_i),
        .s_axi_awsize_i(s_axi_awsize_i),
        .s_axi_awburst_i(s_axi_awburst_i),
        .s_axi_awlock_i(s_axi_awlock_i),
        .s_axi_awcache_i(s_axi_awcache_i),
        .s_axi_awprot_i(s_axi_awprot_i),
        .s_axi_awqos_i(s_axi_awqos_i),
        .s_axi_awvalid_i(s_axi_awvalid_i),
        .s_axi_awready_o(s_axi_awready_o),
        .s_axi_wdata_i(s_axi_wdata_i),
        .s_axi_wstrb_i(s_axi_wstrb_i),
        .s_axi_wlast_i(s_axi_wlast_i),
        .s_axi_wvalid_i(s_axi_wvalid_i),
        .s_axi_wready_o(s_axi_wready_o),
        .s_axi_bid_o(s_axi_bid_o),
        .s_axi_bresp_o(s_axi_bresp_o),
        .s_axi_bvalid_o(s_axi_bvalid_o),
        .s_axi_bready_i(s_axi_bready_i),
        .s_axi_arid_i(s_axi_arid_i),
        .s_axi_araddr_i(s_axi_araddr_i),
        .s_axi_arlen_i(s_axi_arlen_i),
        .s_axi_arsize_i(s_axi_arsize_i),
        .s_axi_arburst_i(s_axi_arburst_i),
        .s_axi_arlock_i(s_axi_arlock_i),
        .s_axi_arcache_i(s_axi_arcache_i),
        .s_axi_arprot_i(s_axi_arprot_i),
        .s_axi_arqos_i(s_axi_arqos_i),
        .s_axi_arvalid_i(s_axi_arvalid_i),
        .s_axi_arready_o(s_axi_arready_o),
        .s_axi_rid_o(s_axi_rid_o),
        .s_axi_rdata_o(s_axi_rdata_o),
        .s_axi_rresp_o(s_axi_rresp_o),
        .s_axi_rlast_o(s_axi_rlast_o),
        .s_axi_rvalid_o(s_axi_rvalid_o),
        .s_axi_rready_i(s_axi_rready_i),
        .cmd_valid_o(cmd_valid),
        .cmd_ready_i(cmd_ready),
        .cmd_data_o(cmd_data),
        .cmd_first_o(cmd_first),
        .cmd_last_o(cmd_last),
        .cmd_rsp_valid_i(cmd_rsp_valid),
        .cmd_rsp_ready_o(cmd_rsp_ready),
        .cmd_rsp_data_i(cmd_rsp_data),
        .reg_req_valid_o(reg_req_valid),
        .reg_req_ready_i(reg_req_ready),
        .reg_req_write_o(reg_req_write),
        .reg_req_space_o(reg_req_space),
        .reg_req_addr_o(reg_req_addr),
        .reg_req_wdata_o(reg_req_wdata),
        .reg_req_wstrb_o(reg_req_wstrb),
        .reg_rsp_valid_i(reg_rsp_valid),
        .reg_rsp_ready_o(reg_rsp_ready),
        .reg_rsp_rdata_i(reg_rsp_rdata),
        .reg_rsp_status_i({1'b0, reg_rsp_status}),
        .l1_req_valid_o(fe_l1_req_valid),
        .l1_req_ready_i(fe_l1_req_ready),
        .l1_req_write_o(fe_l1_req_write),
        .l1_req_addr_o(fe_l1_req_addr),
        .l1_req_wdata_o(fe_l1_req_wdata),
        .l1_req_wstrb_o(fe_l1_req_wstrb),
        .l1_rsp_valid_i(fe_l1_rsp_valid),
        .l1_rsp_ready_o(fe_l1_rsp_ready),
        .l1_rsp_rdata_i(fe_l1_rsp_rdata),
        .l1_rsp_status_i(fe_l1_rsp_status),
        .l1_host_access_enable_i(l1_host_access_enable),
        .core_idle_i(core_idle_o),
        .debug_frozen_i(1'b0),
        .cmd_accept_enable_i(accept_new_cmd_o),
        .ctl_req_valid_o(ctl_req_valid),
        .ctl_req_ready_i(ctl_req_ready),
        .ctl_req_op_o(ctl_req_op),
        .ctl_req_arg0_o(ctl_req_arg0),
        .ctl_req_arg1_o(ctl_req_arg1),
        .ctl_cancel_o(ctl_cancel),
        .ctl_rsp_valid_i(ctl_rsp_valid),
        .ctl_rsp_ready_o(ctl_rsp_ready),
        .ctl_rsp_data_i(ctl_rsp_data),
        .protocol_error_clear_i(interface_error_clear),
        .protocol_error_o(protocol_error),
        .cmd_ingress_idle_o(cmd_ingress_idle),
        .s_axi_idle_o(s_axi_idle)
    );

    npu_cmd_frontend #(
        .FIFO_DEPTH(8),
        .WAIT_HIGH_TIMEOUT(32)
    ) u_cmd_frontend (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .quiesce_i(cfe_quiesce),
        .axi_cmd_valid_i(cmd_valid),
        .axi_cmd_ready_o(cmd_ready),
        .axi_cmd_data_i(cmd_data),
        .axi_cmd_first_i(cmd_first),
        .axi_cmd_last_i(cmd_last),
        .axi_cmd_rsp_valid_o(cmd_rsp_valid),
        .axi_cmd_rsp_ready_i(cmd_rsp_ready),
        .axi_cmd_rsp_data_o(cmd_rsp_data),
        .ts_cmd_valid_o(cfe_ts_cmd_valid),
        .ts_cmd_ready_i(cfe_ts_cmd_ready),
        .ts_cmd_o(cfe_ts_cmd),
        .cmd_id_lookup_valid_o(lookup_valid),
        .cmd_id_lookup_ready_i(lookup_ready),
        .cmd_id_lookup_id_o(lookup_id),
        .cmd_id_lookup_rsp_valid_i(lookup_rsp_valid),
        .cmd_id_busy_i(lookup_busy),
        .cfe_idle_o(cfe_idle),
        .cfe_error_o(cfe_error),
        .cmd_accepted_o(cmd_accepted)
    );

    npu_task_scheduler #(
        .TASK_SLOTS(TASK_SLOTS),
        .EVENT_COUNT(EVENT_COUNT)
    ) u_task_scheduler (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .enable_i(accept_new_cmd_o),
        .quiesce_i(ts_quiesce),
        .abort_i(|eng_abort),
        .cfe_cmd_valid_i(cfe_ts_cmd_valid),
        .cfe_cmd_ready_o(cfe_ts_cmd_ready),
        .cfe_cmd_i(cfe_ts_cmd),
        .input_base_i(input_base),
        .weight_base_i(weight_base),
        .work_base_i(work_base),
        .output_base_i(output_base),
        .kv_base_i(kv_base),
        .param_l1_base_i(param_l1_base),
        .cmd_id_lookup_valid_i(lookup_valid),
        .cmd_id_lookup_ready_o(lookup_ready),
        .cmd_id_lookup_id_i(lookup_id),
        .cmd_id_lookup_rsp_valid_o(lookup_rsp_valid),
        .cmd_id_busy_o(lookup_busy),
        .dma_task_valid_o(dma_task_valid),
        .dma_task_ready_i(dma_task_ready),
        .dma_task_opcode_o(dma_task_opcode),
        .dma_task_command_id_o(dma_task_command_id),
        .dma_task_desc_flat_o(dma_task_desc),
        .dma_done_valid_i(dma_done_valid),
        .dma_done_ready_o(dma_done_ready),
        .dma_done_command_id_i(dma_active_id_q),
        .dma_done_status_i(dma_done_status),
        .dma_done_fault_addr_i(dma_done_fault_addr),
        .dma_done_progress_i(dma_done_progress),
        .matrix_task_valid_o(matrix_task_valid),
        .matrix_task_ready_i(matrix_task_ready),
        .matrix_task_opcode_o(matrix_task_opcode),
        .matrix_task_command_id_o(matrix_task_command_id),
        .matrix_task_desc_flat_o(matrix_task_desc),
        .matrix_done_valid_i(matrix_done_valid),
        .matrix_done_ready_o(matrix_done_ready),
        .matrix_done_command_id_i(matrix_active_id_q),
        .matrix_done_status_i(matrix_done_status),
        .matrix_done_fault_addr_i(matrix_done_fault_addr),
        .matrix_done_progress_i(matrix_done_progress),
        .vector_task_valid_o(vector_task_valid),
        .vector_task_ready_i(vector_task_ready),
        .vector_task_opcode_o(vector_task_opcode),
        .vector_task_command_id_o(vector_task_command_id),
        .vector_task_desc_flat_o(vector_task_desc),
        .vector_done_valid_i(vector_done_valid),
        .vector_done_ready_o(vector_done_ready),
        .vector_done_command_id_i(vector_active_id_q),
        .vector_done_status_i(vector_done_status),
        .vector_done_fault_addr_i(vector_done_fault_addr),
        .vector_done_progress_i(vector_done_progress),
        .complex_task_valid_o(complex_task_valid),
        .complex_task_ready_i(complex_task_ready),
        .complex_task_opcode_o(complex_task_opcode),
        .complex_task_command_id_o(complex_task_command_id),
        .complex_task_desc_flat_o(complex_task_desc),
        .complex_done_valid_i(complex_done_valid),
        .complex_done_ready_o(complex_done_ready),
        .complex_done_command_id_i(complex_active_id_q),
        .complex_done_status_i(complex_done_status),
        .complex_done_fault_addr_i(complex_done_fault_addr),
        .complex_done_progress_i(complex_done_progress),
        .completion_valid_o(completion_valid),
        .completion_ready_i(completion_ready),
        .completion_command_id_o(completion_command_id),
        .completion_engine_o(completion_engine),
        .completion_opcode_o(completion_opcode),
        .completion_status_o(completion_status),
        .completion_fault_addr_o(completion_fault_addr),
        .completion_progress_o(completion_progress),
        .completion_irq_success_o(completion_irq_success),
        .completion_irq_error_o(completion_irq_error),
        .axi_ctl_valid_i(ctl_req_valid),
        .axi_ctl_ready_o(ctl_req_ready),
        .axi_ctl_op_i(ctl_req_op),
        .axi_ctl_arg0_i(ctl_req_arg0),
        .axi_ctl_arg1_i(ctl_req_arg1),
        .axi_ctl_cancel_i(ctl_cancel),
        .axi_ctl_rsp_valid_o(ctl_rsp_valid),
        .axi_ctl_rsp_ready_i(ctl_rsp_ready),
        .axi_ctl_rsp_data_o(ctl_rsp_data),
        .event_query_valid_i(1'b0),
        .event_query_ref_i(12'd0),
        .event_query_found_o(event_query_found),
        .event_query_state_o(event_query_state),
        .event_query_producer_command_id_o(event_query_producer),
        .task_query_valid_i(task_query_valid),
        .task_query_command_id_i(task_query_command_id),
        .task_query_found_o(task_query_found),
        .task_query_state_o(task_query_state),
        .task_query_status_o(task_query_status),
        .task_query_fault_addr_o(task_query_fault_addr),
        .task_query_progress_o(task_query_progress),
        .task_query_user_tag_o(task_query_user_tag),
        .task_query_signal_event_o(task_query_signal_event),
        .task_query_error_info_o(task_query_error_info),
        .task_query_done_flags_o(task_query_done_flags),
        .task_ack_valid_i(task_ack_valid),
        .task_ack_command_id_i(task_ack_command_id),
        .task_ack_ready_o(task_ack_ready),
        .scheduler_idle_o(scheduler_idle),
        .task_occupancy_o(task_occupancy)
    );

    assign task_query_valid = 1'b0;
    assign task_query_command_id = 12'd0;
    assign task_ack_valid = 1'b0;
    assign task_ack_command_id = 12'd0;

    npu_lsc u_lsc (
        .clk_i(core_clk_i),
        .reset_n(crg_core_reset_n),
        .reg_req_valid_i(reg_req_valid),
        .reg_req_ready_o(reg_req_ready),
        .reg_req_write_i(reg_req_write),
        .reg_req_space_i(reg_req_space),
        .reg_req_addr_i(reg_req_addr),
        .reg_req_wdata_i(reg_req_wdata),
        .reg_req_wstrb_i(reg_req_wstrb),
        .reg_rsp_valid_o(reg_rsp_valid),
        .reg_rsp_ready_i(reg_rsp_ready),
        .reg_rsp_rdata_o(reg_rsp_rdata),
        .reg_rsp_status_o(reg_rsp_status),
        .cmd_ingress_idle_i(cmd_ingress_idle),
        .cfe_idle_i(cfe_idle),
        .ts_idle_i(scheduler_idle),
        .ts_quiescent_i(scheduler_idle),
        .eng_quiescent_i({
            complex_task_ready,
            vector_task_ready,
            matrix_task_ready,
            dma_task_ready
        }),
        .l1_idle_i(l1_idle),
        .l1_write_idle_i(l1_idle),
        .mif_idle_i(mif_idle),
        .s_axi_idle_i(s_axi_idle),
        .soft_reset_req_i(soft_reset_req_i),
        .internal_soft_reset_done_i(internal_soft_reset_done_q),
        .power_down_req_i(power_down_req_i),
        .soft_reset_done_o(soft_reset_done_o),
        .power_down_ack_o(power_down_ack_o),
        .accept_new_cmd_o(accept_new_cmd_o),
        .cfe_quiesce_o(cfe_quiesce),
        .ts_quiesce_o(ts_quiesce),
        .eng_abort_o(eng_abort),
        .single_step_pulse_o(single_step_pulse),
        .internal_soft_reset_pulse_o(internal_soft_reset_pulse),
        .core_idle_o(core_idle_o),
        .task_terminal_valid_i(completion_valid),
        .task_terminal_ready_o(completion_ready),
        .task_command_id_i(completion_command_id),
        .task_engine_i(completion_engine),
        .task_opcode_i(completion_opcode),
        .task_status_i(completion_status),
        .task_fault_addr_i(completion_fault_addr),
        .task_irq_on_success_i(completion_irq_success),
        .task_irq_on_error_i(completion_irq_error),
        .interface_error_valid_i(interface_error_valid),
        .interface_error_status_i(interface_error_status),
        .interface_error_addr_i(interface_error_addr),
        .interface_error_clear_o(interface_error_clear),
        .wdt_timeout_i(wdt_timeout),
        .wdt_enable_o(wdt_enable),
        .wdt_timeout_cycles_o(wdt_timeout_cycles),
        .wdt_kick_o(wdt_kick),
        .irq_done_o(irq_done_o),
        .irq_exception_o(irq_exception_o),
        .irq_error_o(irq_error_o),
        .input_base_o(input_base),
        .weight_base_o(weight_base),
        .work_base_o(work_base),
        .output_base_o(output_base),
        .kv_base_o(kv_base),
        .m_axi_addr_base_o(m_axi_addr_base),
        .m_axi_addr_limit_o(m_axi_addr_limit),
        .param_l1_base_o(param_l1_base),
        .param_l1_limit_o(param_l1_limit),
        .param_lock_o(param_lock),
        .l1_host_access_enable_o(l1_host_access_enable),
        .module_clk_enable_o(module_clk_enable)
    );

    npu_wdt u_wdt (
        .clk_i(core_clk_i),
        .reset_n(crg_core_reset_n),
        .wdt_enable_i(wdt_enable),
        .wdt_timeout_cycles_i(wdt_timeout_cycles),
        .wdt_kick_i(wdt_kick),
        .wdt_core_progress_i(core_progress),
        .wdt_timeout_o(wdt_timeout),
        .wdt_reset_req_o(wdt_reset_req_o)
    );

    npu_dma_engine u_dma_engine (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .task_valid_i(dma_task_valid),
        .task_ready_o(dma_task_ready),
        .opcode_i(dma_task_opcode),
        .command_id_i(dma_task_command_id),
        .desc_i(dma_task_desc),
        .done_valid_o(dma_done_valid),
        .done_ready_i(dma_done_ready),
        .done_status_o(dma_done_status),
        .done_fault_addr_o(dma_done_fault_addr),
        .done_progress_o(dma_done_progress),
        .l1_req_valid_o(dma_l1_req_valid),
        .l1_req_ready_i(dma_l1_req_ready),
        .l1_req_write_o(dma_l1_req_write),
        .l1_req_addr_o(dma_l1_req_addr),
        .l1_req_wdata_o(dma_l1_req_wdata),
        .l1_req_wstrb_o(dma_l1_req_wstrb),
        .l1_rsp_valid_i(dma_l1_rsp_valid),
        .l1_rsp_ready_o(dma_l1_rsp_ready),
        .l1_rsp_rdata_i(dma_l1_rsp_rdata),
        .l1_rsp_status_i(dma_l1_rsp_status),
        .mif_req_valid_o(dma_mem_req_valid),
        .mif_req_ready_i(dma_mem_req_ready),
        .mif_req_write_o(dma_mem_req_write),
        .mif_req_addr_o(dma_mem_req_addr),
        .mif_req_wdata_o(dma_mem_req_wdata),
        .mif_req_wstrb_o(dma_mem_req_wstrb),
        .mif_rsp_valid_i(dma_mem_rsp_valid),
        .mif_rsp_ready_o(dma_mem_rsp_ready),
        .mif_rsp_rdata_i(dma_mem_rsp_rdata),
        .mif_rsp_status_i(dma_mem_rsp_status)
    );

    npu_matrix_engine u_matrix_engine (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .task_valid_i(matrix_task_valid),
        .task_ready_o(matrix_task_ready),
        .opcode_i(matrix_task_opcode),
        .command_id_i(matrix_task_command_id),
        .desc_i(matrix_task_desc),
        .done_valid_o(matrix_done_valid),
        .done_ready_i(matrix_done_ready),
        .done_status_o(matrix_done_status),
        .done_fault_addr_o(matrix_done_fault_addr),
        .done_progress_o(matrix_done_progress),
        .l1_req_valid_o(matrix_l1_req_valid),
        .l1_req_ready_i(matrix_l1_req_ready),
        .l1_req_write_o(matrix_l1_req_write),
        .l1_req_addr_o(matrix_l1_req_addr),
        .l1_req_wdata_o(matrix_l1_req_wdata),
        .l1_req_wstrb_o(matrix_l1_req_wstrb),
        .l1_rsp_valid_i(matrix_l1_rsp_valid),
        .l1_rsp_ready_o(matrix_l1_rsp_ready),
        .l1_rsp_rdata_i(matrix_l1_rsp_rdata),
        .l1_rsp_status_i(matrix_l1_rsp_status)
    );

    npu_vector_engine u_vector_engine (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .task_valid_i(vector_task_valid),
        .task_ready_o(vector_task_ready),
        .opcode_i(vector_task_opcode),
        .command_id_i(vector_task_command_id),
        .desc_i(vector_task_desc),
        .done_valid_o(vector_done_valid),
        .done_ready_i(vector_done_ready),
        .done_status_o(vector_done_status),
        .done_fault_addr_o(vector_done_fault_addr),
        .done_progress_o(vector_done_progress),
        .l1_req_valid_o(vector_l1_req_valid),
        .l1_req_ready_i(vector_l1_req_ready),
        .l1_req_write_o(vector_l1_req_write),
        .l1_req_addr_o(vector_l1_req_addr),
        .l1_req_wdata_o(vector_l1_req_wdata),
        .l1_req_wstrb_o(vector_l1_req_wstrb),
        .l1_rsp_valid_i(vector_l1_rsp_valid),
        .l1_rsp_ready_o(vector_l1_rsp_ready),
        .l1_rsp_rdata_i(vector_l1_rsp_rdata),
        .l1_rsp_status_i(vector_l1_rsp_status)
    );

    npu_complex_engine u_complex_engine (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .task_valid_i(complex_task_valid),
        .task_ready_o(complex_task_ready),
        .opcode_i(complex_task_opcode),
        .command_id_i(complex_task_command_id),
        .desc_i(complex_task_desc),
        .done_valid_o(complex_done_valid),
        .done_ready_i(complex_done_ready),
        .done_status_o(complex_done_status),
        .done_fault_addr_o(complex_done_fault_addr),
        .done_progress_o(complex_done_progress),
        .l1_req_valid_o(complex_l1_req_valid),
        .l1_req_ready_i(complex_l1_req_ready),
        .l1_req_write_o(complex_l1_req_write),
        .l1_req_addr_o(complex_l1_req_addr),
        .l1_req_wdata_o(complex_l1_req_wdata),
        .l1_req_wstrb_o(complex_l1_req_wstrb),
        .l1_rsp_valid_i(complex_l1_rsp_valid),
        .l1_rsp_ready_o(complex_l1_rsp_ready),
        .l1_rsp_rdata_i(complex_l1_rsp_rdata),
        .l1_rsp_status_i(complex_l1_rsp_status)
    );

    assign l1_req_valid = {
        1'b0,
        complex_l1_req_valid,
        vector_l1_req_valid,
        matrix_l1_req_valid,
        dma_l1_req_valid,
        fe_l1_req_valid
    };
    assign l1_req_write = {
        1'b0,
        complex_l1_req_write,
        vector_l1_req_write,
        matrix_l1_req_write,
        dma_l1_req_write,
        fe_l1_req_write
    };
    assign l1_req_addr = {
        20'd0,
        complex_l1_req_addr,
        vector_l1_req_addr,
        matrix_l1_req_addr,
        dma_l1_req_addr,
        fe_l1_req_addr
    };
    assign l1_req_wdata = {
        64'd0,
        complex_l1_req_wdata,
        vector_l1_req_wdata,
        matrix_l1_req_wdata,
        dma_l1_req_wdata,
        fe_l1_req_wdata
    };
    assign l1_req_wstrb = {
        8'd0,
        complex_l1_req_wstrb,
        vector_l1_req_wstrb,
        matrix_l1_req_wstrb,
        dma_l1_req_wstrb,
        fe_l1_req_wstrb
    };
    assign l1_rsp_ready = {
        1'b0,
        complex_l1_rsp_ready,
        vector_l1_rsp_ready,
        matrix_l1_rsp_ready,
        dma_l1_rsp_ready,
        fe_l1_rsp_ready
    };

    assign fe_l1_req_ready = l1_req_ready[0];
    assign dma_l1_req_ready = l1_req_ready[1];
    assign matrix_l1_req_ready = l1_req_ready[2];
    assign vector_l1_req_ready = l1_req_ready[3];
    assign complex_l1_req_ready = l1_req_ready[4];

    assign fe_l1_rsp_valid = l1_rsp_valid[0];
    assign dma_l1_rsp_valid = l1_rsp_valid[1];
    assign matrix_l1_rsp_valid = l1_rsp_valid[2];
    assign vector_l1_rsp_valid = l1_rsp_valid[3];
    assign complex_l1_rsp_valid = l1_rsp_valid[4];

    assign fe_l1_rsp_rdata = l1_rsp_rdata[0*64 +: 64];
    assign dma_l1_rsp_rdata = l1_rsp_rdata[1*64 +: 64];
    assign matrix_l1_rsp_rdata = l1_rsp_rdata[2*64 +: 64];
    assign vector_l1_rsp_rdata = l1_rsp_rdata[3*64 +: 64];
    assign complex_l1_rsp_rdata = l1_rsp_rdata[4*64 +: 64];

    assign fe_l1_rsp_status = l1_rsp_status[0*3 +: 3];
    assign dma_l1_rsp_status = l1_rsp_status[1*3 +: 3];
    assign matrix_l1_rsp_status = l1_rsp_status[2*3 +: 3];
    assign vector_l1_rsp_status = l1_rsp_status[3*3 +: 3];
    assign complex_l1_rsp_status = l1_rsp_status[4*3 +: 3];

    npu_l1buf #(
        .CLIENTS(L1_CLIENTS),
        .L1_BYTES(L1_BYTES),
        .BANKS(L1_BANKS)
    ) u_l1buf (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .req_valid_i(l1_req_valid),
        .req_ready_o(l1_req_ready),
        .req_write_i(l1_req_write),
        .req_addr_i(l1_req_addr),
        .req_wdata_i(l1_req_wdata),
        .req_wstrb_i(l1_req_wstrb),
        .rsp_valid_o(l1_rsp_valid),
        .rsp_ready_i(l1_rsp_ready),
        .rsp_rdata_o(l1_rsp_rdata),
        .rsp_status_o(l1_rsp_status),
        .l1_idle_o(l1_idle)
    );

    npu_axi_mif_master #(
        .AXI_ADDR_W(AXI_M_ADDR_W),
        .AXI_ID_W(AXI_M_ID_W)
    ) u_axi_mif_master (
        .clk_i(core_clk_i),
        .reset_n(functional_reset_n),
        .req_valid_i(dma_mem_req_valid),
        .req_ready_o(dma_mem_req_ready),
        .req_write_i(dma_mem_req_write),
        .req_addr_i(dma_mem_req_addr),
        .req_wdata_i(dma_mem_req_wdata),
        .req_wstrb_i(dma_mem_req_wstrb),
        .rsp_valid_o(dma_mem_rsp_valid),
        .rsp_ready_i(dma_mem_rsp_ready),
        .rsp_rdata_o(dma_mem_rsp_rdata),
        .rsp_status_o(dma_mem_rsp_status),
        .addr_base_i(m_axi_addr_base),
        .addr_limit_i(m_axi_addr_limit),
        .m_axi_awid_o(m_axi_awid_o),
        .m_axi_awaddr_o(m_axi_awaddr_o),
        .m_axi_awlen_o(m_axi_awlen_o),
        .m_axi_awsize_o(m_axi_awsize_o),
        .m_axi_awburst_o(m_axi_awburst_o),
        .m_axi_awlock_o(m_axi_awlock_o),
        .m_axi_awcache_o(m_axi_awcache_o),
        .m_axi_awprot_o(m_axi_awprot_o),
        .m_axi_awqos_o(m_axi_awqos_o),
        .m_axi_awvalid_o(m_axi_awvalid_o),
        .m_axi_awready_i(m_axi_awready_i),
        .m_axi_wdata_o(m_axi_wdata_o),
        .m_axi_wstrb_o(m_axi_wstrb_o),
        .m_axi_wlast_o(m_axi_wlast_o),
        .m_axi_wvalid_o(m_axi_wvalid_o),
        .m_axi_wready_i(m_axi_wready_i),
        .m_axi_bid_i(m_axi_bid_i),
        .m_axi_bresp_i(m_axi_bresp_i),
        .m_axi_bvalid_i(m_axi_bvalid_i),
        .m_axi_bready_o(m_axi_bready_o),
        .m_axi_arid_o(m_axi_arid_o),
        .m_axi_araddr_o(m_axi_araddr_o),
        .m_axi_arlen_o(m_axi_arlen_o),
        .m_axi_arsize_o(m_axi_arsize_o),
        .m_axi_arburst_o(m_axi_arburst_o),
        .m_axi_arlock_o(m_axi_arlock_o),
        .m_axi_arcache_o(m_axi_arcache_o),
        .m_axi_arprot_o(m_axi_arprot_o),
        .m_axi_arqos_o(m_axi_arqos_o),
        .m_axi_arvalid_o(m_axi_arvalid_o),
        .m_axi_arready_i(m_axi_arready_i),
        .m_axi_rid_i(m_axi_rid_i),
        .m_axi_rdata_i(m_axi_rdata_i),
        .m_axi_rresp_i(m_axi_rresp_i),
        .m_axi_rlast_i(m_axi_rlast_i),
        .m_axi_rvalid_i(m_axi_rvalid_i),
        .m_axi_rready_o(m_axi_rready_o),
        .error_clear_i(interface_error_clear),
        .error_valid_o(mif_error_valid),
        .error_addr_o(mif_error_addr),
        .error_status_o(mif_error_status),
        .mif_idle_o(mif_idle)
    );

endmodule
