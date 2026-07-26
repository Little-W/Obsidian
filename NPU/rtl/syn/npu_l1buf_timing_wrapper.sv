/*
 * Synthesis-only L1 timing wrapper.
 *
 * The functional RTL models 1 MiB with an unpacked behavioral array.  Mapping
 * that model to standard-cell flip-flops would distort both area and timing.
 * This wrapper keeps request arbitration, response state, bank selection, and
 * the SRAM-facing pins in the core synthesis run.  Each 64 KiB bank is a
 * black-box placeholder for a later 8192 x 64 memory macro.
 *
 * SRAM macro area, access time, setup time, and output transition are not in
 * the FreePDK45 standard-cell reports.  Sign-off must replace the placeholders
 * with characterized .db views and rerun timing.
 */

module npu_l1_sram_bank_blackbox #(
  parameter int unsigned ADDR_W = 13
) (
  input  logic                  clk_i,
  input  logic                  cs_i,
  input  logic                  write_i,
  input  logic [ADDR_W-1:0]     addr_i,
  input  logic [63:0]           wdata_i,
  input  logic [7:0]            wstrb_i,
  output logic [63:0]           rdata_o
);
  // synopsys syn_black_box
endmodule

module npu_l1buf #(
  parameter int unsigned CLIENTS   = 6,
  parameter int unsigned L1_BYTES  = 1 << 20,
  parameter int unsigned BANKS     = 16,
  localparam int unsigned CLIENT_W = (CLIENTS <= 1) ? 1 : $clog2(CLIENTS),
  localparam int unsigned WORDS    = L1_BYTES / 8,
  localparam int unsigned ROWS     = WORDS / BANKS,
  localparam int unsigned BANK_W   = (BANKS <= 1) ? 1 : $clog2(BANKS),
  localparam int unsigned ROW_W    = (ROWS <= 1) ? 1 : $clog2(ROWS)
) (
  input  logic                    clk_i,
  input  logic                    reset_n,

  input  logic [CLIENTS-1:0]      req_valid_i,
  output logic [CLIENTS-1:0]      req_ready_o,
  input  logic [CLIENTS-1:0]      req_write_i,
  input  logic [CLIENTS*20-1:0]   req_addr_i,
  input  logic [CLIENTS*64-1:0]   req_wdata_i,
  input  logic [CLIENTS*8-1:0]    req_wstrb_i,

  output logic [CLIENTS-1:0]      rsp_valid_o,
  input  logic [CLIENTS-1:0]      rsp_ready_i,
  output logic [CLIENTS*64-1:0]   rsp_rdata_o,
  output logic [CLIENTS*3-1:0]    rsp_status_o,

  output logic                    l1_idle_o
);
  import npu_rtl_pkg::*;

  logic [CLIENTS-1:0] rsp_valid_q;
  logic [63:0] rsp_data_q [CLIENTS];
  logic [2:0] rsp_status_q [CLIENTS];
  logic [CLIENT_W-1:0] rr_client_q;

  logic grant_found;
  logic [CLIENT_W-1:0] grant_client;
  logic [19:0] grant_addr;
  logic [16:0] grant_word;
  logic [BANK_W-1:0] grant_bank;
  logic [ROW_W-1:0] grant_row;
  logic grant_bad_align;
  logic grant_bad_range;
  logic grant_handshake;

  logic [BANKS-1:0] bank_cs;
  logic [BANKS-1:0][63:0] bank_rdata;
  logic [63:0] selected_bank_rdata;

  always_comb begin
    grant_found = 1'b0;
    grant_client = rr_client_q;
    for (int unsigned client_idx = 0;
         client_idx < CLIENTS; client_idx++) begin
      if (!grant_found
          && (client_idx >= int'(rr_client_q))
          && req_valid_i[client_idx]
          && (!rsp_valid_q[client_idx] || rsp_ready_i[client_idx])) begin
        grant_found = 1'b1;
        grant_client = CLIENT_W'(client_idx);
      end
    end
    for (int unsigned client_idx = 0;
         client_idx < CLIENTS; client_idx++) begin
      if (!grant_found
          && (client_idx < int'(rr_client_q))
          && req_valid_i[client_idx]
          && (!rsp_valid_q[client_idx] || rsp_ready_i[client_idx])) begin
        grant_found = 1'b1;
        grant_client = CLIENT_W'(client_idx);
      end
    end
  end

  always_comb begin
    req_ready_o = '0;
    if (grant_found)
      req_ready_o[grant_client] = 1'b1;
  end

  assign grant_addr = req_addr_i[grant_client*20 +: 20];
  assign grant_word = grant_addr[19:3];
  assign grant_bank = BANK_W'(grant_word % BANKS);
  assign grant_row = ROW_W'(grant_word / BANKS);
  assign grant_bad_align = grant_addr[2:0] != 3'd0;
  assign grant_bad_range = grant_addr > 20'(L1_BYTES - 8);
  assign grant_handshake = grant_found
                         && req_valid_i[grant_client]
                         && req_ready_o[grant_client];

  always_comb begin
    bank_cs = '0;
    if (grant_handshake && !grant_bad_align && !grant_bad_range)
      bank_cs[grant_bank] = 1'b1;
    selected_bank_rdata = bank_rdata[grant_bank];
  end

  generate
    genvar bank_idx;
    for (bank_idx = 0; bank_idx < BANKS; bank_idx++) begin : g_sram_bank
      npu_l1_sram_bank_blackbox #(
        .ADDR_W(ROW_W)
      ) u_sram_bank (
        .clk_i(clk_i),
        .cs_i(bank_cs[bank_idx]),
        .write_i(req_write_i[grant_client]),
        .addr_i(grant_row),
        .wdata_i(req_wdata_i[grant_client*64 +: 64]),
        .wstrb_i(req_wstrb_i[grant_client*8 +: 8]),
        .rdata_o(bank_rdata[bank_idx])
      );
    end
  endgenerate

  generate
    genvar rsp_client_idx;
    for (rsp_client_idx = 0;
         rsp_client_idx < CLIENTS; rsp_client_idx++) begin : g_rsp_flat
      assign rsp_rdata_o[rsp_client_idx*64 +: 64] =
        rsp_data_q[rsp_client_idx];
      assign rsp_status_o[rsp_client_idx*3 +: 3] =
        rsp_status_q[rsp_client_idx];
    end
  endgenerate

  assign rsp_valid_o = rsp_valid_q;
  assign l1_idle_o = rsp_valid_q == '0;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      rsp_valid_q <= '0;
      rr_client_q <= '0;
      for (int unsigned reset_client_idx = 0;
           reset_client_idx < CLIENTS; reset_client_idx++) begin
        rsp_data_q[reset_client_idx] <= 64'd0;
        rsp_status_q[reset_client_idx] <= NPU_L1_OK;
      end
    end else begin
      for (int unsigned retire_client_idx = 0;
           retire_client_idx < CLIENTS; retire_client_idx++) begin
        if (rsp_valid_q[retire_client_idx]
            && rsp_ready_i[retire_client_idx])
          rsp_valid_q[retire_client_idx] <= 1'b0;
      end

      if (grant_handshake) begin
        rsp_valid_q[grant_client] <= 1'b1;
        rsp_data_q[grant_client] <= selected_bank_rdata;
        if (grant_bad_align)
          rsp_status_q[grant_client] <= NPU_L1_PROTOCOL_ERROR;
        else if (grant_bad_range)
          rsp_status_q[grant_client] <= NPU_L1_ADDR_FAULT;
        else
          rsp_status_q[grant_client] <= NPU_L1_OK;

        if (grant_client == CLIENT_W'(CLIENTS-1))
          rr_client_q <= '0;
        else
          rr_client_q <= grant_client + 1'b1;
      end
    end
  end

  initial begin
    if (L1_BYTES != (1 << 20))
      $error("The timing wrapper is configured for a 1 MiB L1");
    if (BANKS != 16)
      $error("The timing wrapper expects sixteen 64 KiB SRAM banks");
    if (ROWS != 8192)
      $error("Each timing-wrapper bank must contain 8192 64-bit words");
  end

endmodule
