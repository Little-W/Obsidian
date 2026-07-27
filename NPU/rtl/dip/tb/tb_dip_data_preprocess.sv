`timescale 1ns/1ps

module tb_dip_data_preprocess;

  localparam int unsigned ARRAY_N = 2;
  localparam int unsigned MAX_LOGICAL_N = ARRAY_N * 4;
  localparam logic [1:0] MODE_INT16 = 2'd0;
  localparam logic [1:0] MODE_INT8 = 2'd1;
  localparam logic [1:0] MODE_INT4 = 2'd2;

  logic clk;
  logic reset_n;
  logic [1:0] mode;
  logic raw_valid;
  logic raw_ready;
  logic [ARRAY_N * 16 - 1:0] raw_row;
  logic permuted_valid;
  logic permuted_ready;
  logic permuted_last;
  logic [ARRAY_N * 16 - 1:0] permuted_row;
  logic busy;
  logic done;

  integer raw_matrix [0:MAX_LOGICAL_N-1][0:MAX_LOGICAL_N-1];
  integer lanes;
  integer logical_n;
  integer element_bits;

  dip_data_preprocess #(
    .ARRAY_N(ARRAY_N)
  ) dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .mode_i(mode),
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

  task automatic configure_mode(input int mode_index);
    begin
      case (mode_index)
        0: begin
          mode = MODE_INT16;
          lanes = 1;
          element_bits = 16;
        end
        1: begin
          mode = MODE_INT8;
          lanes = 2;
          element_bits = 8;
        end
        default: begin
          mode = MODE_INT4;
          lanes = 4;
          element_bits = 4;
        end
      endcase
      logical_n = ARRAY_N * lanes;

      for (int row = 0; row < logical_n; row++) begin
        for (int col = 0; col < logical_n; col++) begin
          raw_matrix[row][col] =
            ((row * logical_n + col) % (1 << element_bits)) -
            (1 << (element_bits - 1));
        end
      end
    end
  endtask

  task automatic pack_raw_row(input int row);
    begin
      if (row < 0 || row >= logical_n)
        $fatal(1, "raw row %0d out of range", row);

      raw_row = '0;
      for (int physical_col = 0;
           physical_col < ARRAY_N;
           physical_col++) begin
        for (int lane = 0; lane < lanes; lane++) begin
          case (mode)
            MODE_INT16: begin
              raw_row[physical_col * 16 +: 16] =
                16'(raw_matrix[row][physical_col]);
            end
            MODE_INT8: begin
              raw_row[
                physical_col * 16 + lane * 8 +: 8
              ] = 8'(raw_matrix[row][physical_col * lanes + lane]);
            end
            MODE_INT4: begin
              raw_row[
                physical_col * 16 + lane * 4 +: 4
              ] = 4'(raw_matrix[row][physical_col * lanes + lane]);
            end
            default: begin
            end
          endcase
        end
      end
    end
  endtask

  task automatic send_raw_tile;
    begin
      for (int row = 0; row < logical_n; row++) begin
        @(negedge clk);
        pack_raw_row(row);
        raw_valid = 1'b1;
        do @(posedge clk); while (!raw_ready);
      end
      @(negedge clk);
      raw_valid = 1'b0;
      raw_row = '0;
    end
  endtask

  task automatic check_permuted_beat(input int load_index);
    integer got;
    integer expected;
    integer permuted_logical_row;
    integer source_row;
    begin
      while (!permuted_valid)
        @(negedge clk);

      permuted_logical_row = logical_n - 1 - load_index;
      for (int logical_col = 0;
           logical_col < logical_n;
           logical_col++) begin
        int physical_col;
        int lane;

        physical_col = logical_col / lanes;
        lane = logical_col % lanes;
        source_row = permuted_logical_row + logical_col;
        if (source_row >= logical_n)
          source_row -= logical_n;
        expected = raw_matrix[source_row][logical_col];

        case (mode)
          MODE_INT16: begin
            got = $signed({
              {16{permuted_row[physical_col * 16 + 15]}},
              permuted_row[physical_col * 16 +: 16]
            });
          end
          MODE_INT8: begin
            got = $signed({
              {24{permuted_row[
                physical_col * 16 + lane * 8 + 7
              ]}},
              permuted_row[
                physical_col * 16 + lane * 8 +: 8
              ]
            });
          end
          MODE_INT4: begin
            got = $signed({
              {28{permuted_row[
                physical_col * 16 + lane * 4 + 3
              ]}},
              permuted_row[
                physical_col * 16 + lane * 4 +: 4
              ]
            });
          end
          default: got = 0;
        endcase

        if (got != expected) begin
          $fatal(1,
                 "mode %0d load %0d col %0d got %0d expected %0d",
                 mode, load_index, logical_col, got, expected);
        end
      end

      if (permuted_last !== (load_index == logical_n - 1))
        $fatal(1, "mode %0d last mismatch at load %0d",
               mode, load_index);

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
    mode = MODE_INT16;
    raw_valid = 1'b0;
    raw_row = '0;
    permuted_ready = 1'b0;
    lanes = 1;
    logical_n = ARRAY_N;
    element_bits = 16;

    repeat (3) @(posedge clk);
    @(negedge clk);
    reset_n = 1'b1;

    for (int mode_index = 0; mode_index < 3; mode_index++) begin
      configure_mode(mode_index);
      send_raw_tile();

      while (!permuted_valid)
        @(negedge clk);
      held_row = permuted_row;
      repeat (2) begin
        @(posedge clk);
        #1;
        if (!permuted_valid || permuted_row !== held_row)
          $fatal(1, "mode %0d output changed under backpressure", mode);
      end

      for (int load_index = 0;
           load_index < logical_n;
           load_index++) begin
        check_permuted_beat(load_index);
      end

      if (!done || busy || !raw_ready)
        $fatal(1, "mode %0d completion handshake failed", mode);

      @(posedge clk);
      @(negedge clk);
    end

    mode = 2'd3;
    #1;
    if (raw_ready)
      $fatal(1, "invalid mode was accepted");

    $display("tb_dip_data_preprocess: PASS");
    $finish;
  end

endmodule
