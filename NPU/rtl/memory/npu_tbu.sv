module npu_tbu (
  input  logic        clk_i,
  input  logic        reset_n,

  input  logic        enable_i,
  input  logic [15:0] allowed_stream_id_i,
  input  logic [15:0] allowed_substream_id_i,
  input  logic        allow_read_i,
  input  logic        allow_write_i,
  input  logic [47:0] allowed_base_i,
  input  logic [47:0] allowed_limit_i,

  input  logic        req_valid_i,
  output logic        req_ready_o,
  input  logic        req_write_i,
  input  logic [47:0] req_addr_i,
  input  logic [15:0] req_stream_id_i,
  input  logic [15:0] req_substream_id_i,

  output logic        rsp_valid_o,
  input  logic        rsp_ready_i,
  output logic [47:0] rsp_addr_o,
  output logic [2:0]  rsp_status_o,

  output logic        tbu_idle_o
);
  import npu_rtl_pkg::*;

  logic rsp_valid_q;
  logic [47:0] rsp_addr_q;
  logic [2:0] rsp_status_q;
  logic stream_ok;
  logic permission_ok;
  logic range_ok;

  assign req_ready_o = !rsp_valid_q || rsp_ready_i;
  assign rsp_valid_o = rsp_valid_q;
  assign rsp_addr_o  = rsp_addr_q;
  assign rsp_status_o = rsp_status_q;
  assign tbu_idle_o  = !rsp_valid_q;

  assign stream_ok = (req_stream_id_i == allowed_stream_id_i)
                  && (req_substream_id_i == allowed_substream_id_i);
  assign permission_ok = req_write_i ? allow_write_i : allow_read_i;
  assign range_ok = (req_addr_i[2:0] == 3'd0)
                 && (req_addr_i >= allowed_base_i)
                 && (req_addr_i <= allowed_limit_i)
                 && (allowed_limit_i >= allowed_base_i);

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      rsp_valid_q  <= 1'b0;
      rsp_addr_q   <= 48'd0;
      rsp_status_q <= NPU_MEM_OK;
    end else begin
      if (rsp_valid_q && rsp_ready_i) begin
        rsp_valid_q <= 1'b0;
      end
      if (req_valid_i && req_ready_o) begin
        rsp_valid_q <= 1'b1;
        rsp_addr_q  <= req_addr_i;
        if (!enable_i || !range_ok) begin
          rsp_status_q <= NPU_MEM_ADDR;
        end else if (!stream_ok || !permission_ok) begin
          rsp_status_q <= NPU_MEM_PERM;
        end else begin
          // The initial RTL uses identity translation after all checks pass.
          rsp_status_q <= NPU_MEM_OK;
        end
      end
    end
  end

endmodule
