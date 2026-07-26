`timescale 1ns/1ps

module tb_axi_tvip_wrapper_lint;
  import tvip_axi_types_pkg::*;

  logic clk;
  logic reset_n;

  tvip_axi_if axi_if(clk, reset_n);
  npu_cmd_backend_if backend_if(clk, reset_n);
  npu_single_core_system_if system_if(clk, reset_n);

  axi_tvip_myip_wrapper u_wrapper(
    axi_if,
    backend_if,
    system_if
  );

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
  end

  always #5ns clk = ~clk;

  always_comb begin
    axi_if.awvalid = 1'b0;
    axi_if.awid = '0;
    axi_if.awaddr = '0;
    axi_if.awlen = '0;
    axi_if.awsize = TVIP_AXI_BURST_SIZE_8_BYTES;
    axi_if.awburst = TVIP_AXI_FIXED_BURST;
    axi_if.awcache = '0;
    axi_if.awprot = '0;
    axi_if.awqos = '0;
    axi_if.wvalid = 1'b0;
    axi_if.wdata = '0;
    axi_if.wstrb = '0;
    axi_if.wlast = 1'b0;
    axi_if.bready = 1'b0;
    axi_if.arvalid = 1'b0;
    axi_if.arid = '0;
    axi_if.araddr = '0;
    axi_if.arlen = '0;
    axi_if.arsize = TVIP_AXI_BURST_SIZE_8_BYTES;
    axi_if.arburst = TVIP_AXI_FIXED_BURST;
    axi_if.arcache = '0;
    axi_if.arprot = '0;
    axi_if.arqos = '0;
    axi_if.rready = 1'b0;

    backend_if.cmd_ready = 1'b0;
    backend_if.cmd_rsp_valid = 1'b0;
    backend_if.cmd_rsp_data = '0;
    backend_if.protocol_error_clear = 1'b0;
    backend_if.awlock = 1'b0;
    backend_if.arlock = 1'b0;

    system_if.system_memory_backpressure_enable = 1'b1;
  end
endmodule
