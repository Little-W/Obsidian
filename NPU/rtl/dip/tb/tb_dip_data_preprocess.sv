`timescale 1ns/1ps

module tb_dip_data_preprocess;

  localparam int unsigned ARRAY_N = 3;

  logic clk;
  logic reset_n;
  logic raw_valid;
  logic raw_ready;
  logic [ARRAY_N * 16 - 1:0] raw_row;
  logic permuted_valid;
  logic permuted_ready;
  logic permuted_last;
  logic [ARRAY_N * 16 - 1:0] permuted_row;
  logic busy;
  logic done;

  logic signed [15:0] raw_matrix [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [15:0] expected_load [0:ARRAY_N-1][0:ARRAY_N-1];

  dip_data_preprocess #(
    .ARRAY_N(ARRAY_N)
  ) dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .raw_valid_i(raw_valid),
    .raw_ready_o(raw_ready),
    .raw_row_i(raw_row),
    .permuted_valid_o(permuted_valid),
    .permuted_ready_i(permuted_ready),
    .permuted_last_o(permuted_last),
    .permuted_row_o(permuted_row),
    .busy_o(busy),
    .done_o(done)
  );

  always #5 clk = ~clk;

  task automatic send_raw_row(input int row);
    begin
      if (row < 0 || row >= ARRAY_N)
        $fatal(1, "raw row index %0d is out of range", row);

      @(negedge clk);
      for (int col = 0; col < ARRAY_N; col++)
        raw_row[col * 16 +: 16] = raw_matrix[row][col];
      raw_valid = 1'b1;

      do @(posedge clk); while (!raw_ready);

      @(negedge clk);
      raw_valid = 1'b0;
      raw_row = '0;
    end
  endtask

  task automatic check_output_row(input int load_index);
    begin
      while (!permuted_valid)
        @(negedge clk);

      for (int col = 0; col < ARRAY_N; col++) begin
        if ($signed(permuted_row[col * 16 +: 16]) !==
            expected_load[load_index][col]) begin
          $fatal(1,
                 "preprocess row %0d col %0d got %0d expected %0d",
                 load_index, col,
                 $signed(permuted_row[col * 16 +: 16]),
                 expected_load[load_index][col]);
        end
      end

      if (permuted_last !== (load_index == ARRAY_N - 1))
        $fatal(1, "preprocess last flag mismatch at row %0d",
               load_index);

      permuted_ready = 1'b1;
      @(posedge clk);
      @(negedge clk);
      permuted_ready = 1'b0;
    end
  endtask

  initial begin
    logic [ARRAY_N * 16 - 1:0] held_row;

    clk = 1'b0;
    reset_n = 1'b0;
    raw_valid = 1'b0;
    raw_row = '0;
    permuted_ready = 1'b0;

    raw_matrix[0][0] = 16'sd1;
    raw_matrix[0][1] = -16'sd2;
    raw_matrix[0][2] = 16'sd3;
    raw_matrix[1][0] = -16'sd4;
    raw_matrix[1][1] = 16'sd5;
    raw_matrix[1][2] = -16'sd6;
    raw_matrix[2][0] = 16'sd7;
    raw_matrix[2][1] = -16'sd8;
    raw_matrix[2][2] = 16'sd9;

    expected_load[0][0] = 16'sd7;
    expected_load[0][1] = -16'sd2;
    expected_load[0][2] = -16'sd6;
    expected_load[1][0] = -16'sd4;
    expected_load[1][1] = -16'sd8;
    expected_load[1][2] = 16'sd3;
    expected_load[2][0] = 16'sd1;
    expected_load[2][1] = 16'sd5;
    expected_load[2][2] = 16'sd9;

    repeat (3) @(posedge clk);
    @(negedge clk);
    reset_n = 1'b1;

    for (int row = 0; row < ARRAY_N; row++)
      send_raw_row(row);

    while (!permuted_valid)
      @(negedge clk);
    held_row = permuted_row;
    repeat (2) begin
      @(posedge clk);
      #1;
      if (!permuted_valid || permuted_row !== held_row)
        $fatal(1, "preprocess output changed under backpressure");
    end

    for (int load_index = 0; load_index < ARRAY_N; load_index++)
      check_output_row(load_index);

    if (!done)
      $fatal(1, "preprocess done pulse missing");
    if (busy)
      $fatal(1, "preprocess busy did not clear");
    if (!raw_ready)
      $fatal(1, "preprocess did not become ready for next tile");

    $display("tb_dip_data_preprocess: PASS");
    $finish;
  end

endmodule
