module axi_tvip_myip_wrapper(
    tvip_axi_if                  axi_if,
    npu_cmd_backend_if           backend_if,
    npu_single_core_system_if    system_if
);
  import tvip_axi_types_pkg::*;

  logic full_core_mode = 1'b0;
  logic fifo_reset_n;
  logic core_reset_n;

  logic fifo_awready;
  logic fifo_wready;
  logic [7:0] fifo_bid;
  logic [1:0] fifo_bresp;
  logic fifo_bvalid;
  logic fifo_arready;
  logic [7:0] fifo_rid;
  logic [63:0] fifo_rdata;
  logic [1:0] fifo_rresp;
  logic fifo_rlast;
  logic fifo_rvalid;

  logic fifo_cmd_valid;
  logic [63:0] fifo_cmd_data;
  logic fifo_cmd_first;
  logic fifo_cmd_last;
  logic fifo_cmd_rsp_ready;
  logic fifo_cmd_ingress_idle;

  logic core_awready;
  logic core_wready;
  logic [7:0] core_bid;
  logic [1:0] core_bresp;
  logic core_bvalid;
  logic core_arready;
  logic [7:0] core_rid;
  logic [63:0] core_rdata;
  logic [1:0] core_rresp;
  logic core_rlast;
  logic core_rvalid;

  logic core_dvfs_prepare_ack;
  logic core_soft_reset_done;
  logic core_power_down_ack;
  logic core_accept_new_cmd;
  logic core_idle;
  logic [7:0] core_module_clk_active;
  logic core_wdt_reset_req;
  logic core_irq_done;
  logic core_irq_exception;
  logic core_irq_error;

  logic [7:0] m_axi_awid;
  logic [39:0] m_axi_awaddr;
  logic [7:0] m_axi_awlen;
  logic [2:0] m_axi_awsize;
  logic [1:0] m_axi_awburst;
  logic m_axi_awlock;
  logic [3:0] m_axi_awcache;
  logic [2:0] m_axi_awprot;
  logic [3:0] m_axi_awqos;
  logic m_axi_awvalid;
  logic m_axi_awready;

  logic [63:0] m_axi_wdata;
  logic [7:0] m_axi_wstrb;
  logic m_axi_wlast;
  logic m_axi_wvalid;
  logic m_axi_wready;

  logic [7:0] m_axi_bid;
  logic [1:0] m_axi_bresp;
  logic m_axi_bvalid;
  logic m_axi_bready;

  logic [7:0] m_axi_arid;
  logic [39:0] m_axi_araddr;
  logic [7:0] m_axi_arlen;
  logic [2:0] m_axi_arsize;
  logic [1:0] m_axi_arburst;
  logic m_axi_arlock;
  logic [3:0] m_axi_arcache;
  logic [2:0] m_axi_arprot;
  logic [3:0] m_axi_arqos;
  logic m_axi_arvalid;
  logic m_axi_arready;

  logic [7:0] m_axi_rid;
  logic [63:0] m_axi_rdata;
  logic [1:0] m_axi_rresp;
  logic m_axi_rlast;
  logic m_axi_rvalid;
  logic m_axi_rready;

  initial begin
    full_core_mode = $test$plusargs("NPU_SINGLE_CORE");
  end

  assign fifo_reset_n = axi_if.areset_n && !full_core_mode;
  assign core_reset_n = axi_if.areset_n && full_core_mode;

  npu_axi_cmd_fifo_slave #(
    .AXI_ID_WIDTH(8),
    .AXI_ADDR_WIDTH(24),
    .INGRESS_DEPTH(16),
    .CMD_RSP_DEPTH(8)
  ) u_cmd_fifo (
    .clk(axi_if.aclk),
    .reset_n(fifo_reset_n),
    .s_axi_awid(axi_if.awid[7:0]),
    .s_axi_awaddr(axi_if.awaddr[23:0]),
    .s_axi_awlen(axi_if.awlen),
    .s_axi_awsize(axi_if.awsize),
    .s_axi_awburst(axi_if.awburst),
    .s_axi_awlock(backend_if.awlock),
    .s_axi_awcache(axi_if.awcache),
    .s_axi_awprot(axi_if.awprot),
    .s_axi_awqos(axi_if.awqos),
    .s_axi_awvalid(axi_if.awvalid && !full_core_mode),
    .s_axi_awready(fifo_awready),
    .s_axi_wdata(axi_if.wdata[63:0]),
    .s_axi_wstrb(axi_if.wstrb[7:0]),
    .s_axi_wlast(axi_if.wlast),
    .s_axi_wvalid(axi_if.wvalid && !full_core_mode),
    .s_axi_wready(fifo_wready),
    .s_axi_bid(fifo_bid),
    .s_axi_bresp(fifo_bresp),
    .s_axi_bvalid(fifo_bvalid),
    .s_axi_bready(axi_if.bready && !full_core_mode),
    .s_axi_arid(axi_if.arid[7:0]),
    .s_axi_araddr(axi_if.araddr[23:0]),
    .s_axi_arlen(axi_if.arlen),
    .s_axi_arsize(axi_if.arsize),
    .s_axi_arburst(axi_if.arburst),
    .s_axi_arlock(backend_if.arlock),
    .s_axi_arcache(axi_if.arcache),
    .s_axi_arprot(axi_if.arprot),
    .s_axi_arqos(axi_if.arqos),
    .s_axi_arvalid(axi_if.arvalid && !full_core_mode),
    .s_axi_arready(fifo_arready),
    .s_axi_rid(fifo_rid),
    .s_axi_rdata(fifo_rdata),
    .s_axi_rresp(fifo_rresp),
    .s_axi_rlast(fifo_rlast),
    .s_axi_rvalid(fifo_rvalid),
    .s_axi_rready(axi_if.rready && !full_core_mode),
    .cmd_valid_o(fifo_cmd_valid),
    .cmd_ready_i(backend_if.cmd_ready),
    .cmd_data_o(fifo_cmd_data),
    .cmd_first_o(fifo_cmd_first),
    .cmd_last_o(fifo_cmd_last),
    .cmd_rsp_valid_i(backend_if.cmd_rsp_valid),
    .cmd_rsp_ready_o(fifo_cmd_rsp_ready),
    .cmd_rsp_data_i(backend_if.cmd_rsp_data),
    .protocol_error_clear_i(backend_if.protocol_error_clear),
    .cmd_ingress_idle_o(fifo_cmd_ingress_idle)
  );

  npu_single_core_top #(
    .AXI_S_ID_W(8),
    .AXI_S_ADDR_W(24),
    .AXI_M_ID_W(8),
    .AXI_M_ADDR_W(40),
    .L1_BYTES(1 << 20),
    .L1_BANKS(16),
    .TASK_SLOTS(8),
    .EVENT_COUNT(255)
  ) u_single_core (
    .core_clk_i(axi_if.aclk),
    .noc_clk_i(axi_if.aclk),
    .reset_n(core_reset_n),

    .dvfs_prepare_req_i(1'b0),
    .dvfs_prepare_ack_o(core_dvfs_prepare_ack),
    .soft_reset_req_i(1'b0),
    .soft_reset_done_o(core_soft_reset_done),
    .power_down_req_i(1'b0),
    .power_down_ack_o(core_power_down_ack),
    .accept_new_cmd_o(core_accept_new_cmd),
    .core_idle_o(core_idle),
    .module_clk_active_o(core_module_clk_active),
    .wdt_reset_req_o(core_wdt_reset_req),
    .irq_done_o(core_irq_done),
    .irq_exception_o(core_irq_exception),
    .irq_error_o(core_irq_error),

    .s_axi_awid_i(axi_if.awid[7:0]),
    .s_axi_awaddr_i(axi_if.awaddr[23:0]),
    .s_axi_awlen_i(axi_if.awlen),
    .s_axi_awsize_i(axi_if.awsize),
    .s_axi_awburst_i(axi_if.awburst),
    .s_axi_awlock_i(1'b0),
    .s_axi_awcache_i(axi_if.awcache),
    .s_axi_awprot_i(axi_if.awprot),
    .s_axi_awqos_i(axi_if.awqos),
    .s_axi_awvalid_i(axi_if.awvalid && full_core_mode),
    .s_axi_awready_o(core_awready),
    .s_axi_wdata_i(axi_if.wdata[63:0]),
    .s_axi_wstrb_i(axi_if.wstrb[7:0]),
    .s_axi_wlast_i(axi_if.wlast),
    .s_axi_wvalid_i(axi_if.wvalid && full_core_mode),
    .s_axi_wready_o(core_wready),
    .s_axi_bid_o(core_bid),
    .s_axi_bresp_o(core_bresp),
    .s_axi_bvalid_o(core_bvalid),
    .s_axi_bready_i(axi_if.bready && full_core_mode),

    .s_axi_arid_i(axi_if.arid[7:0]),
    .s_axi_araddr_i(axi_if.araddr[23:0]),
    .s_axi_arlen_i(axi_if.arlen),
    .s_axi_arsize_i(axi_if.arsize),
    .s_axi_arburst_i(axi_if.arburst),
    .s_axi_arlock_i(1'b0),
    .s_axi_arcache_i(axi_if.arcache),
    .s_axi_arprot_i(axi_if.arprot),
    .s_axi_arqos_i(axi_if.arqos),
    .s_axi_arvalid_i(axi_if.arvalid && full_core_mode),
    .s_axi_arready_o(core_arready),
    .s_axi_rid_o(core_rid),
    .s_axi_rdata_o(core_rdata),
    .s_axi_rresp_o(core_rresp),
    .s_axi_rlast_o(core_rlast),
    .s_axi_rvalid_o(core_rvalid),
    .s_axi_rready_i(axi_if.rready && full_core_mode),

    .m_axi_awid_o(m_axi_awid),
    .m_axi_awaddr_o(m_axi_awaddr),
    .m_axi_awlen_o(m_axi_awlen),
    .m_axi_awsize_o(m_axi_awsize),
    .m_axi_awburst_o(m_axi_awburst),
    .m_axi_awlock_o(m_axi_awlock),
    .m_axi_awcache_o(m_axi_awcache),
    .m_axi_awprot_o(m_axi_awprot),
    .m_axi_awqos_o(m_axi_awqos),
    .m_axi_awvalid_o(m_axi_awvalid),
    .m_axi_awready_i(m_axi_awready),
    .m_axi_wdata_o(m_axi_wdata),
    .m_axi_wstrb_o(m_axi_wstrb),
    .m_axi_wlast_o(m_axi_wlast),
    .m_axi_wvalid_o(m_axi_wvalid),
    .m_axi_wready_i(m_axi_wready),
    .m_axi_bid_i(m_axi_bid),
    .m_axi_bresp_i(m_axi_bresp),
    .m_axi_bvalid_i(m_axi_bvalid),
    .m_axi_bready_o(m_axi_bready),

    .m_axi_arid_o(m_axi_arid),
    .m_axi_araddr_o(m_axi_araddr),
    .m_axi_arlen_o(m_axi_arlen),
    .m_axi_arsize_o(m_axi_arsize),
    .m_axi_arburst_o(m_axi_arburst),
    .m_axi_arlock_o(m_axi_arlock),
    .m_axi_arcache_o(m_axi_arcache),
    .m_axi_arprot_o(m_axi_arprot),
    .m_axi_arqos_o(m_axi_arqos),
    .m_axi_arvalid_o(m_axi_arvalid),
    .m_axi_arready_i(m_axi_arready),
    .m_axi_rid_i(m_axi_rid),
    .m_axi_rdata_i(m_axi_rdata),
    .m_axi_rresp_i(m_axi_rresp),
    .m_axi_rlast_i(m_axi_rlast),
    .m_axi_rvalid_i(m_axi_rvalid),
    .m_axi_rready_o(m_axi_rready)
  );

  npu_axi_system_memory_model #(
    .AXI_ID_WIDTH(8),
    .AXI_ADDR_WIDTH(40),
    .MEMORY_BYTES(1 << 20)
  ) u_system_memory (
    .clk(axi_if.aclk),
    .reset_n(core_reset_n),
    .system_if(system_if),

    .s_axi_awid(m_axi_awid),
    .s_axi_awaddr(m_axi_awaddr),
    .s_axi_awlen(m_axi_awlen),
    .s_axi_awsize(m_axi_awsize),
    .s_axi_awburst(m_axi_awburst),
    .s_axi_awlock(m_axi_awlock),
    .s_axi_awcache(m_axi_awcache),
    .s_axi_awprot(m_axi_awprot),
    .s_axi_awqos(m_axi_awqos),
    .s_axi_awvalid(m_axi_awvalid),
    .s_axi_awready(m_axi_awready),

    .s_axi_wdata(m_axi_wdata),
    .s_axi_wstrb(m_axi_wstrb),
    .s_axi_wlast(m_axi_wlast),
    .s_axi_wvalid(m_axi_wvalid),
    .s_axi_wready(m_axi_wready),

    .s_axi_bid(m_axi_bid),
    .s_axi_bresp(m_axi_bresp),
    .s_axi_bvalid(m_axi_bvalid),
    .s_axi_bready(m_axi_bready),

    .s_axi_arid(m_axi_arid),
    .s_axi_araddr(m_axi_araddr),
    .s_axi_arlen(m_axi_arlen),
    .s_axi_arsize(m_axi_arsize),
    .s_axi_arburst(m_axi_arburst),
    .s_axi_arlock(m_axi_arlock),
    .s_axi_arcache(m_axi_arcache),
    .s_axi_arprot(m_axi_arprot),
    .s_axi_arqos(m_axi_arqos),
    .s_axi_arvalid(m_axi_arvalid),
    .s_axi_arready(m_axi_arready),

    .s_axi_rid(m_axi_rid),
    .s_axi_rdata(m_axi_rdata),
    .s_axi_rresp(m_axi_rresp),
    .s_axi_rlast(m_axi_rlast),
    .s_axi_rvalid(m_axi_rvalid),
    .s_axi_rready(m_axi_rready)
  );

  always @* begin
    if (full_core_mode) begin
      axi_if.awready = core_awready;
      axi_if.wready  = core_wready;
      axi_if.bid     = tvip_axi_id'(core_bid);
      axi_if.bresp   = tvip_axi_response'(core_bresp);
      axi_if.bvalid  = core_bvalid;
      axi_if.arready = core_arready;
      axi_if.rid     = tvip_axi_id'(core_rid);
      axi_if.rdata   = tvip_axi_data'(core_rdata);
      axi_if.rresp   = tvip_axi_response'(core_rresp);
      axi_if.rlast   = core_rlast;
      axi_if.rvalid  = core_rvalid;
    end
    else begin
      axi_if.awready = fifo_awready;
      axi_if.wready  = fifo_wready;
      axi_if.bid     = tvip_axi_id'(fifo_bid);
      axi_if.bresp   = tvip_axi_response'(fifo_bresp);
      axi_if.bvalid  = fifo_bvalid;
      axi_if.arready = fifo_arready;
      axi_if.rid     = tvip_axi_id'(fifo_rid);
      axi_if.rdata   = tvip_axi_data'(fifo_rdata);
      axi_if.rresp   = tvip_axi_response'(fifo_rresp);
      axi_if.rlast   = fifo_rlast;
      axi_if.rvalid  = fifo_rvalid;
    end

    backend_if.cmd_valid = fifo_cmd_valid;
    backend_if.cmd_data = fifo_cmd_data;
    backend_if.cmd_first = fifo_cmd_first;
    backend_if.cmd_last = fifo_cmd_last;
    backend_if.cmd_rsp_ready = fifo_cmd_rsp_ready;
    backend_if.cmd_ingress_idle = fifo_cmd_ingress_idle;

    system_if.full_core_mode = full_core_mode;
    system_if.accept_new_cmd = core_accept_new_cmd;
    system_if.core_idle = core_idle;
    system_if.wdt_reset_req = core_wdt_reset_req;
    system_if.irq_done = core_irq_done;
    system_if.irq_exception = core_irq_exception;
    system_if.irq_error = core_irq_error;
  end

  logic unused_core_status;
  assign unused_core_status = ^{
    core_dvfs_prepare_ack,
    core_soft_reset_done,
    core_power_down_ack,
    core_module_clk_active
  };
endmodule
