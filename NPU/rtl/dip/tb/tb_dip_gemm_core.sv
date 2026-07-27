`timescale 1ns/1ps

module tb_dip_gemm_core;

  localparam int unsigned ARRAY_N = 3;
  localparam int unsigned TIMEOUT_CYCLES = 200;

  logic clk;
  logic reset_n;
  logic b_raw_row_valid;
  logic b_raw_row_ready;
  logic [ARRAY_N * 16 - 1:0] b_raw_row;
  logic a_row_valid;
  logic a_row_ready;
  logic [ARRAY_N * 16 - 1:0] a_row;
  logic c_row_valid;
  logic c_row_last;
  logic [ARRAY_N * 32 - 1:0] c_row;
  logic busy;
  logic tile_done;

  logic signed [15:0] a_matrix [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [15:0] b_matrix [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [31:0] expected_c [0:ARRAY_N-1][0:ARRAY_N-1];

  integer received_rows;
  time first_a_accept_time;
  time last_c_valid_time;
  logic measure_latency;

  dip_gemm_core #(
    .ARRAY_N(ARRAY_N)
  ) dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .b_raw_row_valid_i(b_raw_row_valid),
    .b_raw_row_ready_o(b_raw_row_ready),
    .b_raw_row_i(b_raw_row),
    .a_row_valid_i(a_row_valid),
    .a_row_ready_o(a_row_ready),
    .a_row_i(a_row),
    .c_row_valid_o(c_row_valid),
    .c_row_last_o(c_row_last),
    .c_row_o(c_row),
    .busy_o(busy),
    .tile_done_o(tile_done)
  );

  always #5 clk = ~clk;

  task automatic calculate_expected;
    longint signed accumulator;
    begin
      for (int row = 0; row < ARRAY_N; row++) begin
        for (int col = 0; col < ARRAY_N; col++) begin
          accumulator = 0;
          for (int k = 0; k < ARRAY_N; k++) begin
            accumulator +=
              $signed(a_matrix[row][k]) *
              $signed(b_matrix[k][col]);
          end
          expected_c[row][col] = accumulator[31:0];
        end
      end
    end
  endtask

  task automatic stream_b_tile;
    begin
      for (int row = 0; row < ARRAY_N; row++) begin
        @(negedge clk);
        for (int col = 0; col < ARRAY_N; col++)
          b_raw_row[col * 16 +: 16] = b_matrix[row][col];
        b_raw_row_valid = 1'b1;

        do @(posedge clk); while (!b_raw_row_ready);
      end

      @(negedge clk);
      b_raw_row_valid = 1'b0;
      b_raw_row = '0;
    end
  endtask

  task automatic stream_a_tile_continuous;
    begin
      for (int row = 0; row < ARRAY_N; row++) begin
        @(negedge clk);
        for (int col = 0; col < ARRAY_N; col++)
          a_row[col * 16 +: 16] = a_matrix[row][col];
        a_row_valid = 1'b1;

        do @(posedge clk); while (!a_row_ready);
        if (measure_latency && row == 0)
          first_a_accept_time = $time;
      end

      @(negedge clk);
      a_row_valid = 1'b0;
      a_row = '0;
    end
  endtask

  task automatic stream_a_tile_with_gaps;
    begin
      for (int row = 0; row < ARRAY_N; row++) begin
        @(negedge clk);
        for (int col = 0; col < ARRAY_N; col++)
          a_row[col * 16 +: 16] = a_matrix[row][col];
        a_row_valid = 1'b1;

        do @(posedge clk); while (!a_row_ready);

        @(negedge clk);
        a_row_valid = 1'b0;
        a_row = '0;
        repeat (row + 1) @(posedge clk);
      end
    end
  endtask

  task automatic wait_for_tile_done;
    int timeout;
    begin
      timeout = 0;
      while (!tile_done && timeout < TIMEOUT_CYCLES) begin
        @(negedge clk);
        timeout++;
      end
      if (!tile_done)
        $fatal(1, "DiP GEMM tile timeout");
      if (received_rows != ARRAY_N)
        $fatal(1, "received %0d result rows, expected %0d",
               received_rows, ARRAY_N);

      @(posedge clk);
      @(negedge clk);
    end
  endtask

  /* verilator lint_off BLKSEQ */
  always @(negedge clk) begin
    if (c_row_valid) begin
      if (received_rows >= ARRAY_N)
        $fatal(1, "received too many result rows");

      for (int col = 0; col < ARRAY_N; col++) begin
        if ($signed(c_row[col * 32 +: 32]) !==
            expected_c[received_rows][col]) begin
          $fatal(1,
                 "C[%0d,%0d] got %0d expected %0d",
                 received_rows, col,
                 $signed(c_row[col * 32 +: 32]),
                 expected_c[received_rows][col]);
        end
      end

      if (c_row_last !== (received_rows == ARRAY_N - 1))
        $fatal(1, "C last flag mismatch on row %0d", received_rows);

      received_rows = received_rows + 1;
    end
  end
  /* verilator lint_on BLKSEQ */

  /* verilator lint_off BLKSEQ */
  always @(posedge c_row_last) begin
    if (measure_latency)
      last_c_valid_time = $time;
  end
  /* verilator lint_on BLKSEQ */

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
    b_raw_row_valid = 1'b0;
    b_raw_row = '0;
    a_row_valid = 1'b0;
    a_row = '0;
    received_rows = 0;
    first_a_accept_time = 0;
    last_c_valid_time = 0;
    measure_latency = 1'b0;

    repeat (4) @(posedge clk);
    @(negedge clk);
    reset_n = 1'b1;

    /*
     * Paper Fig. 3 numeric form:
     * A = B = [1 2 3; 4 5 6; 7 8 9].
     */
    for (int row = 0; row < ARRAY_N; row++) begin
      for (int col = 0; col < ARRAY_N; col++) begin
        a_matrix[row][col] =
          16'(row * ARRAY_N + col + 1);
        b_matrix[row][col] =
          16'(row * ARRAY_N + col + 1);
      end
    end
    calculate_expected();

    stream_b_tile();
    measure_latency = 1'b1;
    stream_a_tile_continuous();
    wait_for_tile_done();

    if (last_c_valid_time - first_a_accept_time !=
        2 * ARRAY_N * 10ns) begin
      $fatal(1,
             "continuous-tile latency was %0t, expected %0t",
             last_c_valid_time - first_a_accept_time,
             2 * ARRAY_N * 10ns);
    end
    measure_latency = 1'b0;

    if (expected_c[0][0] != 32'sd30 ||
        expected_c[0][1] != 32'sd36 ||
        expected_c[0][2] != 32'sd42 ||
        expected_c[2][2] != 32'sd150)
      $fatal(1, "testbench paper-example golden model is wrong");

    /*
     * A signed INT16 tile with deliberate valid bubbles verifies signed
     * multiplication, row-valid propagation, and reuse after tile_done.
     */
    received_rows = 0;
    a_matrix[0][0] = 16'sd32767;
    a_matrix[0][1] = -16'sd32768;
    a_matrix[0][2] = 16'sd1;
    a_matrix[1][0] = -16'sd1;
    a_matrix[1][1] = 16'sd2;
    a_matrix[1][2] = -16'sd3;
    a_matrix[2][0] = 16'sd123;
    a_matrix[2][1] = -16'sd456;
    a_matrix[2][2] = 16'sd789;

    b_matrix[0][0] = -16'sd2;
    b_matrix[0][1] = 16'sd3;
    b_matrix[0][2] = 16'sd4;
    b_matrix[1][0] = 16'sd5;
    b_matrix[1][1] = -16'sd6;
    b_matrix[1][2] = 16'sd7;
    b_matrix[2][0] = -16'sd8;
    b_matrix[2][1] = 16'sd9;
    b_matrix[2][2] = -16'sd10;
    calculate_expected();

    stream_b_tile();
    stream_a_tile_with_gaps();
    wait_for_tile_done();

    if (busy)
      $fatal(1, "core busy remained asserted after tile completion");
    if (!b_raw_row_ready)
      $fatal(1, "core did not return to weight-load state");

    $display("tb_dip_gemm_core: PASS");
    $finish;
  end

endmodule
