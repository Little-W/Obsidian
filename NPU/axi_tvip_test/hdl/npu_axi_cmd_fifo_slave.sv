module npu_axi_cmd_fifo_slave #(
    parameter int unsigned AXI_ID_WIDTH       = 8,
    parameter int unsigned AXI_ADDR_WIDTH     = 24,
    parameter int unsigned INGRESS_DEPTH      = 16,
    parameter int unsigned CMD_RSP_DEPTH      = 8,
    parameter logic [AXI_ADDR_WIDTH-1:0] CMD_FIFO_DATA_ADDR =
        AXI_ADDR_WIDTH'(24'h020000),
    parameter logic [AXI_ADDR_WIDTH-1:0] CMD_RSP_FIFO_ADDR =
        AXI_ADDR_WIDTH'(24'h020008),
    parameter logic [AXI_ADDR_WIDTH-1:0] CMD_FIFO_STATUS_ADDR =
        AXI_ADDR_WIDTH'(24'h020010)
) (
    input  logic                          clk,
    input  logic                          reset_n,

    input  logic [AXI_ID_WIDTH-1:0]       s_axi_awid,
    input  logic [AXI_ADDR_WIDTH-1:0]     s_axi_awaddr,
    input  logic [7:0]                    s_axi_awlen,
    input  logic [2:0]                    s_axi_awsize,
    input  logic [1:0]                    s_axi_awburst,
    input  logic                          s_axi_awlock,
    input  logic [3:0]                    s_axi_awcache,
    input  logic [2:0]                    s_axi_awprot,
    input  logic [3:0]                    s_axi_awqos,
    input  logic                          s_axi_awvalid,
    output logic                          s_axi_awready,

    input  logic [63:0]                   s_axi_wdata,
    input  logic [7:0]                    s_axi_wstrb,
    input  logic                          s_axi_wlast,
    input  logic                          s_axi_wvalid,
    output logic                          s_axi_wready,

    output logic [AXI_ID_WIDTH-1:0]       s_axi_bid,
    output logic [1:0]                    s_axi_bresp,
    output logic                          s_axi_bvalid,
    input  logic                          s_axi_bready,

    input  logic [AXI_ID_WIDTH-1:0]       s_axi_arid,
    input  logic [AXI_ADDR_WIDTH-1:0]     s_axi_araddr,
    input  logic [7:0]                    s_axi_arlen,
    input  logic [2:0]                    s_axi_arsize,
    input  logic [1:0]                    s_axi_arburst,
    input  logic                          s_axi_arlock,
    input  logic [3:0]                    s_axi_arcache,
    input  logic [2:0]                    s_axi_arprot,
    input  logic [3:0]                    s_axi_arqos,
    input  logic                          s_axi_arvalid,
    output logic                          s_axi_arready,

    output logic [AXI_ID_WIDTH-1:0]       s_axi_rid,
    output logic [63:0]                   s_axi_rdata,
    output logic [1:0]                    s_axi_rresp,
    output logic                          s_axi_rlast,
    output logic                          s_axi_rvalid,
    input  logic                          s_axi_rready,

    output logic                          cmd_valid_o,
    input  logic                          cmd_ready_i,
    output logic [63:0]                   cmd_data_o,
    output logic                          cmd_first_o,
    output logic                          cmd_last_o,

    input  logic                          cmd_rsp_valid_i,
    output logic                          cmd_rsp_ready_o,
    input  logic [63:0]                   cmd_rsp_data_i,

    input  logic                          protocol_error_clear_i,
    output logic                          cmd_ingress_idle_o
);

    localparam logic [1:0] AXI_RESP_OKAY   = 2'b00;
    localparam logic [1:0] AXI_RESP_SLVERR = 2'b10;
    localparam logic [1:0] AXI_BURST_FIXED = 2'b00;
    localparam logic [1:0] AXI_BURST_INCR  = 2'b01;
    localparam logic [2:0] AXI_SIZE_8B     = 3'b011;
    localparam int unsigned MAX_BURST_BEATS = 16;
    localparam int unsigned INGRESS_PTR_W =
        (INGRESS_DEPTH <= 1) ? 1 : $clog2(INGRESS_DEPTH);
    localparam int unsigned INGRESS_CNT_W =
        (INGRESS_DEPTH <= 1) ? 1 : $clog2(INGRESS_DEPTH + 1);
    localparam int unsigned RSP_PTR_W =
        (CMD_RSP_DEPTH <= 1) ? 1 : $clog2(CMD_RSP_DEPTH);
    localparam int unsigned RSP_CNT_W =
        (CMD_RSP_DEPTH <= 1) ? 1 : $clog2(CMD_RSP_DEPTH + 1);

    initial begin
        if (INGRESS_DEPTH < MAX_BURST_BEATS) begin
            $error("INGRESS_DEPTH must be at least 16 beats");
        end
        if (CMD_RSP_DEPTH < 8) begin
            $error("CMD_RSP_DEPTH must be at least 8 entries");
        end
    end

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

    function automatic [RSP_PTR_W-1:0] rsp_ptr_inc(
        input logic [RSP_PTR_W-1:0] base
    );
        begin
            if (base == RSP_PTR_W'(CMD_RSP_DEPTH - 1)) begin
                rsp_ptr_inc = '0;
            end else begin
                rsp_ptr_inc = base + RSP_PTR_W'(1);
            end
        end
    endfunction

    logic [63:0] staging_mem [0:MAX_BURST_BEATS-1];
    logic [63:0] ingress_mem [0:INGRESS_DEPTH-1];
    logic [63:0] rsp_mem [0:CMD_RSP_DEPTH-1];

    logic [INGRESS_PTR_W-1:0] ingress_wptr_q;
    logic [INGRESS_PTR_W-1:0] ingress_rptr_q;
    logic [INGRESS_CNT_W-1:0] ingress_count_q;

    logic [RSP_PTR_W-1:0] rsp_wptr_q;
    logic [RSP_PTR_W-1:0] rsp_rptr_q;
    logic [RSP_CNT_W-1:0] rsp_count_q;

    logic                          wr_active_q;
    logic                          wr_finalize_q;
    logic                          wr_addr_is_cmd_q;
    logic                          wr_reservation_valid_q;
    logic                          wr_txn_error_q;
    logic [8:0]                    wr_expected_beats_q;
    logic [8:0]                    wr_received_beats_q;
    logic [7:0]                    wr_reserved_beats_q;
    logic [AXI_ID_WIDTH-1:0]       wr_id_q;

    logic                          protocol_error_q;

    typedef enum logic [1:0] {
        CFE_SEND_LOW,
        CFE_SEND_HIGH,
        CFE_WAIT_RESPONSE
    } cfe_state_t;
    cfe_state_t cfe_state_q;

    logic                          rsp_read_wait_q;
    logic                          rdata_is_rsp_q;

    logic [8:0] aw_beats_w;
    logic [8:0] ingress_free_unreserved_w;
    logic [8:0] ingress_free_visible_w;
    logic       aw_addr_is_cmd_w;
    logic       aw_format_ok_w;
    logic       aw_has_capacity_w;
    logic       wr_last_expected_w;
    logic       wr_current_beat_error_w;
    logic       ingress_commit_w;
    logic       ingress_pop_cmd_w;
    logic       rsp_push_w;
    logic       rsp_pop_w;
    logic       ar_format_ok_w;
    logic [63:0] fifo_status_w;
    logic       unused_axi_attributes;

    assign unused_axi_attributes = ^{
        s_axi_awcache,
        s_axi_awprot,
        s_axi_awqos,
        s_axi_arcache,
        s_axi_arprot,
        s_axi_arqos
    };

    assign aw_beats_w = {1'b0, s_axi_awlen} + 9'd1;
    assign aw_addr_is_cmd_w = (s_axi_awaddr == CMD_FIFO_DATA_ADDR);
    assign aw_format_ok_w =
        aw_addr_is_cmd_w &&
        (s_axi_awsize == AXI_SIZE_8B) &&
        (s_axi_awburst == AXI_BURST_FIXED) &&
        !s_axi_awlock &&
        (aw_beats_w >= 9'd2) &&
        (aw_beats_w <= 9'd16) &&
        (aw_beats_w[0] == 1'b0);

    assign ingress_free_unreserved_w =
        9'(INGRESS_DEPTH) - 9'(ingress_count_q);
    assign ingress_free_visible_w =
        ingress_free_unreserved_w - 9'(wr_reserved_beats_q);
    assign aw_has_capacity_w =
        (ingress_free_unreserved_w >= aw_beats_w);

    /*
     * Unsupported writes are still accepted so the slave can drain their W
     * channel and return SLVERR.  A valid command burst waits until its full
     * storage requirement can be reserved.
     */
    assign s_axi_awready =
        reset_n &&
        !wr_active_q &&
        !wr_finalize_q &&
        !s_axi_bvalid &&
        (!aw_format_ok_w || aw_has_capacity_w);

    assign s_axi_wready = reset_n && wr_active_q;
    assign s_axi_bid    = wr_id_q;

    assign wr_last_expected_w =
        ((wr_received_beats_q + 9'd1) == wr_expected_beats_q);
    assign wr_current_beat_error_w =
        (s_axi_wstrb != 8'hff) ||
        (s_axi_wlast != wr_last_expected_w);

    assign ingress_commit_w =
        wr_finalize_q &&
        wr_reservation_valid_q &&
        !wr_txn_error_q;

    assign cmd_valid_o =
        (ingress_count_q >= INGRESS_CNT_W'(2)) &&
        ((cfe_state_q == CFE_SEND_LOW) ||
         (cfe_state_q == CFE_SEND_HIGH));
    assign cmd_data_o =
        (cfe_state_q == CFE_SEND_HIGH) ?
        ingress_mem[ingress_ptr_add(ingress_rptr_q, 1)] :
        ingress_mem[ingress_rptr_q];
    assign cmd_first_o = cmd_valid_o && (cfe_state_q == CFE_SEND_LOW);
    assign cmd_last_o  = cmd_valid_o && (cfe_state_q == CFE_SEND_HIGH);

    assign rsp_pop_w =
        s_axi_rvalid &&
        s_axi_rready &&
        rdata_is_rsp_q;
    assign cmd_rsp_ready_o =
        (cfe_state_q == CFE_WAIT_RESPONSE) &&
        ((rsp_count_q < RSP_CNT_W'(CMD_RSP_DEPTH)) || rsp_pop_w);
    assign rsp_push_w = cmd_rsp_valid_i && cmd_rsp_ready_o;
    assign ingress_pop_cmd_w = rsp_push_w;

    assign cmd_ingress_idle_o =
        !wr_active_q &&
        !wr_finalize_q &&
        (ingress_count_q == '0) &&
        (cfe_state_q == CFE_SEND_LOW);

    assign ar_format_ok_w =
        (s_axi_arlen == 8'd0) &&
        (s_axi_arsize == AXI_SIZE_8B) &&
        (s_axi_arburst == AXI_BURST_INCR) &&
        !s_axi_arlock &&
        (s_axi_araddr[2:0] == 3'b000);
    assign s_axi_arready =
        reset_n &&
        !rsp_read_wait_q &&
        !s_axi_rvalid;

    assign fifo_status_w = {
        44'd0,
        protocol_error_q,
        (rsp_count_q == RSP_CNT_W'(CMD_RSP_DEPTH)),
        (ingress_free_visible_w == 9'd0),
        (wr_active_q &&
         wr_reservation_valid_q &&
         wr_received_beats_q[0]),
        8'(rsp_count_q),
        ingress_free_visible_w[7:0]
    };

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            wr_active_q            <= 1'b0;
            wr_finalize_q          <= 1'b0;
            wr_addr_is_cmd_q       <= 1'b0;
            wr_reservation_valid_q <= 1'b0;
            wr_txn_error_q         <= 1'b0;
            wr_expected_beats_q    <= '0;
            wr_received_beats_q    <= '0;
            wr_reserved_beats_q    <= '0;
            wr_id_q                <= '0;
            s_axi_bresp            <= AXI_RESP_OKAY;
            s_axi_bvalid           <= 1'b0;
        end else begin
            if (s_axi_bvalid && s_axi_bready) begin
                s_axi_bvalid <= 1'b0;
            end

            if (s_axi_awvalid && s_axi_awready) begin
                wr_active_q            <= 1'b1;
                wr_finalize_q          <= 1'b0;
                wr_addr_is_cmd_q       <= aw_addr_is_cmd_w;
                wr_reservation_valid_q <= aw_format_ok_w;
                wr_txn_error_q         <= !aw_format_ok_w;
                wr_expected_beats_q    <= aw_beats_w;
                wr_received_beats_q    <= 9'd0;
                wr_reserved_beats_q    <=
                    aw_format_ok_w ? aw_beats_w[7:0] : 8'd0;
                wr_id_q                <= s_axi_awid;
            end

            if (s_axi_wvalid && s_axi_wready) begin
                if (wr_reservation_valid_q &&
                    (wr_received_beats_q < 9'd16)) begin
                    staging_mem[wr_received_beats_q[3:0]] <= s_axi_wdata;
                end

                wr_received_beats_q <= wr_received_beats_q + 9'd1;
                if (wr_current_beat_error_w) begin
                    wr_txn_error_q <= 1'b1;
                end

                if (wr_last_expected_w) begin
                    wr_active_q    <= 1'b0;
                    wr_finalize_q  <= 1'b1;
                    wr_txn_error_q <=
                        wr_txn_error_q || wr_current_beat_error_w;
                end
            end

            if (wr_finalize_q) begin
                wr_finalize_q          <= 1'b0;
                wr_reservation_valid_q <= 1'b0;
                wr_reserved_beats_q    <= 8'd0;
                s_axi_bresp            <=
                    (wr_reservation_valid_q && !wr_txn_error_q) ?
                    AXI_RESP_OKAY : AXI_RESP_SLVERR;
                s_axi_bvalid           <= 1'b1;
            end
        end
    end

    integer commit_i;
    always_ff @(posedge clk) begin
        if (!reset_n) begin
            ingress_wptr_q  <= '0;
            ingress_rptr_q  <= '0;
            ingress_count_q <= '0;
        end else begin
            if (ingress_commit_w) begin
                for (commit_i = 0;
                     commit_i < MAX_BURST_BEATS;
                     commit_i = commit_i + 1) begin
                    if (commit_i < wr_reserved_beats_q) begin
                        ingress_mem[
                            ingress_ptr_add(ingress_wptr_q, commit_i)
                        ] <= staging_mem[commit_i];
                    end
                end
                ingress_wptr_q <=
                    ingress_ptr_add(
                        ingress_wptr_q,
                        int'(wr_reserved_beats_q)
                    );
            end

            if (ingress_pop_cmd_w) begin
                ingress_rptr_q <=
                    ingress_ptr_add(ingress_rptr_q, 2);
            end

            case ({ingress_commit_w, ingress_pop_cmd_w})
                2'b10:
                    ingress_count_q <=
                        ingress_count_q +
                        INGRESS_CNT_W'(wr_reserved_beats_q);
                2'b01:
                    ingress_count_q <=
                        ingress_count_q - INGRESS_CNT_W'(2);
                2'b11:
                    ingress_count_q <=
                        ingress_count_q +
                        INGRESS_CNT_W'(wr_reserved_beats_q) -
                        INGRESS_CNT_W'(2);
                default:
                    ingress_count_q <= ingress_count_q;
            endcase
        end
    end

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            cfe_state_q <= CFE_SEND_LOW;
        end else begin
            case (cfe_state_q)
                CFE_SEND_LOW: begin
                    if (cmd_valid_o && cmd_ready_i) begin
                        cfe_state_q <= CFE_SEND_HIGH;
                    end
                end

                CFE_SEND_HIGH: begin
                    if (cmd_valid_o && cmd_ready_i) begin
                        cfe_state_q <= CFE_WAIT_RESPONSE;
                    end
                end

                CFE_WAIT_RESPONSE: begin
                    if (rsp_push_w) begin
                        cfe_state_q <= CFE_SEND_LOW;
                    end
                end

                default: begin
                    cfe_state_q <= CFE_SEND_LOW;
                end
            endcase
        end
    end

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            rsp_wptr_q  <= '0;
            rsp_rptr_q  <= '0;
            rsp_count_q <= '0;
        end else begin
            if (rsp_push_w) begin
                rsp_mem[rsp_wptr_q] <= cmd_rsp_data_i;
                rsp_wptr_q <= rsp_ptr_inc(rsp_wptr_q);
            end

            if (rsp_pop_w) begin
                rsp_rptr_q <= rsp_ptr_inc(rsp_rptr_q);
            end

            case ({rsp_push_w, rsp_pop_w})
                2'b10:
                    rsp_count_q <= rsp_count_q + RSP_CNT_W'(1);
                2'b01:
                    rsp_count_q <= rsp_count_q - RSP_CNT_W'(1);
                default:
                    rsp_count_q <= rsp_count_q;
            endcase
        end
    end

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            protocol_error_q <= 1'b0;
        end else begin
            if (protocol_error_clear_i) begin
                protocol_error_q <= 1'b0;
            end

            if (wr_finalize_q &&
                wr_addr_is_cmd_q &&
                (!wr_reservation_valid_q || wr_txn_error_q)) begin
                protocol_error_q <= 1'b1;
            end
        end
    end

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            s_axi_rid       <= '0;
            s_axi_rdata     <= 64'd0;
            s_axi_rresp     <= AXI_RESP_OKAY;
            s_axi_rlast     <= 1'b0;
            s_axi_rvalid    <= 1'b0;
            rsp_read_wait_q <= 1'b0;
            rdata_is_rsp_q  <= 1'b0;
        end else begin
            if (s_axi_rvalid && s_axi_rready) begin
                s_axi_rvalid   <= 1'b0;
                s_axi_rlast    <= 1'b0;
                rdata_is_rsp_q <= 1'b0;
            end

            if (s_axi_arvalid && s_axi_arready) begin
                s_axi_rid      <= s_axi_arid;
                s_axi_rlast    <= 1'b1;
                rdata_is_rsp_q <= 1'b0;

                if (!ar_format_ok_w) begin
                    s_axi_rdata  <= 64'd0;
                    s_axi_rresp  <= AXI_RESP_SLVERR;
                    s_axi_rvalid <= 1'b1;
                end else if (s_axi_araddr == CMD_FIFO_STATUS_ADDR) begin
                    s_axi_rdata  <= fifo_status_w;
                    s_axi_rresp  <= AXI_RESP_OKAY;
                    s_axi_rvalid <= 1'b1;
                end else if (s_axi_araddr == CMD_RSP_FIFO_ADDR) begin
                    if (rsp_count_q != '0) begin
                        s_axi_rdata     <= rsp_mem[rsp_rptr_q];
                        s_axi_rresp     <= AXI_RESP_OKAY;
                        s_axi_rvalid    <= 1'b1;
                        rdata_is_rsp_q  <= 1'b1;
                    end else begin
                        rsp_read_wait_q <= 1'b1;
                        s_axi_rlast     <= 1'b0;
                    end
                end else begin
                    s_axi_rdata  <= 64'd0;
                    s_axi_rresp  <= AXI_RESP_SLVERR;
                    s_axi_rvalid <= 1'b1;
                end
            end

            if (rsp_read_wait_q && (rsp_count_q != '0)) begin
                s_axi_rdata     <= rsp_mem[rsp_rptr_q];
                s_axi_rresp     <= AXI_RESP_OKAY;
                s_axi_rlast     <= 1'b1;
                s_axi_rvalid    <= 1'b1;
                rsp_read_wait_q <= 1'b0;
                rdata_is_rsp_q  <= 1'b1;
            end
        end
    end

endmodule
