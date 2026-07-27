module dip_data_preprocess #(
  parameter int unsigned ARRAY_N = 4
) (
  input  logic                          clk_i,
  input  logic                          reset_n,

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

  localparam int unsigned ROW_INDEX_W =
    (ARRAY_N <= 1) ? 1 : $clog2(ARRAY_N);
  localparam logic [ROW_INDEX_W-1:0] LAST_ROW =
    ROW_INDEX_W'(ARRAY_N - 1);

  logic signed [15:0] weight_mem [0:ARRAY_N-1][0:ARRAY_N-1];
  logic [ROW_INDEX_W-1:0] capture_row_q;
  logic [ROW_INDEX_W-1:0] emit_row_q;
  logic emitting_q;

  assign raw_ready_o = !emitting_q;
  assign permuted_valid_o = emitting_q;
  assign permuted_last_o =
    emitting_q && (emit_row_q == LAST_ROW);
  assign busy_o = emitting_q || (capture_row_q != '0);

  always_comb begin
    int permuted_row;
    int source_row;

    permuted_row_o = '0;
    permuted_row = ARRAY_N - 1 - int'(emit_row_q);

    for (int col = 0; col < ARRAY_N; col++) begin
      source_row = permuted_row + col;
      if (source_row >= ARRAY_N)
        source_row = source_row - ARRAY_N;
      permuted_row_o[col * 16 +: 16] =
        weight_mem[source_row][col];
    end
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      capture_row_q <= '0;
      emit_row_q <= '0;
      emitting_q <= 1'b0;
      done_o <= 1'b0;
    end else begin
      done_o <= 1'b0;

      if (raw_valid_i && raw_ready_o) begin
        if (capture_row_q == LAST_ROW) begin
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
   * Every bank location is overwritten before it can be emitted.  Keeping
   * the tile storage out of the asynchronous-reset tree makes it suitable
   * for replacement by, or inference as, banked memory.
   */
  always_ff @(posedge clk_i) begin
    if (raw_valid_i && raw_ready_o) begin
      for (int col = 0; col < ARRAY_N; col++) begin
        weight_mem[capture_row_q][col] <=
          $signed(raw_row_i[col * 16 +: 16]);
      end
    end
  end

  initial begin
    if (ARRAY_N < 1)
      $fatal(1, "dip_data_preprocess ARRAY_N must be at least one");
  end

endmodule
