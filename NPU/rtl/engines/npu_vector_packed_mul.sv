module npu_vector_packed_mul (
  input  logic          clk_i,
  input  logic          reset_n,

  input  logic          req_valid_i,
  input  logic [1:0]    dtype_i,
  input  logic [1:0]    group_i,
  input  logic [63:0]   src0_beat_i,
  input  logic [63:0]   src1_beat_i,

  output logic          rsp_valid_o,
  output logic [1:0]    rsp_dtype_o,
  output logic [1:0]    rsp_group_o,
  output logic [4:0]    rsp_count_o,
  output logic [511:0]  rsp_products_o
);

  import npu_engine_pkg::*;

  logic [3:0] mul_a [0:15];
  logic [3:0] mul_b [0:15];
  logic       mul_a_signed [0:15];
  logic       mul_b_signed [0:15];
  logic [7:0] mul_product [0:15];

  logic [7:0] product_q [0:15];
  logic [1:0] product_dtype_q;
  logic [1:0] product_group_q;
  logic       product_valid_q;

  logic signed [39:0] partial_comb [0:15];
  logic signed [39:0] partial_q [0:15];
  logic [1:0] partial_dtype_q;
  logic [1:0] partial_group_q;
  logic       partial_valid_q;
  logic [511:0] products_comb;
  logic [4:0] product_count_comb;

  function automatic logic signed [39:0] extend_product (
    input logic [7:0] product,
    input logic       product_is_signed
  );
    if (product_is_signed)
      return $signed({{32{product[7]}}, product});
    return $signed({32'd0, product});
  endfunction

  function automatic logic signed [39:0] shifted_product (
    input logic [7:0] product,
    input logic       product_is_signed,
    input integer     shift_bits
  );
    return extend_product(product, product_is_signed) <<< shift_bits;
  endfunction

  generate
    for (genvar mul = 0; mul < 16; mul++) begin : gen_base_mul4
      dip_base_mul4 u_mul4 (
        .a_i(mul_a[mul]),
        .b_i(mul_b[mul]),
        .a_signed_i(mul_a_signed[mul]),
        .b_signed_i(mul_b_signed[mul]),
        .product_o(mul_product[mul])
      );
    end
  endgenerate

  /*
   * One physical bank of sixteen 4x4 multipliers is reused as:
   *   INT16: one 16x16 product per request;
   *   INT8 : four 8x8 products per request;
   *   INT4 : sixteen 4x4 products per request.
   *
   * group_i selects one of four INT16 groups or one of two INT8 groups
   * inside the captured 64-bit input beats.  INT4 consumes the full beats
   * in one request.
   */
  always_comb begin : configure_base_multipliers
    integer element_index;
    logic [3:0] mul_index;

    for (integer clear_index = 0;
         clear_index < 16;
         clear_index++) begin
      mul_a[clear_index] = 4'd0;
      mul_b[clear_index] = 4'd0;
      mul_a_signed[clear_index] = 1'b0;
      mul_b_signed[clear_index] = 1'b0;
    end

    case (dtype_i)
      NPU_DTYPE_INT4: begin
        for (integer lane = 0; lane < 16; lane++) begin
          mul_a[lane] = src0_beat_i[lane * 4 +: 4];
          mul_b[lane] = src1_beat_i[lane * 4 +: 4];
          mul_a_signed[lane] = 1'b1;
          mul_b_signed[lane] = 1'b1;
        end
      end

      NPU_DTYPE_INT8: begin
        for (integer lane = 0; lane < 4; lane++) begin
          element_index = integer'(group_i) * 4 + lane;
          for (integer a_digit = 0; a_digit < 2; a_digit++) begin
            for (integer b_digit = 0; b_digit < 2; b_digit++) begin
              mul_index = 4'(lane * 4 + a_digit * 2 + b_digit);
              mul_a[mul_index] =
                src0_beat_i[element_index * 8 + a_digit * 4 +: 4];
              mul_b[mul_index] =
                src1_beat_i[element_index * 8 + b_digit * 4 +: 4];
              mul_a_signed[mul_index] = (a_digit == 1);
              mul_b_signed[mul_index] = (b_digit == 1);
            end
          end
        end
      end

      default: begin
        element_index = integer'(group_i);
        for (integer a_digit = 0; a_digit < 4; a_digit++) begin
          for (integer b_digit = 0; b_digit < 4; b_digit++) begin
            mul_index = 4'(a_digit * 4 + b_digit);
            mul_a[mul_index] =
              src0_beat_i[element_index * 16 + a_digit * 4 +: 4];
            mul_b[mul_index] =
              src1_beat_i[element_index * 16 + b_digit * 4 +: 4];
            mul_a_signed[mul_index] = (a_digit == 3);
            mul_b_signed[mul_index] = (b_digit == 3);
          end
        end
      end
    endcase
  end

  /*
   * The first reduction register holds four INT16 partial sums, one completed
   * sum for each INT8 lane, or sixteen sign-extended INT4 products.  Every
   * four-term sum is written as a balanced pair-of-pairs tree.
   */
  always_comb begin : build_partial_sums
    integer base_index;

    for (integer lane = 0; lane < 16; lane++)
      partial_comb[lane] = 40'sd0;

    case (product_dtype_q)
      NPU_DTYPE_INT4: begin
        for (integer lane = 0; lane < 16; lane++)
          partial_comb[lane] =
            extend_product(product_q[lane], 1'b1);
      end

      NPU_DTYPE_INT8: begin
        for (integer lane = 0; lane < 4; lane++) begin
          base_index = lane * 4;
          partial_comb[lane] =
            (shifted_product(product_q[base_index], 1'b0, 0) +
             shifted_product(product_q[base_index + 1], 1'b1, 4)) +
            (shifted_product(product_q[base_index + 2], 1'b1, 4) +
             shifted_product(product_q[base_index + 3], 1'b1, 8));
        end
      end

      default: begin
        for (integer a_digit = 0; a_digit < 4; a_digit++) begin
          base_index = a_digit * 4;
          partial_comb[a_digit] =
            (shifted_product(
               product_q[base_index],
               a_digit == 3,
               4 * a_digit
             ) +
             shifted_product(
               product_q[base_index + 1],
               (a_digit == 3) || 1'b0,
               4 * (a_digit + 1)
             )) +
            (shifted_product(
               product_q[base_index + 2],
               (a_digit == 3) || 1'b0,
               4 * (a_digit + 2)
             ) +
             shifted_product(
               product_q[base_index + 3],
               1'b1,
               4 * (a_digit + 3)
             ));
        end
      end
    endcase
  end

  /*
   * The second reduction stage joins the four registered INT16 partial sums
   * through another balanced pair-of-pairs tree.  INT8 and INT4 only pack
   * their already completed lane results here.
   */
  always_comb begin : finish_products
    logic signed [31:0] int16_product;

    products_comb = 512'd0;
    product_count_comb = 5'd1;
    int16_product = 32'(
      (partial_q[0] + partial_q[1]) +
      (partial_q[2] + partial_q[3])
    );

    case (partial_dtype_q)
      NPU_DTYPE_INT4: begin
        product_count_comb = 5'd16;
        for (integer lane = 0; lane < 16; lane++)
          products_comb[lane * 32 +: 32] = partial_q[lane][31:0];
      end

      NPU_DTYPE_INT8: begin
        product_count_comb = 5'd4;
        for (integer lane = 0; lane < 4; lane++)
          products_comb[lane * 32 +: 32] = partial_q[lane][31:0];
      end

      default: begin
        product_count_comb = 5'd1;
        products_comb[31:0] = int16_product;
      end
    endcase
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      product_valid_q <= 1'b0;
      partial_valid_q <= 1'b0;
      rsp_valid_o <= 1'b0;
    end else begin
      product_valid_q <= req_valid_i;
      partial_valid_q <= product_valid_q;
      rsp_valid_o <= partial_valid_q;

      if (req_valid_i) begin
        for (integer product = 0; product < 16; product++)
          product_q[product] <= mul_product[product];
        product_dtype_q <= dtype_i;
        product_group_q <= group_i;
      end

      if (product_valid_q) begin
        for (integer partial = 0; partial < 16; partial++)
          partial_q[partial] <= partial_comb[partial];
        partial_dtype_q <= product_dtype_q;
        partial_group_q <= product_group_q;
      end

      if (partial_valid_q) begin
        rsp_dtype_o <= partial_dtype_q;
        rsp_group_o <= partial_group_q;
        rsp_count_o <= product_count_comb;
        rsp_products_o <= products_comb;
      end
    end
  end

endmodule
