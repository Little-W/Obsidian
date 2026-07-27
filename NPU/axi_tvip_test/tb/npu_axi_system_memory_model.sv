`timescale 1ns/1ps

module npu_axi_system_memory_model #(
    parameter int unsigned AXI_ID_WIDTH = 8,
    parameter int unsigned AXI_ADDR_WIDTH = 40,
    parameter int unsigned MEMORY_BYTES = 1 << 20
) (
    input  logic                         clk,
    input  logic                         reset_n,
    npu_single_core_system_if            system_if,

    input  logic [AXI_ID_WIDTH-1:0]      s_axi_awid,
    input  logic [AXI_ADDR_WIDTH-1:0]    s_axi_awaddr,
    input  logic [7:0]                   s_axi_awlen,
    input  logic [2:0]                   s_axi_awsize,
    input  logic [1:0]                   s_axi_awburst,
    input  logic                         s_axi_awlock,
    input  logic [3:0]                   s_axi_awcache,
    input  logic [2:0]                   s_axi_awprot,
    input  logic [3:0]                   s_axi_awqos,
    input  logic                         s_axi_awvalid,
    output logic                         s_axi_awready,

    input  logic [63:0]                  s_axi_wdata,
    input  logic [7:0]                   s_axi_wstrb,
    input  logic                         s_axi_wlast,
    input  logic                         s_axi_wvalid,
    output logic                         s_axi_wready,

    output logic [AXI_ID_WIDTH-1:0]      s_axi_bid,
    output logic [1:0]                   s_axi_bresp,
    output logic                         s_axi_bvalid,
    input  logic                         s_axi_bready,

    input  logic [AXI_ID_WIDTH-1:0]      s_axi_arid,
    input  logic [AXI_ADDR_WIDTH-1:0]    s_axi_araddr,
    input  logic [7:0]                   s_axi_arlen,
    input  logic [2:0]                   s_axi_arsize,
    input  logic [1:0]                   s_axi_arburst,
    input  logic                         s_axi_arlock,
    input  logic [3:0]                   s_axi_arcache,
    input  logic [2:0]                   s_axi_arprot,
    input  logic [3:0]                   s_axi_arqos,
    input  logic                         s_axi_arvalid,
    output logic                         s_axi_arready,

    output logic [AXI_ID_WIDTH-1:0]      s_axi_rid,
    output logic [63:0]                  s_axi_rdata,
    output logic [1:0]                   s_axi_rresp,
    output logic                         s_axi_rlast,
    output logic                         s_axi_rvalid,
    input  logic                         s_axi_rready
);
    localparam logic [1:0] AXI_RESP_OKAY = 2'b00;
    localparam logic [1:0] AXI_RESP_SLVERR = 2'b10;
    localparam logic [1:0] AXI_BURST_INCR = 2'b01;
    localparam int unsigned MEMORY_ADDR_WIDTH = $clog2(MEMORY_BYTES);

    logic [31:0] cycle_count_q;

    logic aw_hold_valid_q;
    logic [AXI_ID_WIDTH-1:0] aw_hold_id_q;
    logic [MEMORY_ADDR_WIDTH-1:0] aw_hold_addr_q;
    logic aw_hold_error_q;

    logic w_hold_valid_q;
    logic [63:0] w_hold_data_q;
    logic [7:0] w_hold_strb_q;
    logic w_hold_error_q;

    logic read_pending_q;
    logic [1:0] read_delay_q;
    logic [AXI_ID_WIDTH-1:0] read_id_q;
    logic [MEMORY_ADDR_WIDTH-1:0] read_addr_q;
    logic read_error_q;

    logic aw_gate;
    logic w_gate;
    logic ar_gate;
    logic aw_format_error;
    logic w_format_error;
    logic ar_format_error;

    assign aw_gate =
        !system_if.system_memory_backpressure_enable ||
        (cycle_count_q[1:0] != 2'b00);
    assign w_gate =
        !system_if.system_memory_backpressure_enable ||
        (cycle_count_q[2:0] != 3'b001);
    assign ar_gate =
        !system_if.system_memory_backpressure_enable ||
        (cycle_count_q[1:0] != 2'b10);

    assign aw_format_error =
        (s_axi_awlen != 8'd0) ||
        (s_axi_awsize != 3'd3) ||
        (s_axi_awburst != AXI_BURST_INCR) ||
        s_axi_awlock ||
        (s_axi_awaddr[2:0] != 3'd0) ||
        (s_axi_awaddr > AXI_ADDR_WIDTH'(MEMORY_BYTES - 8));
    assign w_format_error = !s_axi_wlast;
    assign ar_format_error =
        (s_axi_arlen != 8'd0) ||
        (s_axi_arsize != 3'd3) ||
        (s_axi_arburst != AXI_BURST_INCR) ||
        s_axi_arlock ||
        (s_axi_araddr[2:0] != 3'd0) ||
        (s_axi_araddr > AXI_ADDR_WIDTH'(MEMORY_BYTES - 8));

    assign s_axi_awready =
        reset_n && !aw_hold_valid_q && !s_axi_bvalid && aw_gate;
    assign s_axi_wready =
        reset_n && !w_hold_valid_q && !s_axi_bvalid && w_gate;
    assign s_axi_arready =
        reset_n && !read_pending_q && !s_axi_rvalid && ar_gate;

    always_ff @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
            cycle_count_q <= 32'd0;

            aw_hold_valid_q <= 1'b0;
            aw_hold_id_q <= '0;
            aw_hold_addr_q <= '0;
            aw_hold_error_q <= 1'b0;

            w_hold_valid_q <= 1'b0;
            w_hold_data_q <= 64'd0;
            w_hold_strb_q <= 8'd0;
            w_hold_error_q <= 1'b0;

            read_pending_q <= 1'b0;
            read_delay_q <= 2'd0;
            read_id_q <= '0;
            read_addr_q <= '0;
            read_error_q <= 1'b0;

            s_axi_bid <= '0;
            s_axi_bresp <= AXI_RESP_OKAY;
            s_axi_bvalid <= 1'b0;

            s_axi_rid <= '0;
            s_axi_rdata <= 64'd0;
            s_axi_rresp <= AXI_RESP_OKAY;
            s_axi_rlast <= 1'b1;
            s_axi_rvalid <= 1'b0;

            system_if.system_memory_read_handshakes <= 32'd0;
            system_if.system_memory_aw_handshakes <= 32'd0;
            system_if.system_memory_write_handshakes <= 32'd0;
            system_if.system_memory_protocol_error <= 1'b0;
        end
        else begin
            cycle_count_q <= cycle_count_q + 1'b1;

            if (s_axi_bvalid && s_axi_bready) begin
                s_axi_bvalid <= 1'b0;
            end
            if (s_axi_rvalid && s_axi_rready) begin
                s_axi_rvalid <= 1'b0;
            end

            if (s_axi_awvalid && s_axi_awready) begin
                system_if.system_memory_aw_handshakes <=
                    system_if.system_memory_aw_handshakes + 1'b1;
                aw_hold_valid_q <= 1'b1;
                aw_hold_id_q <= s_axi_awid;
                aw_hold_addr_q <=
                    s_axi_awaddr[MEMORY_ADDR_WIDTH-1:0];
                aw_hold_error_q <= aw_format_error;
            end
            if (s_axi_wvalid && s_axi_wready) begin
                w_hold_valid_q <= 1'b1;
                w_hold_data_q <= s_axi_wdata;
                w_hold_strb_q <= s_axi_wstrb;
                w_hold_error_q <= w_format_error;
            end

            if (aw_hold_valid_q && w_hold_valid_q && !s_axi_bvalid) begin
                s_axi_bid <= aw_hold_id_q;
                s_axi_bresp <=
                    (aw_hold_error_q || w_hold_error_q) ?
                    AXI_RESP_SLVERR : AXI_RESP_OKAY;
                s_axi_bvalid <= 1'b1;
                if (aw_hold_error_q || w_hold_error_q) begin
                    system_if.system_memory_protocol_error <= 1'b1;
                end
                else begin
                    for (int unsigned byte_index = 0;
                         byte_index < 8;
                         byte_index++) begin
                        if (w_hold_strb_q[byte_index]) begin
                            system_if.system_memory[
                                int'(aw_hold_addr_q) + byte_index
                            ] <= w_hold_data_q[byte_index*8 +: 8];
                        end
                    end
                    system_if.system_memory_write_handshakes <=
                        system_if.system_memory_write_handshakes + 1'b1;
                end
                aw_hold_valid_q <= 1'b0;
                w_hold_valid_q <= 1'b0;
            end

            if (s_axi_arvalid && s_axi_arready) begin
                read_pending_q <= 1'b1;
                read_delay_q <=
                    system_if.system_memory_backpressure_enable ?
                    2'd2 : 2'd0;
                read_id_q <= s_axi_arid;
                read_addr_q <=
                    s_axi_araddr[MEMORY_ADDR_WIDTH-1:0];
                read_error_q <= ar_format_error;
                system_if.system_memory_read_handshakes <=
                    system_if.system_memory_read_handshakes + 1'b1;
            end

            if (read_pending_q && !s_axi_rvalid) begin
                if (read_delay_q != 2'd0) begin
                    read_delay_q <= read_delay_q - 1'b1;
                end
                else begin
                    s_axi_rid <= read_id_q;
                    s_axi_rdata <= read_error_q ?
                        64'd0 : system_if.read_u64(64'(read_addr_q));
                    s_axi_rresp <= read_error_q ?
                        AXI_RESP_SLVERR : AXI_RESP_OKAY;
                    s_axi_rlast <= 1'b1;
                    s_axi_rvalid <= 1'b1;
                    read_pending_q <= 1'b0;
                    if (read_error_q) begin
                        system_if.system_memory_protocol_error <= 1'b1;
                    end
                end
            end
        end
    end

    logic unused_axi_attributes;
    assign unused_axi_attributes = ^{
        s_axi_awcache,
        s_axi_awprot,
        s_axi_awqos,
        s_axi_arcache,
        s_axi_arprot,
        s_axi_arqos
    };

    initial begin
        if ((MEMORY_BYTES < 8) || ((MEMORY_BYTES % 8) != 0)) begin
            $error("MEMORY_BYTES must be a positive multiple of eight");
        end
    end
endmodule
