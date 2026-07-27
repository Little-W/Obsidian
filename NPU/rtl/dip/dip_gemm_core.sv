module dip_gemm_core #(
  parameter int unsigned ARRAY_N = 16
) (
  input  logic                          clk_i,
  input  logic                          reset_n,
  input  logic [1:0]                    mode_i,

  input  logic                          b_raw_row_valid_i,
  output logic                          b_raw_row_ready_o,
  input  logic [ARRAY_N * 16 - 1:0]     b_raw_row_i,

  input  logic                          a_row_valid_i,
  output logic                          a_row_ready_o,
  input  logic [ARRAY_N * 16 - 1:0]     a_row_i,

  output logic                          c_row_valid_o,
  output logic                          c_row_last_o,
  output logic [ARRAY_N * 32 - 1:0]     c_row_o,
  output logic [ARRAY_N * 4 * 64 - 1:0] c_accum_row_o,

  output logic                          busy_o,
  output logic                          tile_done_o
);

  localparam logic [1:0] MODE_INT16 = 2'd0;
  localparam logic [1:0] MODE_INT8 = 2'd1;
  localparam logic [1:0] MODE_INT4 = 2'd2;
  localparam int unsigned MAX_LOGICAL_N = ARRAY_N * 4;
  localparam int unsigned ROW_COUNT_W =
    (MAX_LOGICAL_N <= 1) ? 1 : $clog2(MAX_LOGICAL_N + 1);
  localparam int unsigned ROW_INDEX_W =
    (MAX_LOGICAL_N <= 1) ? 1 : $clog2(MAX_LOGICAL_N);

  typedef enum logic [1:0] {
    ST_LOAD_WEIGHTS,
    ST_ACCEPT_INPUTS,
    ST_DRAIN
  } state_t;

  state_t state_q;
  logic [1:0] mode_q;
  logic [ROW_COUNT_W-1:0] accepted_a_rows_q;
  logic [ROW_INDEX_W-1:0] emitted_c_rows_q;

  logic pre_raw_valid;
  logic pre_raw_ready;
  logic pre_permuted_valid;
  logic pre_permuted_ready;
  logic pre_permuted_last;
  logic [ARRAY_N * 16 - 1:0] pre_permuted_row;
  logic pre_busy;
  logic unused_preprocess_done;

  logic array_data_valid;
  logic array_result_valid;
  logic [ARRAY_N * 32 - 1:0] array_result_row;

  logic [1:0] preprocess_mode;
  logic last_weight_beat;
  logic a_row_fire;
  logic first_b_row_fire;

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

  wire idle_for_new_tile =
    (state_q == ST_LOAD_WEIGHTS) && !pre_busy;
  wire requested_mode_valid = lane_count(mode_i) != 0;
  wire active_mode_valid = lane_count(mode_q) != 0;

  assign preprocess_mode = idle_for_new_tile ? mode_i : mode_q;
  assign pre_raw_valid =
    b_raw_row_valid_i &&
    (state_q == ST_LOAD_WEIGHTS) &&
    (pre_busy ? active_mode_valid : requested_mode_valid);
  assign b_raw_row_ready_o =
    pre_raw_ready &&
    (state_q == ST_LOAD_WEIGHTS) &&
    (pre_busy ? active_mode_valid : requested_mode_valid);
  assign pre_permuted_ready = (state_q == ST_LOAD_WEIGHTS);

  assign first_b_row_fire =
    pre_raw_valid && pre_raw_ready && !pre_busy;

  assign last_weight_beat =
    (state_q == ST_LOAD_WEIGHTS) &&
    pre_permuted_valid &&
    pre_permuted_ready &&
    pre_permuted_last;

  assign a_row_ready_o =
    ((state_q == ST_LOAD_WEIGHTS) && last_weight_beat) ||
    ((state_q == ST_ACCEPT_INPUTS) &&
     (int'(accepted_a_rows_q) < logical_size(mode_q)));
  assign a_row_fire = a_row_valid_i && a_row_ready_o;
  assign array_data_valid = a_row_fire;

  assign c_row_valid_o = array_result_valid;
  assign c_row_o = array_result_row;
  assign c_row_last_o =
    array_result_valid &&
    (int'(emitted_c_rows_q) == logical_size(mode_q) - 1);

  assign busy_o =
    (state_q != ST_LOAD_WEIGHTS) || pre_busy;

  dip_data_preprocess #(
    .ARRAY_N(ARRAY_N)
  ) u_data_preprocess (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .mode_i(preprocess_mode),
    .raw_valid_i(pre_raw_valid),
    .raw_ready_o(pre_raw_ready),
    .raw_row_i(b_raw_row_i),
    .permuted_valid_o(pre_permuted_valid),
    .permuted_ready_i(pre_permuted_ready),
    .permuted_last_o(pre_permuted_last),
    .permuted_row_o(pre_permuted_row),
    .busy_o(pre_busy),
    .done_o(unused_preprocess_done)
  );

  dip_systolic_array #(
    .ARRAY_N(ARRAY_N)
  ) u_systolic_array (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .mode_i(mode_q),
    .weight_valid_i(
      pre_permuted_valid && pre_permuted_ready
    ),
    .weight_row_i(pre_permuted_row),
    .data_valid_i(array_data_valid),
    .data_row_i(a_row_i),
    .result_valid_o(array_result_valid),
    .result_row_o(array_result_row),
    .result_accum_row_o(c_accum_row_o)
  );

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      state_q <= ST_LOAD_WEIGHTS;
      mode_q <= MODE_INT16;
      accepted_a_rows_q <= '0;
      emitted_c_rows_q <= '0;
      tile_done_o <= 1'b0;
    end else begin
      tile_done_o <= 1'b0;

      if (first_b_row_fire)
        mode_q <= mode_i;

      case (state_q)
        ST_LOAD_WEIGHTS: begin
          accepted_a_rows_q <= '0;
          emitted_c_rows_q <= '0;

          if (last_weight_beat) begin
            if (a_row_fire) begin
              accepted_a_rows_q <= 1;
              if (logical_size(mode_q) == 1)
                state_q <= ST_DRAIN;
              else
                state_q <= ST_ACCEPT_INPUTS;
            end else begin
              state_q <= ST_ACCEPT_INPUTS;
            end
          end
        end

        ST_ACCEPT_INPUTS: begin
          if (a_row_fire) begin
            accepted_a_rows_q <= accepted_a_rows_q + 1'b1;
            if (int'(accepted_a_rows_q) ==
                logical_size(mode_q) - 1)
              state_q <= ST_DRAIN;
          end
        end

        ST_DRAIN: begin
        end

        default: begin
          state_q <= ST_LOAD_WEIGHTS;
          mode_q <= MODE_INT16;
          accepted_a_rows_q <= '0;
          emitted_c_rows_q <= '0;
        end
      endcase

      if (array_result_valid) begin
        if (int'(emitted_c_rows_q) ==
            logical_size(mode_q) - 1) begin
          emitted_c_rows_q <= '0;
          accepted_a_rows_q <= '0;
          state_q <= ST_LOAD_WEIGHTS;
          tile_done_o <= 1'b1;
        end else begin
          emitted_c_rows_q <= emitted_c_rows_q + 1'b1;
        end
      end
    end
  end

  initial begin
    if (ARRAY_N < 1)
      $fatal(1, "dip_gemm_core ARRAY_N must be at least one");
  end

endmodule
