module dip_data_preprocess #(
  parameter int unsigned ARRAY_N = 16
) (
  input  logic                          clk_i,
  input  logic                          reset_n,
  input  logic [1:0]                    mode_i,

  input  logic                          raw_valid_i,
  output logic                          raw_ready_o,
  input  logic [ARRAY_N * 16 - 1:0]     raw_row_i,

  output logic                          permuted_valid_o,
  input  logic                          permuted_ready_i,
  output logic                          permuted_last_o,
  output logic [ARRAY_N * 16 - 1:0]     permuted_row_o,

  output logic                          busy_o,
  output logic                          done_o
);

  localparam logic [1:0] MODE_INT16 = 2'd0;
  localparam logic [1:0] MODE_INT8 = 2'd1;
  localparam logic [1:0] MODE_INT4 = 2'd2;
  localparam int unsigned MAX_LOGICAL_N = ARRAY_N * 4;
  localparam int unsigned ROW_INDEX_W =
    (MAX_LOGICAL_N <= 1) ? 1 : $clog2(MAX_LOGICAL_N);

  logic [15:0] weight_mem [0:MAX_LOGICAL_N-1][0:ARRAY_N-1];
  logic [ROW_INDEX_W-1:0] capture_row_q;
  logic [ROW_INDEX_W-1:0] emit_row_q;
  logic [1:0] mode_q;
  logic emitting_q;

  function automatic int unsigned lane_count(input logic [1:0] mode);
    case (mode)
      MODE_INT16: return 1;
      MODE_INT8: return 2;
      MODE_INT4: return 4;
      default: return 0;
    endcase
  endfunction

  function automatic int unsigned logical_size(input logic [1:0] mode);
    return ARRAY_N * lane_count(mode);
  endfunction

  function automatic int unsigned wrap_logical_index(
    input int unsigned index,
    input int unsigned size
  );
    if (index >= size)
      return index - size;
    return index;
  endfunction

  wire first_raw_row = !emitting_q && (capture_row_q == '0);
  wire selected_mode_valid =
    first_raw_row ? (lane_count(mode_i) != 0) :
                    (lane_count(mode_q) != 0);

  assign raw_ready_o = !emitting_q && selected_mode_valid;
  assign permuted_valid_o = emitting_q;
  assign permuted_last_o =
    emitting_q &&
    (int'(emit_row_q) == logical_size(mode_q) - 1);
  assign busy_o = emitting_q || (capture_row_q != '0);

  always_comb begin
    int unsigned logical_n;
    int unsigned permuted_logical_row;
    int unsigned logical_col;
    int unsigned source_row;

    permuted_row_o = '0;
    logical_n = logical_size(mode_q);
    permuted_logical_row =
      logical_n - 1 - int'(emit_row_q);

    case (mode_q)
      MODE_INT16: begin
        for (int physical_col = 0;
             physical_col < ARRAY_N;
             physical_col++) begin
          logical_col = physical_col;
          source_row = wrap_logical_index(
            permuted_logical_row + logical_col,
            logical_n
          );
          if (source_row >= MAX_LOGICAL_N)
            source_row = 0;
          permuted_row_o[physical_col * 16 +: 16] =
            weight_mem[source_row][physical_col];
        end
      end

      MODE_INT8: begin
        for (int physical_col = 0;
             physical_col < ARRAY_N;
             physical_col++) begin
          for (int lane = 0; lane < 2; lane++) begin
            logical_col = physical_col * 2 + lane;
            source_row = wrap_logical_index(
              permuted_logical_row + logical_col,
              logical_n
            );
            if (source_row >= MAX_LOGICAL_N)
              source_row = 0;
            permuted_row_o[
              physical_col * 16 + lane * 8 +: 8
            ] = weight_mem[source_row][physical_col][
              lane * 8 +: 8
            ];
          end
        end
      end

      MODE_INT4: begin
        for (int physical_col = 0;
             physical_col < ARRAY_N;
             physical_col++) begin
          for (int lane = 0; lane < 4; lane++) begin
            logical_col = physical_col * 4 + lane;
            source_row = wrap_logical_index(
              permuted_logical_row + logical_col,
              logical_n
            );
            if (source_row >= MAX_LOGICAL_N)
              source_row = 0;
            permuted_row_o[
              physical_col * 16 + lane * 4 +: 4
            ] = weight_mem[source_row][physical_col][
              lane * 4 +: 4
            ];
          end
        end
      end

      default: begin
      end
    endcase
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      capture_row_q <= '0;
      emit_row_q <= '0;
      mode_q <= MODE_INT16;
      emitting_q <= 1'b0;
      done_o <= 1'b0;
    end else begin
      done_o <= 1'b0;

      if (raw_valid_i && raw_ready_o) begin
        if (first_raw_row)
          mode_q <= mode_i;

        if (int'(capture_row_q) ==
            logical_size(first_raw_row ? mode_i : mode_q) - 1) begin
          capture_row_q <= '0;
          emit_row_q <= '0;
          emitting_q <= 1'b1;
        end else begin
          capture_row_q <= capture_row_q + 1'b1;
        end
      end

      if (permuted_valid_o && permuted_ready_i) begin
        if (permuted_last_o) begin
          emit_row_q <= '0;
          emitting_q <= 1'b0;
          done_o <= 1'b1;
        end else begin
          emit_row_q <= emit_row_q + 1'b1;
        end
      end
    end
  end

  /*
   * The complete logical B row is always ARRAY_N*16 bits:
   * N x INT16, 2N x INT8, or 4N x INT4.  One 16-bit word is written into
   * each physical column bank every accepted row.
   */
  always_ff @(posedge clk_i) begin
    if (raw_valid_i && raw_ready_o) begin
      for (int physical_col = 0;
           physical_col < ARRAY_N;
           physical_col++) begin
        weight_mem[capture_row_q][physical_col] <=
          raw_row_i[physical_col * 16 +: 16];
      end
    end
  end

  initial begin
    if (ARRAY_N < 1)
      $fatal(1, "dip_data_preprocess ARRAY_N must be at least one");
  end

endmodule
