`timescale 1ns/1ps

module tb_npu_engines;

    localparam int CLIENTS = 6;
    localparam logic [4:0] MATRIX_ST_EP_MUL   = 5'd16;
    localparam logic [4:0] MATRIX_ST_EP_SHIFT = 5'd17;
    localparam logic [4:0] MATRIX_ST_EP_CLIP  = 5'd18;

    logic clk_i;
    logic reset_n;

    logic [CLIENTS-1:0] l1_req_valid;
    logic [CLIENTS-1:0] l1_req_ready;
    logic [CLIENTS-1:0] l1_req_write;
    logic [CLIENTS*20-1:0] l1_req_addr;
    logic [CLIENTS*64-1:0] l1_req_wdata;
    logic [CLIENTS*8-1:0] l1_req_wstrb;
    logic [CLIENTS-1:0] l1_rsp_valid;
    logic [CLIENTS-1:0] l1_rsp_ready;
    logic [CLIENTS*64-1:0] l1_rsp_rdata;
    logic [CLIENTS*3-1:0] l1_rsp_status;
    logic l1_idle;

    logic bfm_req_valid;
    logic bfm_req_ready;
    logic bfm_req_write;
    logic [19:0] bfm_req_addr;
    logic [63:0] bfm_req_wdata;
    logic [7:0] bfm_req_wstrb;
    logic bfm_rsp_valid;
    logic bfm_rsp_ready;
    logic [63:0] bfm_rsp_rdata;
    logic [2:0] bfm_rsp_status;

    logic dma_task_valid;
    logic dma_task_ready;
    logic [7:0] dma_opcode;
    logic [11:0] dma_command_id;
    logic [2047:0] dma_desc;
    logic dma_done_valid;
    logic [7:0] dma_done_status;
    logic [47:0] dma_done_fault_addr;
    logic [63:0] dma_done_progress;
    logic dma_l1_req_valid;
    logic dma_l1_req_ready;
    logic dma_l1_req_write;
    logic [19:0] dma_l1_req_addr;
    logic [63:0] dma_l1_req_wdata;
    logic [7:0] dma_l1_req_wstrb;
    logic dma_l1_rsp_valid;
    logic dma_l1_rsp_ready;
    logic [63:0] dma_l1_rsp_rdata;
    logic [2:0] dma_l1_rsp_status;
    logic dma_mif_req_valid;
    logic dma_mif_req_ready;
    logic dma_mif_req_write;
    logic [47:0] dma_mif_req_addr;
    logic [63:0] dma_mif_req_wdata;
    logic [7:0] dma_mif_req_wstrb;
    logic dma_mif_rsp_valid;
    logic dma_mif_rsp_ready;
    logic [63:0] dma_mif_rsp_rdata;
    logic [2:0] dma_mif_rsp_status;

    logic matrix_task_valid;
    logic matrix_task_ready;
    logic [7:0] matrix_opcode;
    logic [11:0] matrix_command_id;
    logic [2047:0] matrix_desc;
    logic matrix_done_valid;
    logic [7:0] matrix_done_status;
    logic [47:0] matrix_done_fault_addr;
    logic [63:0] matrix_done_progress;
    logic matrix_l1_req_valid;
    logic matrix_l1_req_ready;
    logic matrix_l1_req_write;
    logic [19:0] matrix_l1_req_addr;
    logic [63:0] matrix_l1_req_wdata;
    logic [7:0] matrix_l1_req_wstrb;
    logic matrix_l1_rsp_valid;
    logic matrix_l1_rsp_ready;
    logic [63:0] matrix_l1_rsp_rdata;
    logic [2:0] matrix_l1_rsp_status;

    logic vector_task_valid;
    logic vector_task_ready;
    logic [7:0] vector_opcode;
    logic [11:0] vector_command_id;
    logic [2047:0] vector_desc;
    logic vector_done_valid;
    logic [7:0] vector_done_status;
    logic [47:0] vector_done_fault_addr;
    logic [63:0] vector_done_progress;
    logic vector_l1_req_valid;
    logic vector_l1_req_ready;
    logic vector_l1_req_write;
    logic [19:0] vector_l1_req_addr;
    logic [63:0] vector_l1_req_wdata;
    logic [7:0] vector_l1_req_wstrb;
    logic vector_l1_rsp_valid;
    logic vector_l1_rsp_ready;
    logic [63:0] vector_l1_rsp_rdata;
    logic [2:0] vector_l1_rsp_status;

    logic complex_task_valid;
    logic complex_task_ready;
    logic [7:0] complex_opcode;
    logic [11:0] complex_command_id;
    logic [2047:0] complex_desc;
    logic complex_done_valid;
    logic [7:0] complex_done_status;
    logic [47:0] complex_done_fault_addr;
    logic [63:0] complex_done_progress;
    logic complex_l1_req_valid;
    logic complex_l1_req_ready;
    logic complex_l1_req_write;
    logic [19:0] complex_l1_req_addr;
    logic [63:0] complex_l1_req_wdata;
    logic [7:0] complex_l1_req_wstrb;
    logic complex_l1_rsp_valid;
    logic complex_l1_rsp_ready;
    logic [63:0] complex_l1_rsp_rdata;
    logic [2:0] complex_l1_rsp_status;

    logic [63:0] system_mem [0:8191];
    logic system_mem_pending_q;
    logic [63:0] system_mem_rsp_data_q;
    logic [2:0] system_mem_rsp_status_q;
    logic [31:0] cycle_count_q;
    logic [31:0] l1_engine_handshakes_q;
    logic [31:0] mif_handshakes_q;
    logic unused_l1_client5;
    integer byte_index;

    assign l1_req_valid = {
        1'b0, complex_l1_req_valid, vector_l1_req_valid,
        matrix_l1_req_valid, dma_l1_req_valid, bfm_req_valid
    };
    assign l1_req_write = {
        1'b0, complex_l1_req_write, vector_l1_req_write,
        matrix_l1_req_write, dma_l1_req_write, bfm_req_write
    };
    assign l1_req_addr = {
        20'd0, complex_l1_req_addr, vector_l1_req_addr,
        matrix_l1_req_addr, dma_l1_req_addr, bfm_req_addr
    };
    assign l1_req_wdata = {
        64'd0, complex_l1_req_wdata, vector_l1_req_wdata,
        matrix_l1_req_wdata, dma_l1_req_wdata, bfm_req_wdata
    };
    assign l1_req_wstrb = {
        8'd0, complex_l1_req_wstrb, vector_l1_req_wstrb,
        matrix_l1_req_wstrb, dma_l1_req_wstrb, bfm_req_wstrb
    };
    assign l1_rsp_ready = {
        1'b0, complex_l1_rsp_ready, vector_l1_rsp_ready,
        matrix_l1_rsp_ready, dma_l1_rsp_ready, bfm_rsp_ready
    };

    assign bfm_req_ready = l1_req_ready[0];
    assign dma_l1_req_ready = l1_req_ready[1];
    assign matrix_l1_req_ready = l1_req_ready[2];
    assign vector_l1_req_ready = l1_req_ready[3];
    assign complex_l1_req_ready = l1_req_ready[4];
    assign bfm_rsp_valid = l1_rsp_valid[0];
    assign dma_l1_rsp_valid = l1_rsp_valid[1];
    assign matrix_l1_rsp_valid = l1_rsp_valid[2];
    assign vector_l1_rsp_valid = l1_rsp_valid[3];
    assign complex_l1_rsp_valid = l1_rsp_valid[4];
    assign bfm_rsp_rdata = l1_rsp_rdata[0*64 +: 64];
    assign dma_l1_rsp_rdata = l1_rsp_rdata[1*64 +: 64];
    assign matrix_l1_rsp_rdata = l1_rsp_rdata[2*64 +: 64];
    assign vector_l1_rsp_rdata = l1_rsp_rdata[3*64 +: 64];
    assign complex_l1_rsp_rdata = l1_rsp_rdata[4*64 +: 64];
    assign bfm_rsp_status = l1_rsp_status[0*3 +: 3];
    assign dma_l1_rsp_status = l1_rsp_status[1*3 +: 3];
    assign matrix_l1_rsp_status = l1_rsp_status[2*3 +: 3];
    assign vector_l1_rsp_status = l1_rsp_status[3*3 +: 3];
    assign complex_l1_rsp_status = l1_rsp_status[4*3 +: 3];
    assign unused_l1_client5 = ^{
        l1_req_ready[5],
        l1_rsp_valid[5],
        l1_rsp_rdata[5*64 +: 64],
        l1_rsp_status[5*3 +: 3]
    };

    npu_l1buf #(
        .CLIENTS(CLIENTS),
        .L1_BYTES(1 << 20),
        .BANKS(16)
    ) u_l1 (
        .clk_i,
        .reset_n,
        .req_valid_i(l1_req_valid),
        .req_ready_o(l1_req_ready),
        .req_write_i(l1_req_write),
        .req_addr_i(l1_req_addr),
        .req_wdata_i(l1_req_wdata),
        .req_wstrb_i(l1_req_wstrb),
        .rsp_valid_o(l1_rsp_valid),
        .rsp_ready_i(l1_rsp_ready),
        .rsp_rdata_o(l1_rsp_rdata),
        .rsp_status_o(l1_rsp_status),
        .l1_idle_o(l1_idle)
    );

    npu_dma_engine u_dma (
        .clk_i,
        .reset_n,
        .task_valid_i(dma_task_valid),
        .task_ready_o(dma_task_ready),
        .opcode_i(dma_opcode),
        .command_id_i(dma_command_id),
        .desc_i(dma_desc),
        .done_valid_o(dma_done_valid),
        .done_ready_i(1'b1),
        .done_status_o(dma_done_status),
        .done_fault_addr_o(dma_done_fault_addr),
        .done_progress_o(dma_done_progress),
        .l1_req_valid_o(dma_l1_req_valid),
        .l1_req_ready_i(dma_l1_req_ready),
        .l1_req_write_o(dma_l1_req_write),
        .l1_req_addr_o(dma_l1_req_addr),
        .l1_req_wdata_o(dma_l1_req_wdata),
        .l1_req_wstrb_o(dma_l1_req_wstrb),
        .l1_rsp_valid_i(dma_l1_rsp_valid),
        .l1_rsp_ready_o(dma_l1_rsp_ready),
        .l1_rsp_rdata_i(dma_l1_rsp_rdata),
        .l1_rsp_status_i(dma_l1_rsp_status),
        .mif_req_valid_o(dma_mif_req_valid),
        .mif_req_ready_i(dma_mif_req_ready),
        .mif_req_write_o(dma_mif_req_write),
        .mif_req_addr_o(dma_mif_req_addr),
        .mif_req_wdata_o(dma_mif_req_wdata),
        .mif_req_wstrb_o(dma_mif_req_wstrb),
        .mif_rsp_valid_i(dma_mif_rsp_valid),
        .mif_rsp_ready_o(dma_mif_rsp_ready),
        .mif_rsp_rdata_i(dma_mif_rsp_rdata),
        .mif_rsp_status_i(dma_mif_rsp_status)
    );

    npu_matrix_engine u_matrix (
        .clk_i,
        .reset_n,
        .task_valid_i(matrix_task_valid),
        .task_ready_o(matrix_task_ready),
        .opcode_i(matrix_opcode),
        .command_id_i(matrix_command_id),
        .desc_i(matrix_desc),
        .done_valid_o(matrix_done_valid),
        .done_ready_i(1'b1),
        .done_status_o(matrix_done_status),
        .done_fault_addr_o(matrix_done_fault_addr),
        .done_progress_o(matrix_done_progress),
        .l1_req_valid_o(matrix_l1_req_valid),
        .l1_req_ready_i(matrix_l1_req_ready),
        .l1_req_write_o(matrix_l1_req_write),
        .l1_req_addr_o(matrix_l1_req_addr),
        .l1_req_wdata_o(matrix_l1_req_wdata),
        .l1_req_wstrb_o(matrix_l1_req_wstrb),
        .l1_rsp_valid_i(matrix_l1_rsp_valid),
        .l1_rsp_ready_o(matrix_l1_rsp_ready),
        .l1_rsp_rdata_i(matrix_l1_rsp_rdata),
        .l1_rsp_status_i(matrix_l1_rsp_status)
    );

    npu_vector_engine u_vector (
        .clk_i,
        .reset_n,
        .task_valid_i(vector_task_valid),
        .task_ready_o(vector_task_ready),
        .opcode_i(vector_opcode),
        .command_id_i(vector_command_id),
        .desc_i(vector_desc),
        .done_valid_o(vector_done_valid),
        .done_ready_i(1'b1),
        .done_status_o(vector_done_status),
        .done_fault_addr_o(vector_done_fault_addr),
        .done_progress_o(vector_done_progress),
        .l1_req_valid_o(vector_l1_req_valid),
        .l1_req_ready_i(vector_l1_req_ready),
        .l1_req_write_o(vector_l1_req_write),
        .l1_req_addr_o(vector_l1_req_addr),
        .l1_req_wdata_o(vector_l1_req_wdata),
        .l1_req_wstrb_o(vector_l1_req_wstrb),
        .l1_rsp_valid_i(vector_l1_rsp_valid),
        .l1_rsp_ready_o(vector_l1_rsp_ready),
        .l1_rsp_rdata_i(vector_l1_rsp_rdata),
        .l1_rsp_status_i(vector_l1_rsp_status)
    );

    npu_complex_engine u_complex (
        .clk_i,
        .reset_n,
        .task_valid_i(complex_task_valid),
        .task_ready_o(complex_task_ready),
        .opcode_i(complex_opcode),
        .command_id_i(complex_command_id),
        .desc_i(complex_desc),
        .done_valid_o(complex_done_valid),
        .done_ready_i(1'b1),
        .done_status_o(complex_done_status),
        .done_fault_addr_o(complex_done_fault_addr),
        .done_progress_o(complex_done_progress),
        .l1_req_valid_o(complex_l1_req_valid),
        .l1_req_ready_i(complex_l1_req_ready),
        .l1_req_write_o(complex_l1_req_write),
        .l1_req_addr_o(complex_l1_req_addr),
        .l1_req_wdata_o(complex_l1_req_wdata),
        .l1_req_wstrb_o(complex_l1_req_wstrb),
        .l1_rsp_valid_i(complex_l1_rsp_valid),
        .l1_rsp_ready_o(complex_l1_rsp_ready),
        .l1_rsp_rdata_i(complex_l1_rsp_rdata),
        .l1_rsp_status_i(complex_l1_rsp_status)
    );

    always #5 clk_i = ~clk_i;

    assign dma_mif_req_ready = !system_mem_pending_q && cycle_count_q[0];
    assign dma_mif_rsp_valid = system_mem_pending_q;
    assign dma_mif_rsp_rdata = system_mem_rsp_data_q;
    assign dma_mif_rsp_status = system_mem_rsp_status_q;

    always_ff @(posedge clk_i or negedge reset_n) begin
        if (!reset_n) begin
            system_mem_pending_q <= 1'b0;
            system_mem_rsp_data_q <= 64'd0;
            system_mem_rsp_status_q <= 3'd0;
            cycle_count_q <= 32'd0;
            l1_engine_handshakes_q <= 32'd0;
            mif_handshakes_q <= 32'd0;
        end else begin
            cycle_count_q <= cycle_count_q + 1;
            if (|(l1_req_valid[4:1] & l1_req_ready[4:1])) begin
                l1_engine_handshakes_q <= l1_engine_handshakes_q + 1;
            end
            if (dma_mif_req_valid && dma_mif_req_ready) begin
                if ((dma_mif_req_addr[47:16] != 32'd0) ||
                    (dma_mif_req_addr[2:0] != 3'd0)) begin
                    $fatal(1, "DMA MIF model received an invalid address");
                end
                system_mem_pending_q <= 1'b1;
                system_mem_rsp_status_q <= 3'd0;
                system_mem_rsp_data_q <=
                    system_mem[dma_mif_req_addr[15:3]];
                mif_handshakes_q <= mif_handshakes_q + 1;
                if (dma_mif_req_write) begin
                    for (byte_index = 0; byte_index < 8; byte_index++) begin
                        if (dma_mif_req_wstrb[byte_index]) begin
                            system_mem[dma_mif_req_addr[15:3]]
                                      [byte_index*8 +: 8] <=
                                dma_mif_req_wdata[byte_index*8 +: 8];
                        end
                    end
                end
            end
            if (system_mem_pending_q && dma_mif_rsp_ready) begin
                system_mem_pending_q <= 1'b0;
            end
        end
    end

    task automatic check(input logic condition, input string message);
        if (!condition) begin
            $fatal(1, "%s", message);
        end
    endtask

    task automatic put_u8(
        ref logic [2047:0] desc,
        input logic [15:0] offset,
        input logic [7:0] value
    );
        desc[offset*8 +: 8] = value;
    endtask

    task automatic put_u16(
        ref logic [2047:0] desc,
        input logic [15:0] offset,
        input logic [15:0] value
    );
        desc[offset*8 +: 16] = value;
    endtask

    task automatic put_u32(
        ref logic [2047:0] desc,
        input logic [15:0] offset,
        input logic [31:0] value
    );
        desc[offset*8 +: 32] = value;
    endtask

    task automatic put_u64(
        ref logic [2047:0] desc,
        input logic [15:0] offset,
        input logic [63:0] value
    );
        desc[offset*8 +: 64] = value;
    endtask

    task automatic init_common(
        ref logic [2047:0] desc,
        input logic [7:0] engine,
        input logic [15:0] bytes,
        input logic [63:0] src0,
        input logic [63:0] src1,
        input logic [63:0] src2,
        input logic [63:0] dst,
        input logic [31:0] numeric
    );
        begin
            desc = '0;
            put_u8(desc, 16'h00, 8'h01);
            put_u8(desc, 16'h01, engine);
            put_u16(desc, 16'h02, bytes);
            put_u64(desc, 16'h08, src0);
            put_u64(desc, 16'h10, src1);
            put_u64(desc, 16'h18, src2);
            put_u64(desc, 16'h20, dst);
            put_u32(desc, 16'h38, numeric);
        end
    endtask

    task automatic l1_write_word(
        input logic [19:0] addr,
        input logic [63:0] data,
        input logic [7:0] strb
    );
        begin
            @(negedge clk_i);
            bfm_req_addr = addr;
            bfm_req_wdata = data;
            bfm_req_wstrb = strb;
            bfm_req_write = 1'b1;
            bfm_req_valid = 1'b1;
            do @(posedge clk_i); while (!bfm_req_ready);
            @(negedge clk_i);
            bfm_req_valid = 1'b0;
            bfm_rsp_ready = 1'b1;
            do @(posedge clk_i); while (!bfm_rsp_valid);
            check(bfm_rsp_status == 0, "L1 BFM write failed");
            @(negedge clk_i);
            bfm_rsp_ready = 1'b0;
        end
    endtask

    task automatic l1_read_word(
        input logic [19:0] addr,
        output logic [63:0] data
    );
        begin
            @(negedge clk_i);
            bfm_req_addr = addr;
            bfm_req_wdata = 64'd0;
            bfm_req_wstrb = 8'd0;
            bfm_req_write = 1'b0;
            bfm_req_valid = 1'b1;
            do @(posedge clk_i); while (!bfm_req_ready);
            @(negedge clk_i);
            bfm_req_valid = 1'b0;
            bfm_rsp_ready = 1'b1;
            do @(posedge clk_i); while (!bfm_rsp_valid);
            data = bfm_rsp_rdata;
            check(bfm_rsp_status == 0, "L1 BFM read failed");
            @(negedge clk_i);
            bfm_rsp_ready = 1'b0;
        end
    endtask

    task automatic start_dma;
        begin
            do @(posedge clk_i); while (!dma_task_ready);
            @(negedge clk_i);
            dma_task_valid = 1'b1;
            @(posedge clk_i);
            @(negedge clk_i);
            dma_task_valid = 1'b0;
        end
    endtask

    task automatic start_matrix;
        begin
            do @(posedge clk_i); while (!matrix_task_ready);
            @(negedge clk_i);
            matrix_task_valid = 1'b1;
            @(posedge clk_i);
            @(negedge clk_i);
            matrix_task_valid = 1'b0;
        end
    endtask

    task automatic check_matrix_requant_case(
        input logic signed [7:0] a_value,
        input logic signed [7:0] b_value,
        input logic [31:0] multiplier,
        input logic signed [7:0] shift_value,
        input logic [1:0] rounding,
        input logic signed [63:0] expected_shifted,
        input logic signed [7:0] expected_output,
        input string case_name
    );
        logic [31:0] numeric;
        logic [63:0] output_word;
        logic signed [63:0] accumulator;
        logic signed [127:0] expected_product;
        logic saw_mul;
        logic saw_shift;
        logic saw_clip;
        begin
            l1_write_word(
                20'h01100, {56'd0, a_value[7:0]}, 8'h01
            );
            l1_write_word(
                20'h01108, {56'd0, b_value[7:0]}, 8'h01
            );
            l1_write_word(
                20'h01110,
                {24'd0, shift_value[7:0], multiplier},
                8'hff
            );
            l1_write_word(20'h01118, 64'd0, 8'hff);

            numeric = 32'h0000_0065;
            numeric[11:10] = rounding;
            init_common(
                matrix_desc, 8'h02, 16'd256,
                64'h1100, 64'h1108, 64'd0, 64'h1118, numeric
            );
            put_u64(matrix_desc, 16'h30, 64'h1110);
            put_u32(matrix_desc, 16'h40, 32'd1);
            put_u32(matrix_desc, 16'h44, 32'd1);
            put_u32(matrix_desc, 16'h48, 32'd1);
            put_u32(matrix_desc, 16'h4c, 32'd1);
            put_u32(matrix_desc, 16'h50, 32'd1);
            put_u32(matrix_desc, 16'h54, 32'd1);
            put_u32(matrix_desc, 16'h58, 32'd1);
            put_u32(matrix_desc, 16'h5c, 32'h0000_00a0);
            put_u32(matrix_desc, 16'h60, 32'd1);
            put_u32(matrix_desc, 16'h64, 32'd1);
            put_u32(matrix_desc, 16'h68, 32'd1);
            put_u8(matrix_desc, 16'h90, 8'd0);
            put_u8(matrix_desc, 16'h91, 8'd0);
            put_u8(matrix_desc, 16'h92, 8'd0);
            put_u32(matrix_desc, 16'h9c, 32'd1);
            put_u8(matrix_desc, 16'ha4, 8'd1);
            put_u8(matrix_desc, 16'ha6, 8'd8);
            put_u32(matrix_desc, 16'ha8, 32'd8);

            accumulator = a_value * b_value;
            expected_product =
                accumulator * $signed({1'b0, multiplier});
            saw_mul = 1'b0;
            saw_shift = 1'b0;
            saw_clip = 1'b0;

            start_matrix();
            do begin
                @(posedge clk_i);
                if (u_matrix.u_scalar_engine.state_q ==
                    MATRIX_ST_EP_MUL) begin
                    saw_mul = 1'b1;
                end
                if (u_matrix.u_scalar_engine.state_q ==
                    MATRIX_ST_EP_SHIFT) begin
                    check(
                        saw_mul,
                        $sformatf(
                            "%s skipped the integer multiply stage",
                            case_name
                        )
                    );
                    check(
                        $signed(
                            u_matrix.u_scalar_engine.requant_product_q
                        ) == expected_product,
                        $sformatf(
                            "%s integer scaled product mismatch",
                            case_name
                        )
                    );
                    saw_shift = 1'b1;
                end
                if (u_matrix.u_scalar_engine.state_q ==
                    MATRIX_ST_EP_CLIP) begin
                    check(
                        saw_shift,
                        $sformatf(
                            "%s skipped the right-shift stage",
                            case_name
                        )
                    );
                    check(
                        $signed(
                            u_matrix.u_scalar_engine.epilogue_value_q
                        ) == expected_shifted,
                        $sformatf(
                            "%s rounded or 64-bit saturated value mismatch",
                            case_name
                        )
                    );
                    saw_clip = 1'b1;
                end
            end while (!matrix_done_valid);

            check(
                saw_mul && saw_shift && saw_clip,
                $sformatf("%s did not traverse all epilogue stages",
                          case_name)
            );
            check(
                matrix_done_status == 8'h00,
                $sformatf("%s returned status 0x%02x",
                          case_name, matrix_done_status)
            );
            check(
                matrix_done_progress == 64'd1,
                $sformatf("%s progress mismatch", case_name)
            );
            l1_read_word(20'h01118, output_word);
            check(
                $signed(output_word[7:0]) == expected_output,
                $sformatf(
                    "%s INT8 output mismatch: got %0d expected %0d",
                    case_name, $signed(output_word[7:0]),
                    expected_output
                )
            );
            check(
                output_word[63:8] == 56'd0,
                $sformatf("%s wrote outside the output byte", case_name)
            );
        end
    endtask

    task automatic start_vector;
        begin
            do @(posedge clk_i); while (!vector_task_ready);
            @(negedge clk_i);
            vector_task_valid = 1'b1;
            @(posedge clk_i);
            @(negedge clk_i);
            vector_task_valid = 1'b0;
        end
    endtask

    task automatic start_complex;
        begin
            do @(posedge clk_i); while (!complex_task_ready);
            @(negedge clk_i);
            complex_task_valid = 1'b1;
            @(posedge clk_i);
            @(negedge clk_i);
            complex_task_valid = 1'b0;
        end
    endtask

    logic [63:0] read_word;
    logic [31:0] handshakes_before_bad_numeric;

    initial begin
        clk_i = 1'b0;
        reset_n = 1'b0;
        bfm_req_valid = 1'b0;
        bfm_req_write = 1'b0;
        bfm_req_addr = 20'd0;
        bfm_req_wdata = 64'd0;
        bfm_req_wstrb = 8'd0;
        bfm_rsp_ready = 1'b0;
        dma_task_valid = 1'b0;
        dma_opcode = 8'h20;
        dma_command_id = 12'h101;
        dma_desc = '0;
        matrix_task_valid = 1'b0;
        matrix_opcode = 8'h40;
        matrix_command_id = 12'h102;
        matrix_desc = '0;
        vector_task_valid = 1'b0;
        vector_opcode = 8'h60;
        vector_command_id = 12'h103;
        vector_desc = '0;
        complex_task_valid = 1'b0;
        complex_opcode = 8'h80;
        complex_command_id = 12'h104;
        complex_desc = '0;
        for (byte_index = 0; byte_index < 8192; byte_index++) begin
            system_mem[byte_index] = 64'd0;
        end

        repeat (5) @(posedge clk_i);
        reset_n = 1'b1;
        repeat (3) @(posedge clk_i);
        check(l1_idle, "L1 did not become idle after reset");

        /*
         * Drive 1x1 GEMM commands through the current epilogue pipeline.
         * The checks observe the registered scaled product, the following
         * shift result, and the final INT8 write.  This avoids depending on
         * a removed single-cycle helper.
         */
        check_matrix_requant_case(
            8'sd1, 8'sd1, 32'd1, 8'sd1, 2'd0,
            64'sd0, 8'sd0, "matrix nearest-even +0.5"
        );
        check_matrix_requant_case(
            8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd0,
            64'sd2, 8'sd2, "matrix nearest-even +1.5"
        );
        check_matrix_requant_case(
            -8'sd1, 8'sd1, 32'd1, 8'sd1, 2'd0,
            64'sd0, 8'sd0, "matrix nearest-even -0.5"
        );
        check_matrix_requant_case(
            -8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd0,
            -64'sd2, -8'sd2, "matrix nearest-even -1.5"
        );
        check_matrix_requant_case(
            8'sd5, 8'sd1, 32'd1, 8'sd2, 2'd0,
            64'sd1, 8'sd1, "matrix nearest-even positive non-half"
        );
        check_matrix_requant_case(
            -8'sd5, 8'sd1, 32'd1, 8'sd2, 2'd0,
            -64'sd1, -8'sd1, "matrix nearest-even negative non-half"
        );
        check_matrix_requant_case(
            8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd1,
            64'sd1, 8'sd1, "matrix round-to-zero positive"
        );
        check_matrix_requant_case(
            -8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd1,
            -64'sd1, -8'sd1, "matrix round-to-zero negative"
        );
        check_matrix_requant_case(
            8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd2,
            64'sd2, 8'sd2, "matrix round-to-positive-infinity positive"
        );
        check_matrix_requant_case(
            -8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd2,
            -64'sd1, -8'sd1, "matrix round-to-positive-infinity negative"
        );
        check_matrix_requant_case(
            8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd3,
            64'sd1, 8'sd1, "matrix round-to-negative-infinity positive"
        );
        check_matrix_requant_case(
            -8'sd3, 8'sd1, 32'd1, 8'sd1, 2'd3,
            -64'sd2, -8'sd2, "matrix round-to-negative-infinity negative"
        );
        check_matrix_requant_case(
            8'sd3, 8'sd1, 32'd5, 8'sd1, 2'd0,
            64'sd8, 8'sd8, "matrix registered positive scaling"
        );
        check_matrix_requant_case(
            -8'sd3, 8'sd1, 32'd5, 8'sd1, 2'd0,
            -64'sd8, -8'sd8, "matrix registered negative scaling"
        );
        check_matrix_requant_case(
            8'sd3, 8'sd1, 32'd5, -8'sd2, 2'd0,
            64'sd60, 8'sd60, "matrix positive left shift"
        );
        check_matrix_requant_case(
            -8'sd3, 8'sd1, 32'd5, -8'sd2, 2'd0,
            -64'sd60, -8'sd60, "matrix negative left shift"
        );
        check_matrix_requant_case(
            8'sd127, 8'sd1, 32'd2, 8'sd0, 2'd0,
            64'sd254, 8'sd127, "matrix positive INT8 saturation"
        );
        check_matrix_requant_case(
            -8'sd128, 8'sd1, 32'd2, 8'sd0, 2'd0,
            -64'sd256, -8'sd128, "matrix negative INT8 saturation"
        );
        check_matrix_requant_case(
            8'sd127, 8'sd127, 32'hffff_ffff, -8'sd18, 2'd0,
            64'sh7fff_ffff_ffff_ffff, 8'sd127,
            "matrix positive 64-bit saturation"
        );
        check_matrix_requant_case(
            -8'sd128, 8'sd127, 32'hffff_ffff, -8'sd18, 2'd0,
            64'sh8000_0000_0000_0000, -8'sd128,
            "matrix negative 64-bit saturation"
        );

        // DMA_COPY_1D: system-memory bytes move into L1 despite MIF stalls.
        system_mem[13'h1000] = 64'h0a07_0301_00ff_fcf8;
        init_common(
            dma_desc, 8'h01, 16'd256,
            64'h8000, 64'd0, 64'd0, 64'h0300, 32'h0000_0055
        );
        put_u8(dma_desc, 16'h40, 8'd1);
        put_u8(dma_desc, 16'h41, 8'd1);
        put_u8(dma_desc, 16'h42, 8'd0);
        put_u8(dma_desc, 16'h43, 8'd0);
        put_u8(dma_desc, 16'h44, 8'd15);
        put_u8(dma_desc, 16'h45, 8'd8);
        put_u32(dma_desc, 16'h48, 32'd8);
        put_u64(dma_desc, 16'h98, 64'd8);
        put_u64(dma_desc, 16'ha0, 64'd8);
        start_dma();
        do @(posedge clk_i); while (!dma_done_valid);
        check(dma_done_status == 8'h00, "DMA returned a failure status");
        check(dma_done_fault_addr == 0, "DMA reported an unexpected fault");
        check(dma_done_progress == 8, "DMA progress byte count mismatch");
        l1_read_word(20'h00300, read_word);
        check(read_word == 64'h0a07_0301_00ff_fcf8,
              "DMA_COPY_1D numeric result mismatch");
        check(mif_handshakes_q == 8,
              "DMA did not issue one acknowledged read per element");

        // GEMM 2x3 by 3x2 produces four exact INT32 outputs.
        l1_write_word(20'h00100, 64'h0000_0204_ff03_0201, 8'h3f);
        l1_write_word(20'h00200, 64'h0000_04fe_0103_ff02, 8'h3f);
        init_common(
            matrix_desc, 8'h02, 16'd256,
            64'h0100, 64'h0200, 64'd0, 64'h0600, 32'h0000_00a5
        );
        put_u32(matrix_desc, 16'h40, 32'd2);
        put_u32(matrix_desc, 16'h44, 32'd2);
        put_u32(matrix_desc, 16'h48, 32'd3);
        put_u32(matrix_desc, 16'h4c, 32'd1);
        put_u32(matrix_desc, 16'h50, 32'd2);
        put_u32(matrix_desc, 16'h54, 32'd2);
        put_u32(matrix_desc, 16'h58, 32'd3);
        put_u32(matrix_desc, 16'h5c, 32'h0000_0080);
        put_u32(matrix_desc, 16'h60, 32'd3);
        put_u32(matrix_desc, 16'h64, 32'd2);
        put_u32(matrix_desc, 16'h68, 32'd8);
        put_u8(matrix_desc, 16'h90, 8'd0);
        put_u8(matrix_desc, 16'h91, 8'd0);
        put_u8(matrix_desc, 16'h92, 8'd4);
        start_matrix();
        do @(posedge clk_i); while (!matrix_done_valid);
        check(matrix_done_status == 8'h00, "GEMM returned a failure status");
        check(matrix_done_fault_addr == 0,
              "GEMM reported an unexpected fault");
        check(matrix_done_progress == 4,
              "GEMM progress element count mismatch");
        l1_read_word(20'h00600, read_word);
        check(read_word == 64'h0000_000d_0000_0002,
              "GEMM output row 0 mismatch");
        l1_read_word(20'h00608, read_word);
        check(read_word == 64'h0000_000d_0000_0006,
              "GEMM output row 1 mismatch");

        // VADD consumes the DMA result and checks every output byte.
        l1_write_word(20'h00400, 64'h0101_0101_0101_0101, 8'hff);
        init_common(
            vector_desc, 8'h03, 16'd192,
            64'h0300, 64'h0400, 64'd0, 64'h0500, 32'h0000_0055
        );
        put_u32(vector_desc, 16'h40, 32'd1);
        put_u32(vector_desc, 16'h44, 32'd8);
        put_u32(vector_desc, 16'h48, 32'd8);
        put_u32(vector_desc, 16'h50, 32'd1);
        put_u32(vector_desc, 16'h54, 32'd8);
        put_u32(vector_desc, 16'h58, 32'd1);
        put_u32(vector_desc, 16'h5c, 32'd8);
        put_u32(vector_desc, 16'h68, 32'd1);
        put_u32(vector_desc, 16'h6c, 32'd8);
        start_vector();
        do @(posedge clk_i); while (!vector_done_valid);
        check(vector_done_status == 8'h00, "VADD returned a failure status");
        check(vector_done_fault_addr == 0,
              "VADD reported an unexpected fault");
        check(vector_done_progress == 8,
              "VADD progress element count mismatch");
        l1_read_word(20'h00500, read_word);
        check(read_word == 64'h0b08_0402_0100_fdf9,
              "VADD numeric result mismatch");

        // VACT/Tanh performs integer to internal math to integer conversion.
        l1_write_word(20'h00700, 64'h0000_0000_0400_fffc, 8'h0f);
        init_common(
            complex_desc, 8'h04, 16'd256,
            64'h0700, 64'd0, 64'd0, 64'h0800, 32'h0001_3055
        );
        put_u32(complex_desc, 16'h40, 32'd1);
        put_u32(complex_desc, 16'h44, 32'd4);
        put_u32(complex_desc, 16'h48, 32'd4);
        put_u32(complex_desc, 16'h4c, 32'd1);
        put_u32(complex_desc, 16'h50, 32'd4);
        put_u32(complex_desc, 16'h5c, 32'd4);
        put_u32(complex_desc, 16'h70, 32'h3f80_0000);
        put_u32(complex_desc, 16'h74, 32'h3f80_0000);
        put_u32(complex_desc, 16'h78, 32'h3f80_0000);
        put_u32(complex_desc, 16'h7c, 32'h3f80_0000);
        put_u32(complex_desc, 16'h94, 32'hc180_0000);
        put_u32(complex_desc, 16'h98, 32'h4180_0000);
        start_complex();
        do @(posedge clk_i); while (!complex_done_valid);
        check(complex_done_status == 8'h00,
              "Complex ACT returned a failure status");
        check(complex_done_fault_addr == 0,
              "Complex ACT reported an unexpected fault");
        check(complex_done_progress == 4,
              "Complex ACT progress element count mismatch");
        l1_read_word(20'h00800, read_word);
        check((read_word & 64'hffff_ffff) == 64'h0100_ffff,
              "Complex Tanh numeric result mismatch");

        /*
         * Softmax must find the maximum from the unmodified inputs.  The
         * clipping range applies to x-max, not to x itself.  Inputs above the
         * positive clipping value therefore remain distinguishable.
         */
        l1_write_word(20'h00900, 64'h0000_0000_1d1e_1f20, 8'h0f);
        init_common(
            complex_desc, 8'h04, 16'd256,
            64'h0900, 64'd0, 64'd0, 64'h0a00, 32'h0001_30d5
        );
        put_u32(complex_desc, 16'h40, 32'd1);
        put_u32(complex_desc, 16'h44, 32'd4);
        put_u32(complex_desc, 16'h48, 32'd4);
        put_u32(complex_desc, 16'h4c, 32'd4);
        put_u32(complex_desc, 16'h50, 32'd4);
        put_u32(complex_desc, 16'h5c, 32'd8);
        put_u32(complex_desc, 16'h70, 32'h3f80_0000);
        put_u32(complex_desc, 16'h74, 32'h3f80_0000);
        put_u32(complex_desc, 16'h78, 32'h3f80_0000);
        put_u32(complex_desc, 16'h7c, 32'h3a83_126f);
        put_u32(complex_desc, 16'h94, 32'hc180_0000);
        put_u32(complex_desc, 16'h98, 32'h4180_0000);
        complex_opcode = 8'h81;
        start_complex();
        do @(posedge clk_i); while (!complex_done_valid);
        check(complex_done_status == 8'h00,
              "Complex Softmax returned a failure status");
        check(complex_done_progress == 4,
              "Complex Softmax progress element count mismatch");
        l1_read_word(20'h00a00, read_word);
        check(read_word == 64'h0020_0057_00ed_0284,
              "Complex Softmax lane sum or reciprocal mismatch");

        /*
         * LayerNorm mode 0 uses one pass for the lane-wise mean, one pass for
         * squared deviations, and a final pass for gamma/beta and output.
         */
        l1_write_word(20'h00b00, 64'h0000_0000_0301_fffd, 8'h0f);
        l1_write_word(20'h00c00, 64'h0000_0000_01ff_0201, 8'h0f);
        l1_write_word(20'h00d00, 64'h0000_0000_0002_ff01, 8'h0f);
        init_common(
            complex_desc, 8'h04, 16'd256,
            64'h0b00, 64'h0c00, 64'h0d00, 64'h0e00,
            32'h0001_30d5
        );
        put_u32(complex_desc, 16'h40, 32'd1);
        put_u32(complex_desc, 16'h44, 32'd4);
        put_u32(complex_desc, 16'h48, 32'd4);
        put_u32(complex_desc, 16'h4c, 32'd5);
        put_u32(complex_desc, 16'h50, 32'd4);
        put_u32(complex_desc, 16'h54, 32'd4);
        put_u32(complex_desc, 16'h58, 32'd4);
        put_u32(complex_desc, 16'h5c, 32'd8);
        put_u32(complex_desc, 16'h70, 32'h3f80_0000);
        put_u32(complex_desc, 16'h74, 32'h3f80_0000);
        put_u32(complex_desc, 16'h78, 32'h3f80_0000);
        put_u32(complex_desc, 16'h7c, 32'h3c23_d70a);
        put_u32(complex_desc, 16'h90, 32'h3c23_d70a);
        complex_opcode = 8'h82;
        start_complex();
        do @(posedge clk_i); while (!complex_done_valid);
        check(complex_done_status == 8'h00,
              "Complex LayerNorm returned a failure status");
        check(complex_done_progress == 4,
              "Complex LayerNorm progress element count mismatch");
        l1_read_word(20'h00e00, read_word);
        check(read_word == 64'h0086_009b_ff43_ffde,
              "Complex LayerNorm two-pass result mismatch");

        // Two rows exercise row-state reset and shared gamma/beta addressing.
        l1_write_word(20'h00f00, 64'h0300_03fe_ff03_ff03, 8'hff);
        l1_write_word(20'h00f40, 64'h0000_0000_0a08_0604, 8'h0f);
        l1_write_word(20'h00f80, 64'h0000_0000_fc05_fe03, 8'h0f);
        init_common(
            complex_desc, 8'h04, 16'd256,
            64'h0f00, 64'h0f40, 64'h0f80, 64'h1000,
            32'h0001_3055
        );
        put_u32(complex_desc, 16'h40, 32'd2);
        put_u32(complex_desc, 16'h44, 32'd4);
        put_u32(complex_desc, 16'h48, 32'd4);
        put_u32(complex_desc, 16'h4c, 32'd5);
        put_u32(complex_desc, 16'h50, 32'd4);
        put_u32(complex_desc, 16'h54, 32'd0);
        put_u32(complex_desc, 16'h58, 32'd0);
        put_u32(complex_desc, 16'h5c, 32'd4);
        put_u32(complex_desc, 16'h70, 32'h3f80_0000);
        put_u32(complex_desc, 16'h74, 32'h3f80_0000);
        put_u32(complex_desc, 16'h78, 32'h3f80_0000);
        put_u32(complex_desc, 16'h7c, 32'h3f80_0000);
        put_u32(complex_desc, 16'h90, 32'h3a83_126f);
        start_complex();
        do @(posedge clk_i); while (!complex_done_valid);
        check(complex_done_status == 8'h00,
              "Complex two-row LayerNorm returned a failure status");
        check(complex_done_progress == 8,
              "Complex two-row LayerNorm progress mismatch");
        l1_read_word(20'h01000, read_word);
        check(read_word == 64'h0501_04fd_f20d_f807,
              "Complex two-row LayerNorm row reset mismatch");

        // A nonzero accumulator encoding is invalid for this Vector command.
        handshakes_before_bad_numeric = l1_engine_handshakes_q;
        put_u32(vector_desc, 16'h38, 32'h0000_0155);
        vector_command_id = 12'h105;
        start_vector();
        do @(posedge clk_i); while (!vector_done_valid);
        check(vector_done_status == 8'h02,
              "invalid numeric configuration did not return BAD_DESC");
        check(vector_done_progress == 0,
              "invalid numeric configuration reported nonzero progress");
        check(l1_engine_handshakes_q == handshakes_before_bad_numeric,
              "invalid numeric configuration issued an L1 request");

        $display(
            "TB_MODULE_ENGINES_PASS l1_handshakes=%0d mif_handshakes=%0d",
            l1_engine_handshakes_q, mif_handshakes_q
        );
        $finish;
    end

    initial begin
        #2000000;
        $fatal(1, "engine module test timed out");
    end

endmodule
