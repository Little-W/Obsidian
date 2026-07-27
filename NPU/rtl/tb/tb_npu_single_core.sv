`timescale 1ns/1ps

module tb_npu_single_core;

    import npu_rtl_pkg::*;

    localparam int unsigned AXI_S_ID_W = 8;
    localparam int unsigned AXI_S_ADDR_W = 24;
    localparam int unsigned AXI_M_ID_W = 8;
    localparam int unsigned AXI_M_ADDR_W = 40;
`ifdef NPU_TRANSFORMER_E2E
    localparam int unsigned TB_L1_BYTES = 1 << 15;
    localparam int unsigned TB_SYSTEM_MEMORY_BYTES = 1 << 18;
`else
    localparam int unsigned TB_L1_BYTES = 1 << 12;
    localparam int unsigned TB_SYSTEM_MEMORY_BYTES = 1 << 14;
`endif

    localparam logic [23:0] CSR_CORE_CONTROL = 24'h000040;
    localparam logic [23:0] CSR_L1_HOST_ACCESS_CONTROL = 24'h0000f0;
    localparam logic [23:0] CMD_FIFO_DATA = 24'h020000;
    localparam logic [23:0] CMD_RSP_FIFO = 24'h020008;
    localparam logic [23:0] CTL_ARG0 = 24'h020020;
    localparam logic [23:0] CTL_ARG1 = 24'h020028;
    localparam logic [23:0] CTL_START = 24'h020030;
    localparam logic [23:0] CTL_STATUS = 24'h020038;
    localparam logic [23:0] CTL_RESULT = 24'h020040;
    localparam logic [23:0] CTL_CANCEL = 24'h020048;
    localparam logic [23:0] L1_AXI_BASE = 24'h100000;

    logic core_clk_i;
    logic noc_clk_i;
    logic reset_n;
    logic dvfs_prepare_req_i;
    logic dvfs_prepare_ack_o;
    logic soft_reset_req_i;
    logic soft_reset_done_o;
    logic power_down_req_i;
    logic power_down_ack_o;
    logic accept_new_cmd_o;
    logic core_idle_o;
    logic [7:0] module_clk_active_o;
    logic wdt_reset_req_o;
    logic irq_done_o;
    logic irq_exception_o;
    logic irq_error_o;

    logic [AXI_S_ID_W-1:0] s_axi_awid_i;
    logic [AXI_S_ADDR_W-1:0] s_axi_awaddr_i;
    logic [7:0] s_axi_awlen_i;
    logic [2:0] s_axi_awsize_i;
    logic [1:0] s_axi_awburst_i;
    logic s_axi_awlock_i;
    logic [3:0] s_axi_awcache_i;
    logic [2:0] s_axi_awprot_i;
    logic [3:0] s_axi_awqos_i;
    logic s_axi_awvalid_i;
    logic s_axi_awready_o;
    logic [63:0] s_axi_wdata_i;
    logic [7:0] s_axi_wstrb_i;
    logic s_axi_wlast_i;
    logic s_axi_wvalid_i;
    logic s_axi_wready_o;
    logic [AXI_S_ID_W-1:0] s_axi_bid_o;
    logic [1:0] s_axi_bresp_o;
    logic s_axi_bvalid_o;
    logic s_axi_bready_i;

    logic [AXI_S_ID_W-1:0] s_axi_arid_i;
    logic [AXI_S_ADDR_W-1:0] s_axi_araddr_i;
    logic [7:0] s_axi_arlen_i;
    logic [2:0] s_axi_arsize_i;
    logic [1:0] s_axi_arburst_i;
    logic s_axi_arlock_i;
    logic [3:0] s_axi_arcache_i;
    logic [2:0] s_axi_arprot_i;
    logic [3:0] s_axi_arqos_i;
    logic s_axi_arvalid_i;
    logic s_axi_arready_o;
    logic [AXI_S_ID_W-1:0] s_axi_rid_o;
    logic [63:0] s_axi_rdata_o;
    logic [1:0] s_axi_rresp_o;
    logic s_axi_rlast_o;
    logic s_axi_rvalid_o;
    logic s_axi_rready_i;

    logic [AXI_M_ID_W-1:0] m_axi_awid_o;
    logic [AXI_M_ADDR_W-1:0] m_axi_awaddr_o;
    logic [7:0] m_axi_awlen_o;
    logic [2:0] m_axi_awsize_o;
    logic [1:0] m_axi_awburst_o;
    logic m_axi_awlock_o;
    logic [3:0] m_axi_awcache_o;
    logic [2:0] m_axi_awprot_o;
    logic [3:0] m_axi_awqos_o;
    logic m_axi_awvalid_o;
    logic m_axi_awready_i;
    logic [63:0] m_axi_wdata_o;
    logic [7:0] m_axi_wstrb_o;
    logic m_axi_wlast_o;
    logic m_axi_wvalid_o;
    logic m_axi_wready_i;
    logic [AXI_M_ID_W-1:0] m_axi_bid_i;
    logic [1:0] m_axi_bresp_i;
    logic m_axi_bvalid_i;
    logic m_axi_bready_o;

    logic [AXI_M_ID_W-1:0] m_axi_arid_o;
    logic [AXI_M_ADDR_W-1:0] m_axi_araddr_o;
    logic [7:0] m_axi_arlen_o;
    logic [2:0] m_axi_arsize_o;
    logic [1:0] m_axi_arburst_o;
    logic m_axi_arlock_o;
    logic [3:0] m_axi_arcache_o;
    logic [2:0] m_axi_arprot_o;
    logic [3:0] m_axi_arqos_o;
    logic m_axi_arvalid_o;
    logic m_axi_arready_i;
    logic [AXI_M_ID_W-1:0] m_axi_rid_i;
    logic [63:0] m_axi_rdata_i;
    logic [1:0] m_axi_rresp_i;
    logic m_axi_rlast_i;
    logic m_axi_rvalid_i;
    logic m_axi_rready_o;

    logic system_bus_backpressure;
    logic [31:0] system_bus_read_handshakes;
    logic [31:0] system_bus_write_handshakes;
    logic system_bus_protocol_error;

    logic [127:0] command_words [0:7];
