`timescale 1ns/1ps

module tb_axi_memory_model #(
    parameter int unsigned AXI_ID_W = 8,
    parameter int unsigned AXI_ADDR_W = 40,
    parameter int unsigned MEM_BYTES = 1 << 18
) (
    input  logic                       clk_i,
    input  logic                       reset_n,
    input  logic                       backpressure_enable_i,

    input  logic [AXI_ID_W-1:0]        s_axi_awid_i,
    input  logic [AXI_ADDR_W-1:0]      s_axi_awaddr_i,
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

    output logic [AXI_ID_W-1:0]        s_axi_bid_o,
    output logic [1:0]                 s_axi_bresp_o,
    output logic                       s_axi_bvalid_o,
    input  logic                       s_axi_bready_i,

    input  logic [AXI_ID_W-1:0]        s_axi_arid_i,
    input  logic [AXI_ADDR_W-1:0]      s_axi_araddr_i,
    input  logic [7:0]                 s_axi_arlen_i,
    input  logic [2:0]                 s_axi_arsize_i,
    input  logic [1:0]                 s_axi_arburst_i,
    input  logic                       s_axi_arlock_i,
    input  logic [3:0]                 s_axi_arcache_i,
    input  logic [2:0]                 s_axi_arprot_i,
    input  logic [3:0]                 s_axi_arqos_i,
    input  logic                       s_axi_arvalid_i,
    output logic                       s_axi_arready_o,

    output logic [AXI_ID_W-1:0]        s_axi_rid_o,
    output logic [63:0]                s_axi_rdata_o,
    output logic [1:0]                 s_axi_rresp_o,
    output logic                       s_axi_rlast_o,
    output logic                       s_axi_rvalid_o,
    input  logic                       s_axi_rready_i,

    output logic [31:0]                read_handshake_count_o,
    output logic [31:0]                write_handshake_count_o,
    output logic                       protocol_error_o
);

    localparam logic [1:0] AXI_RESP_OKAY = 2'b00;
    localparam logic [1:0] AXI_RESP_SLVERR = 2'b10;
    localparam logic [1:0] AXI_BURST_INCR = 2'b01;
    localparam int unsigned MEM_WORDS = MEM_BYTES / 8;
    localparam int unsigned MEM_INDEX_W =
        MEM_WORDS > 1 ? $clog2(MEM_WORDS) : 1;

    logic [63:0] mem [0:MEM_WORDS-1];
    logic [31:0] cycle_count_q;

    logic aw_hold_valid_q;
    logic [AXI_ID_W-1:0] aw_hold_id_q;
    logic [AXI_ADDR_W-1:0] aw_hold_addr_q;
    logic aw_hold_error_q;
    logic w_hold_valid_q;
    logic [63:0] w_hold_data_q;
    logic [7:0] w_hold_strb_q;
    logic w_hold_error_q;

    logic read_pending_q;
    logic [1:0] read_delay_q;
    logic [AXI_ID_W-1:0] read_id_q;
    logic [AXI_ADDR_W-1:0] read_addr_q;
    logic read_error_q;

    logic aw_gate;
    logic w_gate;
    logic ar_gate;
    logic aw_format_error;
    logic w_format_error;
    logic ar_format_error;

    integer byte_index;

    task automatic write_byte(
        input longint unsigned address,
        input logic [7:0] value
    );
        if (address >= 64'(MEM_BYTES)) begin
            $fatal(
                1,
                "system-bus memory preload address 0x%0h is outside the model",
                address
            );
        end
        mem[MEM_INDEX_W'(address >> 3)]
           [address[2:0]*8 +: 8] = value;
    endtask

    task automatic write_u32(
        input longint unsigned address,
        input logic [31:0] value
    );
        for (int unsigned index = 0; index < 4; index++) begin
            write_byte(address + 64'(index), value[index*8 +: 8]);
        end
    endtask

    task automatic write_u64(
        input longint unsigned address,
        input logic [63:0] value
    );
        for (int unsigned index = 0; index < 8; index++) begin
            write_byte(address + 64'(index), value[index*8 +: 8]);
        end
    endtask

    function automatic logic [63:0] read_u64(
        input longint unsigned address
    );
        logic [63:0] value;
        longint unsigned byte_address;
        value = 64'd0;
        for (int unsigned index = 0; index < 8; index++) begin
            byte_address = address + 64'(index);
            if (byte_address < 64'(MEM_BYTES)) begin
                value[index*8 +: 8] =
                    mem[MEM_INDEX_W'(byte_address >> 3)]
                       [byte_address[2:0]*8 +: 8];
            end
        end
        return value;
    endfunction

    assign aw_gate = !backpressure_enable_i || (cycle_count_q[1:0] != 2'b00);
    assign w_gate = !backpressure_enable_i || (cycle_count_q[2:0] != 3'b001);
    assign ar_gate = !backpressure_enable_i || (cycle_count_q[1:0] != 2'b10);

    assign aw_format_error =
        (s_axi_awlen_i != 8'd0) ||
        (s_axi_awsize_i != 3'd3) ||
        (s_axi_awburst_i != AXI_BURST_INCR) ||
        s_axi_awlock_i ||
        (s_axi_awaddr_i[2:0] != 3'd0) ||
        (s_axi_awaddr_i > AXI_ADDR_W'(MEM_BYTES - 8));
    assign w_format_error = !s_axi_wlast_i;
    assign ar_format_error =
        (s_axi_arlen_i != 8'd0) ||
        (s_axi_arsize_i != 3'd3) ||
        (s_axi_arburst_i != AXI_BURST_INCR) ||
        s_axi_arlock_i ||
        (s_axi_araddr_i[2:0] != 3'd0) ||
        (s_axi_araddr_i > AXI_ADDR_W'(MEM_BYTES - 8));

    assign s_axi_awready_o =
        reset_n && !aw_hold_valid_q && !s_axi_bvalid_o && aw_gate;
    assign s_axi_wready_o =
        reset_n && !w_hold_valid_q && !s_axi_bvalid_o && w_gate;
    assign s_axi_arready_o =
        reset_n && !read_pending_q && !s_axi_rvalid_o && ar_gate;

    always_ff @(posedge clk_i or negedge reset_n) begin
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
            s_axi_bid_o <= '0;
            s_axi_bresp_o <= AXI_RESP_OKAY;
            s_axi_bvalid_o <= 1'b0;
            s_axi_rid_o <= '0;
            s_axi_rdata_o <= 64'd0;
            s_axi_rresp_o <= AXI_RESP_OKAY;
            s_axi_rlast_o <= 1'b1;
            s_axi_rvalid_o <= 1'b0;
            read_handshake_count_o <= 32'd0;
            write_handshake_count_o <= 32'd0;
            protocol_error_o <= 1'b0;
        end else begin
            cycle_count_q <= cycle_count_q + 1'b1;

            if (s_axi_bvalid_o && s_axi_bready_i) begin
                s_axi_bvalid_o <= 1'b0;
            end
            if (s_axi_rvalid_o && s_axi_rready_i) begin
                s_axi_rvalid_o <= 1'b0;
            end

            if (s_axi_awvalid_i && s_axi_awready_o) begin
                aw_hold_valid_q <= 1'b1;
                aw_hold_id_q <= s_axi_awid_i;
                aw_hold_addr_q <= s_axi_awaddr_i;
                aw_hold_error_q <= aw_format_error;
            end
            if (s_axi_wvalid_i && s_axi_wready_o) begin
                w_hold_valid_q <= 1'b1;
                w_hold_data_q <= s_axi_wdata_i;
                w_hold_strb_q <= s_axi_wstrb_i;
                w_hold_error_q <= w_format_error;
            end

            if (aw_hold_valid_q && w_hold_valid_q && !s_axi_bvalid_o) begin
                s_axi_bid_o <= aw_hold_id_q;
                s_axi_bresp_o <=
                    (aw_hold_error_q || w_hold_error_q) ?
                    AXI_RESP_SLVERR : AXI_RESP_OKAY;
                s_axi_bvalid_o <= 1'b1;
                if (aw_hold_error_q || w_hold_error_q) begin
                    protocol_error_o <= 1'b1;
                end else begin
                    for (byte_index = 0; byte_index < 8;
                        byte_index = byte_index + 1) begin
                        if (w_hold_strb_q[byte_index]) begin
                            mem[MEM_INDEX_W'(aw_hold_addr_q >> 3)]
                               [byte_index*8 +: 8] <=
                                w_hold_data_q[byte_index*8 +: 8];
                        end
                    end
                    write_handshake_count_o <=
                        write_handshake_count_o + 1'b1;
                end
                aw_hold_valid_q <= 1'b0;
                w_hold_valid_q <= 1'b0;
            end

            if (s_axi_arvalid_i && s_axi_arready_o) begin
                read_pending_q <= 1'b1;
                read_delay_q <= backpressure_enable_i ? 2'd2 : 2'd0;
                read_id_q <= s_axi_arid_i;
                read_addr_q <= s_axi_araddr_i;
                read_error_q <= ar_format_error;
                read_handshake_count_o <= read_handshake_count_o + 1'b1;
            end

            if (read_pending_q && !s_axi_rvalid_o) begin
                if (read_delay_q != 2'd0) begin
                    read_delay_q <= read_delay_q - 1'b1;
                end else begin
                    s_axi_rid_o <= read_id_q;
                    s_axi_rdata_o <= read_error_q ?
                        64'd0 : read_u64(64'(read_addr_q));
                    s_axi_rresp_o <= read_error_q ?
                        AXI_RESP_SLVERR : AXI_RESP_OKAY;
                    s_axi_rlast_o <= 1'b1;
                    s_axi_rvalid_o <= 1'b1;
                    read_pending_q <= 1'b0;
                    if (read_error_q) begin
                        protocol_error_o <= 1'b1;
                    end
                end
            end
        end
    end

    logic unused_axi_attributes;
    assign unused_axi_attributes = ^{
        s_axi_awcache_i,
        s_axi_awprot_i,
        s_axi_awqos_i,
        s_axi_arcache_i,
        s_axi_arprot_i,
        s_axi_arqos_i
    };

    initial begin
        if ((MEM_BYTES < 8) || ((MEM_BYTES % 8) != 0)) begin
            $error("MEM_BYTES must be a positive multiple of eight");
        end
    end

endmodule
