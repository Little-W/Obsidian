module tb_memory_smoke;
  import npu_rtl_pkg::*;

  localparam int unsigned L1_CLIENTS = 6;

  logic clk;
  logic reset_n;

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

  logic mif_req_valid;
  logic mif_req_ready;
  logic mif_req_write;
  logic [47:0] mif_req_addr;
  logic [63:0] mif_req_wdata;
  logic [7:0] mif_req_wstrb;
  logic mif_rsp_valid;
  logic [63:0] mif_rsp_rdata;
  logic [2:0] mif_rsp_status;
  logic [47:0] mif_addr_base;
  logic [47:0] mif_addr_limit;
  logic [7:0] axi_awid;
  logic [39:0] axi_awaddr;
  logic [7:0] axi_awlen;
  logic [2:0] axi_awsize;
  logic [1:0] axi_awburst;
  logic axi_awlock;
  logic [3:0] axi_awcache;
  logic [2:0] axi_awprot;
  logic [3:0] axi_awqos;
  logic axi_awvalid;
  logic axi_awready;
  logic [63:0] axi_wdata;
  logic [7:0] axi_wstrb;
  logic axi_wlast;
  logic axi_wvalid;
  logic axi_wready;
  logic [7:0] axi_bid;
  logic [1:0] axi_bresp;
  logic axi_bvalid;
  logic axi_bready;
  logic [7:0] axi_arid;
  logic [39:0] axi_araddr;
  logic [7:0] axi_arlen;
  logic [2:0] axi_arsize;
  logic [1:0] axi_arburst;
  logic axi_arlock;
  logic [3:0] axi_arcache;
  logic [2:0] axi_arprot;
  logic [3:0] axi_arqos;
  logic axi_arvalid;
  logic axi_arready;
  logic [7:0] axi_rid;
  logic [63:0] axi_rdata;
  logic [1:0] axi_rresp;
  logic axi_rlast;
  logic axi_rvalid;
  logic axi_rready;
  logic mif_error_valid;
  logic [47:0] mif_error_addr;
  logic [2:0] mif_error_status;
  logic mif_idle;
  logic aw_seen_q;
  logic w_seen_q;
  logic [1:0] next_read_response;
  int unsigned read_count;
  int unsigned write_count;

  always #5 clk = ~clk;

  npu_l1buf #(
    .CLIENTS(L1_CLIENTS),
    .L1_BYTES(256),
    .BANKS(4)
  ) u_l1 (
    .clk_i(clk),
    .reset_n(reset_n),
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

  npu_axi_mif_master u_mif (
    .clk_i(clk),
    .reset_n(reset_n),
    .req_valid_i(mif_req_valid),
    .req_ready_o(mif_req_ready),
    .req_write_i(mif_req_write),
    .req_addr_i(mif_req_addr),
    .req_wdata_i(mif_req_wdata),
    .req_wstrb_i(mif_req_wstrb),
    .rsp_valid_o(mif_rsp_valid),
    .rsp_ready_i(1'b1),
    .rsp_rdata_o(mif_rsp_rdata),
    .rsp_status_o(mif_rsp_status),
    .addr_base_i(mif_addr_base),
    .addr_limit_i(mif_addr_limit),
    .m_axi_awid_o(axi_awid),
    .m_axi_awaddr_o(axi_awaddr),
    .m_axi_awlen_o(axi_awlen),
    .m_axi_awsize_o(axi_awsize),
    .m_axi_awburst_o(axi_awburst),
    .m_axi_awlock_o(axi_awlock),
    .m_axi_awcache_o(axi_awcache),
    .m_axi_awprot_o(axi_awprot),
    .m_axi_awqos_o(axi_awqos),
    .m_axi_awvalid_o(axi_awvalid),
    .m_axi_awready_i(axi_awready),
    .m_axi_wdata_o(axi_wdata),
    .m_axi_wstrb_o(axi_wstrb),
    .m_axi_wlast_o(axi_wlast),
    .m_axi_wvalid_o(axi_wvalid),
    .m_axi_wready_i(axi_wready),
    .m_axi_bid_i(axi_bid),
    .m_axi_bresp_i(axi_bresp),
    .m_axi_bvalid_i(axi_bvalid),
    .m_axi_bready_o(axi_bready),
    .m_axi_arid_o(axi_arid),
    .m_axi_araddr_o(axi_araddr),
    .m_axi_arlen_o(axi_arlen),
    .m_axi_arsize_o(axi_arsize),
    .m_axi_arburst_o(axi_arburst),
    .m_axi_arlock_o(axi_arlock),
    .m_axi_arcache_o(axi_arcache),
    .m_axi_arprot_o(axi_arprot),
    .m_axi_arqos_o(axi_arqos),
    .m_axi_arvalid_o(axi_arvalid),
    .m_axi_arready_i(axi_arready),
    .m_axi_rid_i(axi_rid),
    .m_axi_rdata_i(axi_rdata),
    .m_axi_rresp_i(axi_rresp),
    .m_axi_rlast_i(axi_rlast),
    .m_axi_rvalid_i(axi_rvalid),
    .m_axi_rready_o(axi_rready),
    .error_clear_i(1'b0),
    .error_valid_o(mif_error_valid),
    .error_addr_o(mif_error_addr),
    .error_status_o(mif_error_status),
    .mif_idle_o(mif_idle)
  );

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      axi_awready <= 1'b1;
      axi_wready  <= 1'b1;
      axi_bvalid  <= 1'b0;
      axi_bid     <= 8'd0;
      axi_bresp   <= 2'b00;
      axi_arready <= 1'b1;
      axi_rvalid  <= 1'b0;
      axi_rid     <= 8'd0;
      axi_rdata   <= 64'hcafe_f00d_1234_5678;
      axi_rresp   <= 2'b00;
      axi_rlast   <= 1'b1;
      aw_seen_q   <= 1'b0;
      w_seen_q    <= 1'b0;
      read_count  <= 0;
      write_count <= 0;
    end else begin
      if (axi_awvalid && axi_awready) begin
        if ((axi_awid != 8'd0) || (axi_awaddr != 40'h1008)
            || (axi_awlen != 8'd0) || (axi_awsize != 3'd3)
            || (axi_awburst != 2'b01) || axi_awlock
            || (axi_awcache != 4'b0011) || (axi_awprot != 3'b000)
            || (axi_awqos != 4'd0)) begin
          $fatal(1, "MIF AXI write-address fields are incorrect");
        end
        aw_seen_q <= 1'b1;
      end
      if (axi_wvalid && axi_wready) begin
        if (!axi_wlast) begin
          $fatal(1, "MIF AXI write data did not assert WLAST");
        end
        w_seen_q <= 1'b1;
      end
      if (!axi_bvalid && (aw_seen_q || (axi_awvalid && axi_awready))
          && (w_seen_q || (axi_wvalid && axi_wready))) begin
        axi_bvalid <= 1'b1;
        axi_bid    <= axi_awid;
        axi_bresp  <= 2'b00;
      end else if (axi_bvalid && axi_bready) begin
        axi_bvalid  <= 1'b0;
        aw_seen_q   <= 1'b0;
        w_seen_q    <= 1'b0;
        write_count <= write_count + 1;
      end

      if (!axi_rvalid && axi_arvalid && axi_arready) begin
        if ((axi_arid != 8'd0)
            || !((axi_araddr == 40'h1000)
                 || (axi_araddr == 40'h1010)
                 || (axi_araddr == 40'hff_ffff_fff8))
            || (axi_arlen != 8'd0) || (axi_arsize != 3'd3)
            || (axi_arburst != 2'b01) || axi_arlock
            || (axi_arcache != 4'b0011) || (axi_arprot != 3'b000)
            || (axi_arqos != 4'd0)) begin
          $fatal(1, "MIF AXI read-address fields are incorrect");
        end
        axi_rvalid <= 1'b1;
        axi_rid    <= axi_arid;
        axi_rdata  <= 64'hcafe_f00d_1234_5678 ^ {24'd0, axi_araddr};
        axi_rresp  <= next_read_response;
        axi_rlast  <= 1'b1;
      end else if (axi_rvalid && axi_rready) begin
        axi_rvalid <= 1'b0;
        read_count <= read_count + 1;
      end
    end
  end

  task automatic l1_send_request(
    input int unsigned client,
    input logic write_access,
    input logic [19:0] address,
    input logic [63:0] data,
    input logic [7:0] strobe
  );
    logic accepted;
    begin
      @(negedge clk);
      l1_req_write[client] = write_access;
      l1_req_addr[client*20 +: 20] = address;
      l1_req_wdata[client*64 +: 64] = data;
      l1_req_wstrb[client*8 +: 8] = strobe;
      l1_req_valid[client] = 1'b1;
      accepted = 1'b0;
      while (!accepted) begin
        @(posedge clk);
        accepted = l1_req_ready[client];
      end
      @(negedge clk);
      l1_req_valid[client] = 1'b0;
    end
  endtask

  task automatic l1_access(
    input int unsigned client,
    input logic write_access,
    input logic [19:0] address,
    input logic [63:0] data,
    input logic [7:0] strobe
  );
    logic [L1_CLIENTS*64-1:0] response_data_before;
    logic [L1_CLIENTS*3-1:0] response_status_before;
    begin
      response_data_before = l1_rsp_rdata;
      response_status_before = l1_rsp_status;
      l1_send_request(client, write_access, address, data, strobe);
      wait (l1_rsp_valid[client]);
      for (int unsigned other = 0; other < L1_CLIENTS; other++) begin
        if (other != client) begin
          if (l1_rsp_rdata[other*64 +: 64] !==
              response_data_before[other*64 +: 64]) begin
            $fatal(1, "L1 response data changed for inactive client %0d",
                   other);
          end
          if (l1_rsp_status[other*3 +: 3] !==
              response_status_before[other*3 +: 3]) begin
            $fatal(1, "L1 response status changed for inactive client %0d",
                   other);
          end
        end
      end
    end
  endtask

  task automatic expect_l1_response(
    input int unsigned client,
    input logic [2:0] expected_status,
    input logic [63:0] expected_data
  );
    logic [L1_CLIENTS-1:0] expected_valid;
    begin
      expected_valid = '0;
      expected_valid[client] = 1'b1;
      if (l1_rsp_valid !== expected_valid) begin
        $fatal(1,
               "L1 response valid mismatch client=%0d expected=%b got=%b",
               client, expected_valid, l1_rsp_valid);
      end
      if (l1_rsp_status[client*3 +: 3] !== expected_status) begin
        $fatal(1,
               "L1 response status mismatch client=%0d expected=%0d got=%0d",
               client, expected_status,
               l1_rsp_status[client*3 +: 3]);
      end
      if (l1_rsp_rdata[client*64 +: 64] !== expected_data) begin
        $fatal(1, "L1 response data mismatch client=%0d", client);
      end
    end
  endtask

  task automatic consume_l1_responses;
    begin
      @(posedge clk);
      @(negedge clk);
      if (l1_rsp_valid != '0) begin
        $fatal(1, "L1 response did not clear after ready handshake");
      end
    end
  endtask

  task automatic l1_backpressure_check(
    input int unsigned client,
    input logic [19:0] address,
    input logic [63:0] data
  );
    begin
      @(negedge clk);
      l1_rsp_ready[client] = 1'b0;
      l1_access(client, 1'b1, address, data, 8'hff);
      expect_l1_response(client, NPU_L1_OK, 64'd0);
      repeat (3) begin
        @(posedge clk);
        @(negedge clk);
        expect_l1_response(client, NPU_L1_OK, 64'd0);
      end
      l1_rsp_ready[client] = 1'b1;
      consume_l1_responses();
    end
  endtask

  task automatic l1_concurrent_return_check(
    input int unsigned read_client,
    input int unsigned request_client,
    input logic [19:0] read_address,
    input logic [63:0] read_data,
    input logic [19:0] write_address,
    input logic [63:0] write_data
  );
    logic [L1_CLIENTS*64-1:0] response_data_before;
    logic [L1_CLIENTS*3-1:0] response_status_before;
    logic [L1_CLIENTS-1:0] expected_valid;
    begin
      response_data_before = l1_rsp_rdata;
      response_status_before = l1_rsp_status;
      l1_send_request(read_client, 1'b0, read_address, 64'd0, 8'd0);

      l1_req_write[request_client] = 1'b1;
      l1_req_addr[request_client*20 +: 20] = write_address;
      l1_req_wdata[request_client*64 +: 64] = write_data;
      l1_req_wstrb[request_client*8 +: 8] = 8'hff;
      l1_req_valid[request_client] = 1'b1;

      @(posedge clk);
      if (!l1_req_ready[request_client]) begin
        $fatal(1,
               "L1 did not accept client %0d while returning client %0d read",
               request_client, read_client);
      end
      @(negedge clk);
      l1_req_valid[request_client] = 1'b0;

      @(posedge clk);
      @(negedge clk);
      expected_valid = '0;
      expected_valid[read_client] = 1'b1;
      expected_valid[request_client] = 1'b1;
      if (l1_rsp_valid !== expected_valid) begin
        $fatal(1,
               "L1 concurrent response mismatch expected=%b got=%b",
               expected_valid, l1_rsp_valid);
      end
      if ((l1_rsp_status[read_client*3 +: 3] !== NPU_L1_OK)
          || (l1_rsp_rdata[read_client*64 +: 64] !== read_data)) begin
        $fatal(1, "L1 concurrent read response is incorrect");
      end
      if ((l1_rsp_status[request_client*3 +: 3] !== NPU_L1_OK)
          || (l1_rsp_rdata[request_client*64 +: 64] !== 64'd0)) begin
        $fatal(1, "L1 concurrent write response is incorrect");
      end
      for (int unsigned other = 0; other < L1_CLIENTS; other++) begin
        if ((other != read_client) && (other != request_client)) begin
          if (l1_rsp_rdata[other*64 +: 64] !==
              response_data_before[other*64 +: 64]) begin
            $fatal(1,
                   "L1 concurrent operation changed client %0d response data",
                   other);
          end
          if (l1_rsp_status[other*3 +: 3] !==
              response_status_before[other*3 +: 3]) begin
            $fatal(1,
                   "L1 concurrent operation changed client %0d status",
                   other);
          end
        end
      end
      consume_l1_responses();
    end
  endtask

  task automatic l1_same_client_busy_check(
    input int unsigned client,
    input logic [19:0] address,
    input logic [63:0] expected_data
  );
    begin
      @(negedge clk);
      l1_rsp_ready[client] = 1'b0;
      l1_req_write[client] = 1'b0;
      l1_req_addr[client*20 +: 20] = address;
      l1_req_wdata[client*64 +: 64] = 64'd0;
      l1_req_wstrb[client*8 +: 8] = 8'd0;
      l1_req_valid[client] = 1'b1;

      @(posedge clk);
      if (!l1_req_ready[client]) begin
        $fatal(1, "L1 did not accept the initial read request");
      end

      @(negedge clk);
      if (l1_req_ready[client] || l1_idle) begin
        $fatal(1, "L1 request register did not block the same client");
      end

      @(posedge clk);
      @(negedge clk);
      if (l1_req_ready[client] || l1_idle) begin
        $fatal(1, "L1 read wait state did not block the same client");
      end

      @(posedge clk);
      @(negedge clk);
      if (l1_req_ready[client] || l1_idle) begin
        $fatal(1, "L1 pending response did not block the same client");
      end
      expect_l1_response(client, NPU_L1_OK, expected_data);

      l1_req_valid[client] = 1'b0;
      l1_rsp_ready[client] = 1'b1;
      consume_l1_responses();
    end
  endtask

  task automatic mif_access(
    input logic write_access,
    input logic [47:0] address,
    input logic [63:0] data
  );
    begin
      @(negedge clk);
      mif_req_write = write_access;
      mif_req_addr  = address;
      mif_req_wdata = data;
      mif_req_wstrb = 8'hff;
      mif_req_valid = 1'b1;
      while (!mif_req_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      mif_req_valid = 1'b0;
      wait (mif_rsp_valid);
    end
  endtask

  initial begin
    clk              = 1'b0;
    reset_n          = 1'b0;
    l1_req_valid     = '0;
    l1_req_write     = '0;
    l1_req_addr      = '0;
    l1_req_wdata     = '0;
    l1_req_wstrb     = '0;
    l1_rsp_ready     = '1;
    mif_req_valid    = 1'b0;
    mif_req_write    = 1'b0;
    mif_req_addr     = 48'd0;
    mif_req_wdata    = 64'd0;
    mif_req_wstrb    = 8'd0;
    mif_addr_base    = 48'h1000;
    mif_addr_limit   = 48'h1ff8;
    next_read_response = 2'b00;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;
    repeat (2) @(posedge clk);

    for (int unsigned client = 0;
         client < L1_CLIENTS; client++) begin
      l1_access(
        client,
        1'b1,
        20'(client * 8),
        64'h1100_0000_0000_0000 + 64'(client),
        8'hff
      );
      expect_l1_response(client, NPU_L1_OK, 64'd0);
      consume_l1_responses();

      l1_access(client, 1'b0, 20'(client * 8), 64'd0, 8'd0);
      expect_l1_response(
        client,
        NPU_L1_OK,
        64'h1100_0000_0000_0000 + 64'(client)
      );
      consume_l1_responses();
    end

    l1_same_client_busy_check(
      0, 20'h00000, 64'h1100_0000_0000_0000
    );

    l1_access(
      0, 1'b1, 20'h00038, 64'h1122_3344_5566_7788, 8'hff
    );
    expect_l1_response(0, NPU_L1_OK, 64'd0);
    consume_l1_responses();
    l1_access(
      1, 1'b1, 20'h00038, 64'haaaa_bbbb_cccc_dddd, 8'h0f
    );
    expect_l1_response(1, NPU_L1_OK, 64'd0);
    consume_l1_responses();
    l1_access(2, 1'b0, 20'h00038, 64'd0, 8'd0);
    expect_l1_response(
      2, NPU_L1_OK, 64'h1122_3344_cccc_dddd
    );
    consume_l1_responses();

    for (int unsigned client = 0;
         client < L1_CLIENTS; client++) begin
      l1_access(
        client, 1'b0, 20'h00041 + 20'(client * 8), 64'd0, 8'd0
      );
      expect_l1_response(
        client, NPU_L1_PROTOCOL_ERROR, 64'd0
      );
      consume_l1_responses();

      l1_access(client, 1'b0, 20'h00100, 64'd0, 8'd0);
      expect_l1_response(client, NPU_L1_ADDR_FAULT, 64'd0);
      consume_l1_responses();
    end

    for (int unsigned client = 0;
         client < L1_CLIENTS; client++) begin
      l1_backpressure_check(
        client,
        20'h00080 + 20'(client * 8),
        64'h2200_0000_0000_0000 + 64'(client)
      );
    end

    for (int unsigned client = 0;
         client < L1_CLIENTS; client++) begin
      l1_concurrent_return_check(
        client,
        (client + 1) % L1_CLIENTS,
        20'(client * 8),
        64'h1100_0000_0000_0000 + 64'(client),
        20'h000c0 + 20'(client * 8),
        64'h3300_0000_0000_0000 + 64'(client)
      );
    end

    mif_access(1'b0, 48'h1000, 64'd0);
    if ((mif_rsp_status != NPU_MEM_OK)
        || (mif_rsp_rdata !=
            (64'hcafe_f00d_1234_5678 ^ 64'h0000_0000_0000_1000))) begin
      $fatal(1, "MIF AXI read failed");
    end
    @(posedge clk);
    mif_access(1'b1, 48'h1008, 64'hdead_beef_0123_4567);
    if ((mif_rsp_status != NPU_MEM_OK)
        || (axi_wdata != 64'hdead_beef_0123_4567)
        || (axi_wstrb != 8'hff)) begin
      $fatal(1, "MIF AXI write failed");
    end
    @(posedge clk);
    next_read_response = 2'b11;
    mif_access(1'b0, 48'h1010, 64'd0);
    if (mif_rsp_status != NPU_MEM_DECERR) begin
      $fatal(1, "MIF did not report AXI DECERR");
    end
    @(posedge clk);
    mif_access(1'b0, 48'h2000, 64'd0);
    if (mif_rsp_status != NPU_MEM_ADDR) begin
      $fatal(1, "MIF accepted a physical address outside its configured range");
    end
    @(posedge clk);
    mif_access(1'b0, 48'h1004, 64'd0);
    if (mif_rsp_status != NPU_MEM_ADDR) begin
      $fatal(1, "MIF accepted a misaligned physical address");
    end
    @(posedge clk);
    mif_addr_base  = 48'd0;
    mif_addr_limit = 48'hffff_ffff_fff8;
    next_read_response = 2'b00;
    mif_access(1'b0, 48'h00ff_ffff_fff8, 64'd0);
    if (mif_rsp_status != NPU_MEM_OK) begin
      $fatal(1, "MIF rejected the highest aligned 40-bit physical address");
    end
    @(posedge clk);
    mif_access(1'b0, 48'h0100_0000_0000, 64'd0);
    if (mif_rsp_status != NPU_MEM_ADDR) begin
      $fatal(1, "MIF truncated a physical address with bit 40 set");
    end

    @(posedge clk);
    @(negedge clk);
    if ((read_count != 3) || (write_count != 1)) begin
      $fatal(1, "AXI target transaction counts do not match");
    end
    if (!mif_error_valid || (mif_error_addr != 48'h1010)
        || (mif_error_status != NPU_MEM_DECERR)) begin
      $fatal(1, "MIF sticky error metadata is incorrect");
    end
    if (!l1_idle || !mif_idle) begin
      $fatal(1, "memory modules did not return to idle");
    end

    $display(
      "PASS: L1BUF and direct physical-address AXI MIF signature=%0b",
      ^l1_rsp_rdata[63:0]
    );
    $finish;
  end

  initial begin
    #100000;
    $fatal(1, "memory smoke test timeout");
  end

endmodule
