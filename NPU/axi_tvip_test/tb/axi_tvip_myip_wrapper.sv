module axi_tvip_myip_wrapper(tvip_axi_if axi_if);
  import tvip_axi_types_pkg::*;

  logic awready;
  logic wready;
  logic [0:0] bid;
  logic [1:0] bresp;
  logic bvalid;
  logic arready;
  logic [0:0] rid;
  logic [31:0] rdata;
  logic [1:0] rresp;
  logic rlast;
  logic rvalid;

  myip #(
    .C_S00_AXI_ID_WIDTH(1),
    .C_S00_AXI_DATA_WIDTH(32),
    .C_S00_AXI_ADDR_WIDTH(6),
    .C_S00_AXI_AWUSER_WIDTH(1),
    .C_S00_AXI_ARUSER_WIDTH(1),
    .C_S00_AXI_WUSER_WIDTH(1),
    .C_S00_AXI_RUSER_WIDTH(1),
    .C_S00_AXI_BUSER_WIDTH(1)
  ) u_dut (
    .s00_axi_aclk(axi_if.aclk),
    .s00_axi_aresetn(axi_if.areset_n),
    .s00_axi_awid(axi_if.awid[0:0]),
    .s00_axi_awaddr(axi_if.awaddr[5:0]),
    .s00_axi_awlen(axi_if.awlen),
    .s00_axi_awsize(axi_if.awsize),
    .s00_axi_awburst(axi_if.awburst),
    .s00_axi_awlock(1'b0),
    .s00_axi_awcache(axi_if.awcache),
    .s00_axi_awprot(axi_if.awprot),
    .s00_axi_awqos(axi_if.awqos),
    .s00_axi_awregion(4'b0),
    .s00_axi_awuser(1'b0),
    .s00_axi_awvalid(axi_if.awvalid),
    .s00_axi_awready(awready),
    .s00_axi_wdata(axi_if.wdata[31:0]),
    .s00_axi_wstrb(axi_if.wstrb[3:0]),
    .s00_axi_wlast(axi_if.wlast),
    .s00_axi_wuser(1'b0),
    .s00_axi_wvalid(axi_if.wvalid),
    .s00_axi_wready(wready),
    .s00_axi_bid(bid),
    .s00_axi_bresp(bresp),
    .s00_axi_buser(),
    .s00_axi_bvalid(bvalid),
    .s00_axi_bready(axi_if.bready),
    .s00_axi_arid(axi_if.arid[0:0]),
    .s00_axi_araddr(axi_if.araddr[5:0]),
    .s00_axi_arlen(axi_if.arlen),
    .s00_axi_arsize(axi_if.arsize),
    .s00_axi_arburst(axi_if.arburst),
    .s00_axi_arlock(1'b0),
    .s00_axi_arcache(axi_if.arcache),
    .s00_axi_arprot(axi_if.arprot),
    .s00_axi_arqos(axi_if.arqos),
    .s00_axi_arregion(4'b0),
    .s00_axi_aruser(1'b0),
    .s00_axi_arvalid(axi_if.arvalid),
    .s00_axi_arready(arready),
    .s00_axi_rid(rid),
    .s00_axi_rdata(rdata),
    .s00_axi_rresp(rresp),
    .s00_axi_rlast(rlast),
    .s00_axi_ruser(),
    .s00_axi_rvalid(rvalid),
    .s00_axi_rready(axi_if.rready)
  );

  always @(*) begin
    axi_if.awready = awready;
    axi_if.wready  = wready;
    axi_if.bid     = bid;
    axi_if.bresp   = tvip_axi_response'(bresp);
    axi_if.bvalid  = bvalid;
    axi_if.arready = arready;
    axi_if.rid     = rid;
    axi_if.rdata   = rdata;
    axi_if.rresp   = tvip_axi_response'(rresp);
    axi_if.rlast   = rlast;
    axi_if.rvalid  = rvalid;
  end
endmodule
