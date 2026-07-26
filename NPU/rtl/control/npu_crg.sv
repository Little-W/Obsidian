module npu_crg (
  input  logic       core_clk_i,
  input  logic       noc_clk_i,
  input  logic       reset_n,
  input  logic       dvfs_prepare_req_i,
  output logic       dvfs_prepare_ack_o,
  input  logic       core_idle_i,
  input  logic       axi_idle_i,
  input  logic [7:0] module_clk_en_i,
  input  logic [7:0] module_idle_i,
  output logic [7:0] module_clk_active_o,
  output logic       core_clk_gated_o,
  output logic       noc_clk_gated_o,
  output logic       core_reset_n_o,
  output logic       noc_reset_n_o
);

  logic [1:0] core_reset_sync_q;
  logic [1:0] noc_reset_sync_q;
  logic core_gate_enable_q;
  logic noc_gate_enable_q;
  logic core_gate_request;
  logic noc_gate_request;

  assign module_clk_active_o = module_clk_en_i | ~module_idle_i;
  assign core_gate_request = (|module_clk_active_o[6:0])
                           || !core_reset_n_o;
  assign noc_gate_request  = module_clk_active_o[7]
                           || !noc_reset_n_o;
  assign core_clk_gated_o = core_clk_i & core_gate_enable_q;
  assign noc_clk_gated_o  = noc_clk_i & noc_gate_enable_q;
  assign core_reset_n_o   = core_reset_sync_q[1];
  assign noc_reset_n_o    = noc_reset_sync_q[1];
  assign dvfs_prepare_ack_o = dvfs_prepare_req_i
                            && core_idle_i && axi_idle_i;

  always_ff @(posedge core_clk_i or negedge reset_n) begin
    if (!reset_n) begin
      core_reset_sync_q <= 2'b00;
    end else begin
      core_reset_sync_q <= {core_reset_sync_q[0], 1'b1};
    end
  end

  always_ff @(posedge noc_clk_i or negedge reset_n) begin
    if (!reset_n) begin
      noc_reset_sync_q <= 2'b00;
    end else begin
      noc_reset_sync_q <= {noc_reset_sync_q[0], 1'b1};
    end
  end

  // Falling-edge updates keep each enable constant while its clock is high.
  always_ff @(negedge core_clk_i or negedge reset_n) begin
    if (!reset_n) begin
      core_gate_enable_q <= 1'b1;
    end else begin
      core_gate_enable_q <= core_gate_request;
    end
  end

  always_ff @(negedge noc_clk_i or negedge reset_n) begin
    if (!reset_n) begin
      noc_gate_enable_q <= 1'b1;
    end else begin
      noc_gate_enable_q <= noc_gate_request;
    end
  end

endmodule
