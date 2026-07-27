module dip_simd_dot_product (
  input  logic        clk_i,
  input  logic        reset_n,
  input  logic        mul_en_i,
  input  logic        reduce_en_i,

  input  logic [1:0]  mode_i,
  input  logic [15:0] data_i,
  input  logic [15:0] data_neighbor_i,
  input  logic [63:0] weight_bank_i,

  output logic [63:0] contribution_o,
  output logic [1:0]  contribution_mode_o
);

  localparam logic [1:0] MODE_INT16 = 2'b00;
  localparam logic [1:0] MODE_INT8  = 2'b01;
  localparam logic [1:0] MODE_INT4  = 2'b10;

  logic [3:0] mul_a [0:15];
  logic [3:0] mul_b [0:15];
  logic       mul_a_signed [0:15];
  logic       mul_b_signed [0:15];
  logic [7:0] mul_product_comb [0:15];

  // This bank is the hard timing boundary immediately after all sixteen
  // base multipliers.  No partial-product reduction is performed before it.
  logic [7:0] product_q [0:15];
  logic [1:0] product_mode_q;

  logic signed [39:0] lane_sum_comb [0:3];
  logic        [63:0] contribution_comb;

  // Turn an 8-bit base-product bit pattern into a wide signed addend.
  // Only unsigned x unsigned needs zero extension.  If either radix-16
  // digit is signed, the mathematical result fits in signed eight bits.
  function automatic logic signed [39:0] extend_product (
    input logic [7:0] product,
    input logic       product_is_signed
  );
    if (product_is_signed)
      extend_product = $signed({{32{product[7]}}, product});
    else
      extend_product = $signed({32'b0, product});
  endfunction

  generate
    for (genvar mul = 0; mul < 16; mul++) begin : gen_base_mul4
      dip_base_mul4 u_mul4 (
        .a_i(mul_a[mul]),
        .b_i(mul_b[mul]),
        .a_signed_i(mul_a_signed[mul]),
        .b_signed_i(mul_b_signed[mul]),
        .product_o(mul_product_comb[mul])
      );
    end
  endgenerate

  // Reconfigure the same sixteen 4x4 multipliers as:
  //   INT16: 1 output x 1 K x (4x4 radix products) = 16
  //   INT8 : 2 outputs x 2 K x (2x2 radix products) = 16
  //   INT4 : 4 outputs x 4 K x (1 radix product)    = 16
  always_comb begin : configure_multipliers
    logic [3:0] map_idx;

    map_idx = '0;
    for (integer clear_idx = 0; clear_idx < 16; clear_idx++) begin
      mul_a[clear_idx] = '0;
      mul_b[clear_idx] = '0;
      mul_a_signed[clear_idx] = 1'b0;
      mul_b_signed[clear_idx] = 1'b0;
    end

    case (mode_i)
      MODE_INT8: begin
        for (integer out_lane = 0; out_lane < 2; out_lane++) begin
          for (integer k_lane = 0; k_lane < 2; k_lane++) begin
            for (integer a_digit = 0; a_digit < 2; a_digit++) begin
              for (integer b_digit = 0; b_digit < 2; b_digit++) begin
                map_idx = 4'((((out_lane * 2 + k_lane) * 2 + a_digit)
                             * 2 + b_digit));
                if ((k_lane + out_lane) < 2)
                  mul_a[map_idx] =
                    data_i[
                      (k_lane + out_lane) * 8 +
                      a_digit * 4 +: 4
                    ];
                else
                  mul_a[map_idx] =
                    data_neighbor_i[
                      (k_lane + out_lane - 2) * 8 +
                      a_digit * 4 +: 4
                    ];
                mul_b[map_idx] =
                  weight_bank_i[
                    k_lane * 16 + out_lane * 8 +
                    b_digit * 4 +: 4
                  ];
                mul_a_signed[map_idx] = (a_digit == 1);
                mul_b_signed[map_idx] = (b_digit == 1);
              end
            end
          end
        end
      end

      MODE_INT4: begin
        for (integer out_lane = 0; out_lane < 4; out_lane++) begin
          for (integer k_lane = 0; k_lane < 4; k_lane++) begin
            map_idx = 4'(out_lane * 4 + k_lane);
            if ((k_lane + out_lane) < 4)
              mul_a[map_idx] =
                data_i[(k_lane + out_lane) * 4 +: 4];
            else
              mul_a[map_idx] =
                data_neighbor_i[
                  (k_lane + out_lane - 4) * 4 +: 4
                ];
            mul_b[map_idx] =
              weight_bank_i[k_lane * 16 + out_lane * 4 +: 4];
            mul_a_signed[map_idx] = 1'b1;
            mul_b_signed[map_idx] = 1'b1;
          end
        end
      end

      default: begin
        // MODE_INT16, and the reserved mode as a fail-safe fallback.
        for (integer a_digit = 0; a_digit < 4; a_digit++) begin
          for (integer b_digit = 0; b_digit < 4; b_digit++) begin
            map_idx = 4'(a_digit * 4 + b_digit);
            mul_a[map_idx] = data_i[a_digit * 4 +: 4];
            mul_b[map_idx] =
              weight_bank_i[b_digit * 4 +: 4];
            mul_a_signed[map_idx] = (a_digit == 3);
            mul_b_signed[map_idx] = (b_digit == 3);
          end
        end
      end
    endcase
  end

  always_comb begin : reduce_partial_products
    logic [3:0] map_idx;

    map_idx = '0;
    for (integer lane = 0; lane < 4; lane++)
      lane_sum_comb[lane] = '0;

    // product_mode_q was captured together with product_q, so bubbles and
    // back-to-back mode changes cannot reinterpret an older product bank.
    case (product_mode_q)
      MODE_INT8: begin
        for (integer out_lane = 0; out_lane < 2; out_lane++) begin
          for (integer k_lane = 0; k_lane < 2; k_lane++) begin
            for (integer a_digit = 0; a_digit < 2; a_digit++) begin
              for (integer b_digit = 0; b_digit < 2; b_digit++) begin
                map_idx = 4'((((out_lane * 2 + k_lane) * 2 + a_digit)
                             * 2 + b_digit));
                lane_sum_comb[out_lane] =
                  lane_sum_comb[out_lane] +
                  (extend_product(
                     product_q[map_idx],
                     (a_digit == 1) || (b_digit == 1)
                   ) <<< (4 * (a_digit + b_digit)));
              end
            end
          end
        end
      end

      MODE_INT4: begin
        for (integer out_lane = 0; out_lane < 4; out_lane++) begin
          for (integer k_lane = 0; k_lane < 4; k_lane++) begin
            map_idx = 4'(out_lane * 4 + k_lane);
            lane_sum_comb[out_lane] =
              lane_sum_comb[out_lane] +
              extend_product(product_q[map_idx], 1'b1);
          end
        end
      end

      default: begin
        for (integer a_digit = 0; a_digit < 4; a_digit++) begin
          for (integer b_digit = 0; b_digit < 4; b_digit++) begin
            map_idx = 4'(a_digit * 4 + b_digit);
            lane_sum_comb[0] =
              lane_sum_comb[0] +
              (extend_product(
                 product_q[map_idx],
                 (a_digit == 3) || (b_digit == 3)
               ) <<< (4 * (a_digit + b_digit)));
          end
        end
      end
    endcase

    contribution_comb = '0;
    case (product_mode_q)
      MODE_INT8: begin
        contribution_comb[0 * 32 +: 32] =
          lane_sum_comb[0][31:0];
        contribution_comb[1 * 32 +: 32] =
          lane_sum_comb[1][31:0];
      end
      MODE_INT4: begin
        contribution_comb[0 * 16 +: 16] =
          lane_sum_comb[0][15:0];
        contribution_comb[1 * 16 +: 16] =
          lane_sum_comb[1][15:0];
        contribution_comb[2 * 16 +: 16] =
          lane_sum_comb[2][15:0];
        contribution_comb[3 * 16 +: 16] =
          lane_sum_comb[3][15:0];
      end
      default:
        contribution_comb = {
          {32{lane_sum_comb[0][31]}},
          lane_sum_comb[0][31:0]
        };
    endcase
  end

  // Stage 1: capture only base-multiplier results.
  // Stage 2: capture the completed partial-product/local-K reduction.
  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      for (integer product = 0; product < 16; product++)
        product_q[product] <= '0;
      product_mode_q <= MODE_INT16;
      contribution_o <= '0;
      contribution_mode_o <= MODE_INT16;
    end else begin
      if (mul_en_i) begin
        for (integer product = 0; product < 16; product++)
          product_q[product] <= mul_product_comb[product];

        case (mode_i)
          MODE_INT8: product_mode_q <= MODE_INT8;
          MODE_INT4: product_mode_q <= MODE_INT4;
          default:   product_mode_q <= MODE_INT16;
        endcase
      end

      if (reduce_en_i) begin
        contribution_o <= contribution_comb;
        contribution_mode_o <= product_mode_q;
      end
    end
  end

endmodule
