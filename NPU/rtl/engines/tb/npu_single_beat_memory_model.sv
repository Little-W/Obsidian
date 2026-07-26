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
  integer lane;
  integer address_value;

  assign req_ready_o = !pending_q;
  assign rsp_valid_o = pending_q;
  assign rsp_rdata_o = response_data_q;
  assign rsp_status_o = response_status_q;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      pending_q <= 1'b0;
      response_data_q <= 64'd0;
      response_status_q <= 3'd0;
    end else begin
      if (pending_q && rsp_ready_i)
        pending_q <= 1'b0;

      if (req_valid_i && req_ready_o) begin
        address_value = req_addr_i;
        pending_q <= 1'b1;
        response_data_q <= 64'd0;
        if (address_value < 0 ||
            address_value + 7 >= MEM_BYTES) begin
          response_status_q <= 3'd2;
        end else begin
          response_status_q <= 3'd0;
          for (lane = 0; lane < 8; lane = lane + 1) begin
            response_data_q[lane * 8 +: 8] <=
              mem[address_value + lane];
            if (req_write_i && req_wstrb_i[lane])
              mem[address_value + lane] <=
                req_wdata_i[lane * 8 +: 8];
          end
        end
      end
    end
  end

endmodule
