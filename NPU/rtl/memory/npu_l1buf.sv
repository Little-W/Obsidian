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

  logic [63:0] sram_q [BANKS][ROWS];
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

  always_comb begin
    grant_found  = 1'b0;
    grant_client = rr_client_q;
    for (int unsigned client_idx = 0;
         client_idx < CLIENTS; client_idx++) begin
      if (!grant_found
          && (client_idx >= int'(rr_client_q))
          && req_valid_i[client_idx]
          && (!rsp_valid_q[client_idx] || rsp_ready_i[client_idx])) begin
        grant_found  = 1'b1;
        grant_client = CLIENT_W'(client_idx);
      end
    end
    for (int unsigned client_idx = 0;
         client_idx < CLIENTS; client_idx++) begin
      if (!grant_found
          && (client_idx < int'(rr_client_q))
          && req_valid_i[client_idx]
          && (!rsp_valid_q[client_idx] || rsp_ready_i[client_idx])) begin
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

  generate
    genvar client;
    for (client = 0; client < CLIENTS; client++) begin : g_rsp_flat
      assign rsp_rdata_o[client*64 +: 64] = rsp_data_q[client];
      assign rsp_status_o[client*3 +: 3]  = rsp_status_q[client];
    end
  endgenerate
  assign rsp_valid_o = rsp_valid_q;
  assign l1_idle_o   = rsp_valid_q == '0;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      rsp_valid_q <= '0;
      rr_client_q <= '0;
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

      if (grant_handshake) begin
        rsp_valid_q[grant_client] <= 1'b1;
        rsp_data_q[grant_client]  <= 64'd0;
        if (grant_bad_align) begin
          rsp_status_q[grant_client] <= NPU_L1_PROTOCOL_ERROR;
        end else if (grant_bad_range) begin
          rsp_status_q[grant_client] <= NPU_L1_ADDR_FAULT;
        end else begin
          rsp_status_q[grant_client] <= NPU_L1_OK;
          if (req_write_i[grant_client]) begin
            for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
              if (req_wstrb_i[grant_client*8 + byte_idx]) begin
                sram_q[grant_bank][grant_row][byte_idx*8 +: 8]
                  <= req_wdata_i[grant_client*64 + byte_idx*8 +: 8];
              end
            end
          end else begin
            rsp_data_q[grant_client] <= sram_q[grant_bank][grant_row];
          end
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
