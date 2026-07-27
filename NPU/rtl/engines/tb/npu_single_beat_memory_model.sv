module npu_single_beat_memory_model #(
  parameter integer ADDR_W = 20,
  parameter integer MEM_BYTES = 4096
) (
  input  logic                clk_i,
  input  logic                reset_n,
  input  logic                req_valid_i,
  output logic                req_ready_o,
  input  logic                req_write_i,
  input  logic [ADDR_W-1:0]   req_addr_i,
  input  logic [63:0]         req_wdata_i,
  input  logic [7:0]          req_wstrb_i,
  output logic                rsp_valid_o,
  input  logic                rsp_ready_i,
  output logic [63:0]         rsp_rdata_o,
  output logic [2:0]          rsp_status_o
);

  logic [7:0] mem [0:MEM_BYTES-1];
  logic pending_q;
  logic [63:0] response_data_q;
  logic [2:0] response_status_q;
  localparam integer MEM_ADDR_W = $clog2(MEM_BYTES);
  logic [MEM_ADDR_W-1:0] address_index;
  integer lane;

  assign req_ready_o = !pending_q;
  assign rsp_valid_o = pending_q;
  assign rsp_rdata_o = response_data_q;
  assign rsp_status_o = response_status_q;
  assign address_index = req_addr_i[MEM_ADDR_W-1:0];

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      pending_q <= 1'b0;
      response_data_q <= 64'd0;
      response_status_q <= 3'd0;
    end else begin
      if (pending_q && rsp_ready_i)
        pending_q <= 1'b0;

      if (req_valid_i && req_ready_o) begin
        pending_q <= 1'b1;
        response_data_q <= 64'd0;
        if (req_addr_i > ADDR_W'(MEM_BYTES - 8)) begin
          response_status_q <= 3'd2;
        end else begin
          response_status_q <= 3'd0;
          for (lane = 0; lane < 8; lane = lane + 1) begin
            response_data_q[lane * 8 +: 8] <=
              mem[int'(address_index) + lane];
            if (req_write_i && req_wstrb_i[lane])
              mem[int'(address_index) + lane] <=
                req_wdata_i[lane * 8 +: 8];
          end
        end
      end
    end
  end

endmodule
