`timescale 1ns/1ps

module tb_dip_gemm_core;

  localparam int unsigned ARRAY_N = 2;
  localparam int unsigned MAX_LOGICAL_N = ARRAY_N * 4;
  localparam int unsigned TIMEOUT_CYCLES = 1000;
  localparam logic [1:0] MODE_INT16 = 2'd0;
  localparam logic [1:0] MODE_INT8 = 2'd1;
  localparam logic [1:0] MODE_INT4 = 2'd2;

  logic clk;
  logic reset_n;
  logic [1:0] mode;
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

  integer a_matrix [0:MAX_LOGICAL_N-1][0:MAX_LOGICAL_N-1];
  integer b_matrix [0:MAX_LOGICAL_N-1][0:MAX_LOGICAL_N-1];
  integer expected_c [0:MAX_LOGICAL_N-1][0:MAX_LOGICAL_N-1];

  integer logical_n;
  integer lanes;
  integer input_bits;
  integer accumulator_bits;
  integer output_bits;
  integer current_tile_id;
  integer received_rows;
  integer vector_fd;

  time first_a_accept_time;
  time last_c_valid_time;
  time previous_c_valid_time;
  logic measure_latency;

  dip_gemm_core #(
    .ARRAY_N(ARRAY_N)
  ) dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .mode_i(mode),
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

  function automatic logic [1:0] precision_to_mode(
    input int precision
  );
    case (precision)
      16: return MODE_INT16;
      8: return MODE_INT8;
      4: return MODE_INT4;
      default: return 2'd3;
    endcase
  endfunction

  task automatic pack_a_row(input int row);
    begin
      if (row < 0 || row >= logical_n)
        $fatal(1, "A row %0d out of range", row);

      a_row = '0;
      for (int physical_col = 0;
           physical_col < ARRAY_N;
           physical_col++) begin
        for (int lane = 0; lane < lanes; lane++) begin
          case (mode)
            MODE_INT16: begin
              a_row[physical_col * 16 +: 16] =
                16'(a_matrix[row][physical_col]);
            end
            MODE_INT8: begin
              a_row[
                physical_col * 16 + lane * 8 +: 8
              ] = 8'(a_matrix[row][physical_col * lanes + lane]);
            end
            MODE_INT4: begin
              a_row[
                physical_col * 16 + lane * 4 +: 4
              ] = 4'(a_matrix[row][physical_col * lanes + lane]);
            end
            default: begin
            end
          endcase
        end
      end
    end
  endtask

  task automatic pack_b_row(input int row);
    begin
      if (row < 0 || row >= logical_n)
        $fatal(1, "B row %0d out of range", row);

      b_raw_row = '0;
      for (int physical_col = 0;
           physical_col < ARRAY_N;
           physical_col++) begin
        for (int lane = 0; lane < lanes; lane++) begin
          case (mode)
            MODE_INT16: begin
              b_raw_row[physical_col * 16 +: 16] =
                16'(b_matrix[row][physical_col]);
            end
            MODE_INT8: begin
              b_raw_row[
                physical_col * 16 + lane * 8 +: 8
              ] = 8'(b_matrix[row][physical_col * lanes + lane]);
            end
            MODE_INT4: begin
              b_raw_row[
                physical_col * 16 + lane * 4 +: 4
              ] = 4'(b_matrix[row][physical_col * lanes + lane]);
            end
            default: begin
            end
          endcase
        end
      end
    end
  endtask

  task automatic stream_b_tile(input logic insert_gaps);
    begin
      for (int row = 0; row < logical_n; row++) begin
        @(negedge clk);
        if (insert_gaps && ((row + current_tile_id) % 3 == 1)) begin
          b_raw_row_valid = 1'b0;
          b_raw_row = '0;
          @(posedge clk);
          @(negedge clk);
        end

        pack_b_row(row);
        b_raw_row_valid = 1'b1;
        do @(posedge clk); while (!b_raw_row_ready);
      end

      @(negedge clk);
      b_raw_row_valid = 1'b0;
      b_raw_row = '0;
    end
  endtask

  task automatic stream_a_tile(input logic insert_gaps);
    begin
      for (int row = 0; row < logical_n; row++) begin
        @(negedge clk);
        if (insert_gaps && ((row + current_tile_id) % 4 == 2)) begin
          a_row_valid = 1'b0;
          a_row = '0;
          repeat (2) @(posedge clk);
          @(negedge clk);
        end

        pack_a_row(row);
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

  task automatic wait_for_tile_done;
    int timeout;
    begin
      timeout = 0;
      while (!tile_done && timeout < TIMEOUT_CYCLES) begin
        @(negedge clk);
        timeout++;
      end
      if (!tile_done)
        $fatal(1, "tile %0d timed out", current_tile_id);
      if (received_rows != logical_n) begin
        $fatal(1,
               "tile %0d received %0d rows, expected %0d",
               current_tile_id, received_rows, logical_n);
      end

      @(posedge clk);
      @(negedge clk);
    end
  endtask

  /* verilator lint_off BLKSEQ */
  always @(negedge clk) begin
    integer got;

    if (c_row_valid) begin
      if (received_rows >= logical_n)
        $fatal(1, "tile %0d produced too many rows", current_tile_id);
      if (measure_latency &&
          received_rows > 0 &&
          $time - previous_c_valid_time != 10ns) begin
        $fatal(1,
               "tile %0d row output interval %0t, expected 10ns",
               current_tile_id, $time - previous_c_valid_time);
      end

      for (int logical_col = 0;
           logical_col < logical_n;
           logical_col++) begin
        int physical_col;
        int lane;

        physical_col = logical_col / lanes;
        lane = logical_col % lanes;
        case (mode)
          MODE_INT16: begin
            got = $signed(c_row[physical_col * 32 +: 32]);
          end
          MODE_INT8: begin
            got = $signed({
              {16{c_row[
                physical_col * 32 + lane * 16 + 15
              ]}},
              c_row[
                physical_col * 32 + lane * 16 +: 16
              ]
            });
          end
          MODE_INT4: begin
            got = $signed({
              {24{c_row[
                physical_col * 32 + lane * 8 + 7
              ]}},
              c_row[
                physical_col * 32 + lane * 8 +: 8
              ]
            });
          end
          default: got = 0;
        endcase

        if (got != expected_c[received_rows][logical_col]) begin
          $fatal(1,
                 "tile %0d C[%0d,%0d] got %0d expected %0d",
                 current_tile_id, received_rows, logical_col,
                 got, expected_c[received_rows][logical_col]);
        end
      end

      if (c_row_last !== (received_rows == logical_n - 1)) begin
        $fatal(1, "tile %0d c_row_last mismatch on row %0d",
               current_tile_id, received_rows);
      end

      previous_c_valid_time = $time;
      received_rows = received_rows + 1;
    end
  end

  always @(posedge c_row_last) begin
    if (measure_latency)
      last_c_valid_time = $time;
  end
  /* verilator lint_on BLKSEQ */

  initial begin
    string vector_path;
    integer scan_count;
    integer format_version;
    integer file_physical_n;
    integer tile_count;
    integer file_seed;
    integer mode_precision;
    integer metadata_lanes;
    integer metadata_logical_n;

    clk = 1'b0;
    reset_n = 1'b0;
    mode = MODE_INT16;
    b_raw_row_valid = 1'b0;
    b_raw_row = '0;
    a_row_valid = 1'b0;
    a_row = '0;
    logical_n = ARRAY_N;
    lanes = 1;
    input_bits = 16;
    accumulator_bits = 64;
    output_bits = 32;
    current_tile_id = 0;
    received_rows = 0;
    first_a_accept_time = 0;
    last_c_valid_time = 0;
    previous_c_valid_time = 0;
    measure_latency = 1'b0;

    if (!$value$plusargs("VECTOR_FILE=%s", vector_path))
      $fatal(1, "missing +VECTOR_FILE=<path>");
    vector_fd = $fopen(vector_path, "r");
    if (vector_fd == 0)
      $fatal(1, "cannot open vector file %s", vector_path);

    scan_count = $fscanf(
      vector_fd, "%d %d %d %d",
      format_version, file_physical_n, tile_count, file_seed
    );
    if (scan_count != 4 || format_version != 1)
      $fatal(1, "invalid random-vector header");
    if (file_physical_n != ARRAY_N)
      $fatal(1, "vector physical N=%0d, testbench N=%0d",
             file_physical_n, ARRAY_N);

    repeat (4) @(posedge clk);
    @(negedge clk);
    reset_n = 1'b1;

    for (int tile_index = 0; tile_index < tile_count; tile_index++) begin
      scan_count = $fscanf(
        vector_fd, "%d %d %d %d %d %d %d",
        current_tile_id, mode_precision, metadata_lanes,
        metadata_logical_n, input_bits, accumulator_bits,
        output_bits
      );
      if (scan_count != 7 || current_tile_id != tile_index)
        $fatal(1, "invalid metadata for tile %0d", tile_index);

      mode = precision_to_mode(mode_precision);
      lanes = metadata_lanes;
      logical_n = metadata_logical_n;
      if (mode == 2'd3 ||
          logical_n != ARRAY_N * lanes ||
          input_bits != mode_precision ||
          accumulator_bits != 2 * output_bits) begin
        $fatal(1, "inconsistent metadata for tile %0d", tile_index);
      end

      for (int row = 0; row < logical_n; row++) begin
        for (int col = 0; col < logical_n; col++) begin
          scan_count = $fscanf(vector_fd, "%d", a_matrix[row][col]);
          if (scan_count != 1)
            $fatal(1, "truncated A matrix in tile %0d", tile_index);
        end
      end
      for (int row = 0; row < logical_n; row++) begin
        for (int col = 0; col < logical_n; col++) begin
          scan_count = $fscanf(vector_fd, "%d", b_matrix[row][col]);
          if (scan_count != 1)
            $fatal(1, "truncated B matrix in tile %0d", tile_index);
        end
      end
      for (int row = 0; row < logical_n; row++) begin
        for (int col = 0; col < logical_n; col++) begin
          scan_count = $fscanf(vector_fd, "%d", expected_c[row][col]);
          if (scan_count != 1)
            $fatal(1, "truncated C matrix in tile %0d", tile_index);
        end
      end

      received_rows = 0;
      first_a_accept_time = 0;
      last_c_valid_time = 0;
      previous_c_valid_time = 0;
      measure_latency = (tile_index % 2) == 0;

      stream_b_tile(!measure_latency);
      stream_a_tile(!measure_latency);
      wait_for_tile_done();

      if (measure_latency &&
          last_c_valid_time - first_a_accept_time !=
          (logical_n + ARRAY_N + 1) * 10ns) begin
        $fatal(1,
               "tile %0d latency %0t, expected %0t",
               tile_index,
               last_c_valid_time - first_a_accept_time,
               (logical_n + ARRAY_N + 1) * 10ns);
      end
      measure_latency = 1'b0;

      if (busy || !b_raw_row_ready)
        $fatal(1, "tile %0d did not return to idle", tile_index);
    end

    if (!$feof(vector_fd)) begin
      integer trailing_value;
      if ($fscanf(vector_fd, "%d", trailing_value) == 1)
        $fatal(1, "unexpected trailing vector value %0d",
               trailing_value);
    end

    $fclose(vector_fd);
    $display(
      "tb_dip_gemm_core: PASS (%0d Python-generated tiles, seed %0d)",
      tile_count, file_seed
    );
    $finish;
  end

endmodule