`ifdef NPU_TRANSFORMER_E2E
    logic [127:0] transformer_commands [0:63];
    logic [7:0] transformer_batch_sizes [0:15];
    logic [7:0] transformer_weights [0:4095];
    logic [7:0] transformer_input [0:63];
    logic [7:0] transformer_expected [0:63];
    logic [7:0] transformer_expected_score [0:63];
    logic [7:0] transformer_expected_probability [0:63];
    logic [7:0] transformer_expected_context [0:63];
    logic [39:0] transformer_output_ddr_q;
    logic [31:0] transformer_output_bytes_q;
`endif
    logic [63:0] read_data;
    logic [63:0] ctl_data;
    logic [31:0] matrix_l1_handshakes_q;
    logic [31:0] vector_l1_handshakes_q;
    logic [31:0] matrix_int16_valid_l1_handshakes_q;
    logic [31:0] matrix_int16_invalid_l1_handshakes_q;
    logic matrix_dependency_done_q;
    logic dependency_check_enable_q;
    logic protocol_checks_enable;
    logic cfe_expect_high_q;
    logic [31:0] cfe_low_word_count_q;
    logic [31:0] cfe_high_word_count_q;
    logic system_dma_write_check_q;
    logic [31:0] system_aw_handshakes_q;
    logic [31:0] system_w_handshakes_q;
    logic [31:0] system_b_handshakes_q;
    logic unused_control_status;

    npu_single_core_top #(
        .AXI_S_ID_W(AXI_S_ID_W),
        .AXI_S_ADDR_W(AXI_S_ADDR_W),
        .AXI_M_ID_W(AXI_M_ID_W),
        .AXI_M_ADDR_W(AXI_M_ADDR_W),
        .L1_BYTES(TB_L1_BYTES),
        .L1_BANKS(16),
        .TASK_SLOTS(8),
        .EVENT_COUNT(255)
    ) dut (.*);

    tb_axi_memory_model #(
        .AXI_ID_W(AXI_M_ID_W),
        .AXI_ADDR_W(AXI_M_ADDR_W),
        .MEM_BYTES(TB_SYSTEM_MEMORY_BYTES)
    ) u_system_memory (
        .clk_i(core_clk_i),
        .reset_n(reset_n),
        .backpressure_enable_i(system_bus_backpressure),
        .s_axi_awid_i(m_axi_awid_o),
        .s_axi_awaddr_i(m_axi_awaddr_o),
        .s_axi_awlen_i(m_axi_awlen_o),
        .s_axi_awsize_i(m_axi_awsize_o),
        .s_axi_awburst_i(m_axi_awburst_o),
        .s_axi_awlock_i(m_axi_awlock_o),
        .s_axi_awcache_i(m_axi_awcache_o),
        .s_axi_awprot_i(m_axi_awprot_o),
        .s_axi_awqos_i(m_axi_awqos_o),
        .s_axi_awvalid_i(m_axi_awvalid_o),
        .s_axi_awready_o(m_axi_awready_i),
        .s_axi_wdata_i(m_axi_wdata_o),
        .s_axi_wstrb_i(m_axi_wstrb_o),
        .s_axi_wlast_i(m_axi_wlast_o),
        .s_axi_wvalid_i(m_axi_wvalid_o),
        .s_axi_wready_o(m_axi_wready_i),
        .s_axi_bid_o(m_axi_bid_i),
        .s_axi_bresp_o(m_axi_bresp_i),
        .s_axi_bvalid_o(m_axi_bvalid_i),
        .s_axi_bready_i(m_axi_bready_o),
        .s_axi_arid_i(m_axi_arid_o),
        .s_axi_araddr_i(m_axi_araddr_o),
        .s_axi_arlen_i(m_axi_arlen_o),
        .s_axi_arsize_i(m_axi_arsize_o),
        .s_axi_arburst_i(m_axi_arburst_o),
        .s_axi_arlock_i(m_axi_arlock_o),
        .s_axi_arcache_i(m_axi_arcache_o),
        .s_axi_arprot_i(m_axi_arprot_o),
        .s_axi_arqos_i(m_axi_arqos_o),
        .s_axi_arvalid_i(m_axi_arvalid_o),
        .s_axi_arready_o(m_axi_arready_i),
        .s_axi_rid_o(m_axi_rid_i),
        .s_axi_rdata_o(m_axi_rdata_i),
        .s_axi_rresp_o(m_axi_rresp_i),
        .s_axi_rlast_o(m_axi_rlast_i),
        .s_axi_rvalid_o(m_axi_rvalid_i),
        .s_axi_rready_i(m_axi_rready_o),
        .read_handshake_count_o(system_bus_read_handshakes),
        .write_handshake_count_o(system_bus_write_handshakes),
        .protocol_error_o(system_bus_protocol_error)
    );

    always #5 core_clk_i = ~core_clk_i;
    assign noc_clk_i = core_clk_i;
    assign unused_control_status = ^{
        dvfs_prepare_ack_o,
        soft_reset_done_o,
        power_down_ack_o,
        core_idle_o,
        module_clk_active_o
    };

    property p_master_ar_stable;
        @(posedge core_clk_i) disable iff (!protocol_checks_enable)
        m_axi_arvalid_o && !m_axi_arready_i |=>
        m_axi_arvalid_o &&
        $stable({
            m_axi_arid_o, m_axi_araddr_o, m_axi_arlen_o,
            m_axi_arsize_o, m_axi_arburst_o, m_axi_arlock_o
        });
    endproperty
    assert property (p_master_ar_stable);

    property p_master_aw_stable;
        @(posedge core_clk_i) disable iff (!protocol_checks_enable)
        m_axi_awvalid_o && !m_axi_awready_i |=>
        m_axi_awvalid_o &&
        $stable({
            m_axi_awid_o, m_axi_awaddr_o, m_axi_awlen_o,
            m_axi_awsize_o, m_axi_awburst_o, m_axi_awlock_o
        });
    endproperty
    assert property (p_master_aw_stable);

    property p_master_w_stable;
        @(posedge core_clk_i) disable iff (!protocol_checks_enable)
        m_axi_wvalid_o && !m_axi_wready_i |=>
        m_axi_wvalid_o &&
        $stable({m_axi_wdata_o, m_axi_wstrb_o, m_axi_wlast_o});
    endproperty
    assert property (p_master_w_stable);

    property p_slave_b_stable;
        @(posedge core_clk_i) disable iff (!protocol_checks_enable)
        s_axi_bvalid_o && !s_axi_bready_i |=>
        s_axi_bvalid_o && $stable({s_axi_bid_o, s_axi_bresp_o});
    endproperty
    assert property (p_slave_b_stable);

    property p_slave_r_stable;
        @(posedge core_clk_i) disable iff (!protocol_checks_enable)
        s_axi_rvalid_o && !s_axi_rready_i |=>
        s_axi_rvalid_o &&
        $stable({
            s_axi_rid_o, s_axi_rdata_o, s_axi_rresp_o, s_axi_rlast_o
        });
    endproperty
    assert property (p_slave_r_stable);

    always_ff @(posedge core_clk_i or negedge reset_n) begin
        if (!reset_n) begin
            matrix_l1_handshakes_q <= 32'd0;
            vector_l1_handshakes_q <= 32'd0;
            matrix_int16_valid_l1_handshakes_q <= 32'd0;
            matrix_int16_invalid_l1_handshakes_q <= 32'd0;
            matrix_dependency_done_q <= 1'b0;
            cfe_expect_high_q <= 1'b0;
            cfe_low_word_count_q <= 32'd0;
            cfe_high_word_count_q <= 32'd0;
            system_aw_handshakes_q <= 32'd0;
            system_w_handshakes_q <= 32'd0;
            system_b_handshakes_q <= 32'd0;
        end else begin
            if (dut.matrix_l1_req_valid && dut.matrix_l1_req_ready) begin
                matrix_l1_handshakes_q <= matrix_l1_handshakes_q + 1'b1;
                unique case (dut.matrix_active_id_q)
                    12'h106:
                        matrix_int16_valid_l1_handshakes_q <=
                            matrix_int16_valid_l1_handshakes_q + 1'b1;
                    12'h107:
                        matrix_int16_invalid_l1_handshakes_q <=
                            matrix_int16_invalid_l1_handshakes_q + 1'b1;
                    default: begin end
                endcase
            end
            if (dut.vector_l1_req_valid && dut.vector_l1_req_ready) begin
                vector_l1_handshakes_q <= vector_l1_handshakes_q + 1'b1;
            end
            if (dut.matrix_done_valid && dut.matrix_done_ready &&
                (dut.matrix_active_id_q == 12'h101)) begin
                matrix_dependency_done_q <= 1'b1;
            end
            if (dependency_check_enable_q &&
                dut.vector_task_valid && dut.vector_task_ready &&
                !matrix_dependency_done_q) begin
                $fatal(1, "dependent Vector task started before Matrix event");
            end

            if (dut.cmd_valid && dut.cmd_ready) begin
                if (!cfe_expect_high_q) begin
                    if (!dut.cmd_first || dut.cmd_last) begin
                        $fatal(1, "CFE low word markers are incorrect");
                    end
                    cfe_low_word_count_q <= cfe_low_word_count_q + 1'b1;
                    cfe_expect_high_q <= 1'b1;
                end else begin
                    if (dut.cmd_first || !dut.cmd_last) begin
                        $fatal(1, "CFE high word markers are incorrect");
                    end
                    if (!npu_cmd_opcode_valid(dut.cmd_data[63:58])) begin
                        $fatal(1, "CFE opcode is invalid");
                    end
                    cfe_high_word_count_q <= cfe_high_word_count_q + 1'b1;
                    cfe_expect_high_q <= 1'b0;
                end
            end

            if (m_axi_arvalid_o && m_axi_arready_i) begin
                if ((m_axi_arlen_o != 8'd0) ||
                    (m_axi_arsize_o != 3'd3) ||
                    (m_axi_arburst_o != 2'b01) ||
                    (m_axi_araddr_o[2:0] != 3'd0)) begin
                    $fatal(1, "NPU AXI Master emitted an invalid read");
                end
            end

            if (m_axi_awvalid_o && m_axi_awready_i) begin
                system_aw_handshakes_q <= system_aw_handshakes_q + 1'b1;
                if (!system_dma_write_check_q) begin
                    $fatal(1, "unexpected NPU AXI write-address handshake");
                end
`ifdef NPU_TRANSFORMER_E2E
                if ((m_axi_awid_o != 8'd0) ||
                    (m_axi_awaddr_o <
                     {transformer_output_ddr_q[39:3], 3'b000}) ||
                    (m_axi_awaddr_o >=
                     transformer_output_ddr_q +
                     40'(transformer_output_bytes_q)) ||
                    (m_axi_awlen_o != 8'd0) ||
                    (m_axi_awsize_o != 3'd3) ||
                    (m_axi_awburst_o != 2'b01) ||
                    m_axi_awlock_o ||
                    (m_axi_awcache_o != 4'b0011) ||
                    (m_axi_awprot_o != 3'b000) ||
                    (m_axi_awqos_o != 4'd0)) begin
                    $fatal(1, "Transformer output AW fields are incorrect");
                end
`else
                if ((m_axi_awid_o != 8'd0) ||
                    (m_axi_awaddr_o != 40'h0000_003100) ||
                    (m_axi_awlen_o != 8'd0) ||
                    (m_axi_awsize_o != 3'd3) ||
                    (m_axi_awburst_o != 2'b01) ||
                    m_axi_awlock_o ||
                    (m_axi_awcache_o != 4'b0011) ||
                    (m_axi_awprot_o != 3'b000) ||
                    (m_axi_awqos_o != 4'd0)) begin
                    $fatal(1, "L1-to-system DMA AW fields are incorrect");
                end
`endif
            end

            if (m_axi_wvalid_o && m_axi_wready_i) begin
                system_w_handshakes_q <= system_w_handshakes_q + 1'b1;
                if (!system_dma_write_check_q || !m_axi_wlast_o) begin
                    $fatal(1, "L1-to-system DMA W handshake is incorrect");
                end
`ifdef NPU_TRANSFORMER_E2E
                if (!$onehot(m_axi_wstrb_o)) begin
                    $fatal(1, "Transformer output WSTRB is not one-hot");
                end
`else
                unique case (system_w_handshakes_q)
                    32'd0:
                        if ((m_axi_wdata_o != 64'h0000_0000_0000_0011) ||
                            (m_axi_wstrb_o != 8'h01))
                            $fatal(1, "DMA W beat zero is incorrect");
                    32'd1:
                        if ((m_axi_wdata_o != 64'h0000_0000_0000_2200) ||
                            (m_axi_wstrb_o != 8'h02))
                            $fatal(1, "DMA W beat one is incorrect");
                    32'd2:
                        if ((m_axi_wdata_o != 64'h0000_0000_0033_0000) ||
                            (m_axi_wstrb_o != 8'h04))
                            $fatal(1, "DMA W beat two is incorrect");
                    32'd3:
                        if ((m_axi_wdata_o != 64'h0000_0000_4400_0000) ||
                            (m_axi_wstrb_o != 8'h08))
                            $fatal(1, "DMA W beat three is incorrect");
                    32'd4:
                        if ((m_axi_wdata_o != 64'h0000_0055_0000_0000) ||
                            (m_axi_wstrb_o != 8'h10))
                            $fatal(1, "DMA W beat four is incorrect");
                    32'd5:
                        if ((m_axi_wdata_o != 64'h0000_6600_0000_0000) ||
                            (m_axi_wstrb_o != 8'h20))
                            $fatal(1, "DMA W beat five is incorrect");
                    32'd6:
                        if ((m_axi_wdata_o != 64'h0077_0000_0000_0000) ||
                            (m_axi_wstrb_o != 8'h40))
                            $fatal(1, "DMA W beat six is incorrect");
                    32'd7:
                        if ((m_axi_wdata_o != 64'h8800_0000_0000_0000) ||
                            (m_axi_wstrb_o != 8'h80))
                            $fatal(1, "DMA W beat seven is incorrect");
                    default:
                        $fatal(1, "L1-to-system DMA emitted extra W beats");
                endcase
`endif
            end

            if (m_axi_bvalid_i && m_axi_bready_o) begin
                system_b_handshakes_q <= system_b_handshakes_q + 1'b1;
                if (!system_dma_write_check_q ||
                    (m_axi_bid_i != 8'd0) ||
                    (m_axi_bresp_i != 2'b00)) begin
                    $fatal(1, "L1-to-system DMA B response is incorrect");
                end
            end
        end
    end

    task automatic check(input logic condition, input string message);
        if (!condition) begin
            $fatal(1, "%s", message);
        end
    endtask

    function automatic logic [127:0] make_command(
        input logic [5:0] command_opcode,
        input logic [9:0] command_id,
        input logic [1:0] dtype,
        input logic [79:0] payload,
        input logic [7:0] wait0,
        input logic [7:0] wait1,
        input logic [7:0] signal_event
    );
        logic [127:0] command;
        command = 128'd0;
        command[127:122] = command_opcode;
        command[121:112] = command_id;
        command[111:104] = wait0;
        command[103:96] = wait1;
        command[95:88] = signal_event;
        command[81:80] = dtype;
        command[79:0] = payload;
        return command;
    endfunction

    task automatic axi_write_single(
        input logic [23:0] address,
        input logic [63:0] data,
        input logic [7:0] strobe
    );
        logic [1:0] observed_response;
        @(negedge core_clk_i);
        s_axi_awid_i = 8'h31;
        s_axi_awaddr_i = address;
        s_axi_awlen_i = 8'd0;
        s_axi_awsize_i = 3'd3;
        s_axi_awburst_i = 2'b01;
        s_axi_awlock_i = 1'b0;
        s_axi_awvalid_i = 1'b1;
        do @(posedge core_clk_i); while (!s_axi_awready_o);
        @(negedge core_clk_i);
        s_axi_awvalid_i = 1'b0;

        s_axi_wdata_i = data;
        s_axi_wstrb_i = strobe;
        s_axi_wlast_i = 1'b1;
        s_axi_wvalid_i = 1'b1;
        do @(posedge core_clk_i); while (!s_axi_wready_o);
        @(negedge core_clk_i);
        s_axi_wvalid_i = 1'b0;

        do @(posedge core_clk_i); while (!s_axi_bvalid_o);
        observed_response = s_axi_bresp_o;
        repeat (2) @(posedge core_clk_i);
        check(s_axi_bvalid_o, "AXI Slave dropped BVALID during host stall");
        check(s_axi_bresp_o == observed_response,
              "AXI Slave changed BRESP during host stall");
        @(negedge core_clk_i);
        s_axi_bready_i = 1'b1;
        @(posedge core_clk_i);
        check(s_axi_bvalid_o, "AXI Slave BVALID disappeared before handshake");
        check(s_axi_bid_o == 8'h31, "AXI Slave returned the wrong BID");
        check(s_axi_bresp_o == 2'b00, "AXI Slave single write failed");
        @(negedge core_clk_i);
        s_axi_bready_i = 1'b0;
    endtask

    task automatic axi_read_single(
        input logic [23:0] address,
        output logic [63:0] data
    );
        logic [63:0] observed_data;
        logic [1:0] observed_response;
        @(negedge core_clk_i);
        s_axi_arid_i = 8'h52;
        s_axi_araddr_i = address;
        s_axi_arlen_i = 8'd0;
        s_axi_arsize_i = 3'd3;
        s_axi_arburst_i = 2'b01;
        s_axi_arlock_i = 1'b0;
        s_axi_arvalid_i = 1'b1;
        do @(posedge core_clk_i); while (!s_axi_arready_o);
        @(negedge core_clk_i);
        s_axi_arvalid_i = 1'b0;

        do @(posedge core_clk_i); while (!s_axi_rvalid_o);
        observed_data = s_axi_rdata_o;
        observed_response = s_axi_rresp_o;
        repeat (2) @(posedge core_clk_i);
        check(s_axi_rvalid_o, "AXI Slave dropped RVALID during host stall");
        check((s_axi_rdata_o == observed_data) &&
              (s_axi_rresp_o == observed_response),
              "AXI Slave changed read response during host stall");
        @(negedge core_clk_i);
        s_axi_rready_i = 1'b1;
        @(posedge core_clk_i);
        check(s_axi_rvalid_o, "AXI Slave RVALID disappeared before handshake");
        check(s_axi_rid_o == 8'h52, "AXI Slave returned the wrong RID");
        check(s_axi_rresp_o == 2'b00, "AXI Slave single read failed");
        check(s_axi_rlast_o, "AXI Slave single read did not assert RLAST");
        data = s_axi_rdata_o;
        @(negedge core_clk_i);
        s_axi_rready_i = 1'b0;
    endtask

    task automatic axi_submit_commands(input int unsigned command_count);
        logic [1:0] observed_response;
        int unsigned beat_count;
        beat_count = command_count * 2;
        check((command_count >= 1) && (command_count <= 8),
              "invalid command burst count");

        @(negedge core_clk_i);
        s_axi_awid_i = 8'h63;
        s_axi_awaddr_i = CMD_FIFO_DATA;
        s_axi_awlen_i = 8'(beat_count - 1);
        s_axi_awsize_i = 3'd3;
        s_axi_awburst_i = 2'b00;
        s_axi_awlock_i = 1'b0;
        s_axi_awvalid_i = 1'b1;
        do @(posedge core_clk_i); while (!s_axi_awready_o);
        @(negedge core_clk_i);
        s_axi_awvalid_i = 1'b0;

        for (int unsigned command_index = 0;
             command_index < command_count; command_index++) begin
            for (int unsigned word_index = 0;
                 word_index < 2; word_index++) begin
                @(negedge core_clk_i);
                s_axi_wdata_i =
                    command_words[command_index][word_index*64 +: 64];
                s_axi_wstrb_i = 8'hff;
                s_axi_wlast_i =
                    ((command_index * 2 + word_index + 1) == beat_count);
                s_axi_wvalid_i = 1'b1;
                do @(posedge core_clk_i); while (!s_axi_wready_o);
                @(negedge core_clk_i);
                s_axi_wvalid_i = 1'b0;
            end
        end

        do @(posedge core_clk_i); while (!s_axi_bvalid_o);
        observed_response = s_axi_bresp_o;
        repeat (2) @(posedge core_clk_i);
        check(s_axi_bvalid_o && (s_axi_bresp_o == observed_response),
              "command burst response was not held");
        @(negedge core_clk_i);
        s_axi_bready_i = 1'b1;
        @(posedge core_clk_i);
        check((s_axi_bid_o == 8'h63) && (s_axi_bresp_o == 2'b00),
              "FIXED command burst failed");
        @(negedge core_clk_i);
        s_axi_bready_i = 1'b0;
    endtask

    task automatic read_command_response(
        input logic [11:0] expected_command_id,
        input logic [7:0] expected_status
    );
        logic [63:0] response;
        axi_read_single(CMD_RSP_FIFO, response);
        check(response[11:0] == expected_command_id,
              "CFE response returned the wrong command_id");
        check(response[19:12] == expected_status,
              "CFE response returned the wrong status");
        check(response[27:20] <= 8'd8,
              "CFE response fifo_free_entries exceeds the configured depth");
        check(response[63:28] == 36'd0,
              "CFE response reserved bits are nonzero");
    endtask

    task automatic ctl_request(
        input logic [1:0] operation,
        input logic [63:0] argument0,
        input logic [63:0] argument1,
        output logic [63:0] result
    );
        logic [63:0] status;
        int unsigned poll_count;
        axi_write_single(CTL_ARG0, argument0, 8'hff);
        axi_write_single(CTL_ARG1, argument1, 8'hff);
        axi_write_single(CTL_START, {62'd0, operation}, 8'hff);
        status = 64'd0;
        for (poll_count = 0; poll_count < 20000;
             poll_count = poll_count + 1) begin
            axi_read_single(CTL_STATUS, status);
            if (status[1]) begin
                break;
            end
        end
        check(status[1], "control request polling timed out");
        check(!status[0], "control request stayed busy after completion");
        check(status[15:8] == 8'h00,
              "control window reported an internal failure");
        check((status[63:16] == 48'd0) && (status[7:2] == 6'd0),
              "control window status reserved bits are nonzero");
        axi_read_single(CTL_RESULT, result);
    endtask

    task automatic query_task(
        input logic [11:0] command_id,
        input logic [2:0] selector,
        output logic [63:0] result
    );
        ctl_request(NPU_CTL_QUERY, {52'd0, command_id},
                    {61'd0, selector}, result);
    endtask

    task automatic acknowledge_task(input logic [11:0] command_id);
        logic [63:0] result;
        query_task(command_id, 3'd4, result);
        check(result == 64'd0, "task ACK failed");
    endtask

    task automatic l1_write_word(
        input logic [19:0] address,
        input logic [63:0] data,
        input logic [7:0] strobe
    );
        axi_write_single(L1_AXI_BASE + 24'(address), data, strobe);
    endtask

    task automatic l1_read_word(
        input logic [19:0] address,
        output logic [63:0] data
    );
        axi_read_single(L1_AXI_BASE + 24'(address), data);
    endtask

`ifdef NPU_TRANSFORMER_E2E
    function automatic logic [11:0] transformer_command_id(
        input logic [127:0] command
    );
        return {2'd0, command[121:112]};
    endfunction

    task automatic run_transformer_batch(
        input int unsigned command_offset,
        input int unsigned command_count
    );
        logic [63:0] fence_result;
        logic [63:0] task_status;
        logic [11:0] command_id;
        int unsigned poll_count;

        check((command_count >= 1) && (command_count <= 8),
              "Transformer batch size is invalid");
        for (int unsigned index = 0; index < command_count; index++) begin
            command_words[index] =
                transformer_commands[command_offset + index];
        end
        axi_submit_commands(command_count);
        for (int unsigned index = 0; index < command_count; index++) begin
            command_id = transformer_command_id(
                transformer_commands[command_offset + index]
            );
            read_command_response(command_id, NPU_STATUS_SUCCESS);
        end

        ctl_request(NPU_CTL_FENCE, 64'hf, 64'd500000, fence_result);
        check(fence_result[7:0] == NPU_STATUS_SUCCESS,
              "Transformer batch FENCE returned a failure");
        for (int unsigned index = 0; index < command_count; index++) begin
            command_id = transformer_command_id(
                transformer_commands[command_offset + index]
            );
            task_status = 64'd0;
            for (poll_count = 0; poll_count < 1000;
                 poll_count = poll_count + 1) begin
                query_task(command_id, 3'd0, task_status);
                if (task_status[3:0] == 4'd3) begin
                    break;
                end
            end
            check(task_status[3:0] == 4'd3,
                  "Transformer task did not reach terminal state");
            check(task_status[11:4] == NPU_STATUS_SUCCESS,
                  "Transformer task returned a failure status");
            acknowledge_task(command_id);
        end
        for (int unsigned index = 0; index < 8; index++) begin
            command_words[index] = 128'd0;
        end
    endtask
`endif

`ifdef NPU_TRANSFORMER_E2E
    initial begin : run_transformer_model
        string command_hex;
        string batch_hex;
        string weight_hex;
        string input_hex;
        string expected_hex;
        string score_hex;
        string probability_hex;
        string context_hex;
        int unsigned command_count;
        int unsigned batch_count;
        int unsigned weight_bytes;
        int unsigned input_bytes;
        int unsigned output_bytes;
        int unsigned score_bytes;
        int unsigned probability_bytes;
        int unsigned context_bytes;
        longint unsigned weight_ddr;
        longint unsigned input_ddr;
        longint unsigned output_ddr;
        longint unsigned score_l1;
        longint unsigned probability_l1;
        longint unsigned context_l1;
        int unsigned command_offset;
        int unsigned output_index;
        logic [63:0] actual_output_word;
        logic [63:0] actual_score_word;
        logic [63:0] actual_probability_word;
        logic [63:0] actual_context_word;

        core_clk_i = 1'b0;
        reset_n = 1'b0;
        dvfs_prepare_req_i = 1'b0;
        soft_reset_req_i = 1'b0;
        power_down_req_i = 1'b0;
        system_bus_backpressure = 1'b1;
        dependency_check_enable_q = 1'b0;
        protocol_checks_enable = 1'b0;
        system_dma_write_check_q = 1'b1;
        transformer_output_ddr_q = 40'd0;
        transformer_output_bytes_q = 32'd0;

        s_axi_awid_i = '0;
        s_axi_awaddr_i = '0;
        s_axi_awlen_i = '0;
        s_axi_awsize_i = 3'd3;
        s_axi_awburst_i = 2'b01;
        s_axi_awlock_i = 1'b0;
        s_axi_awcache_i = 4'd0;
        s_axi_awprot_i = 3'd0;
        s_axi_awqos_i = 4'd0;
        s_axi_awvalid_i = 1'b0;
        s_axi_wdata_i = 64'd0;
        s_axi_wstrb_i = 8'd0;
        s_axi_wlast_i = 1'b0;
        s_axi_wvalid_i = 1'b0;
        s_axi_bready_i = 1'b0;
        s_axi_arid_i = '0;
        s_axi_araddr_i = '0;
        s_axi_arlen_i = '0;
        s_axi_arsize_i = 3'd3;
        s_axi_arburst_i = 2'b01;
        s_axi_arlock_i = 1'b0;
        s_axi_arcache_i = 4'd0;
        s_axi_arprot_i = 3'd0;
        s_axi_arqos_i = 4'd0;
        s_axi_arvalid_i = 1'b0;
        s_axi_rready_i = 1'b0;
        for (int unsigned index = 0; index < 8; index++) begin
            command_words[index] = 128'd0;
        end

        check($value$plusargs("COMMAND_HEX=%s", command_hex),
              "COMMAND_HEX plusarg is missing");
        check($value$plusargs("COMMAND_COUNT=%d", command_count),
              "COMMAND_COUNT plusarg is missing");
        check($value$plusargs("BATCH_HEX=%s", batch_hex),
              "BATCH_HEX plusarg is missing");
        check($value$plusargs("BATCH_COUNT=%d", batch_count),
              "BATCH_COUNT plusarg is missing");
        check($value$plusargs("WEIGHT_HEX=%s", weight_hex),
              "WEIGHT_HEX plusarg is missing");
        check($value$plusargs("WEIGHT_BYTES=%d", weight_bytes),
              "WEIGHT_BYTES plusarg is missing");
        check($value$plusargs("WEIGHT_DDR=%d", weight_ddr),
              "WEIGHT_DDR plusarg is missing");
        check($value$plusargs("INPUT_HEX=%s", input_hex),
              "INPUT_HEX plusarg is missing");
        check($value$plusargs("INPUT_BYTES=%d", input_bytes),
              "INPUT_BYTES plusarg is missing");
        check($value$plusargs("INPUT_DDR=%d", input_ddr),
              "INPUT_DDR plusarg is missing");
        check($value$plusargs("EXPECTED_HEX=%s", expected_hex),
              "EXPECTED_HEX plusarg is missing");
        check($value$plusargs("OUTPUT_BYTES=%d", output_bytes),
              "OUTPUT_BYTES plusarg is missing");
        check($value$plusargs("OUTPUT_DDR=%d", output_ddr),
              "OUTPUT_DDR plusarg is missing");
        check($value$plusargs("SCORE_HEX=%s", score_hex),
              "SCORE_HEX plusarg is missing");
        check($value$plusargs("SCORE_BYTES=%d", score_bytes),
              "SCORE_BYTES plusarg is missing");
        check($value$plusargs("SCORE_L1=%d", score_l1),
              "SCORE_L1 plusarg is missing");
        check($value$plusargs("PROBABILITY_HEX=%s", probability_hex),
              "PROBABILITY_HEX plusarg is missing");
        check($value$plusargs(
                  "PROBABILITY_BYTES=%d", probability_bytes
              ), "PROBABILITY_BYTES plusarg is missing");
        check($value$plusargs("PROBABILITY_L1=%d", probability_l1),
              "PROBABILITY_L1 plusarg is missing");
        check($value$plusargs("CONTEXT_HEX=%s", context_hex),
              "CONTEXT_HEX plusarg is missing");
        check($value$plusargs("CONTEXT_BYTES=%d", context_bytes),
              "CONTEXT_BYTES plusarg is missing");
        check($value$plusargs("CONTEXT_L1=%d", context_l1),
              "CONTEXT_L1 plusarg is missing");
        check((command_count <= 64) && (batch_count <= 16) &&
              (weight_bytes <= 4096) && (input_bytes <= 64) &&
              (output_bytes <= 64) && (score_bytes <= 64) &&
              (probability_bytes <= 64) && (context_bytes <= 64),
              "Transformer fixture exceeds testbench storage");
        check((weight_ddr + 64'(weight_bytes) <=
               64'(TB_SYSTEM_MEMORY_BYTES)) &&
              (input_ddr + 64'(input_bytes) <=
               64'(TB_SYSTEM_MEMORY_BYTES)) &&
              (output_ddr + 64'(output_bytes) <=
               64'(TB_SYSTEM_MEMORY_BYTES)),
              "Transformer fixture exceeds system memory");
        check((score_l1 + 64'(score_bytes) <= 64'(TB_L1_BYTES)) &&
              (probability_l1 + 64'(probability_bytes) <=
               64'(TB_L1_BYTES)) &&
              (context_l1 + 64'(context_bytes) <=
               64'(TB_L1_BYTES)),
              "Transformer stage fixture exceeds L1");
        check(output_bytes == 8,
              "Transformer output check currently requires eight bytes");

        $readmemh(command_hex, transformer_commands, 0, command_count - 1);
        $readmemh(batch_hex, transformer_batch_sizes, 0, batch_count - 1);
        $readmemh(weight_hex, transformer_weights, 0, weight_bytes - 1);
        $readmemh(input_hex, transformer_input, 0, input_bytes - 1);
        $readmemh(expected_hex, transformer_expected, 0, output_bytes - 1);
        $readmemh(score_hex, transformer_expected_score, 0, score_bytes - 1);
        $readmemh(
            probability_hex,
            transformer_expected_probability,
            0,
            probability_bytes - 1
        );
        $readmemh(
            context_hex,
            transformer_expected_context,
            0,
            context_bytes - 1
        );
        transformer_output_ddr_q = 40'(output_ddr);
        transformer_output_bytes_q = output_bytes;

        repeat (8) @(posedge core_clk_i);
        @(negedge core_clk_i);
        reset_n = 1'b1;
        repeat (6) @(posedge core_clk_i);
        protocol_checks_enable = 1'b1;
        check(!accept_new_cmd_o,
              "NPU accepted Transformer commands before START");
        axi_write_single(CSR_CORE_CONTROL, 64'h1, 8'hff);
        axi_write_single(CSR_L1_HOST_ACCESS_CONTROL, 64'h1, 8'hff);
        repeat (2) @(posedge core_clk_i);
        check(accept_new_cmd_o,
              "NPU did not enter running state for Transformer");

        for (int unsigned index = 0; index < weight_bytes; index++) begin
            u_system_memory.write_byte(
                weight_ddr + 64'(index), transformer_weights[index]
            );
        end
        for (int unsigned index = 0; index < input_bytes; index++) begin
            u_system_memory.write_byte(
                input_ddr + 64'(index), transformer_input[index]
            );
        end

        command_offset = 0;
        for (int unsigned batch = 0; batch < batch_count; batch++) begin
            check((transformer_batch_sizes[batch] >= 1) &&
                  (transformer_batch_sizes[batch] <= 8),
                  "Transformer batch file contains an invalid size");
            check(command_offset +
                  32'(transformer_batch_sizes[batch]) <=
                  command_count,
                  "Transformer batches exceed command count");
            run_transformer_batch(
                command_offset, 32'(transformer_batch_sizes[batch])
            );
            command_offset =
                command_offset + 32'(transformer_batch_sizes[batch]);
        end
        check(command_offset == command_count,
              "Transformer batches do not cover every command");

        actual_output_word = u_system_memory.read_u64(output_ddr);
        for (output_index = 0; output_index < output_bytes;
             output_index = output_index + 1) begin
            check(actual_output_word[output_index*8 +: 8] ==
                  transformer_expected[output_index],
                  "Transformer final output byte is incorrect");
        end

        l1_read_word(20'(score_l1), actual_score_word);
        for (output_index = 0; output_index < score_bytes;
             output_index = output_index + 1) begin
            check(actual_score_word[output_index*8 +: 8] ==
                  transformer_expected_score[output_index],
                  "Transformer QK score is incorrect");
        end
        check((actual_score_word[7:0] != 0) &&
              (actual_score_word[15:8] != 0) &&
              (actual_score_word[23:16] != 0) &&
              (actual_score_word[31:24] != 0),
              "Transformer QK score fixture is zero");

        l1_read_word(20'(probability_l1), actual_probability_word);
        for (output_index = 0; output_index < probability_bytes;
             output_index = output_index + 1) begin
            check(actual_probability_word[output_index*8 +: 8] ==
                  transformer_expected_probability[output_index],
                  "Transformer Softmax output is incorrect");
        end

        l1_read_word(20'(context_l1), actual_context_word);
        for (output_index = 0; output_index < context_bytes;
             output_index = output_index + 1) begin
            check(actual_context_word[output_index*8 +: 8] ==
                  transformer_expected_context[output_index],
                  "Transformer attention context is incorrect");
        end

        check(system_bus_read_handshakes ==
              weight_bytes + input_bytes,
              "Transformer AXI Master read count is incorrect");
        check(system_bus_write_handshakes == output_bytes,
              "Transformer AXI Master write count is incorrect");
        check(system_aw_handshakes_q == output_bytes,
              "Transformer output AW count is incorrect");
        check(system_w_handshakes_q == output_bytes,
              "Transformer output W count is incorrect");
        check(system_b_handshakes_q == output_bytes,
              "Transformer output B count is incorrect");
        check(cfe_low_word_count_q == command_count,
              "Transformer CFE low-word count is incorrect");
        check(cfe_high_word_count_q == command_count,
              "Transformer CFE high-word count is incorrect");
        check(!cfe_expect_high_q,
              "Transformer CFE ended with an unmatched word");
        check(!system_bus_protocol_error,
              "Transformer system-memory AXI model reported an error");
        check(!wdt_reset_req_o,
              "watchdog requested reset during Transformer inference");

        $display(
            "TB_TRANSFORMER_STAGES score=[%0d,%0d,%0d,%0d] probability=[%0d,%0d,%0d,%0d] context=[%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d]",
            $signed(actual_score_word[7:0]),
            $signed(actual_score_word[15:8]),
            $signed(actual_score_word[23:16]),
            $signed(actual_score_word[31:24]),
            $signed(actual_probability_word[7:0]),
            $signed(actual_probability_word[15:8]),
            $signed(actual_probability_word[23:16]),
            $signed(actual_probability_word[31:24]),
            $signed(actual_context_word[7:0]),
            $signed(actual_context_word[15:8]),
            $signed(actual_context_word[23:16]),
            $signed(actual_context_word[31:24]),
            $signed(actual_context_word[39:32]),
            $signed(actual_context_word[47:40]),
            $signed(actual_context_word[55:48]),
            $signed(actual_context_word[63:56])
        );
        $display(
            "TB_TRANSFORMER_OUTPUT int8=[%0d,%0d,%0d,%0d,%0d,%0d,%0d,%0d]",
            $signed(actual_output_word[7:0]),
            $signed(actual_output_word[15:8]),
            $signed(actual_output_word[23:16]),
            $signed(actual_output_word[31:24]),
            $signed(actual_output_word[39:32]),
            $signed(actual_output_word[47:40]),
            $signed(actual_output_word[55:48]),
            $signed(actual_output_word[63:56])
        );
        $display(
            "TB_TRANSFORMER_E2E_PASS commands=%0d batches=%0d master_reads=%0d master_writes=%0d",
            command_count, batch_count, system_bus_read_handshakes,
            system_bus_write_handshakes
        );
        $finish;
    end
`else
    initial begin
        logic [31:0] vector_l1_before_int16;
        logic [63:0] control_status;
        logic [79:0] command_payload;
        int unsigned reset_wait_cycles;

        core_clk_i = 1'b0;
        reset_n = 1'b0;
        dvfs_prepare_req_i = 1'b0;
        soft_reset_req_i = 1'b0;
        power_down_req_i = 1'b0;
        system_bus_backpressure = 1'b1;
        dependency_check_enable_q = 1'b0;
        protocol_checks_enable = 1'b0;
        system_dma_write_check_q = 1'b0;

        s_axi_awid_i = '0;
        s_axi_awaddr_i = '0;
        s_axi_awlen_i = '0;
        s_axi_awsize_i = 3'd3;
        s_axi_awburst_i = 2'b01;
        s_axi_awlock_i = 1'b0;
        s_axi_awcache_i = 4'd0;
        s_axi_awprot_i = 3'd0;
        s_axi_awqos_i = 4'd0;
        s_axi_awvalid_i = 1'b0;
        s_axi_wdata_i = 64'd0;
        s_axi_wstrb_i = 8'd0;
        s_axi_wlast_i = 1'b0;
        s_axi_wvalid_i = 1'b0;
        s_axi_bready_i = 1'b0;
        s_axi_arid_i = '0;
        s_axi_araddr_i = '0;
        s_axi_arlen_i = '0;
        s_axi_arsize_i = 3'd3;
        s_axi_arburst_i = 2'b01;
        s_axi_arlock_i = 1'b0;
        s_axi_arcache_i = 4'd0;
        s_axi_arprot_i = 3'd0;
        s_axi_arqos_i = 4'd0;
        s_axi_arvalid_i = 1'b0;
        s_axi_rready_i = 1'b0;
        for (int unsigned index = 0; index < 8; index++) begin
            command_words[index] = 128'd0;
        end

        repeat (8) @(posedge core_clk_i);
        @(negedge core_clk_i);
        reset_n = 1'b1;
        repeat (6) @(posedge core_clk_i);
        protocol_checks_enable = 1'b1;
        check(!accept_new_cmd_o,
              "NPU accepted commands before CORE_CONTROL.START");

        axi_write_single(CSR_CORE_CONTROL, 64'h1, 8'hff);
        axi_write_single(CSR_L1_HOST_ACCESS_CONTROL, 64'h1, 8'hff);
        repeat (2) @(posedge core_clk_i);
        check(accept_new_cmd_o, "NPU did not enter the running state");

        // Matrix producer and Vector consumer use event 0:1.
        l1_write_word(20'h00100, 64'h0000_0204_ff03_0201, 8'h3f);
        l1_write_word(20'h00200, 64'h0000_0000_0000_ff02, 8'h03);
        l1_write_word(20'h00208, 64'h0000_0000_0000_0103, 8'h03);
        l1_write_word(20'h00210, 64'h0000_0000_0000_04fe, 8'h03);
        l1_write_word(20'h00300, 64'h0a07_0301_00ff_fcf8, 8'hff);
        l1_write_word(20'h00400, 64'h0101_0101_0101_0101, 8'hff);

        command_payload = {
            14'h004, 14'h008, 14'h018, 12'd0,
            6'd1, 6'd1, 6'd2,
            1'b0, NPU_DTYPE_INT32, 5'd0
        };
        command_words[0] = make_command(
            6'd12, 10'h101, NPU_DTYPE_INT8, command_payload,
            8'hff, 8'hff, 8'h01
        );
        command_payload = {
            16'h0030, 16'h0040, 16'h0000, 16'h0050,
            5'd0, 5'd7, 2'd0, 2'd0, 2'd0
        };
        command_words[1] = make_command(
            6'd16, 10'h102, NPU_DTYPE_INT8, command_payload,
            8'h01, 8'hff, 8'hff
        );
        dependency_check_enable_q = 1'b1;
        axi_submit_commands(2);
        read_command_response(12'h101, NPU_STATUS_SUCCESS);
        read_command_response(12'h102, NPU_STATUS_SUCCESS);

        ctl_request(NPU_CTL_WAIT, 64'h001, 64'd50000, ctl_data);
        check(ctl_data[2:0] == NPU_EVENT_SUCCESS,
              "WAIT did not return event success");
        check(ctl_data[19:8] == 12'h101,
              "WAIT returned the wrong producer command_id");

        ctl_request(NPU_CTL_FENCE, 64'hf, 64'd50000, ctl_data);
        check(ctl_data[7:0] == NPU_STATUS_SUCCESS,
              "FENCE returned a failure for valid tasks");
        dependency_check_enable_q = 1'b0;

        query_task(12'h101, 3'd0, ctl_data);
        check((ctl_data[3:0] == 4'd3) &&
              (ctl_data[11:4] == NPU_STATUS_SUCCESS) &&
              (ctl_data[23:12] == 12'h101),
              "Matrix terminal status is incorrect");
        query_task(12'h101, 3'd3, ctl_data);
        check(ctl_data == 64'd4, "Matrix progress is not four outputs");
        query_task(12'h102, 3'd0, ctl_data);
        check((ctl_data[3:0] == 4'd3) &&
              (ctl_data[11:4] == NPU_STATUS_SUCCESS),
              "Vector terminal status is incorrect");
        query_task(12'h102, 3'd3, ctl_data);
        check(ctl_data == 64'd8, "Vector progress is not eight outputs");

        l1_read_word(20'h00600, read_data);
        check(read_data == 64'h0000_000d_0000_0002,
              "Matrix result row zero is incorrect");
        l1_read_word(20'h00608, read_data);
        check(read_data == 64'h0000_000d_0000_0006,
              "Matrix result row one is incorrect");
        l1_read_word(20'h00500, read_data);
        check(read_data == 64'h0b08_0402_0100_fdf9,
              "Vector result is incorrect");
        acknowledge_task(12'h101);
        acknowledge_task(12'h102);
        query_task(12'h101, 3'd0, ctl_data);
        check((ctl_data[3:0] == 4'd0) &&
              (ctl_data[11:4] == NPU_STATUS_NOT_FOUND),
              "ACK did not release the Matrix task slot");
        // DMA moves eight bytes from a normal system-bus memory target into L1.
        u_system_memory.write_u64(64'h3000, 64'h0a07_0301_00ff_fcf8);
        command_payload = {
            28'h800_3000, 28'h000_0900, 20'd8,
            NPU_DTYPE_INT8, 1'b0, 1'b0
        };
        command_words[0] = make_command(
            6'd5, 10'h103, NPU_DTYPE_INT8, command_payload,
            8'hff, 8'hff, 8'hff
        );
        axi_submit_commands(1);
        read_command_response(12'h103, NPU_STATUS_SUCCESS);
        ctl_request(NPU_CTL_FENCE, 64'h1, 64'd50000, ctl_data);
        check(ctl_data[7:0] == NPU_STATUS_SUCCESS,
              "DMA FENCE returned a failure");
        query_task(12'h103, 3'd3, ctl_data);
        check(ctl_data == 64'd8, "DMA progress is not eight bytes");
        l1_read_word(20'h00900, read_data);
        check(read_data == 64'h0a07_0301_00ff_fcf8,
              "DMA system-memory-to-L1 result is incorrect");
        acknowledge_task(12'h103);

        // DMA moves eight INT8 values from L1 to system memory.  Each element
        // uses one narrow-strobe AXI write to the same aligned 64-bit word.
        l1_write_word(20'h00d00, 64'h8877_6655_4433_2211, 8'hff);
        check((system_bus_write_handshakes == 32'd0) &&
              (system_aw_handshakes_q == 32'd0) &&
              (system_w_handshakes_q == 32'd0) &&
              (system_b_handshakes_q == 32'd0),
              "system writes occurred before the L1-to-system DMA");
        system_dma_write_check_q = 1'b1;
        command_payload = {
            28'h000_0d00, 28'h800_3100, 20'd8,
            NPU_DTYPE_INT8, 1'b0, 1'b0
        };
        command_words[0] = make_command(
            6'd5, 10'h109, NPU_DTYPE_INT8, command_payload,
            8'hff, 8'hff, 8'h02
        );
        axi_submit_commands(1);
        read_command_response(12'h109, NPU_STATUS_SUCCESS);
        ctl_request(NPU_CTL_WAIT, 64'h002, 64'd50000, ctl_data);
        check(ctl_data[2:0] == NPU_EVENT_SUCCESS,
              "L1-to-system DMA event did not report success");
        check(ctl_data[19:8] == 12'h109,
              "L1-to-system DMA event returned the wrong producer");
        query_task(12'h109, 3'd0, ctl_data);
        check((ctl_data[3:0] == 4'd3) &&
              (ctl_data[11:4] == NPU_STATUS_SUCCESS) &&
              (ctl_data[23:12] == 12'h109),
              "L1-to-system DMA terminal status is incorrect");
        query_task(12'h109, 3'd3, ctl_data);
        check(ctl_data == 64'd8,
              "L1-to-system DMA progress is not eight bytes");
        check((system_aw_handshakes_q == 32'd8) &&
              (system_w_handshakes_q == 32'd8) &&
              (system_b_handshakes_q == 32'd8) &&
              (system_bus_write_handshakes == 32'd8),
              "L1-to-system DMA did not complete eight AW/W/B transfers");
        check(u_system_memory.read_u64(64'h3100) ==
              64'h8877_6655_4433_2211,
              "L1-to-system DMA memory result is incorrect");
        acknowledge_task(12'h109);
        query_task(12'h109, 3'd0, ctl_data);
        check((ctl_data[3:0] == 4'd0) &&
              (ctl_data[11:4] == NPU_STATUS_NOT_FOUND),
              "L1-to-system DMA ACK did not release its task slot");
        system_dma_write_check_q = 1'b0;

        // Complex ACT demonstrates INT to internal math to INT.
        l1_write_word(20'h00700, 64'h0000_0000_0400_fffc, 8'h0f);
        command_payload = {
            16'h0070, 16'h0000, 16'h0080,
            5'd0, 8'd3,
            2'd1, 4'd0, 4'd0, NPU_DTYPE_INT8, 2'd0, 5'd0
        };
        command_words[0] = make_command(
            6'd26, 10'h104, NPU_DTYPE_INT8, command_payload,
            8'hff, 8'hff, 8'hff
        );
        axi_submit_commands(1);
        read_command_response(12'h104, NPU_STATUS_SUCCESS);
        ctl_request(NPU_CTL_FENCE, 64'h8, 64'd50000, ctl_data);
        check(ctl_data[7:0] == NPU_STATUS_SUCCESS,
              "Complex FENCE returned a failure");
        query_task(12'h104, 3'd3, ctl_data);
        check(ctl_data == 64'd4, "Complex progress is not four outputs");
        l1_read_word(20'h00800, read_data);
        check((read_data & 64'hffff_ffff) == 64'h0100_ffff,
              "Complex ACT result is incorrect");
        acknowledge_task(12'h104);

        // INT16 Vector ADD verifies 16-bit loads, arithmetic and stores.
        l1_write_word(
            20'h00a00, 64'hfc70_012c_fffe_0001, 8'hff
        );
        l1_write_word(
            20'h00a10, 64'h0008_fff9_0006_0005, 8'hff
        );
        vector_l1_before_int16 = vector_l1_handshakes_q;
        command_payload = {
            16'h00a0, 16'h00a1, 16'h0000, 16'h00a2,
            5'd0, 5'd3, 2'd0, 2'd0, 2'd0
        };
        command_words[0] = make_command(
            6'd16, 10'h105, NPU_DTYPE_INT16, command_payload,
            8'hff, 8'hff, 8'hff
        );
        axi_submit_commands(1);
        read_command_response(12'h105, NPU_STATUS_SUCCESS);
        ctl_request(NPU_CTL_FENCE, 64'h4, 64'd50000, ctl_data);
        check(ctl_data[7:0] == NPU_STATUS_SUCCESS,
              "INT16 Vector FENCE returned a failure");
        query_task(12'h105, 3'd0, ctl_data);
        check((ctl_data[3:0] == 4'd3) &&
              (ctl_data[11:4] == NPU_STATUS_SUCCESS),
              "INT16 Vector task status is incorrect");
        query_task(12'h105, 3'd3, ctl_data);
        check(ctl_data == 64'd4,
              "INT16 Vector progress is not four outputs");
        l1_read_word(20'h00a20, read_data);
        check(read_data == 64'hfc78_0125_0004_0006,
              "INT16 Vector result is incorrect");
        check(vector_l1_handshakes_q == vector_l1_before_int16 + 32'd12,
              "INT16 Vector request count is incorrect");
        acknowledge_task(12'h105);

        // INT16 Matrix uses tiled B storage and INT16 output scaling.
        l1_write_word(
            20'h00b00, 64'hffff_0003_0002_0001, 8'hff
        );
        l1_write_word(
            20'h00b08, 64'h0000_0000_0002_0004, 8'h0f
        );
        l1_write_word(
            20'h00b40, 64'h0000_0000_ffff_0002, 8'h0f
        );
        l1_write_word(
            20'h00b50, 64'h0000_0000_0001_0003, 8'h0f
        );
        l1_write_word(
            20'h00b60, 64'h0000_0000_0004_fffe, 8'h0f
        );

        command_payload = {
            14'h02c, 14'h02d, 14'h031, 12'd0,
            6'd1, 6'd1, 6'd2,
            1'b0, NPU_DTYPE_INT16, 5'd1
        };
        command_words[0] = make_command(
            6'd12, 10'h106, NPU_DTYPE_INT16, command_payload,
            8'hff, 8'hff, 8'hff
        );

        // INT32 output does not accept a nonzero output shift.
        command_payload[6:5] = NPU_DTYPE_INT32;
        command_words[1] = make_command(
            6'd12, 10'h107, NPU_DTYPE_INT16, command_payload,
            8'hff, 8'hff, 8'hff
        );

        axi_submit_commands(2);
        read_command_response(12'h106, NPU_STATUS_SUCCESS);
        read_command_response(12'h107, NPU_STATUS_SUCCESS);

        // Cancel an active Matrix FENCE request.
        axi_write_single(CTL_ARG0, 64'h2, 8'hff);
        axi_write_single(CTL_ARG1, 64'd50000, 8'hff);
        axi_write_single(CTL_START, 64'd3, 8'hff);
        axi_write_single(CTL_CANCEL, 64'd1, 8'hff);
        axi_read_single(CTL_STATUS, control_status);
        check(control_status[1] && !control_status[0] &&
              (control_status[15:8] == NPU_STATUS_ABORTED) &&
              (control_status[63:16] == 48'd0) &&
              (control_status[7:2] == 6'd0),
              "CTL_CANCEL did not finish the FENCE as ABORTED");
        axi_read_single(CTL_RESULT, ctl_data);
        check(ctl_data[7:0] == NPU_STATUS_ABORTED,
              "CTL_CANCEL result is not ABORTED");

        ctl_request(NPU_CTL_FENCE, 64'h2, 64'd50000, ctl_data);
        check(ctl_data[7:0] == NPU_STATUS_BAD_DESC,
              "invalid Matrix payload did not produce BAD_DESC");
        for (int unsigned index = 0; index < 2; index++) begin
            query_task(12'(12'h106 + index), 3'd0, ctl_data);
            check((ctl_data[3:0] == 4'd3) &&
                  (ctl_data[11:4] ==
                   (index == 0 ? NPU_STATUS_SUCCESS :
                                 NPU_STATUS_BAD_DESC)),
                  "INT16 Matrix task status is incorrect");
            query_task(12'(12'h106 + index), 3'd3, ctl_data);
            check(ctl_data == (index == 0 ? 64'd4 : 64'd0),
                  "INT16 Matrix progress is incorrect");
            if (index == 0) begin
                acknowledge_task(12'h106);
            end
        end
        l1_read_word(20'h00c40, read_data);
        check(read_data == 64'h0006_0003_0006_0001,
              "INT16 Matrix output scaling result is incorrect");
        check(matrix_int16_valid_l1_handshakes_q == 32'd28,
              "INT16 Matrix issued an unexpected L1 request count");
        check(matrix_int16_invalid_l1_handshakes_q == 32'd0,
              "invalid Matrix payload issued an L1 request");

        repeat (5) @(posedge core_clk_i);
        $display(
            "TB_SYSTEM_COUNTS system_reads=%0d system_writes=%0d",
            system_bus_read_handshakes,
            system_bus_write_handshakes
        );
        check(system_bus_read_handshakes == 32'd8,
              "system-bus read count does not include eight DMA reads");
        check(system_bus_write_handshakes == 32'd8,
              "system-bus write count does not include eight DMA writes");
        check(!system_bus_protocol_error,
              "system-bus AXI model detected a protocol error");
        check(cfe_low_word_count_q == 32'd8,
              "CFE did not receive eight command low words");
        check(cfe_high_word_count_q == 32'd8,
              "CFE did not receive eight command high words");
        check(!cfe_expect_high_q, "CFE ended with an unmatched low word");
        check(!wdt_reset_req_o, "watchdog unexpectedly requested reset");
        check(!(irq_done_o || irq_exception_o || irq_error_o),
              "masked interrupt unexpectedly asserted");

        // Keep the terminal BAD_DESC task unacknowledged.  A soft reset must
        // complete even though the task table still contains this entry.
        check(dut.task_occupancy == 16'd1,
              "soft-reset fixture did not retain one terminal task");
        check(!dut.scheduler_idle,
              "Scheduler reported idle with a retained terminal task");
        @(negedge core_clk_i);
        soft_reset_req_i = 1'b1;
        for (reset_wait_cycles = 0;
             reset_wait_cycles < 200;
             reset_wait_cycles = reset_wait_cycles + 1) begin
            @(posedge core_clk_i);
            if (soft_reset_done_o) begin
                break;
            end
        end
        check(soft_reset_done_o,
              "soft reset timed out with a retained terminal task");
        check(dut.task_occupancy == 16'd0,
              "soft reset did not clear the retained terminal task");
        $display(
            "TB_SOFT_RESET_PASS retained_tasks=1 completion_cycles=%0d",
            reset_wait_cycles + 1
        );

        @(negedge core_clk_i);
        soft_reset_req_i = 1'b0;
        for (reset_wait_cycles = 0;
             reset_wait_cycles < 20;
             reset_wait_cycles = reset_wait_cycles + 1) begin
            @(posedge core_clk_i);
            if (!soft_reset_done_o) begin
                break;
            end
        end
        check(!soft_reset_done_o,
              "soft reset completion stayed asserted after request release");
        repeat (2) @(posedge core_clk_i);
        check(!accept_new_cmd_o,
              "NPU accepted commands after returning to the stopped state");
        check(core_idle_o,
              "NPU did not become idle after soft reset");

        $display(
            "TB_SYSTEM_PASS commands=8 system_reads=%0d system_writes=%0d matrix_l1=%0d vector_l1=%0d",
            system_bus_read_handshakes,
            system_bus_write_handshakes, matrix_l1_handshakes_q,
            vector_l1_handshakes_q
        );
        $finish;
    end
`endif

    initial begin
        #20000000;
        $fatal(1, "single-core system test timed out");
    end

endmodule
