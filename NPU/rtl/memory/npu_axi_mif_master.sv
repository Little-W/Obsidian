module npu_axi_mif_master #(
  parameter int unsigned AXI_ADDR_W = 40,
  parameter int unsigned AXI_ID_W   = 8
) (
  input  logic                  clk_i,
  input  logic                  reset_n,

  input  logic                  req_valid_i,
  output logic                  req_ready_o,
  input  logic                  req_write_i,
  input  logic [47:0]           req_addr_i,
  input  logic [63:0]           req_wdata_i,
  input  logic [7:0]            req_wstrb_i,

  output logic                  rsp_valid_o,
  input  logic                  rsp_ready_i,
  output logic [63:0]           rsp_rdata_o,
  output logic [2:0]            rsp_status_o,

  input  logic [15:0]           stream_id_i,
  input  logic [15:0]           substream_id_i,
  output logic                  tbu_req_valid_o,
  input  logic                  tbu_req_ready_i,
  output logic                  tbu_req_write_o,
  output logic [47:0]           tbu_req_addr_o,
  output logic [15:0]           tbu_req_stream_id_o,
  output logic [15:0]           tbu_req_substream_id_o,
  input  logic                  tbu_rsp_valid_i,
  output logic                  tbu_rsp_ready_o,
  input  logic [47:0]           tbu_rsp_addr_i,
  input  logic [2:0]            tbu_rsp_status_i,

  output logic [AXI_ID_W-1:0]   m_axi_awid_o,
  output logic [AXI_ADDR_W-1:0] m_axi_awaddr_o,
  output logic [7:0]            m_axi_awlen_o,
  output logic [2:0]            m_axi_awsize_o,
  output logic [1:0]            m_axi_awburst_o,
  output logic                  m_axi_awlock_o,
  output logic [3:0]            m_axi_awcache_o,
  output logic [2:0]            m_axi_awprot_o,
  output logic [3:0]            m_axi_awqos_o,
  output logic                  m_axi_awvalid_o,
  input  logic                  m_axi_awready_i,

  output logic [63:0]           m_axi_wdata_o,
  output logic [7:0]            m_axi_wstrb_o,
  output logic                  m_axi_wlast_o,
  output logic                  m_axi_wvalid_o,
  input  logic                  m_axi_wready_i,

  input  logic [AXI_ID_W-1:0]   m_axi_bid_i,
  input  logic [1:0]            m_axi_bresp_i,
  input  logic                  m_axi_bvalid_i,
  output logic                  m_axi_bready_o,

  output logic [AXI_ID_W-1:0]   m_axi_arid_o,
  output logic [AXI_ADDR_W-1:0] m_axi_araddr_o,
  output logic [7:0]            m_axi_arlen_o,
  output logic [2:0]            m_axi_arsize_o,
  output logic [1:0]            m_axi_arburst_o,
  output logic                  m_axi_arlock_o,
  output logic [3:0]            m_axi_arcache_o,
  output logic [2:0]            m_axi_arprot_o,
  output logic [3:0]            m_axi_arqos_o,
  output logic                  m_axi_arvalid_o,
  input  logic                  m_axi_arready_i,

  input  logic [AXI_ID_W-1:0]   m_axi_rid_i,
  input  logic [63:0]           m_axi_rdata_i,
  input  logic [1:0]            m_axi_rresp_i,
  input  logic                  m_axi_rlast_i,
  input  logic                  m_axi_rvalid_i,
  output logic                  m_axi_rready_o,

  input  logic                  error_clear_i,
  output logic                  error_valid_o,
  output logic [47:0]           error_addr_o,
  output logic [2:0]            error_status_o,
  output logic                  mif_idle_o
);
  import npu_rtl_pkg::*;

  typedef enum logic [2:0] {
    MIF_IDLE,
    MIF_TBU_REQ,
    MIF_TBU_RSP,
    MIF_READ_ADDR,
    MIF_READ_DATA,
    MIF_WRITE_ISSUE,
    MIF_WRITE_RESP,
    MIF_INTERNAL_RESP
  } mif_state_e;

  mif_state_e state_q;
  logic req_write_q;
  logic [47:0] req_addr_q;
  logic [63:0] req_wdata_q;
  logic [7:0] req_wstrb_q;
  logic [15:0] stream_id_q;
  logic [15:0] substream_id_q;
  logic [AXI_ADDR_W-1:0] translated_addr_q;
  logic aw_done_q;
  logic w_done_q;
  logic [63:0] rsp_rdata_q;
  logic [2:0] rsp_status_q;
  logic error_valid_q;
  logic [47:0] error_addr_q;
  logic [2:0] error_status_q;

  logic aw_handshake;
  logic w_handshake;
  logic translated_addr_fits;
  logic write_channels_done;

  function automatic logic [2:0] axi_resp_status(input logic [1:0] response);
    unique case (response)
      2'b00:   return NPU_MEM_OK;
      2'b10:   return NPU_MEM_SLVERR;
      2'b11:   return NPU_MEM_DECERR;
      default: return NPU_MEM_PROTOCOL;
    endcase
  endfunction

  assign req_ready_o = state_q == MIF_IDLE;
  assign rsp_valid_o = state_q == MIF_INTERNAL_RESP;
  assign rsp_rdata_o = rsp_rdata_q;
  assign rsp_status_o = rsp_status_q;

  assign tbu_req_valid_o        = state_q == MIF_TBU_REQ;
  assign tbu_req_write_o        = req_write_q;
  assign tbu_req_addr_o         = req_addr_q;
  assign tbu_req_stream_id_o    = stream_id_q;
  assign tbu_req_substream_id_o = substream_id_q;
  assign tbu_rsp_ready_o        = state_q == MIF_TBU_RSP;

  assign m_axi_awid_o    = '0;
  assign m_axi_awaddr_o  = translated_addr_q;
  assign m_axi_awlen_o   = 8'd0;
  assign m_axi_awsize_o  = 3'd3;
  assign m_axi_awburst_o = 2'b01;
  assign m_axi_awlock_o  = 1'b0;
  assign m_axi_awcache_o = 4'b0011;
  assign m_axi_awprot_o  = 3'b000;
  assign m_axi_awqos_o   = 4'd0;
  assign m_axi_awvalid_o = (state_q == MIF_WRITE_ISSUE) && !aw_done_q;

  assign m_axi_wdata_o  = req_wdata_q;
  assign m_axi_wstrb_o  = req_wstrb_q;
  assign m_axi_wlast_o  = 1'b1;
  assign m_axi_wvalid_o = (state_q == MIF_WRITE_ISSUE) && !w_done_q;
  assign m_axi_bready_o = state_q == MIF_WRITE_RESP;

  assign m_axi_arid_o    = '0;
  assign m_axi_araddr_o  = translated_addr_q;
  assign m_axi_arlen_o   = 8'd0;
  assign m_axi_arsize_o  = 3'd3;
  assign m_axi_arburst_o = 2'b01;
  assign m_axi_arlock_o  = 1'b0;
  assign m_axi_arcache_o = 4'b0011;
  assign m_axi_arprot_o  = 3'b000;
  assign m_axi_arqos_o   = 4'd0;
  assign m_axi_arvalid_o = state_q == MIF_READ_ADDR;
  assign m_axi_rready_o  = state_q == MIF_READ_DATA;

  assign aw_handshake = m_axi_awvalid_o && m_axi_awready_i;
  assign w_handshake  = m_axi_wvalid_o && m_axi_wready_i;
  assign write_channels_done = (aw_done_q || aw_handshake)
                            && (w_done_q || w_handshake);
  assign translated_addr_fits = (tbu_rsp_addr_i >> AXI_ADDR_W) == 0;

  assign error_valid_o  = error_valid_q;
  assign error_addr_o   = error_addr_q;
  assign error_status_o = error_status_q;
  assign mif_idle_o     = state_q == MIF_IDLE;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      state_q             <= MIF_IDLE;
      req_write_q         <= 1'b0;
      req_addr_q          <= 48'd0;
      req_wdata_q         <= 64'd0;
      req_wstrb_q         <= 8'd0;
      stream_id_q         <= 16'd0;
      substream_id_q      <= 16'd0;
      translated_addr_q   <= '0;
      aw_done_q           <= 1'b0;
      w_done_q            <= 1'b0;
      rsp_rdata_q         <= 64'd0;
      rsp_status_q        <= NPU_MEM_OK;
      error_valid_q       <= 1'b0;
      error_addr_q        <= 48'd0;
      error_status_q      <= NPU_MEM_OK;
    end else begin
      if (error_clear_i) begin
        error_valid_q <= 1'b0;
      end

      unique case (state_q)
        MIF_IDLE: begin
          if (req_valid_i && req_ready_o) begin
            req_write_q <= req_write_i;
            req_addr_q  <= req_addr_i;
            req_wdata_q <= req_wdata_i;
            req_wstrb_q <= req_wstrb_i;
            stream_id_q <= stream_id_i;
            substream_id_q <= substream_id_i;
            rsp_rdata_q <= 64'd0;
            if (req_addr_i[2:0] != 3'd0) begin
              rsp_status_q <= NPU_MEM_ADDR;
              state_q      <= MIF_INTERNAL_RESP;
            end else begin
              state_q <= MIF_TBU_REQ;
            end
          end
        end

        MIF_TBU_REQ: begin
          if (tbu_req_valid_o && tbu_req_ready_i) begin
            state_q <= MIF_TBU_RSP;
          end
        end

        MIF_TBU_RSP: begin
          if (tbu_rsp_valid_i && tbu_rsp_ready_o) begin
            translated_addr_q <= tbu_rsp_addr_i[AXI_ADDR_W-1:0];
            if (tbu_rsp_status_i != NPU_MEM_OK) begin
              unique case (tbu_rsp_status_i)
                NPU_MEM_ADDR,
                NPU_MEM_PERM,
                NPU_MEM_SLVERR,
                NPU_MEM_DECERR,
                NPU_MEM_PROTOCOL: rsp_status_q <= tbu_rsp_status_i;
                default:          rsp_status_q <= NPU_MEM_PROTOCOL;
              endcase
              state_q      <= MIF_INTERNAL_RESP;
            end else if (!translated_addr_fits) begin
              rsp_status_q <= NPU_MEM_ADDR;
              state_q      <= MIF_INTERNAL_RESP;
            end else if (req_write_q) begin
              aw_done_q <= 1'b0;
              w_done_q  <= 1'b0;
              state_q   <= MIF_WRITE_ISSUE;
            end else begin
              state_q <= MIF_READ_ADDR;
            end
          end
        end

        MIF_READ_ADDR: begin
          if (m_axi_arvalid_o && m_axi_arready_i) begin
            state_q <= MIF_READ_DATA;
          end
        end

        MIF_READ_DATA: begin
          if (m_axi_rvalid_i && m_axi_rready_o) begin
            rsp_rdata_q <= m_axi_rdata_i;
            if ((m_axi_rid_i != '0) || !m_axi_rlast_i) begin
              rsp_status_q <= NPU_MEM_PROTOCOL;
            end else begin
              rsp_status_q <= axi_resp_status(m_axi_rresp_i);
            end
            state_q <= MIF_INTERNAL_RESP;
          end
        end

        MIF_WRITE_ISSUE: begin
          if (aw_handshake) begin
            aw_done_q <= 1'b1;
          end
          if (w_handshake) begin
            w_done_q <= 1'b1;
          end
          if (write_channels_done) begin
            state_q <= MIF_WRITE_RESP;
          end
        end

        MIF_WRITE_RESP: begin
          if (m_axi_bvalid_i && m_axi_bready_o) begin
            if (m_axi_bid_i != '0) begin
              rsp_status_q <= NPU_MEM_PROTOCOL;
            end else begin
              rsp_status_q <= axi_resp_status(m_axi_bresp_i);
            end
            rsp_rdata_q <= 64'd0;
            state_q     <= MIF_INTERNAL_RESP;
          end
        end

        MIF_INTERNAL_RESP: begin
          if (rsp_valid_o && rsp_ready_i) begin
            state_q <= MIF_IDLE;
          end
        end

        default: state_q <= MIF_IDLE;
      endcase

      if ((state_q == MIF_INTERNAL_RESP) &&
          (rsp_status_q != NPU_MEM_OK)
          && (!error_valid_q || error_clear_i)) begin
        error_valid_q  <= 1'b1;
        error_addr_q   <= req_addr_q;
        error_status_q <= rsp_status_q;
      end
    end
  end

  initial begin
    if ((AXI_ADDR_W < 3) || (AXI_ADDR_W > 48)) begin
      $error("AXI_ADDR_W must be between 3 and 48");
    end
  end

endmodule
