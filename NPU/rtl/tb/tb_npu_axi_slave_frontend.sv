`timescale 1ns/1ps

module tb_npu_axi_slave_frontend;

    localparam logic [1:0] AXI_OKAY   = 2'b00;
    localparam logic [1:0] AXI_SLVERR = 2'b10;

    logic clk_i;
    logic reset_n;

    logic [7:0] s_axi_awid;
    logic [23:0] s_axi_awaddr;
    logic [7:0] s_axi_awlen;
    logic [2:0] s_axi_awsize;
    logic [1:0] s_axi_awburst;
    logic s_axi_awlock;
    logic [3:0] s_axi_awcache;
    logic [2:0] s_axi_awprot;
    logic [3:0] s_axi_awqos;
    logic s_axi_awvalid;
    logic s_axi_awready;
    logic [63:0] s_axi_wdata;
    logic [7:0] s_axi_wstrb;
    logic s_axi_wlast;
    logic s_axi_wvalid;
    logic s_axi_wready;
    logic [7:0] s_axi_bid;
    logic [1:0] s_axi_bresp;
    logic s_axi_bvalid;
    logic s_axi_bready;

    logic [7:0] s_axi_arid;
    logic [23:0] s_axi_araddr;
    logic [7:0] s_axi_arlen;
    logic [2:0] s_axi_arsize;
    logic [1:0] s_axi_arburst;
    logic s_axi_arlock;
    logic [3:0] s_axi_arcache;
    logic [2:0] s_axi_arprot;
    logic [3:0] s_axi_arqos;
    logic s_axi_arvalid;
    logic s_axi_arready;
    logic [7:0] s_axi_rid;
    logic [63:0] s_axi_rdata;
    logic [1:0] s_axi_rresp;
    logic s_axi_rlast;
    logic s_axi_rvalid;
    logic s_axi_rready;

    logic cmd_valid;
    logic cmd_ready;
    logic [63:0] cmd_data;
    logic cmd_first;
    logic cmd_last;
    logic cmd_rsp_valid;
    logic cmd_rsp_ready;
    logic [63:0] cmd_rsp_data;

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
    logic [2:0] reg_rsp_status;

    logic l1_req_valid;
    logic l1_req_ready;
    logic l1_req_write;
    logic [19:0] l1_req_addr;
    logic [63:0] l1_req_wdata;
    logic [7:0] l1_req_wstrb;
    logic l1_rsp_valid;
    logic l1_rsp_ready;
    logic [63:0] l1_rsp_rdata;
    logic [2:0] l1_rsp_status;

    logic cfe_enable;
    logic cfe_have_low_q;
    logic [63:0] cfe_low_q;
    logic [31:0] cfe_command_count_q;
    logic [63:0] csr_mem [0:31];
    logic [63:0] l1_mem [0:255];
    logic reg_pending_q;
    logic l1_pending_q;
    logic [63:0] reg_rsp_data_q;
    logic [63:0] l1_rsp_data_q;
    logic [2:0] reg_rsp_status_q;
    logic [2:0] l1_rsp_status_q;
    logic protocol_error;
    logic cmd_ingress_idle;
    logic s_axi_idle;
    logic protocol_error_clear;
    logic ctl_req_valid;
    logic [1:0] ctl_req_op;
    logic [63:0] ctl_req_arg0;
    logic [63:0] ctl_req_arg1;
    logic ctl_cancel;
    logic ctl_rsp_ready;
    logic unused_ctl;
    integer byte_index;

    npu_axi_slave_frontend dut (
        .clk_i,
        .reset_n,
        .s_axi_awid_i(s_axi_awid),
        .s_axi_awaddr_i(s_axi_awaddr),
        .s_axi_awlen_i(s_axi_awlen),
        .s_axi_awsize_i(s_axi_awsize),
        .s_axi_awburst_i(s_axi_awburst),
        .s_axi_awlock_i(s_axi_awlock),
        .s_axi_awcache_i(s_axi_awcache),
        .s_axi_awprot_i(s_axi_awprot),
        .s_axi_awqos_i(s_axi_awqos),
        .s_axi_awvalid_i(s_axi_awvalid),
        .s_axi_awready_o(s_axi_awready),
        .s_axi_wdata_i(s_axi_wdata),
        .s_axi_wstrb_i(s_axi_wstrb),
        .s_axi_wlast_i(s_axi_wlast),
        .s_axi_wvalid_i(s_axi_wvalid),
        .s_axi_wready_o(s_axi_wready),
        .s_axi_bid_o(s_axi_bid),
        .s_axi_bresp_o(s_axi_bresp),
        .s_axi_bvalid_o(s_axi_bvalid),
        .s_axi_bready_i(s_axi_bready),
        .s_axi_arid_i(s_axi_arid),
        .s_axi_araddr_i(s_axi_araddr),
        .s_axi_arlen_i(s_axi_arlen),
        .s_axi_arsize_i(s_axi_arsize),
        .s_axi_arburst_i(s_axi_arburst),
        .s_axi_arlock_i(s_axi_arlock),
        .s_axi_arcache_i(s_axi_arcache),
        .s_axi_arprot_i(s_axi_arprot),
        .s_axi_arqos_i(s_axi_arqos),
        .s_axi_arvalid_i(s_axi_arvalid),
        .s_axi_arready_o(s_axi_arready),
        .s_axi_rid_o(s_axi_rid),
        .s_axi_rdata_o(s_axi_rdata),
        .s_axi_rresp_o(s_axi_rresp),
        .s_axi_rlast_o(s_axi_rlast),
        .s_axi_rvalid_o(s_axi_rvalid),
        .s_axi_rready_i(s_axi_rready),
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
        .reg_rsp_status_i(reg_rsp_status),
        .l1_req_valid_o(l1_req_valid),
        .l1_req_ready_i(l1_req_ready),
        .l1_req_write_o(l1_req_write),
        .l1_req_addr_o(l1_req_addr),
        .l1_req_wdata_o(l1_req_wdata),
        .l1_req_wstrb_o(l1_req_wstrb),
        .l1_rsp_valid_i(l1_rsp_valid),
        .l1_rsp_ready_o(l1_rsp_ready),
        .l1_rsp_rdata_i(l1_rsp_rdata),
        .l1_rsp_status_i(l1_rsp_status),
        .l1_host_access_enable_i(1'b1),
        .core_idle_i(1'b1),
        .debug_frozen_i(1'b0),
        .cmd_accept_enable_i(1'b1),
        .ctl_req_valid_o(ctl_req_valid),
        .ctl_req_ready_i(1'b1),
        .ctl_req_op_o(ctl_req_op),
        .ctl_req_arg0_o(ctl_req_arg0),
        .ctl_req_arg1_o(ctl_req_arg1),
        .ctl_cancel_o(ctl_cancel),
        .ctl_rsp_valid_i(1'b0),
        .ctl_rsp_ready_o(ctl_rsp_ready),
        .ctl_rsp_data_i(64'd0),
        .protocol_error_clear_i(protocol_error_clear),
        .protocol_error_o(protocol_error),
        .cmd_ingress_idle_o(cmd_ingress_idle),
        .s_axi_idle_o(s_axi_idle)
    );

    always #5 clk_i = ~clk_i;

    assign cmd_ready = cfe_enable && !cmd_rsp_valid;
    assign reg_req_ready = !reg_pending_q;
    assign reg_rsp_valid = reg_pending_q;
    assign reg_rsp_rdata = reg_rsp_data_q;
    assign reg_rsp_status = reg_rsp_status_q;
    assign l1_req_ready = !l1_pending_q;
    assign l1_rsp_valid = l1_pending_q;
    assign l1_rsp_rdata = l1_rsp_data_q;
    assign l1_rsp_status = l1_rsp_status_q;
    assign unused_ctl = ^{
        ctl_req_valid, ctl_req_op, ctl_req_arg0,
        ctl_req_arg1, ctl_cancel, ctl_rsp_ready, reg_req_space
    };

    always_ff @(posedge clk_i or negedge reset_n) begin
        if (!reset_n) begin
            cfe_have_low_q <= 1'b0;
            cfe_low_q <= '0;
            cfe_command_count_q <= '0;
            cmd_rsp_valid <= 1'b0;
            cmd_rsp_data <= '0;
            reg_pending_q <= 1'b0;
            l1_pending_q <= 1'b0;
            reg_rsp_data_q <= '0;
            l1_rsp_data_q <= '0;
            reg_rsp_status_q <= '0;
            l1_rsp_status_q <= '0;
        end else begin
            if (cmd_valid && cmd_ready) begin
                if (cmd_first && !cmd_last) begin
                    if (cfe_have_low_q) begin
                        $fatal(1, "CFE model received two low command words");
                    end
                    cfe_have_low_q <= 1'b1;
                    cfe_low_q <= cmd_data;
                end else if (!cmd_first && cmd_last && cfe_have_low_q) begin
                    cfe_have_low_q <= 1'b0;
                    cfe_command_count_q <= cfe_command_count_q + 1;
                    cmd_rsp_valid <= 1'b1;
                    cmd_rsp_data <= {
                        36'd0, 8'd7, 8'd0, cfe_low_q[59:48]
                    };
                end else begin
                    $fatal(1, "CFE model saw invalid first/last markers");
                end
            end
            if (cmd_rsp_valid && cmd_rsp_ready) begin
                cmd_rsp_valid <= 1'b0;
            end

            if (reg_req_valid && reg_req_ready) begin
                if ((reg_req_addr[15:8] != 8'd0) ||
                    (reg_req_addr[2:0] != 3'd0)) begin
                    $fatal(1, "CSR model received an invalid address");
                end
                reg_pending_q <= 1'b1;
                reg_rsp_status_q <= 3'd0;
                reg_rsp_data_q <= csr_mem[reg_req_addr[7:3]];
                if (reg_req_write) begin
                    for (byte_index = 0; byte_index < 8; byte_index++) begin
                        if (reg_req_wstrb[byte_index]) begin
                            csr_mem[reg_req_addr[7:3]][byte_index*8 +: 8] <=
                                reg_req_wdata[byte_index*8 +: 8];
                        end
                    end
                end
            end
            if (reg_pending_q && reg_rsp_ready) begin
                reg_pending_q <= 1'b0;
            end

            if (l1_req_valid && l1_req_ready) begin
                if (l1_req_addr[2:0] != 3'd0) begin
                    $fatal(1, "L1 model received an unaligned address");
                end
                l1_pending_q <= 1'b1;
                if (l1_req_addr[19:3] < 256) begin
                    l1_rsp_status_q <= 3'd0;
                    l1_rsp_data_q <= l1_mem[l1_req_addr[10:3]];
                    if (l1_req_write) begin
                        for (byte_index = 0; byte_index < 8; byte_index++) begin
                            if (l1_req_wstrb[byte_index]) begin
                                l1_mem[l1_req_addr[10:3]][byte_index*8 +: 8] <=
                                    l1_req_wdata[byte_index*8 +: 8];
                            end
                        end
                    end
                end else begin
                    l1_rsp_status_q <= 3'd4;
                    l1_rsp_data_q <= 64'd0;
                end
            end
            if (l1_pending_q && l1_rsp_ready) begin
                l1_pending_q <= 1'b0;
            end
        end
    end

    task automatic check(input logic condition, input string message);
        if (!condition) begin
            $fatal(1, "%s", message);
        end
    endtask

    task automatic axi_write_address(
        input logic [23:0] addr,
        input logic [7:0] len,
        input logic [2:0] size,
        input logic [1:0] burst,
        input logic [7:0] id
    );
        begin
            @(negedge clk_i);
            s_axi_awaddr = addr;
            s_axi_awlen = len;
            s_axi_awsize = size;
            s_axi_awburst = burst;
            s_axi_awid = id;
            s_axi_awvalid = 1'b1;
            do @(posedge clk_i); while (!s_axi_awready);
            @(negedge clk_i);
            s_axi_awvalid = 1'b0;
        end
    endtask

    task automatic axi_write_data(
        input logic [63:0] data,
        input logic [7:0] strb,
        input logic last
    );
        begin
            @(negedge clk_i);
            s_axi_wdata = data;
            s_axi_wstrb = strb;
            s_axi_wlast = last;
            s_axi_wvalid = 1'b1;
            do @(posedge clk_i); while (!s_axi_wready);
            @(negedge clk_i);
            s_axi_wvalid = 1'b0;
        end
    endtask

    task automatic axi_wait_b(
        input logic [1:0] expected_resp,
        input logic [7:0] expected_id
    );
        begin
            s_axi_bready = 1'b1;
            do @(posedge clk_i); while (!s_axi_bvalid);
            check(s_axi_bresp == expected_resp, "unexpected AXI B response");
            check(s_axi_bid == expected_id, "unexpected AXI B ID");
            @(negedge clk_i);
            s_axi_bready = 1'b0;
        end
    endtask

    task automatic axi_read_address(
        input logic [23:0] addr,
        input logic [7:0] len,
        input logic [2:0] size,
        input logic [1:0] burst,
        input logic [7:0] id
    );
        begin
            @(negedge clk_i);
            s_axi_araddr = addr;
            s_axi_arlen = len;
            s_axi_arsize = size;
            s_axi_arburst = burst;
            s_axi_arid = id;
            s_axi_arvalid = 1'b1;
            do @(posedge clk_i); while (!s_axi_arready);
            @(negedge clk_i);
            s_axi_arvalid = 1'b0;
        end
    endtask

    task automatic axi_read_beat(
        output logic [63:0] data,
        input logic [1:0] expected_resp,
        input logic expected_last,
        input logic [7:0] expected_id
    );
        begin
            s_axi_rready = 1'b1;
            do @(posedge clk_i); while (!s_axi_rvalid);
            data = s_axi_rdata;
            check(s_axi_rresp == expected_resp, "unexpected AXI R response");
            check(s_axi_rlast == expected_last, "unexpected AXI RLAST");
            check(s_axi_rid == expected_id, "unexpected AXI R ID");
            @(negedge clk_i);
            s_axi_rready = 1'b0;
        end
    endtask

    logic [63:0] read_data;
    logic [31:0] command_count_before;

    initial begin
        clk_i = 1'b0;
        reset_n = 1'b0;
        s_axi_awid = '0;
        s_axi_awaddr = '0;
        s_axi_awlen = '0;
        s_axi_awsize = 3;
        s_axi_awburst = 1;
        s_axi_awlock = 0;
        s_axi_awcache = 0;
        s_axi_awprot = 0;
        s_axi_awqos = 0;
        s_axi_awvalid = 0;
        s_axi_wdata = 0;
        s_axi_wstrb = 0;
        s_axi_wlast = 0;
        s_axi_wvalid = 0;
        s_axi_bready = 0;
        s_axi_arid = 0;
        s_axi_araddr = 0;
        s_axi_arlen = 0;
        s_axi_arsize = 3;
        s_axi_arburst = 1;
        s_axi_arlock = 0;
        s_axi_arcache = 0;
        s_axi_arprot = 0;
        s_axi_arqos = 0;
        s_axi_arvalid = 0;
        s_axi_rready = 0;
        cfe_enable = 0;
        protocol_error_clear = 0;
        for (byte_index = 0; byte_index < 32; byte_index++) begin
            csr_mem[byte_index] = 64'd0;
        end
        for (byte_index = 0; byte_index < 256; byte_index++) begin
            l1_mem[byte_index] = 64'd0;
        end

        repeat (4) @(posedge clk_i);
        reset_n = 1'b1;
        repeat (2) @(posedge clk_i);
        check(s_axi_idle, "AXI frontend did not become idle after reset");

        // A complete command burst must become visible atomically.
        axi_write_address(24'h020000, 8'd1, 3'd3, 2'b00, 8'h31);
        axi_write_data(64'h2000_0000_0000_1000, 8'hff, 1'b0);
        repeat (3) @(posedge clk_i);
        check(!cmd_valid, "low command word escaped before burst commit");
        axi_write_data(64'h01ff_ffff_fff0_0040, 8'hff, 1'b1);
        axi_wait_b(AXI_OKAY, 8'h31);
        check(!cmd_ingress_idle, "committed command was reported idle");
        cfe_enable = 1'b1;
        do @(posedge clk_i); while (cfe_command_count_q != 1);
        check(cfe_low_q == 64'h2000_0000_0000_1000,
              "CFE received the wrong low command word");

        axi_read_address(24'h020008, 0, 3, 2'b01, 8'h42);
        axi_read_beat(read_data, AXI_OKAY, 1'b1, 8'h42);
        check(read_data[11:0] == 12'h000, "command response ID mismatch");
        check(read_data[19:12] == 8'h00, "command response status mismatch");

        // A malformed command burst returns SLVERR and never reaches CFE.
        command_count_before = cfe_command_count_q;
        axi_write_address(24'h020000, 8'd2, 3'd3, 2'b00, 8'h32);
        axi_write_data(64'h1, 8'hff, 1'b0);
        axi_write_data(64'h2, 8'hff, 1'b0);
        axi_write_data(64'h3, 8'hff, 1'b1);
        axi_wait_b(AXI_SLVERR, 8'h32);
        repeat (5) @(posedge clk_i);
        check(cfe_command_count_q == command_count_before,
              "malformed command burst changed CFE state");
        check(protocol_error, "malformed command did not set sticky error");

        protocol_error_clear = 1'b1;
        @(posedge clk_i);
        protocol_error_clear = 1'b0;
        @(posedge clk_i);
        check(!protocol_error, "sticky protocol error did not clear");

        // CSR byte strobes and aligned readback are checked numerically.
        axi_write_address(24'h000018, 0, 3, 2'b01, 8'h51);
        axi_write_data(64'h1122_3344_5566_7788, 8'h0f, 1'b1);
        axi_wait_b(AXI_OKAY, 8'h51);
        axi_read_address(24'h000018, 0, 3, 2'b01, 8'h52);
        axi_read_beat(read_data, AXI_OKAY, 1'b1, 8'h52);
        check(read_data == 64'h0000_0000_5566_7788,
              "CSR write strobe or read data was incorrect");

        // L1 full-width INCR burst must preserve address order and values.
        axi_write_address(24'h100040, 2, 3, 2'b01, 8'h61);
        axi_write_data(64'h0123_4567_89ab_cdef, 8'hff, 1'b0);
        axi_write_data(64'hfedc_ba98_7654_3210, 8'hff, 1'b0);
        axi_write_data(64'h0f1e_2d3c_4b5a_6978, 8'hff, 1'b1);
        axi_wait_b(AXI_OKAY, 8'h61);

        axi_read_address(24'h100040, 2, 3, 2'b01, 8'h62);
        axi_read_beat(read_data, AXI_OKAY, 1'b0, 8'h62);
        check(read_data == 64'h0123_4567_89ab_cdef, "L1 beat 0 mismatch");
        axi_read_beat(read_data, AXI_OKAY, 1'b0, 8'h62);
        check(read_data == 64'hfedc_ba98_7654_3210, "L1 beat 1 mismatch");
        axi_read_beat(read_data, AXI_OKAY, 1'b1, 8'h62);
        check(read_data == 64'h0f1e_2d3c_4b5a_6978, "L1 beat 2 mismatch");

        $display("TB_MODULE_FRONTEND_PASS commands=%0d", cfe_command_count_q);
        $finish;
    end

    initial begin
        #200000;
        $fatal(1, "frontend module test timed out");
    end

endmodule
