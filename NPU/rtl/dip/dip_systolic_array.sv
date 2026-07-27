module dip_systolic_array #(
  parameter int unsigned ARRAY_N = 4
) (
  input  logic                          clk_i,
  input  logic                          reset_n,

  input  logic                          weight_valid_i,
  input  logic [ARRAY_N * 16 - 1:0]     weight_row_i,

  input  logic                          data_valid_i,
  input  logic [ARRAY_N * 16 - 1:0]     data_row_i,

  output logic                          result_valid_o,
  output logic [ARRAY_N * 32 - 1:0]     result_row_o
);

  logic signed [15:0] data_to_pe [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [15:0] data_from_pe [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [15:0] weight_to_pe [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [15:0] weight_from_pe [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [31:0] psum_to_pe [0:ARRAY_N-1][0:ARRAY_N-1];
  logic signed [31:0] psum_from_pe [0:ARRAY_N-1][0:ARRAY_N-1];

  logic [ARRAY_N-1:0] data_valid_q;
  logic [ARRAY_N-1:0] product_valid_q;
  logic [ARRAY_N-1:0] psum_valid_q;
  logic [ARRAY_N-1:0] pe_en;
  logic [ARRAY_N-1:0] mul_en;
  logic [ARRAY_N-1:0] adder_en;
  logic unused_bottom_forwarding;

  assign pe_en[0] = data_valid_i;
  assign mul_en = data_valid_q;
  assign adder_en[0] = product_valid_q[0];

  generate
    for (genvar row = 1; row < ARRAY_N; row++) begin : gen_row_control
      assign pe_en[row] = data_valid_q[row-1];
      assign adder_en[row] =
        product_valid_q[row] && psum_valid_q[row-1];
    end
  endgenerate

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      data_valid_q <= '0;
      product_valid_q <= '0;
      psum_valid_q <= '0;
    end else begin
      data_valid_q[0] <= data_valid_i;
      product_valid_q <= data_valid_q;
      psum_valid_q[0] <= product_valid_q[0];

      for (int row = 1; row < ARRAY_N; row++) begin
        data_valid_q[row] <= data_valid_q[row-1];
        psum_valid_q[row] <=
          product_valid_q[row] && psum_valid_q[row-1];
      end
    end
  end

  generate
    for (genvar row = 0; row < ARRAY_N; row++) begin : gen_pe_row
      for (genvar col = 0; col < ARRAY_N; col++) begin : gen_pe_col
        if (row == 0) begin : gen_top_inputs
          assign data_to_pe[row][col] =
            $signed(data_row_i[col * 16 +: 16]);
          assign weight_to_pe[row][col] =
            $signed(weight_row_i[col * 16 +: 16]);
          assign psum_to_pe[row][col] = '0;
        end else begin : gen_internal_inputs
          localparam int unsigned DIAGONAL_SOURCE_COL =
            (col + 1) % ARRAY_N;

          assign data_to_pe[row][col] =
            data_from_pe[row-1][DIAGONAL_SOURCE_COL];
          assign weight_to_pe[row][col] =
            weight_from_pe[row-1][col];
          assign psum_to_pe[row][col] =
            psum_from_pe[row-1][col];
        end

        dip_pe u_pe (
          .clk_i(clk_i),
          .reset_n(reset_n),
          .wshift_i(weight_valid_i),
          .pe_en_i(pe_en[row]),
          .mul_en_i(mul_en[row]),
          .adder_en_i(adder_en[row]),
          .data_i(data_to_pe[row][col]),
          .weight_i(weight_to_pe[row][col]),
          .psum_i(psum_to_pe[row][col]),
          .data_o(data_from_pe[row][col]),
          .weight_o(weight_from_pe[row][col]),
          .psum_o(psum_from_pe[row][col])
        );
      end
    end

    for (genvar col = 0; col < ARRAY_N; col++) begin : gen_result_bus
      assign result_row_o[col * 32 +: 32] =
        psum_from_pe[ARRAY_N-1][col];
    end
  endgenerate

  assign result_valid_o = psum_valid_q[ARRAY_N-1];
  assign unused_bottom_forwarding =
    ^data_from_pe[ARRAY_N-1][0] ^
    ^weight_from_pe[ARRAY_N-1][0];

  initial begin
    if (ARRAY_N < 1)
      $fatal(1, "dip_systolic_array ARRAY_N must be at least one");
  end

endmodule
