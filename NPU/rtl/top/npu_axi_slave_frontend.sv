`timescale 1ns/1ps

module npu_axi_slave_frontend #(
    parameter int unsigned AXI_ID_W      = 8,
    parameter int unsigned AXI_ADDR_W    = 24,
    parameter int unsigned INGRESS_DEPTH = 16,
    parameter int unsigned RSP_DEPTH     = 8
) (
    input  logic                      clk_i,
    input  logic                      reset_n,

    input  logic [AXI_ID_W-1:0]       s_axi_awid_i,
    input  logic [AXI_ADDR_W-1:0]     s_axi_awaddr_i,
    input  logic [7:0]                s_axi_awlen_i,
    input  logic [2:0]                s_axi_awsize_i,
    input  logic [1:0]                s_axi_awburst_i,
    input  logic                      s_axi_awlock_i,
    input  logic [3:0]                s_axi_awcache_i,
    input  logic [2:0]                s_axi_awprot_i,
    input  logic [3:0]                s_axi_awqos_i,
    input  logic                      s_axi_awvalid_i,
    output logic                      s_axi_awready_o,

    input  logic [63:0]               s_axi_wdata_i,
    input  logic [7:0]                s_axi_wstrb_i,
    input  logic                      s_axi_wlast_i,
    input  logic                      s_axi_wvalid_i,
    output logic                      s_axi_wready_o,

    output logic [AXI_ID_W-1:0]       s_axi_bid_o,
    output logic [1:0]                s_axi_bresp_o,
    output logic                      s_axi_bvalid_o,
    input  logic                      s_axi_bready_i,

    input  logic [AXI_ID_W-1:0]       s_axi_arid_i,
    input  logic [AXI_ADDR_W-1:0]     s_axi_araddr_i,
    input  logic [7:0]                s_axi_arlen_i,
    input  logic [2:0]                s_axi_arsize_i,
    input  logic [1:0]                s_axi_arburst_i,
    input  logic                      s_axi_arlock_i,
    input  logic [3:0]                s_axi_arcache_i,
    input  logic [2:0]                s_axi_arprot_i,
    input  logic [3:0]                s_axi_arqos_i,
    input  logic                      s_axi_arvalid_i,
    output logic                      s_axi_arready_o,

    output logic [AXI_ID_W-1:0]       s_axi_rid_o,
    output logic [63:0]               s_axi_rdata_o,
    output logic [1:0]                s_axi_rresp_o,
    output logic                      s_axi_rlast_o,
    output logic                      s_axi_rvalid_o,
    input  logic                      s_axi_rready_i,

    output logic                      cmd_valid_o,
    input  logic                      cmd_ready_i,
    output logic [63:0]               cmd_data_o,
    output logic                      cmd_first_o,
    output logic                      cmd_last_o,
    input  logic                      cmd_rsp_valid_i,
    output logic                      cmd_rsp_ready_o,
    input  logic [63:0]               cmd_rsp_data_i,

    output logic                      reg_req_valid_o,
    input  logic                      reg_req_ready_i,
    output logic                      reg_req_write_o,
    output logic                      reg_req_space_o,
    output logic [15:0]               reg_req_addr_o,
    output logic [63:0]               reg_req_wdata_o,
    output logic [7:0]                reg_req_wstrb_o,
    input  logic                      reg_rsp_valid_i,
    output logic                      reg_rsp_ready_o,
    input  logic [63:0]               reg_rsp_rdata_i,
    input  logic [2:0]                reg_rsp_status_i,

    output logic                      l1_req_valid_o,
    input  logic                      l1_req_ready_i,
    output logic                      l1_req_write_o,
    output logic [19:0]               l1_req_addr_o,
    output logic [63:0]               l1_req_wdata_o,
    output logic [7:0]                l1_req_wstrb_o,
    input  logic                      l1_rsp_valid_i,
    output logic                      l1_rsp_ready_o,
    input  logic [63:0]               l1_rsp_rdata_i,
    input  logic [2:0]                l1_rsp_status_i,

    input  logic                      l1_host_access_enable_i,
    input  logic                      core_idle_i,
    input  logic                      debug_frozen_i,
    input  logic                      cmd_accept_enable_i,

    output logic                      ctl_req_valid_o,
    input  logic                      ctl_req_ready_i,
    output logic [1:0]                ctl_req_op_o,
    output logic [63:0]               ctl_req_arg0_o,
    output logic [63:0]               ctl_req_arg1_o,
    output logic                      ctl_cancel_o,
    input  logic                      ctl_rsp_valid_i,
    output logic                      ctl_rsp_ready_o,
    input  logic [63:0]               ctl_rsp_data_i,

    input  logic                      protocol_error_clear_i,
    output logic                      protocol_error_o,
    output logic                      cmd_ingress_idle_o,
    output logic                      s_axi_idle_o
);

    localparam logic [AXI_ADDR_W-1:0] CMD_DATA_ADDR = AXI_ADDR_W'(24'h020000);
    localparam logic [AXI_ADDR_W-1:0] CMD_RSP_ADDR  = AXI_ADDR_W'(24'h020008);
    localparam logic [AXI_ADDR_W-1:0] CMD_STAT_ADDR = AXI_ADDR_W'(24'h020010);
    localparam logic [AXI_ADDR_W-1:0] CTL_ARG0_ADDR = AXI_ADDR_W'(24'h020020);
    localparam logic [AXI_ADDR_W-1:0] CTL_ARG1_ADDR = AXI_ADDR_W'(24'h020028);
    localparam logic [AXI_ADDR_W-1:0] CTL_START_ADDR = AXI_ADDR_W'(24'h020030);
    localparam logic [AXI_ADDR_W-1:0] CTL_STAT_ADDR = AXI_ADDR_W'(24'h020038);
    localparam logic [AXI_ADDR_W-1:0] CTL_RESULT_ADDR = AXI_ADDR_W'(24'h020040);
    localparam logic [AXI_ADDR_W-1:0] CTL_CANCEL_ADDR = AXI_ADDR_W'(24'h020048);
    localparam logic [AXI_ADDR_W-1:0] L1_BASE_ADDR  = AXI_ADDR_W'(24'h100000);
    localparam logic [AXI_ADDR_W-1:0] L1_LAST_ADDR  = AXI_ADDR_W'(24'h1fffff);

    localparam logic [1:0] AXI_RESP_OKAY   = 2'b00;
    localparam logic [1:0] AXI_RESP_SLVERR = 2'b10;
    localparam logic [1:0] AXI_BURST_FIXED = 2'b00;
    localparam logic [1:0] AXI_BURST_INCR  = 2'b01;

    localparam int unsigned INGRESS_PTR_W =
        (INGRESS_DEPTH <= 1) ? 1 : $clog2(INGRESS_DEPTH);
    localparam int unsigned INGRESS_CNT_W =
        (INGRESS_DEPTH <= 1) ? 1 : $clog2(INGRESS_DEPTH + 1);
    localparam int unsigned RSP_PTR_W =
        (RSP_DEPTH <= 1) ? 1 : $clog2(RSP_DEPTH);
    localparam int unsigned RSP_CNT_W =
        (RSP_DEPTH <= 1) ? 1 : $clog2(RSP_DEPTH + 1);

    typedef enum logic [2:0] {
        WR_IDLE,
        WR_CMD,
        WR_DATA,
        WR_REQ,
        WR_RSP,
        WR_DROP
    } wr_state_t;

    typedef enum logic [2:0] {
        RD_IDLE,
        RD_REQ,
        RD_RSP,
        RD_SEND,
        RD_CMD_WAIT
    } rd_state_t;

    typedef enum logic [1:0] {
        TARGET_NONE,
        TARGET_CSR,
        TARGET_L1,
        TARGET_CTL
    } target_t;

    typedef enum logic [1:0] {
        CMD_SEND_LOW,
        CMD_SEND_HIGH,
        CMD_WAIT_RSP
    } cmd_state_t;

    logic [63:0] staging_mem [0:15];
    logic [63:0] ingress_mem [0:INGRESS_DEPTH-1];
    logic [63:0] rsp_mem [0:RSP_DEPTH-1];

    logic [INGRESS_PTR_W-1:0] ingress_wptr_q;
    logic [INGRESS_PTR_W-1:0] ingress_rptr_q;
    logic [INGRESS_CNT_W-1:0] ingress_count_q;
    logic [RSP_PTR_W-1:0] rsp_wptr_q;
    logic [RSP_PTR_W-1:0] rsp_rptr_q;
    logic [RSP_CNT_W-1:0] rsp_count_q;

    wr_state_t wr_state_q;
    rd_state_t rd_state_q;
    target_t wr_target_q;
    target_t rd_target_q;
    cmd_state_t cmd_state_q;

    logic [AXI_ID_W-1:0] wr_id_q;
    logic [AXI_ADDR_W-1:0] wr_addr_q;
    logic [8:0] wr_beats_q;
    logic [8:0] wr_index_q;
    logic wr_error_q;
    logic wr_req_sent_q;

    logic [AXI_ID_W-1:0] rd_id_q;
    logic [AXI_ADDR_W-1:0] rd_addr_q;
    logic [8:0] rd_beats_q;
    logic [8:0] rd_index_q;
    logic [2:0] rd_size_q;
    logic rd_req_sent_q;
    logic rd_pop_rsp_q;

    logic [63:0] wr_req_data_q;
    logic [7:0] wr_req_strb_q;
    logic [AXI_ADDR_W-1:0] wr_req_addr_q;
    logic aw_cmd_format_w;
    logic aw_csr_format_w;
    logic aw_l1_format_w;
    logic ar_csr_format_w;
    logic ar_l1_format_w;
    logic ar_cmd_rsp_format_w;
    logic ar_cmd_stat_format_w;
    logic aw_ctl_format_w;
    logic ar_ctl_format_w;
    logic [8:0] aw_beats_w;
    logic [8:0] ar_beats_w;
    logic [8:0] ingress_free_w;
    logic cmd_commit_w;
    logic cmd_pop_w;
    logic rsp_push_w;
    logic rsp_pop_w;
    logic wr_last_expected_w;
    logic wr_current_error_w;
    logic wr_complete_error_w;
    logic unused_axi_attr_w;
    logic [63:0] fifo_status_w;
    logic [63:0] ctl_arg0_q;
    logic [63:0] ctl_arg1_q;
    logic [63:0] ctl_result_q;
    logic [7:0] ctl_status_q;
    logic ctl_busy_q;
    logic ctl_done_q;
    logic ctl_pending_q;
    logic ctl_inflight_q;
    logic [1:0] ctl_op_q;
    logic ctl_cancel_q;

    integer i;

    function automatic logic aligned_for_size(
        input logic [2:0] size,
        input logic [2:0] addr_low
    );
        case (size)
            3'd0: aligned_for_size = 1'b1;
            3'd1: aligned_for_size = (addr_low[0] == 1'b0);
            3'd2: aligned_for_size = (addr_low[1:0] == 2'b00);
            3'd3: aligned_for_size = (addr_low == 3'b000);
            default: aligned_for_size = 1'b0;
        endcase
    endfunction

    function automatic [INGRESS_PTR_W-1:0] ingress_ptr_add(
        input logic [INGRESS_PTR_W-1:0] base,
        input int unsigned amount
    );
        int unsigned value;
        begin
            value = int'(base) + amount;
            ingress_ptr_add = INGRESS_PTR_W'(value % INGRESS_DEPTH);
        end
    endfunction

    function automatic [RSP_PTR_W-1:0] rsp_ptr_add(
        input logic [RSP_PTR_W-1:0] base,
        input int unsigned amount
    );
        int unsigned value;
        begin
            value = int'(base) + amount;
            rsp_ptr_add = RSP_PTR_W'(value % RSP_DEPTH);
        end
    endfunction

    function automatic logic l1_burst_ok(
        input logic [AXI_ADDR_W-1:0] addr,
        input logic [8:0] beats,
        input logic [2:0] size,
        input logic [1:0] burst,
        input logic lock
    );
        logic [AXI_ADDR_W:0] last_addr;
        begin
            last_addr = {1'b0, addr} +
                ((AXI_ADDR_W + 1)'(beats - 9'd1) << size);
            l1_burst_ok =
                !lock &&
                (burst == AXI_BURST_INCR) &&
                (size <= 3) &&
                aligned_for_size(size, addr[2:0]) &&
                ((beats == 9'd1) || (size == 3'd3)) &&
                (addr >= L1_BASE_ADDR) &&
                (last_addr <= {1'b0, L1_LAST_ADDR}) &&
                (addr[AXI_ADDR_W-1:12] == last_addr[AXI_ADDR_W-1:12]);
        end
    endfunction

    function automatic [63:0] narrow_read_data(
        input logic [63:0] data,
        input logic [2:0] size,
        input logic [2:0] addr_low
    );
        logic [63:0] mask;
        begin
            case (size)
                3'd0: mask = 64'h00000000000000ff << (addr_low * 8);
                3'd1: mask = 64'h000000000000ffff << (addr_low * 8);
                3'd2: mask = 64'h00000000ffffffff << (addr_low * 8);
                default: mask = 64'hffffffffffffffff;
            endcase
            narrow_read_data = data & mask;
        end
    endfunction

    initial begin
        if (INGRESS_DEPTH < 16) begin
            $error("INGRESS_DEPTH must hold a full 16-beat command burst");
        end
        if (RSP_DEPTH < 8) begin
            $error("RSP_DEPTH must hold eight command responses");
        end
    end

    assign unused_axi_attr_w = ^{
        s_axi_awcache_i, s_axi_awprot_i, s_axi_awqos_i,
        s_axi_arcache_i, s_axi_arprot_i, s_axi_arqos_i
    };

    assign aw_beats_w = {1'b0, s_axi_awlen_i} + 9'd1;
    assign ar_beats_w = {1'b0, s_axi_arlen_i} + 9'd1;
    assign ingress_free_w = 9'(INGRESS_DEPTH) - 9'(ingress_count_q);

    assign aw_cmd_format_w =
        (s_axi_awaddr_i == CMD_DATA_ADDR) &&
        (s_axi_awsize_i == 3'd3) &&
        (s_axi_awburst_i == AXI_BURST_FIXED) &&
        !s_axi_awlock_i &&
        (aw_beats_w >= 9'd2) &&
        (aw_beats_w <= 9'd16) &&
        !aw_beats_w[0];

    assign aw_csr_format_w =
        (s_axi_awaddr_i < AXI_ADDR_W'(24'h020000)) &&
        (aw_beats_w == 9'd1) &&
        (s_axi_awburst_i == AXI_BURST_INCR) &&
        !s_axi_awlock_i &&
        (s_axi_awsize_i <= 3'd3) &&
        aligned_for_size(s_axi_awsize_i, s_axi_awaddr_i[2:0]);

    assign aw_l1_format_w = l1_burst_ok(
        s_axi_awaddr_i, aw_beats_w, s_axi_awsize_i,
        s_axi_awburst_i, s_axi_awlock_i
    );

    assign aw_ctl_format_w =
        ((s_axi_awaddr_i == CTL_ARG0_ADDR) ||
         (s_axi_awaddr_i == CTL_ARG1_ADDR) ||
         (s_axi_awaddr_i == CTL_START_ADDR) ||
         (s_axi_awaddr_i == CTL_CANCEL_ADDR)) &&
        (aw_beats_w == 9'd1) &&
        (s_axi_awsize_i == 3'd3) &&
        (s_axi_awburst_i == AXI_BURST_INCR) &&
        !s_axi_awlock_i;

    assign ar_csr_format_w =
        (s_axi_araddr_i < AXI_ADDR_W'(24'h020000)) &&
        (ar_beats_w == 9'd1) &&
        (s_axi_arburst_i == AXI_BURST_INCR) &&
        !s_axi_arlock_i &&
        (s_axi_arsize_i <= 3'd3) &&
        aligned_for_size(s_axi_arsize_i, s_axi_araddr_i[2:0]);

    assign ar_l1_format_w = l1_burst_ok(
        s_axi_araddr_i, ar_beats_w, s_axi_arsize_i,
        s_axi_arburst_i, s_axi_arlock_i
    );

    assign ar_cmd_rsp_format_w =
        (s_axi_araddr_i == CMD_RSP_ADDR) &&
        (ar_beats_w == 9'd1) &&
        (s_axi_arsize_i == 3'd3) &&
        (s_axi_arburst_i == AXI_BURST_INCR) &&
        !s_axi_arlock_i;

    assign ar_cmd_stat_format_w =
        (s_axi_araddr_i == CMD_STAT_ADDR) &&
        (ar_beats_w == 9'd1) &&
        (s_axi_arsize_i == 3'd3) &&
        (s_axi_arburst_i == AXI_BURST_INCR) &&
        !s_axi_arlock_i;

    assign ar_ctl_format_w =
        ((s_axi_araddr_i == CTL_ARG0_ADDR) ||
         (s_axi_araddr_i == CTL_ARG1_ADDR) ||
         (s_axi_araddr_i == CTL_STAT_ADDR) ||
         (s_axi_araddr_i == CTL_RESULT_ADDR)) &&
        (ar_beats_w == 9'd1) &&
        (s_axi_arsize_i == 3'd3) &&
        (s_axi_arburst_i == AXI_BURST_INCR) &&
        !s_axi_arlock_i;

    assign s_axi_awready_o =
        reset_n &&
        (wr_state_q == WR_IDLE) &&
        !s_axi_bvalid_o &&
        (rd_state_q == RD_IDLE) &&
        !s_axi_rvalid_o &&
        (!aw_cmd_format_w ||
         (cmd_accept_enable_i && (ingress_free_w >= aw_beats_w)));

    assign s_axi_arready_o =
        reset_n &&
        (rd_state_q == RD_IDLE) &&
        !s_axi_rvalid_o &&
        (wr_state_q == WR_IDLE) &&
        !s_axi_bvalid_o &&
        !s_axi_awvalid_i;

    assign s_axi_wready_o =
        (wr_state_q == WR_CMD) ||
        (wr_state_q == WR_DATA) ||
        (wr_state_q == WR_DROP);

    assign s_axi_bid_o = wr_id_q;

    assign wr_last_expected_w = ((wr_index_q + 9'd1) == wr_beats_q);
    assign wr_current_error_w =
        (s_axi_wlast_i != wr_last_expected_w) ||
        ((wr_state_q == WR_CMD) && (s_axi_wstrb_i != 8'hff));
    assign wr_complete_error_w = wr_error_q || wr_current_error_w;

    assign cmd_commit_w =
        (wr_state_q == WR_CMD) &&
        s_axi_wvalid_i &&
        s_axi_wready_o &&
        wr_last_expected_w &&
        !wr_complete_error_w;

    assign cmd_valid_o =
        (ingress_count_q >= INGRESS_CNT_W'(2)) &&
        ((cmd_state_q == CMD_SEND_LOW) ||
         (cmd_state_q == CMD_SEND_HIGH));
    assign cmd_data_o =
        (cmd_state_q == CMD_SEND_HIGH) ?
        ingress_mem[ingress_ptr_add(ingress_rptr_q, 1)] :
        ingress_mem[ingress_rptr_q];
    assign cmd_first_o = cmd_valid_o && (cmd_state_q == CMD_SEND_LOW);
    assign cmd_last_o  = cmd_valid_o && (cmd_state_q == CMD_SEND_HIGH);

    assign rsp_pop_w =
        s_axi_rvalid_o &&
        s_axi_rready_i &&
        rd_pop_rsp_q;
    assign cmd_rsp_ready_o =
        (cmd_state_q == CMD_WAIT_RSP) &&
        ((rsp_count_q < RSP_CNT_W'(RSP_DEPTH)) || rsp_pop_w);
    assign rsp_push_w = cmd_rsp_valid_i && cmd_rsp_ready_o;
    assign cmd_pop_w = rsp_push_w;

    assign cmd_ingress_idle_o =
        (wr_state_q != WR_CMD) &&
        (ingress_count_q == '0) &&
        (cmd_state_q == CMD_SEND_LOW);
    assign s_axi_idle_o =
        (wr_state_q == WR_IDLE) &&
        !s_axi_bvalid_o &&
        (rd_state_q == RD_IDLE) &&
        !s_axi_rvalid_o;

    assign fifo_status_w = {
        44'd0,
        protocol_error_o,
        (rsp_count_q == RSP_CNT_W'(RSP_DEPTH)),
        (ingress_count_q == INGRESS_CNT_W'(INGRESS_DEPTH)),
        ((wr_state_q == WR_CMD) && wr_index_q[0]),
        8'(rsp_count_q),
        8'(ingress_free_w)
    };

    assign ctl_req_valid_o = ctl_pending_q;
    assign ctl_req_op_o = ctl_op_q;
    assign ctl_req_arg0_o = ctl_arg0_q;
    assign ctl_req_arg1_o = ctl_arg1_q;
    assign ctl_cancel_o = ctl_cancel_q;
    assign ctl_rsp_ready_o = ctl_inflight_q;

    assign reg_req_valid_o =
        ((wr_state_q == WR_REQ) && (wr_target_q == TARGET_CSR) && !wr_req_sent_q) ||
        ((rd_state_q == RD_REQ) && (rd_target_q == TARGET_CSR) && !rd_req_sent_q);
    assign reg_req_write_o = (wr_state_q == WR_REQ);
    assign reg_req_space_o =
        ((wr_state_q == WR_REQ) ? wr_req_addr_q[16] : rd_addr_q[16]);
    assign reg_req_addr_o =
        ((wr_state_q == WR_REQ) ? wr_req_addr_q[15:0] : rd_addr_q[15:0])
        & 16'hfff8;
    assign reg_req_wdata_o = wr_req_data_q;
    assign reg_req_wstrb_o = wr_req_strb_q;
    assign reg_rsp_ready_o =
        ((wr_state_q == WR_RSP) && (wr_target_q == TARGET_CSR)) ||
        ((rd_state_q == RD_RSP) && (rd_target_q == TARGET_CSR));

    assign l1_req_valid_o =
        ((wr_state_q == WR_REQ) && (wr_target_q == TARGET_L1) && !wr_req_sent_q) ||
        ((rd_state_q == RD_REQ) && (rd_target_q == TARGET_L1) && !rd_req_sent_q);
    assign l1_req_write_o = (wr_state_q == WR_REQ);
    assign l1_req_addr_o =
        20'(((wr_state_q == WR_REQ) ? wr_req_addr_q : rd_addr_q)
            - L1_BASE_ADDR) & 20'hffff8;
    assign l1_req_wdata_o = wr_req_data_q;
    assign l1_req_wstrb_o = wr_req_strb_q;
    assign l1_rsp_ready_o =
        ((wr_state_q == WR_RSP) && (wr_target_q == TARGET_L1)) ||
        ((rd_state_q == RD_RSP) && (rd_target_q == TARGET_L1));

    always_ff @(posedge clk_i or negedge reset_n) begin
        if (!reset_n) begin
            ingress_wptr_q <= '0;
            ingress_rptr_q <= '0;
            ingress_count_q <= '0;
            rsp_wptr_q <= '0;
            rsp_rptr_q <= '0;
            rsp_count_q <= '0;
            cmd_state_q <= CMD_SEND_LOW;
            wr_state_q <= WR_IDLE;
            rd_state_q <= RD_IDLE;
            wr_target_q <= TARGET_NONE;
            rd_target_q <= TARGET_NONE;
            wr_id_q <= '0;
            wr_addr_q <= '0;
            wr_beats_q <= '0;
            wr_index_q <= '0;
            wr_error_q <= 1'b0;
            wr_req_sent_q <= 1'b0;
            wr_req_data_q <= '0;
            wr_req_strb_q <= '0;
            wr_req_addr_q <= '0;
            rd_id_q <= '0;
            rd_addr_q <= '0;
            rd_beats_q <= '0;
            rd_index_q <= '0;
            rd_size_q <= '0;
            rd_req_sent_q <= 1'b0;
            rd_pop_rsp_q <= 1'b0;
            s_axi_bvalid_o <= 1'b0;
            s_axi_bresp_o <= AXI_RESP_OKAY;
            s_axi_rid_o <= '0;
            s_axi_rdata_o <= '0;
            s_axi_rresp_o <= AXI_RESP_OKAY;
            s_axi_rlast_o <= 1'b0;
            s_axi_rvalid_o <= 1'b0;
            protocol_error_o <= 1'b0;
            ctl_arg0_q <= 64'd0;
            ctl_arg1_q <= 64'd0;
            ctl_result_q <= 64'd0;
            ctl_status_q <= 8'd0;
            ctl_busy_q <= 1'b0;
            ctl_done_q <= 1'b0;
            ctl_pending_q <= 1'b0;
            ctl_inflight_q <= 1'b0;
            ctl_op_q <= 2'd0;
            ctl_cancel_q <= 1'b0;
        end else begin
            ctl_cancel_q <= 1'b0;
            if (protocol_error_clear_i) begin
                protocol_error_o <= 1'b0;
            end

            if (s_axi_bvalid_o && s_axi_bready_i) begin
                s_axi_bvalid_o <= 1'b0;
            end
            if (s_axi_rvalid_o && s_axi_rready_i) begin
                s_axi_rvalid_o <= 1'b0;
                rd_pop_rsp_q <= 1'b0;
                if (rd_state_q == RD_SEND) begin
                    if ((rd_index_q + 9'd1) == rd_beats_q) begin
                        rd_state_q <= RD_IDLE;
                    end else begin
                        rd_index_q <= rd_index_q + 9'd1;
                        rd_addr_q <= rd_addr_q + AXI_ADDR_W'(8);
                        rd_req_sent_q <= 1'b0;
                        rd_state_q <= RD_REQ;
                    end
                end else if (rd_state_q == RD_CMD_WAIT) begin
                    rd_state_q <= RD_IDLE;
                end
            end

            if (s_axi_awvalid_i && s_axi_awready_o) begin
                wr_id_q <= s_axi_awid_i;
                wr_addr_q <= s_axi_awaddr_i;
                wr_beats_q <= aw_beats_w;
                wr_index_q <= '0;
                wr_error_q <= 1'b0;
                wr_req_sent_q <= 1'b0;
                if (aw_cmd_format_w) begin
                    wr_target_q <= TARGET_NONE;
                    wr_state_q <= WR_CMD;
                end else if (aw_ctl_format_w) begin
                    wr_target_q <= TARGET_CTL;
                    wr_state_q <= WR_DATA;
                end else if (aw_csr_format_w) begin
                    wr_target_q <= TARGET_CSR;
                    wr_state_q <= WR_DATA;
                end else if (aw_l1_format_w && l1_host_access_enable_i) begin
                    wr_target_q <= TARGET_L1;
                    wr_state_q <= WR_DATA;
                end else begin
                    wr_target_q <= TARGET_NONE;
                    wr_error_q <= 1'b1;
                    wr_state_q <= WR_DROP;
                    protocol_error_o <= 1'b1;
                end
            end

            if (s_axi_wvalid_i && s_axi_wready_o) begin
                if (wr_state_q == WR_CMD) begin
                    staging_mem[wr_index_q[3:0]] <= s_axi_wdata_i;
                    wr_error_q <= wr_complete_error_w;
                    if (wr_last_expected_w) begin
                        if (!wr_complete_error_w) begin
                            for (i = 0; i < 16; i = i + 1) begin
                                if (i < wr_beats_q) begin
                                    ingress_mem[ingress_ptr_add(ingress_wptr_q, i)] <=
                                        (i == int'(wr_index_q)) ?
                                        s_axi_wdata_i : staging_mem[i];
                                end
                            end
                        end else begin
                            protocol_error_o <= 1'b1;
                        end
                        s_axi_bresp_o <= wr_complete_error_w ?
                            AXI_RESP_SLVERR : AXI_RESP_OKAY;
                        s_axi_bvalid_o <= 1'b1;
                        wr_state_q <= WR_IDLE;
                    end else begin
                        wr_index_q <= wr_index_q + 9'd1;
                    end
                end else if (wr_state_q == WR_DATA) begin
                    if (wr_target_q == TARGET_CTL) begin
                        s_axi_bresp_o <= AXI_RESP_OKAY;
                        if (wr_complete_error_w ||
                            (s_axi_wstrb_i != 8'hff)) begin
                            s_axi_bresp_o <= AXI_RESP_SLVERR;
                            protocol_error_o <= 1'b1;
                        end else begin
                            unique case (wr_addr_q)
                                CTL_ARG0_ADDR: ctl_arg0_q <= s_axi_wdata_i;
                                CTL_ARG1_ADDR: ctl_arg1_q <= s_axi_wdata_i;
                                CTL_START_ADDR: begin
                                    if (ctl_busy_q ||
                                        (s_axi_wdata_i[63:2] != 62'd0) ||
                                        (s_axi_wdata_i[1:0] == 2'd0)) begin
                                        s_axi_bresp_o <= AXI_RESP_SLVERR;
                                    end else begin
                                        ctl_op_q <= s_axi_wdata_i[1:0];
                                        ctl_busy_q <= 1'b1;
                                        ctl_done_q <= 1'b0;
                                        ctl_status_q <= 8'd0;
                                        ctl_pending_q <= 1'b1;
                                    end
                                end
                                CTL_CANCEL_ADDR: begin
                                    if ((s_axi_wdata_i != 64'd1) ||
                                        !ctl_busy_q ||
                                        (ctl_op_q == 2'd2)) begin
                                        s_axi_bresp_o <= AXI_RESP_SLVERR;
                                    end else if (ctl_pending_q) begin
                                        ctl_pending_q <= 1'b0;
                                        ctl_busy_q <= 1'b0;
                                        ctl_done_q <= 1'b1;
                                        ctl_status_q <= 8'h0a;
                                        ctl_result_q <= 64'h0a;
                                    end else if (ctl_inflight_q) begin
                                        ctl_cancel_q <= 1'b1;
                                        ctl_inflight_q <= 1'b0;
                                        ctl_busy_q <= 1'b0;
                                        ctl_done_q <= 1'b1;
                                        ctl_status_q <= 8'h0a;
                                        ctl_result_q <= 64'h0a;
                                    end
                                end
                                default: s_axi_bresp_o <= AXI_RESP_SLVERR;
                            endcase
                        end
                        s_axi_bvalid_o <= 1'b1;
                        wr_state_q <= WR_IDLE;
                    end else begin
                        wr_req_data_q <= s_axi_wdata_i;
                        wr_req_strb_q <= s_axi_wstrb_i;
                        wr_req_addr_q <= wr_addr_q;
                        wr_error_q <= wr_complete_error_w;
                        wr_req_sent_q <= 1'b0;
                        wr_state_q <= WR_REQ;
                    end
                end else if (wr_state_q == WR_DROP) begin
                    wr_error_q <= 1'b1;
                    if (wr_current_error_w) begin
                        protocol_error_o <= 1'b1;
                    end
                    if (wr_last_expected_w) begin
                        s_axi_bresp_o <= AXI_RESP_SLVERR;
                        s_axi_bvalid_o <= 1'b1;
                        wr_state_q <= WR_IDLE;
                    end else begin
                        wr_index_q <= wr_index_q + 9'd1;
                    end
                end
            end

            if (wr_state_q == WR_REQ) begin
                if (((wr_target_q == TARGET_CSR) &&
                     reg_req_valid_o && reg_req_ready_i) ||
                    ((wr_target_q == TARGET_L1) &&
                     l1_req_valid_o && l1_req_ready_i)) begin
                    wr_req_sent_q <= 1'b1;
                    wr_state_q <= WR_RSP;
                end
            end

            if ((wr_state_q == WR_RSP) &&
                (((wr_target_q == TARGET_CSR) &&
                  reg_rsp_valid_i && reg_rsp_ready_o) ||
                 ((wr_target_q == TARGET_L1) &&
                  l1_rsp_valid_i && l1_rsp_ready_o))) begin
                if (((wr_target_q == TARGET_CSR) && (reg_rsp_status_i != 3'd0)) ||
                    ((wr_target_q == TARGET_L1) && (l1_rsp_status_i != 3'd0))) begin
                    wr_error_q <= 1'b1;
                end
                if ((wr_index_q + 9'd1) == wr_beats_q) begin
                    s_axi_bresp_o <=
                        (wr_error_q ||
                         ((wr_target_q == TARGET_CSR) && (reg_rsp_status_i != 3'd0)) ||
                         ((wr_target_q == TARGET_L1) && (l1_rsp_status_i != 3'd0))) ?
                        AXI_RESP_SLVERR : AXI_RESP_OKAY;
                    s_axi_bvalid_o <= 1'b1;
                    wr_state_q <= WR_IDLE;
                end else begin
                    wr_index_q <= wr_index_q + 9'd1;
                    wr_addr_q <= wr_addr_q + AXI_ADDR_W'(8);
                    wr_req_sent_q <= 1'b0;
                    wr_state_q <= WR_DATA;
                end
            end

            if (s_axi_arvalid_i && s_axi_arready_o) begin
                rd_id_q <= s_axi_arid_i;
                s_axi_rid_o <= s_axi_arid_i;
                rd_addr_q <= s_axi_araddr_i;
                rd_beats_q <= ar_beats_w;
                rd_index_q <= '0;
                rd_size_q <= s_axi_arsize_i;
                rd_req_sent_q <= 1'b0;
                rd_pop_rsp_q <= 1'b0;
                if (ar_cmd_rsp_format_w) begin
                    rd_target_q <= TARGET_NONE;
                    rd_state_q <= RD_CMD_WAIT;
                end else if (ar_cmd_stat_format_w) begin
                    rd_target_q <= TARGET_NONE;
                    s_axi_rdata_o <= fifo_status_w;
                    s_axi_rresp_o <= AXI_RESP_OKAY;
                    s_axi_rlast_o <= 1'b1;
                    s_axi_rvalid_o <= 1'b1;
                    rd_state_q <= RD_SEND;
                end else if (ar_ctl_format_w) begin
                    rd_target_q <= TARGET_NONE;
                    unique case (s_axi_araddr_i)
                        CTL_ARG0_ADDR: s_axi_rdata_o <= ctl_arg0_q;
                        CTL_ARG1_ADDR: s_axi_rdata_o <= ctl_arg1_q;
                        CTL_STAT_ADDR: s_axi_rdata_o <= {
                            48'd0, ctl_status_q, 6'd0, ctl_done_q, ctl_busy_q
                        };
                        CTL_RESULT_ADDR: s_axi_rdata_o <= ctl_result_q;
                        default: s_axi_rdata_o <= 64'd0;
                    endcase
                    s_axi_rresp_o <= AXI_RESP_OKAY;
                    s_axi_rlast_o <= 1'b1;
                    s_axi_rvalid_o <= 1'b1;
                    rd_state_q <= RD_SEND;
                end else if (ar_csr_format_w &&
                             ((s_axi_araddr_i[16] == 1'b0) ||
                              core_idle_i || debug_frozen_i)) begin
                    rd_target_q <= TARGET_CSR;
                    rd_state_q <= RD_REQ;
                end else if (ar_l1_format_w && l1_host_access_enable_i) begin
                    rd_target_q <= TARGET_L1;
                    rd_state_q <= RD_REQ;
                end else begin
                    rd_target_q <= TARGET_NONE;
                    s_axi_rdata_o <= 64'd0;
                    s_axi_rresp_o <= AXI_RESP_SLVERR;
                    s_axi_rlast_o <= 1'b1;
                    s_axi_rvalid_o <= 1'b1;
                    rd_state_q <= RD_SEND;
                    protocol_error_o <= 1'b1;
                end
            end

            if ((rd_state_q == RD_CMD_WAIT) && !s_axi_rvalid_o &&
                (rsp_count_q != '0)) begin
                s_axi_rid_o <= rd_id_q;
                s_axi_rdata_o <= rsp_mem[rsp_rptr_q];
                s_axi_rresp_o <= AXI_RESP_OKAY;
                s_axi_rlast_o <= 1'b1;
                s_axi_rvalid_o <= 1'b1;
                rd_pop_rsp_q <= 1'b1;
            end

            if (rd_state_q == RD_REQ) begin
                if (((rd_target_q == TARGET_CSR) &&
                     reg_req_valid_o && reg_req_ready_i) ||
                    ((rd_target_q == TARGET_L1) &&
                     l1_req_valid_o && l1_req_ready_i)) begin
                    rd_req_sent_q <= 1'b1;
                    rd_state_q <= RD_RSP;
                end
            end

            if ((rd_state_q == RD_RSP) &&
                (((rd_target_q == TARGET_CSR) &&
                  reg_rsp_valid_i && reg_rsp_ready_o) ||
                 ((rd_target_q == TARGET_L1) &&
                  l1_rsp_valid_i && l1_rsp_ready_o))) begin
                s_axi_rid_o <= rd_id_q;
                s_axi_rdata_o <= narrow_read_data(
                    (rd_target_q == TARGET_CSR) ?
                        reg_rsp_rdata_i : l1_rsp_rdata_i,
                    rd_size_q, rd_addr_q[2:0]
                );
                s_axi_rresp_o <=
                    (((rd_target_q == TARGET_CSR) && (reg_rsp_status_i != 3'd0)) ||
                     ((rd_target_q == TARGET_L1) && (l1_rsp_status_i != 3'd0))) ?
                    AXI_RESP_SLVERR : AXI_RESP_OKAY;
                s_axi_rlast_o <= ((rd_index_q + 9'd1) == rd_beats_q);
                s_axi_rvalid_o <= 1'b1;
                rd_state_q <= RD_SEND;
            end

            if (ctl_pending_q && ctl_req_ready_i) begin
                ctl_pending_q <= 1'b0;
                ctl_inflight_q <= 1'b1;
            end

            if (ctl_rsp_valid_i && ctl_rsp_ready_o) begin
                ctl_inflight_q <= 1'b0;
                ctl_busy_q <= 1'b0;
                ctl_done_q <= 1'b1;
                ctl_status_q <= 8'h00;
                ctl_result_q <= ctl_rsp_data_i;
            end

            case (cmd_state_q)
                CMD_SEND_LOW: begin
                    if (cmd_valid_o && cmd_ready_i) begin
                        cmd_state_q <= CMD_SEND_HIGH;
                    end
                end
                CMD_SEND_HIGH: begin
                    if (cmd_valid_o && cmd_ready_i) begin
                        cmd_state_q <= CMD_WAIT_RSP;
                    end
                end
                CMD_WAIT_RSP: begin
                    if (rsp_push_w) begin
                        cmd_state_q <= CMD_SEND_LOW;
                    end
                end
                default: cmd_state_q <= CMD_SEND_LOW;
            endcase

            if (cmd_commit_w) begin
                ingress_wptr_q <= ingress_ptr_add(
                    ingress_wptr_q, int'(wr_beats_q)
                );
            end
            if (cmd_pop_w) begin
                ingress_rptr_q <= ingress_ptr_add(ingress_rptr_q, 2);
            end
            case ({cmd_commit_w, cmd_pop_w})
                2'b10: ingress_count_q <=
                    ingress_count_q + INGRESS_CNT_W'(wr_beats_q);
                2'b01: ingress_count_q <= ingress_count_q - INGRESS_CNT_W'(2);
                2'b11: ingress_count_q <=
                    ingress_count_q + INGRESS_CNT_W'(wr_beats_q) - INGRESS_CNT_W'(2);
                default: ;
            endcase

            if (rsp_push_w) begin
                rsp_mem[rsp_wptr_q] <= cmd_rsp_data_i;
                rsp_wptr_q <= rsp_ptr_add(rsp_wptr_q, 1);
            end
            if (rsp_pop_w) begin
                rsp_rptr_q <= rsp_ptr_add(rsp_rptr_q, 1);
            end
            case ({rsp_push_w, rsp_pop_w})
                2'b10: rsp_count_q <= rsp_count_q + RSP_CNT_W'(1);
                2'b01: rsp_count_q <= rsp_count_q - RSP_CNT_W'(1);
                default: ;
            endcase
        end
    end

endmodule
