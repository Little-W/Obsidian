module tb_npu_vector_fast_mul;
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

  npu_vector_engine dut (
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

  task automatic put_i4(
    input integer base,
    input integer index,
    input logic signed [3:0] value
  );
    if ((index & 1) == 0)
      l1.mem[base + index / 2][3:0] = value;
    else
      l1.mem[base + index / 2][7:4] = value;
  endtask

  task automatic put_i8(
    input integer base,
    input integer index,
    input logic signed [7:0] value
  );
    l1.mem[base + index] = value;
  endtask

  task automatic put_i16(
    input integer base,
    input integer index,
    input logic signed [15:0] value
  );
    begin
      l1.mem[base + index * 2] = value[7:0];
      l1.mem[base + index * 2 + 1] = value[15:8];
    end
  endtask

  function automatic logic signed [31:0] read_i32(
    input integer address
  );
    return $signed({
      l1.mem[address + 3],
      l1.mem[address + 2],
      l1.mem[address + 1],
      l1.mem[address]
    });
  endfunction

  function automatic logic signed [3:0] sample_i4_a(input integer index);
    case (index % 8)
      0: return 4'sh8;
      1: return 4'sh7;
      2: return -4'sd1;
      3: return 4'sd0;
      4: return -4'sd6;
      5: return 4'sd5;
      6: return -4'sd3;
      default: return 4'sd2;
    endcase
  endfunction

  function automatic logic signed [3:0] sample_i4_b(input integer index);
    case (index % 8)
      0: return 4'sh8;
      1: return -4'sd1;
      2: return 4'sh7;
      3: return -4'sd4;
      4: return 4'sd3;
      5: return -4'sd2;
      6: return 4'sd0;
      default: return 4'sd6;
    endcase
  endfunction

  function automatic logic signed [7:0] sample_i8_a(input integer index);
    case (index % 8)
      0: return 8'sh80;
      1: return 8'sh7f;
      2: return -8'sd1;
      3: return 8'sd0;
      4: return -8'sd100;
      5: return 8'sd63;
      6: return -8'sd17;
      default: return 8'sd42;
    endcase
  endfunction

  function automatic logic signed [7:0] sample_i8_b(input integer index);
    case (index % 8)
      0: return 8'sh80;
      1: return -8'sd1;
      2: return 8'sh7f;
      3: return -8'sd64;
      4: return 8'sd3;
      5: return -8'sd2;
      6: return 8'sd0;
      default: return 8'sd6;
    endcase
  endfunction

  function automatic logic signed [15:0] sample_i16_a(
    input integer index
  );
    case (index % 4)
      0: return 16'sh8000;
      1: return 16'sh7fff;
      2: return -16'sd12345;
      default: return 16'sd0;
    endcase
  endfunction

  function automatic logic signed [15:0] sample_i16_b(
    input integer index
  );
    case (index % 4)
      0: return 16'sh8000;
      1: return -16'sd1;
      2: return 16'sh7fff;
      default: return -16'sd23456;
    endcase
  endfunction

  task automatic setup_mul_task(
    input logic [1:0] dtype,
    input integer task_rows,
    input integer task_length,
    input integer task_valid_length,
    input integer src0_address,
    input integer src1_address,
    input integer dst_address
  );
    integer input_stride;
    integer input_row_stride;
    begin
      input_stride =
        (dtype == NPU_DTYPE_INT16) ? 2 :
        (dtype == NPU_DTYPE_INT8) ? 1 : 0;
      input_row_stride =
        (dtype == NPU_DTYPE_INT16) ? task_length * 2 :
        (dtype == NPU_DTYPE_INT8) ? task_length :
        (task_length + 1) / 2;

      opcode = NPU_VECTOR_MUL;
      desc = '0;
      put8('h00, 8'h01);
      put8('h01, 8'h03);
      put16('h02, 16'd192);
      put64('h08, 64'(src0_address));
      put64('h10, 64'(src1_address));
      put64('h20, 64'(dst_address));
      put32(
        'h38,
        {
          22'd0,
          2'd0,
          NPU_DTYPE_INT32,
          NPU_DTYPE_INT32,
          dtype,
          dtype
        }
      );
      put32('h40, 32'(task_rows));
      put32('h44, 32'(task_length));
      put32('h48, 32'(task_valid_length));
      put32('h4c, 32'd0);
      put32('h50, 32'(input_stride));
      put32('h54, 32'(input_row_stride));
      put32('h58, 32'(input_stride));
      put32('h5c, 32'(input_row_stride));
      put32('h68, 32'd4);
      put32('h6c, 32'(task_length * 4));
      put8('h78, 8'd0);
      put8('h7a, 8'd0);
      put8('h7b, 8'd0);
    end
  endtask

  task automatic submit_and_check_path(
    input logic expect_fast,
    input integer expected_progress,
    input integer expected_reads,
    input integer expected_writes
  );
    integer timeout;
    integer read_count;
    integer write_count;
    logic fast_seen;
    begin
      timeout = 0;
      while (!task_ready && timeout < 1000) begin
        @(posedge clk);
        timeout++;
      end
      if (!task_ready)
        $fatal(1, "task_ready timeout");

      @(negedge clk);
      task_valid = 1'b1;
      @(negedge clk);
      task_valid = 1'b0;

      timeout = 0;
      read_count = 0;
      write_count = 0;
      fast_seen = 1'b0;
      while (!done_valid && timeout < 20000) begin
        @(posedge clk);
        if (dut.fast_path_active_q)
          fast_seen = 1'b1;
        if (l1_req_valid && l1_req_ready) begin
          if (l1_req_write)
            write_count++;
          else
            read_count++;
        end
        timeout++;
      end

      if (!done_valid)
        $fatal(1, "done timeout");
      if (done_status != NPU_STATUS_SUCCESS)
        $fatal(1, "status %02x", done_status);
      if (done_fault_addr != 48'd0)
        $fatal(1, "fault address %012x", done_fault_addr);
      if (done_progress != 64'(expected_progress))
        $fatal(1, "progress %0d expected %0d",
               done_progress, expected_progress);
      if (fast_seen != expect_fast)
        $fatal(1, "fast path seen=%0d expected=%0d",
               fast_seen, expect_fast);
      if (read_count != expected_reads || write_count != expected_writes)
        $fatal(1, "request counts read=%0d/%0d write=%0d/%0d",
               read_count, expected_reads, write_count, expected_writes);
    end
  endtask

  initial begin : run_tests
    logic signed [31:0] expected;

    clk = 1'b0;
    reset_n = 1'b0;
    task_valid = 1'b0;
    done_ready = 1'b1;
    opcode = NPU_VECTOR_MUL;
    command_id = 12'h201;
    desc = '0;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;

    for (integer index = 0; index < 32; index++) begin
      put_i4('h100, index, sample_i4_a(index));
      put_i4('h200, index, sample_i4_b(index));
    end
    setup_mul_task(
      NPU_DTYPE_INT4, 2, 16, 16, 'h100, 'h200, 'h300
    );
    submit_and_check_path(1'b1, 32, 4, 16);
    for (integer index = 0; index < 32; index++) begin
      expected = sample_i4_a(index) * sample_i4_b(index);
      if (read_i32('h300 + index * 4) != expected)
        $fatal(1, "INT4 index %0d got %0d expected %0d",
               index, read_i32('h300 + index * 4), expected);
    end

    for (integer index = 0; index < 32; index++) begin
      put_i8('h400, index, sample_i8_a(index));
      put_i8('h500, index, sample_i8_b(index));
    end
    setup_mul_task(
      NPU_DTYPE_INT8, 2, 16, 12, 'h400, 'h500, 'h600
    );
    submit_and_check_path(1'b1, 28, 8, 14);
    for (integer index = 0; index < 28; index++) begin
      expected = sample_i8_a(index) * sample_i8_b(index);
      if (read_i32('h600 + index * 4) != expected)
        $fatal(1, "INT8 index %0d got %0d expected %0d",
               index, read_i32('h600 + index * 4), expected);
    end

    for (integer index = 0; index < 8; index++) begin
      put_i16('h700, index, sample_i16_a(index));
      put_i16('h800, index, sample_i16_b(index));
    end
    setup_mul_task(
      NPU_DTYPE_INT16, 2, 4, 4, 'h700, 'h800, 'h900
    );
    submit_and_check_path(1'b1, 8, 4, 4);
    for (integer index = 0; index < 8; index++) begin
      expected = sample_i16_a(index) * sample_i16_b(index);
      if (read_i32('h900 + index * 4) != expected)
        $fatal(1, "INT16 index %0d got %0d expected %0d",
               index, read_i32('h900 + index * 4), expected);
    end

    put_i8('ha01, 0, -8'sd7);
    put_i8('ha01, 1, 8'sd12);
    put_i8('ha01, 2, 8'sh80);
    put_i8('ha21, 0, 8'sd9);
    put_i8('ha21, 1, -8'sd3);
    put_i8('ha21, 2, -8'sd1);
    setup_mul_task(
      NPU_DTYPE_INT8, 1, 3, 3, 'ha01, 'ha21, 'ha40
    );
    submit_and_check_path(1'b0, 3, 6, 3);
    if (read_i32('ha40) != -63 ||
        read_i32('ha44) != -36 ||
        read_i32('ha48) != 128)
      $fatal(1, "scalar fallback mismatch");

    $display("tb_npu_vector_fast_mul PASS");
    $finish;
  end

  initial begin
    #2ms;
    $fatal(1, "tb_npu_vector_fast_mul global timeout");
  end

endmodule
