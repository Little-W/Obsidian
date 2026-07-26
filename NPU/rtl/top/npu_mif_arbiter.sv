`timescale 1ns/1ps

module npu_mif_arbiter (
    input  logic        clk_i,
    input  logic        reset_n,

    input  logic        df_req_valid_i,
    output logic        df_req_ready_o,
    input  logic        df_req_write_i,
    input  logic [47:0] df_req_addr_i,
    input  logic [63:0] df_req_wdata_i,
    input  logic [7:0]  df_req_wstrb_i,
    output logic        df_rsp_valid_o,
    input  logic        df_rsp_ready_i,
    output logic [63:0] df_rsp_rdata_o,
    output logic [2:0]  df_rsp_status_o,

    input  logic        dma_req_valid_i,
    output logic        dma_req_ready_o,
    input  logic        dma_req_write_i,
    input  logic [47:0] dma_req_addr_i,
    input  logic [63:0] dma_req_wdata_i,
    input  logic [7:0]  dma_req_wstrb_i,
    output logic        dma_rsp_valid_o,
    input  logic        dma_rsp_ready_i,
    output logic [63:0] dma_rsp_rdata_o,
    output logic [2:0]  dma_rsp_status_o,

    output logic        mif_req_valid_o,
    input  logic        mif_req_ready_i,
    output logic        mif_req_write_o,
    output logic [47:0] mif_req_addr_o,
    output logic [63:0] mif_req_wdata_o,
    output logic [7:0]  mif_req_wstrb_o,
    input  logic        mif_rsp_valid_i,
    output logic        mif_rsp_ready_o,
    input  logic [63:0] mif_rsp_rdata_i,
    input  logic [2:0]  mif_rsp_status_i,

    output logic        idle_o
);

    logic busy_q;
    logic owner_dma_q;
    logic last_grant_dma_q;
    logic select_dma_w;
    logic select_valid_w;

    always_comb begin
        select_valid_w = df_req_valid_i || dma_req_valid_i;
        if (df_req_valid_i && dma_req_valid_i) begin
            select_dma_w = !last_grant_dma_q;
        end else begin
            select_dma_w = dma_req_valid_i;
        end
    end

    assign mif_req_valid_o = !busy_q && select_valid_w;
    assign mif_req_write_o = select_dma_w ? dma_req_write_i : df_req_write_i;
    assign mif_req_addr_o   = select_dma_w ? dma_req_addr_i : df_req_addr_i;
    assign mif_req_wdata_o  = select_dma_w ? dma_req_wdata_i : df_req_wdata_i;
    assign mif_req_wstrb_o  = select_dma_w ? dma_req_wstrb_i : df_req_wstrb_i;

    assign df_req_ready_o =
        !busy_q && !select_dma_w && select_valid_w && mif_req_ready_i;
    assign dma_req_ready_o =
        !busy_q && select_dma_w && select_valid_w && mif_req_ready_i;

    assign df_rsp_valid_o = busy_q && !owner_dma_q && mif_rsp_valid_i;
    assign dma_rsp_valid_o = busy_q && owner_dma_q && mif_rsp_valid_i;
    assign df_rsp_rdata_o = mif_rsp_rdata_i;
    assign dma_rsp_rdata_o = mif_rsp_rdata_i;
    assign df_rsp_status_o = mif_rsp_status_i;
    assign dma_rsp_status_o = mif_rsp_status_i;
    assign mif_rsp_ready_o =
        busy_q && (owner_dma_q ? dma_rsp_ready_i : df_rsp_ready_i);

    assign idle_o = !busy_q && !select_valid_w;

    always_ff @(posedge clk_i or negedge reset_n) begin
        if (!reset_n) begin
            busy_q <= 1'b0;
            owner_dma_q <= 1'b0;
            last_grant_dma_q <= 1'b0;
        end else begin
            if (mif_req_valid_o && mif_req_ready_i) begin
                busy_q <= 1'b1;
                owner_dma_q <= select_dma_w;
                last_grant_dma_q <= select_dma_w;
            end
            if (mif_rsp_valid_i && mif_rsp_ready_o) begin
                busy_q <= 1'b0;
            end
        end
    end

endmodule
