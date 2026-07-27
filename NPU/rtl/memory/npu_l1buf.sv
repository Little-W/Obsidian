module npu_l1buf_bank #(
  parameter int unsigned ROWS = 8192,
  localparam int unsigned ROW_W = (ROWS <= 1) ? 1 : $clog2(ROWS)
) (
  input  logic                 clk_i,
  input  logic                 enable_i,
  input  logic                 write_i,
  input  logic [ROW_W-1:0]     row_i,
  input  logic [63:0]          wdata_i,
  input  logic [7:0]           wstrb_i,
  output logic [63:0]          rdata_o
);
  /*
   * Keep each bank as an independent one-dimensional synchronous RAM.  This
   * form lets FPGA synthesis infer block RAM while retaining byte write
   * enables.  Memory contents intentionally have no reset.
   */
  (* ram_style = "block" *) logic [63:0] memory_q [0:ROWS-1];

  always_ff @(posedge clk_i) begin
    if (enable_i) begin
      if (write_i) begin
        for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
          if (wstrb_i[byte_idx]) begin
            memory_q[row_i][byte_idx*8 +: 8]
              <= wdata_i[byte_idx*8 +: 8];
          end
        end
      end else begin
        rdata_o <= memory_q[row_i];
      end
    end
  end

  initial begin
    if (ROWS < 1) begin
      $error("ROWS must be positive");
    end
  end
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
  logic [2:0]  rsp_status_q [CLIENTS];
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
  logic grant_write;
  logic [63:0] grant_wdata;
  logic [7:0] grant_wstrb;

  logic [BANKS-1:0] bank_enable;
  logic [BANKS*64-1:0] bank_rdata;
  logic read_pending_q;
  logic [CLIENT_W-1:0] read_client_q;
  logic [BANK_W-1:0] read_bank_q;
  logic [63:0] read_bank_data;

  always_comb begin
    grant_found  = 1'b0;
    grant_client = rr_client_q;
    for (int unsigned client_idx = 0;
         client_idx < CLIENTS; client_idx++) begin
      if (!grant_found
          && (client_idx >= int'(rr_client_q))
          && req_valid_i[client_idx]
          && (!rsp_valid_q[client_idx] || rsp_ready_i[client_idx])
          && !(read_pending_q
               && (read_client_q == CLIENT_W'(client_idx)))) begin
        grant_found  = 1'b1;
        grant_client = CLIENT_W'(client_idx);
      end
    end
    for (int unsigned client_idx = 0;
         client_idx < CLIENTS; client_idx++) begin
      if (!grant_found
          && (client_idx < int'(rr_client_q))
          && req_valid_i[client_idx]
          && (!rsp_valid_q[client_idx] || rsp_ready_i[client_idx])
          && !(read_pending_q
               && (read_client_q == CLIENT_W'(client_idx)))) begin
        grant_found  = 1'b1;
        grant_client = CLIENT_W'(client_idx);
      end
    end
  end

  always_comb begin
    req_ready_o = '0;
    if (grant_found) begin
      req_ready_o[grant_client] = 1'b1;
    end
  end

  assign grant_addr      = req_addr_i[grant_client*20 +: 20];
  assign grant_word      = grant_addr[19:3];
  assign grant_bank      = BANK_W'(grant_word % BANKS);
  assign grant_row       = ROW_W'(grant_word / BANKS);
  assign grant_bad_align = grant_addr[2:0] != 3'd0;
  assign grant_bad_range = grant_addr > 20'(L1_BYTES - 8);
  assign grant_handshake = grant_found
                         && req_valid_i[grant_client]
                         && req_ready_o[grant_client];
  assign grant_write     = req_write_i[grant_client];
  assign grant_wdata     = req_wdata_i[grant_client*64 +: 64];
  assign grant_wstrb     = req_wstrb_i[grant_client*8 +: 8];
  assign read_bank_data  =
      bank_rdata[read_bank_q*64 +: 64];

  always_comb begin
    bank_enable = '0;
    if (grant_handshake
        && !grant_bad_align
        && !grant_bad_range) begin
      bank_enable[grant_bank] = 1'b1;
    end
  end

  generate
    genvar bank;
    for (bank = 0; bank < BANKS; bank++) begin : g_bank
      npu_l1buf_bank #(
        .ROWS(ROWS)
      ) u_bank (
        .clk_i(clk_i),
        .enable_i(bank_enable[bank]),
        .write_i(grant_write),
        .row_i(grant_row),
        .wdata_i(grant_wdata),
        .wstrb_i(grant_wstrb),
        .rdata_o(bank_rdata[bank*64 +: 64])
      );
    end
  endgenerate

  generate
    genvar client;
    for (client = 0; client < CLIENTS; client++) begin : g_rsp_flat
      assign rsp_rdata_o[client*64 +: 64] = rsp_data_q[client];
      assign rsp_status_o[client*3 +: 3]  = rsp_status_q[client];
    end
  endgenerate
  assign rsp_valid_o = rsp_valid_q;
  assign l1_idle_o   = (rsp_valid_q == '0) && !read_pending_q;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      rsp_valid_q   <= '0;
      rr_client_q   <= '0;
      read_pending_q <= 1'b0;
      read_client_q  <= '0;
      read_bank_q    <= '0;
      for (int unsigned client_idx = 0;
           client_idx < CLIENTS; client_idx++) begin
        rsp_data_q[client_idx]   <= 64'd0;
        rsp_status_q[client_idx] <= NPU_L1_OK;
      end
    end else begin
      for (int unsigned client_idx = 0;
           client_idx < CLIENTS; client_idx++) begin
        if (rsp_valid_q[client_idx] && rsp_ready_i[client_idx]) begin
          rsp_valid_q[client_idx] <= 1'b0;
        end
      end

      read_pending_q <= 1'b0;
      if (read_pending_q) begin
        rsp_valid_q[read_client_q]  <= 1'b1;
        rsp_data_q[read_client_q]   <= read_bank_data;
        rsp_status_q[read_client_q] <= NPU_L1_OK;
      end

      if (grant_handshake) begin
        if (grant_bad_align) begin
          rsp_valid_q[grant_client]  <= 1'b1;
          rsp_data_q[grant_client]   <= 64'd0;
          rsp_status_q[grant_client] <= NPU_L1_PROTOCOL_ERROR;
        end else if (grant_bad_range) begin
          rsp_valid_q[grant_client]  <= 1'b1;
          rsp_data_q[grant_client]   <= 64'd0;
          rsp_status_q[grant_client] <= NPU_L1_ADDR_FAULT;
        end else if (grant_write) begin
          rsp_valid_q[grant_client]  <= 1'b1;
          rsp_data_q[grant_client]   <= 64'd0;
          rsp_status_q[grant_client] <= NPU_L1_OK;
        end else begin
          read_pending_q <= 1'b1;
          read_client_q  <= grant_client;
          read_bank_q    <= grant_bank;
        end
        if (grant_client == CLIENT_W'(CLIENTS-1)) begin
          rr_client_q <= '0;
        end else begin
          rr_client_q <= grant_client + 1'b1;
        end
      end
    end
  end

  initial begin
    if ((L1_BYTES < 8) || ((L1_BYTES % 8) != 0)) begin
      $error("L1_BYTES must be a positive multiple of 8");
    end
    if (L1_BYTES > (1 << 20)) begin
      $error("L1_BYTES exceeds the 20-bit local address range");
    end
    if ((BANKS < 1) || ((WORDS % BANKS) != 0)) begin
      $error("BANKS must divide the L1 word count");
    end
    if ((BANKS & (BANKS - 1)) != 0) begin
      $error("BANKS must be a power of two");
    end
  end

endmodule
