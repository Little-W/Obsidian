module tb_npu_matrix_engine;
  import npu_engine_pkg::*;

  logic clk;
  logic reset_n;
  logic task_valid;
  logic task_ready;
  logic [7:0] opcode;
  logic [11:0] command_id;
  logic [2047:0] desc;
  logic done_valid;
  logic done_ready;
  logic [7:0] done_status;
  logic [47:0] done_fault_addr;
  logic [63:0] done_progress;
  logic l1_req_valid;
  logic l1_req_ready;
  logic l1_req_write;
  logic [19:0] l1_req_addr;
  logic [63:0] l1_req_wdata;
  logic [7:0] l1_req_wstrb;
  logic l1_rsp_valid;
  logic l1_rsp_ready;
  logic [63:0] l1_rsp_rdata;
  logic [2:0] l1_rsp_status;

  npu_matrix_engine dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .task_valid_i(task_valid),
    .task_ready_o(task_ready),
    .opcode_i(opcode),
    .command_id_i(command_id),
    .desc_i(desc),
    .done_valid_o(done_valid),
    .done_ready_i(done_ready),
    .done_status_o(done_status),
    .done_fault_addr_o(done_fault_addr),
    .done_progress_o(done_progress),
    .l1_req_valid_o(l1_req_valid),
    .l1_req_ready_i(l1_req_ready),
    .l1_req_write_o(l1_req_write),
    .l1_req_addr_o(l1_req_addr),
    .l1_req_wdata_o(l1_req_wdata),
    .l1_req_wstrb_o(l1_req_wstrb),
    .l1_rsp_valid_i(l1_rsp_valid),
    .l1_rsp_ready_o(l1_rsp_ready),
    .l1_rsp_rdata_i(l1_rsp_rdata),
    .l1_rsp_status_i(l1_rsp_status)
  );

  npu_single_beat_memory_model #(
    .ADDR_W(20),
    .MEM_BYTES(4096)
  ) l1 (
    .clk_i(clk),
    .reset_n(reset_n),
    .req_valid_i(l1_req_valid),
    .req_ready_o(l1_req_ready),
    .req_write_i(l1_req_write),
    .req_addr_i(l1_req_addr),
    .req_wdata_i(l1_req_wdata),
    .req_wstrb_i(l1_req_wstrb),
    .rsp_valid_o(l1_rsp_valid),
    .rsp_ready_i(l1_rsp_ready),
    .rsp_rdata_o(l1_rsp_rdata),
    .rsp_status_o(l1_rsp_status)
  );

  always #5 clk = ~clk;

  task automatic put8(input integer offset, input logic [7:0] value);
    desc[offset * 8 +: 8] = value;
  endtask

  task automatic put16(input integer offset, input logic [15:0] value);
    desc[offset * 8 +: 16] = value;
  endtask

  task automatic put32(input integer offset, input logic [31:0] value);
    desc[offset * 8 +: 32] = value;
  endtask

  task automatic put64(input integer offset, input logic [63:0] value);
    desc[offset * 8 +: 64] = value;
  endtask

  function automatic logic signed [31:0] read_s32(input integer address);
    return $signed({
      l1.mem[address + 3],
      l1.mem[address + 2],
      l1.mem[address + 1],
      l1.mem[address]
    });
  endfunction

  function automatic integer fast_a_value(
    input integer batch,
    input integer row,
    input integer col
  );
    return ((batch + row + col) % 7) - 3;
  endfunction

  function automatic integer fast_b_value(
    input integer batch,
    input integer row,
    input integer col
  );
    return ((batch + 2 * row + 3 * col) % 5) - 2;
  endfunction

  function automatic integer packed_byte_offset(
    input logic [1:0] dtype,
    input integer element
  );
    case (dtype)
      NPU_DTYPE_INT16: return element * 2;
      NPU_DTYPE_INT8:  return element;
      default:         return element / 2;
    endcase
  endfunction

  function automatic integer tiled_b_byte_offset(
    input logic [1:0] dtype,
    input integer row,
    input integer col,
    input integer n_size
  );
    integer element_index;
    integer n_tiles;
    begin
      n_tiles = (n_size + 7) / 8;
      element_index =
        ((((row / 16) * n_tiles + (col / 8)) * 16 +
          (row % 16)) * 8) + (col % 8);
      if (dtype == NPU_DTYPE_INT4)
        return element_index / 2;
      if (dtype == NPU_DTYPE_INT8)
        return element_index;
      return element_index * 2;
    end
  endfunction

  task automatic write_packed_value(
    input integer address,
    input logic [1:0] dtype,
    input logic element_odd,
    input logic signed [15:0] value
  );
    logic [15:0] value16;
    logic [7:0] value8;
    logic [3:0] value4;
    begin
      value16 = 16'(value);
      value8 = 8'(value);
      value4 = 4'(value);
      case (dtype)
        NPU_DTYPE_INT16: begin
          l1.mem[address] = value16[7:0];
          l1.mem[address + 1] = value16[15:8];
        end
        NPU_DTYPE_INT8:
          l1.mem[address] = value8;
        default: begin
          if (element_odd)
            l1.mem[address][7:4] = value4;
          else
            l1.mem[address][3:0] = value4;
        end
      endcase
    end
  endtask

  task automatic run_fast_dip_case(
    input logic [1:0] dtype,
    input logic [7:0] b_pack,
    input logic [7:0] test_opcode,
    input integer batches
  );
    integer logical_n;
    integer a_base_addr;
    integer b_base_addr;
    integer c_base_addr;
    integer a_batch_bytes;
    integer b_batch_bytes;
    integer c_batch_bytes;
    logic [7:0] a_pack;
    integer last_mn;
    integer expected;
    integer before_count;
    integer address;
    integer numeric;
    begin
      case (dtype)
        NPU_DTYPE_INT16: begin
          logical_n = 4;
          a_pack = 5;
        end
        NPU_DTYPE_INT8: begin
          logical_n = 8;
          a_pack = 0;
        end
        default: begin
          logical_n = 16;
          a_pack = 1;
        end
      endcase

      a_base_addr = 'h800;
      b_base_addr = 'ha00;
      c_base_addr = 'hc00;
      a_batch_bytes = 'h100;
      b_batch_bytes = 'h100;
      c_batch_bytes = logical_n * logical_n * 4;
      last_mn = logical_n == 16 ? 8 : logical_n;

      for (int byte_index = 'h800;
           byte_index < 'h1000;
           byte_index++)
        l1.mem[byte_index] = 8'd0;

      for (int batch = 0; batch < batches; batch++) begin
        for (int row = 0; row < logical_n; row++) begin
          for (int col = 0; col < logical_n; col++) begin
            address =
              a_base_addr + batch * a_batch_bytes + row * 8 +
              packed_byte_offset(dtype, col);
            write_packed_value(
              address, dtype, col[0],
              16'(fast_a_value(batch, row, col))
            );
            address =
              b_base_addr + batch * b_batch_bytes +
              tiled_b_byte_offset(dtype, row, col, logical_n);
            write_packed_value(
              address, dtype, col[0],
              16'(fast_b_value(batch, row, col))
            );
          end
        end
      end

      desc = '0;
      opcode = test_opcode;
      put8('h00, 8'h01);
      put8('h01, 8'h02);
      put16('h02, 16'd256);
      put64('h08, 64'(a_base_addr));
      put64('h10, 64'(b_base_addr));
      put64('h20, 64'(c_base_addr));
      numeric = {
        24'd0,
        NPU_DTYPE_INT32,
        NPU_DTYPE_INT32,
        dtype,
        dtype
      };
      put32('h38, numeric);
      put32('h40, logical_n);
      put32('h44, logical_n);
      put32('h48, logical_n);
      put32('h4c, batches);
      put32('h50, last_mn);
      put32('h54, last_mn);
      put32('h58, logical_n);
      put32('h5c, 32'h0000_0080);
      put32('h60, 32'd8);
      put32('h64, 32'd8);
      put32('h68, logical_n * 4);
      put64('h70, 64'(a_batch_bytes));
      put64('h78, 64'(b_batch_bytes));
      put64('h80, 64'(c_batch_bytes));
      put8('h90, a_pack);
      put8('h91, b_pack);
      put8('h92, 8'd4);
      put8('h93, 8'd0);
      put8('h94, 8'd0);
      put8('h95, 8'd0);

      before_count = dut.dip_task_count_q;
      submit_and_expect(NPU_STATUS_SUCCESS);
      if (dut.dip_task_count_q != before_count + 1)
        $fatal(1, "DiP task counter did not advance");
      if (done_progress != 64'(batches * logical_n * logical_n))
        $fatal(1, "DiP progress %0d expected %0d",
               done_progress, batches * logical_n * logical_n);

      for (int batch = 0; batch < batches; batch++) begin
        for (int row = 0; row < logical_n; row++) begin
          for (int col = 0; col < logical_n; col++) begin
            expected = 0;
            for (int k = 0; k < logical_n; k++)
              expected +=
                fast_a_value(batch, row, k) *
                fast_b_value(batch, k, col);
            address =
              c_base_addr + batch * c_batch_bytes +
              row * logical_n * 4 + col * 4;
            if (read_s32(address) != expected)
              $fatal(
                1,
                "DiP dtype=%0d batch=%0d row=%0d col=%0d got=%0d expected=%0d",
                dtype, batch, row, col,
                read_s32(address), expected
              );
          end
        end
      end

      $display(
        "DiP fast path PASS: dtype=%0d size=%0d batches=%0d",
        dtype, logical_n, batches
      );
    end
  endtask

  task automatic run_scalar_tiled_b_case;
    integer address;
    integer expected;
    begin
      for (int byte_index = 'h500;
           byte_index < 'h780;
           byte_index++)
        l1.mem[byte_index] = 8'd0;

      l1.mem['h500] = 8'd2;
      l1.mem['h501] = 8'hfd;
      l1.mem['h510] = 8'hff;
      l1.mem['h511] = 8'd4;
      for (int batch = 0; batch < 2; batch++) begin
        for (int col = 0; col < 9; col++) begin
          address =
            'h520 + batch * 'h100 +
            tiled_b_byte_offset(NPU_DTYPE_INT8, 0, col, 9);
          write_packed_value(
            address, NPU_DTYPE_INT8, 1'b0,
            16'(col + 1 + batch)
          );
          address =
            'h520 + batch * 'h100 +
            tiled_b_byte_offset(NPU_DTYPE_INT8, 1, col, 9);
          write_packed_value(
            address, NPU_DTYPE_INT8, 1'b0,
            16'(2 * col - 4 - batch)
          );
        end
      end

      desc = '0;
      opcode = NPU_MATRIX_BMM;
      put8('h00, 8'h01);
      put8('h01, 8'h02);
      put16('h02, 16'd256);
      put64('h08, 64'h500);
      put64('h10, 64'h520);
      put64('h20, 64'h700);
      put32('h38, 32'h0000_0085);
      put32('h40, 32'd1);
      put32('h44, 32'd9);
      put32('h48, 32'd2);
      put32('h4c, 32'd2);
      put32('h50, 32'd1);
      put32('h54, 32'd1);
      put32('h58, 32'd2);
      put32('h5c, 32'h0000_0080);
      put32('h60, 32'd2);
      put32('h64, 32'd9);
      put32('h68, 32'd36);
      put64('h70, 64'h10);
      put64('h78, 64'h100);
      put64('h80, 64'h40);
      put8('h90, 8'd0);
      put8('h91, 8'd2);
      put8('h92, 8'd4);
      put8('h93, 8'd0);
      put8('h94, 8'd0);
      put8('h95, 8'd0);

      submit_and_expect(NPU_STATUS_SUCCESS);
      if (dut.dip_task_count_q != 0)
        $fatal(1, "scalar tiled-B case unexpectedly used DiP");
      if (done_progress != 18)
        $fatal(1, "scalar tiled-B progress %0d expected 18",
               done_progress);
      for (int batch = 0; batch < 2; batch++) begin
        for (int col = 0; col < 9; col++) begin
          expected = batch == 0 ? 14 - 4 * col : 7 * col - 22;
          address = 'h700 + batch * 'h40 + col * 4;
          if (read_s32(address) != expected)
            $fatal(
              1,
              "scalar tiled-B batch=%0d col=%0d got=%0d expected=%0d",
              batch, col, read_s32(address), expected
            );
        end
      end
    end
  endtask

  task automatic run_scalar_tiled_rollover_case(
    input logic [1:0] dtype,
    input logic [7:0] a_pack,
    input logic [7:0] b_pack
  );
    integer a_stride;
    integer b_stride;
    integer address;
    integer expected;
    integer before_count;
    integer numeric;
    begin
      case (dtype)
        NPU_DTYPE_INT16: begin
          a_stride = 34;
          b_stride = 18;
        end
        NPU_DTYPE_INT8: begin
          a_stride = 17;
          b_stride = 9;
        end
        default: begin
          a_stride = 9;
          b_stride = 5;
        end
      endcase

      for (int byte_index = 'h700;
           byte_index < 'hc40;
           byte_index++)
        l1.mem[byte_index] = 8'd0;

      for (int k = 0; k < 17; k++) begin
        address = 'h700 + packed_byte_offset(dtype, k);
        write_packed_value(
          address, dtype, k[0], 16'((k % 7) - 3)
        );
        for (int col = 0; col < 9; col++) begin
          address =
            'h800 + tiled_b_byte_offset(dtype, k, col, 9);
          write_packed_value(
            address, dtype, col[0],
            16'(((3 * k + 2 * col) % 5) - 2)
          );
        end
      end

      desc = '0;
      opcode = NPU_MATRIX_GEMM;
      put8('h00, 8'h01);
      put8('h01, 8'h02);
      put16('h02, 16'd256);
      put64('h08, 64'h700);
      put64('h10, 64'h800);
      put64('h20, 64'hc00);
      numeric = {
        24'd0,
        NPU_DTYPE_INT32,
        NPU_DTYPE_INT32,
        dtype,
        dtype
      };
      put32('h38, numeric);
      put32('h40, 32'd1);
      put32('h44, 32'd9);
      put32('h48, 32'd17);
      put32('h4c, 32'd1);
      put32('h50, 32'd1);
      put32('h54, 32'd1);
      put32('h58, 32'd1);
      put32('h5c, 32'h0000_0080);
      put32('h60, a_stride);
      put32('h64, b_stride);
      put32('h68, 32'd36);
      put8('h90, a_pack);
      put8('h91, b_pack);
      put8('h92, 8'd4);
      put8('h93, 8'd0);
      put8('h94, 8'd0);
      put8('h95, 8'd0);

      before_count = dut.dip_task_count_q;
      submit_and_expect(NPU_STATUS_SUCCESS);
      if (dut.dip_task_count_q != before_count)
        $fatal(1, "tiled rollover case unexpectedly used DiP");
      if (done_progress != 9)
        $fatal(1, "tiled rollover progress %0d expected 9",
               done_progress);
      for (int col = 0; col < 9; col++) begin
        expected = 0;
        for (int k = 0; k < 17; k++)
          expected +=
            ((k % 7) - 3) *
            (((3 * k + 2 * col) % 5) - 2);
        address = 'hc00 + col * 4;
        if (read_s32(address) != expected)
          $fatal(
            1,
            "tiled rollover dtype=%0d col=%0d got=%0d expected=%0d",
            dtype, col, read_s32(address), expected
          );
      end
    end
  endtask

  task automatic run_scalar_transpose_int4_case;
    integer before_count;
    begin
      for (int byte_index = 'h500;
           byte_index < 'h600;
           byte_index++)
        l1.mem[byte_index] = 8'd0;

      l1.mem['h500] = 8'hf1;
      l1.mem['h501] = 8'h02;
      l1.mem['h502] = 8'h23;
      l1.mem['h520] = 8'h01;
      l1.mem['h521] = 8'h02;
      l1.mem['h522] = 8'hf2;
      l1.mem['h523] = 8'h01;
      l1.mem['h524] = 8'h30;
      l1.mem['h525] = 8'h01;

      desc = '0;
      opcode = NPU_MATRIX_GEMM;
      put8('h00, 8'h01);
      put8('h01, 8'h02);
      put16('h02, 16'd256);
      put64('h08, 64'h500);
      put64('h10, 64'h520);
      put64('h20, 64'h580);
      put32('h38, 32'h0000_0080);
      put32('h40, 32'd2);
      put32('h44, 32'd3);
      put32('h48, 32'd3);
      put32('h4c, 32'd1);
      put32('h50, 32'd2);
      put32('h54, 32'd3);
      put32('h58, 32'd3);
      put32('h5c, 32'h0000_0083);
      put32('h60, 32'd1);
      put32('h64, 32'd2);
      put32('h68, 32'd12);
      put8('h90, 8'd1);
      put8('h91, 8'd1);
      put8('h92, 8'd4);
      put8('h93, 8'd0);
      put8('h94, 8'd0);
      put8('h95, 8'd0);

      before_count = dut.dip_task_count_q;
      submit_and_expect(NPU_STATUS_SUCCESS);
      if (dut.dip_task_count_q != before_count)
        $fatal(1, "transpose case unexpectedly used DiP");
      if (done_progress != 6)
        $fatal(1, "transpose progress %0d expected 6",
               done_progress);
      if (read_s32('h580) != 7 ||
          read_s32('h584) != 3 ||
          read_s32('h588) != 9 ||
          read_s32('h58c) != 3 ||
          read_s32('h590) != 0 ||
          read_s32('h594) != 2)
        $fatal(
          1,
          "transpose INT4 mismatch: %0d %0d %0d %0d %0d %0d",
          read_s32('h580), read_s32('h584),
          read_s32('h588), read_s32('h58c),
          read_s32('h590), read_s32('h594)
        );
    end
  endtask

  task automatic submit_and_expect(input logic [7:0] expected_status);
    integer timeout;
    begin
      timeout = 0;
      while (!task_ready && timeout < 1000) begin
        @(posedge clk);
        timeout = timeout + 1;
      end
      if (!task_ready)
        $fatal(1, "matrix task_ready timeout");
      @(negedge clk);
      task_valid = 1'b1;
      @(negedge clk);
      task_valid = 1'b0;
      timeout = 0;
      while (!done_valid && timeout < 20000) begin
        @(posedge clk);
        timeout = timeout + 1;
      end
      if (!done_valid)
        $fatal(1, "matrix done timeout");
      if (done_status !== expected_status)
        $fatal(1, "matrix status %02x expected %02x",
               done_status, expected_status);
      if (done_fault_addr !== 48'd0)
        $fatal(1, "matrix unexpected fault address %012x",
               done_fault_addr);
    end
  endtask

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
    task_valid = 1'b0;
    done_ready = 1'b1;
    opcode = NPU_MATRIX_GEMM;
    command_id = 12'h301;
    desc = '0;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;

    l1.mem['h100] = 8'd1;
    l1.mem['h101] = 8'd2;
    l1.mem['h102] = 8'd3;
    l1.mem['h103] = 8'd4;
    l1.mem['h120] = 8'd5;
    l1.mem['h121] = 8'd6;
    l1.mem['h122] = 8'd7;
    l1.mem['h123] = 8'd8;

    put8('h00, 8'h01);
    put8('h01, 8'h02);
    put16('h02, 16'd256);
    put64('h08, 64'h100);
    put64('h10, 64'h120);
    put64('h20, 64'h200);
    put32('h38, 32'h0000_0085);
    put32('h40, 32'd2);
    put32('h44, 32'd2);
    put32('h48, 32'd2);
    put32('h4c, 32'd1);
    put32('h50, 32'd2);
    put32('h54, 32'd2);
    put32('h58, 32'd2);
    put32('h5c, 32'h0000_0080);
    put32('h60, 32'd2);
    put32('h64, 32'd2);
    put32('h68, 32'd8);
    put8('h90, 8'd0);
    put8('h91, 8'd0);
    put8('h92, 8'd4);
    put8('h93, 8'd0);
    put8('h94, 8'd0);
    put8('h95, 8'd0);

    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 4)
      $fatal(1, "matrix progress %0d expected 4", done_progress);
    if (read_s32('h200) != 19 ||
        read_s32('h204) != 22 ||
        read_s32('h208) != 43 ||
        read_s32('h20c) != 50)
      $fatal(1, "matrix GEMM mismatch: %0d %0d %0d %0d",
             read_s32('h200), read_s32('h204),
             read_s32('h208), read_s32('h20c));

    desc['h38 * 8 + 8 +: 2] = 2'd1;
    submit_and_expect(NPU_STATUS_BAD_DESC);

    desc['h38 * 8 + 8 +: 2] = 2'd0;
    put8('h90, 8'd7);
    submit_and_expect(NPU_STATUS_BAD_DESC);

    l1.mem['h300] = 8'hf8;
    l1.mem['h301] = 8'h02;
    l1.mem['h320] = 8'he1;
    l1.mem['h321] = 8'h4d;
    l1.mem['h322] = 8'hf5;
    desc = '0;
    opcode = NPU_MATRIX_GEMM;
    put8('h00, 8'h01);
    put8('h01, 8'h02);
    put16('h02, 16'd256);
    put64('h08, 64'h300);
    put64('h10, 64'h320);
    put64('h20, 64'h380);
    put32('h38, 32'h0000_0080);
    put32('h40, 32'd1);
    put32('h44, 32'd2);
    put32('h48, 32'd3);
    put32('h4c, 32'd1);
    put32('h50, 32'd1);
    put32('h54, 32'd2);
    put32('h58, 32'd3);
    put32('h5c, 32'h0000_0080);
    put32('h60, 32'd2);
    put32('h64, 32'd1);
    put32('h68, 32'd8);
    put8('h90, 8'd1);
    put8('h91, 8'd1);
    put8('h92, 8'd4);
    put8('h93, 8'd0);
    put8('h94, 8'd0);
    put8('h95, 8'd0);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 2)
      $fatal(1, "matrix INT4 progress %0d expected 2",
             done_progress);
    if (read_s32('h380) != 5 || read_s32('h384) != 10)
      $fatal(1, "matrix INT4 GEMM mismatch: %0d %0d",
             read_s32('h380), read_s32('h384));

    l1.mem['h400] = 8'hfe;
    l1.mem['h401] = 8'h03;
    l1.mem['h420] = 8'hf4;
    l1.mem['h421] = 8'h00;
    l1.mem['h422] = 8'h00;
    l1.mem['h423] = 8'h00;
    l1.mem['h424] = 8'h2d;
    desc = '0;
    put8('h00, 8'h01);
    put8('h01, 8'h02);
    put16('h02, 16'd256);
    put64('h08, 64'h400);
    put64('h10, 64'h420);
    put64('h20, 64'h480);
    put32('h38, 32'h0000_0081);
    put32('h40, 32'd1);
    put32('h44, 32'd2);
    put32('h48, 32'd2);
    put32('h4c, 32'd1);
    put32('h50, 32'd1);
    put32('h54, 32'd2);
    put32('h58, 32'd2);
    put32('h5c, 32'h0000_0080);
    put32('h60, 32'd2);
    put32('h64, 32'd0);
    put32('h68, 32'd8);
    put8('h90, 8'd0);
    put8('h91, 8'd3);
    put8('h92, 8'd4);
    put8('h93, 8'd0);
    put8('h94, 8'd0);
    put8('h95, 8'd0);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (read_s32('h480) != -17 || read_s32('h484) != 8)
      $fatal(1, "matrix INT8xINT4 GEMM mismatch: %0d %0d",
             read_s32('h480), read_s32('h484));

    run_scalar_tiled_b_case();
    run_scalar_tiled_rollover_case(
      NPU_DTYPE_INT4, 8'd1, 8'd3
    );
    run_scalar_tiled_rollover_case(
      NPU_DTYPE_INT8, 8'd0, 8'd2
    );
    run_scalar_tiled_rollover_case(
      NPU_DTYPE_INT16, 8'd5, 8'd6
    );
    run_scalar_transpose_int4_case();

    l1.mem['h600] = 8'h02;
    l1.mem['h601] = 8'h00;
    l1.mem['h602] = 8'hfd;
    l1.mem['h603] = 8'hff;
    l1.mem['h620] = 8'h04;
    l1.mem['h621] = 8'h00;
    l1.mem['h622] = 8'hff;
    l1.mem['h623] = 8'hff;
    l1.mem['h630] = 8'hfe;
    l1.mem['h631] = 8'hff;
    l1.mem['h632] = 8'h05;
    l1.mem['h633] = 8'h00;
    l1.mem['h680] = 8'h01;
    l1.mem['h681] = 8'h00;
    l1.mem['h682] = 8'h00;
    l1.mem['h683] = 8'h00;
    l1.mem['h684] = 8'h00;
    l1.mem['h685] = 8'h00;
    l1.mem['h686] = 8'h00;
    l1.mem['h687] = 8'h00;
    desc = '0;
    opcode = NPU_MATRIX_GEMM;
    put8('h00, 8'h01);
    put8('h01, 8'h02);
    put16('h02, 16'd256);
    put64('h08, 64'h600);
    put64('h10, 64'h620);
    put64('h20, 64'h660);
    put64('h30, 64'h680);
    put32('h38, 32'h0000_00cf);
    put32('h40, 32'd1);
    put32('h44, 32'd2);
    put32('h48, 32'd2);
    put32('h4c, 32'd1);
    put32('h50, 32'd1);
    put32('h54, 32'd2);
    put32('h58, 32'd2);
    put32('h5c, 32'h0000_00a0);
    put32('h60, 32'd4);
    put32('h64, 32'd4);
    put32('h68, 32'd4);
    put8('h90, 8'd5);
    put8('h91, 8'd6);
    put8('h92, 8'd5);
    put8('h93, 8'd0);
    put8('h94, 8'd0);
    put8('h95, 8'd0);
    put32('h9c, 32'd1);
    put32('ha0, 32'd0);
    put8('ha4, 8'd1);
    put8('ha5, 8'd0);
    put8('ha6, 8'd8);
    put32('ha8, 32'd8);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed({l1.mem['h661], l1.mem['h660]}) != 16'sd14 ||
        $signed({l1.mem['h663], l1.mem['h662]}) != -16'sd17)
      $fatal(1, "matrix INT16 pack5/pack6 mismatch: %0d %0d",
             $signed({l1.mem['h661], l1.mem['h660]}),
             $signed({l1.mem['h663], l1.mem['h662]}));

    run_fast_dip_case(
      NPU_DTYPE_INT16, 8'd6, NPU_MATRIX_BMM, 2
    );
    run_fast_dip_case(
      NPU_DTYPE_INT8, 8'd2, NPU_MATRIX_GEMM, 1
    );
    run_fast_dip_case(
      NPU_DTYPE_INT4, 8'd3, NPU_MATRIX_GEMM, 1
    );

    $display("tb_npu_matrix_engine PASS");
    $finish;
  end

  initial begin
    #2ms;
    $fatal(1, "tb_npu_matrix_engine global timeout");
  end
endmodule
