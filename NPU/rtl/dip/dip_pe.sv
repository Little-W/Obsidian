module dip_pe (
  input  logic               clk_i,
  input  logic               reset_n,
  input  logic [1:0]         mode_i,

  input  logic               wshift_i,
  input  logic               pe_en_i,
  input  logic               mul_en_i,
  input  logic               reassemble_en_i,
  input  logic               reduce_en_i,
  input  logic               adder_en_i,

  input  logic signed [15:0] data_i,
  input  logic signed [15:0] data_neighbor_i,
  input  logic signed [15:0] weight_i,
  input  logic signed [63:0] psum_i,

  output logic signed [15:0] data_o,
  output logic signed [15:0] weight_o,
  output logic signed [63:0] psum_o
);

  localparam logic [1:0] MODE_INT16 = 2'b00;
  localparam logic [1:0] MODE_INT8  = 2'b01;
  localparam logic [1:0] MODE_INT4  = 2'b10;

  logic signed [15:0] data_q;
  logic        [1:0]  data_mode_q;
  logic signed [15:0] weight_q [0:3];
  logic signed [63:0] psum_q;

  logic [63:0] weight_bank;
  logic [63:0] contribution_from_dot;
  logic [1:0]  contribution_mode_from_dot;
  logic [63:0] psum_comb;
  logic [1:0]  sanitized_mode;

  always_comb begin
    case (mode_i)
      MODE_INT8: sanitized_mode = MODE_INT8;
      MODE_INT4: sanitized_mode = MODE_INT4;
      default:   sanitized_mode = MODE_INT16;
    endcase
  end

  assign weight_bank = {
    weight_q[3],
    weight_q[2],
    weight_q[1],
    weight_q[0]
  };

  dip_simd_dot_product u_simd_dot_product (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .mul_en_i(mul_en_i),
    .reassemble_en_i(reassemble_en_i),
    .reduce_en_i(reduce_en_i),
    .mode_i(data_mode_q),
    .data_i(data_q),
    .data_neighbor_i(data_neighbor_i),
    .weight_bank_i(weight_bank),
    .contribution_o(contribution_from_dot),
    .contribution_mode_o(contribution_mode_from_dot)
  );

  dip_segmented_adder64 u_segmented_accumulator (
    .mode_i(contribution_mode_from_dot),
    .a_i(psum_i),
    .b_i(contribution_from_dot),
    .sum_o(psum_comb)
  );

  assign data_o = data_q;
  assign psum_o = psum_q;

  always_comb begin
    case (sanitized_mode)
      MODE_INT8: weight_o = weight_q[1];
      MODE_INT4: weight_o = weight_q[3];
      default:   weight_o = weight_q[0];
    endcase
  end

  always_ff @(posedge clk_i) begin
    if (wshift_i) begin
      weight_q[0] <= weight_i;
      case (sanitized_mode)
        MODE_INT8:
          weight_q[1] <= weight_q[0];
        MODE_INT4: begin
          weight_q[1] <= weight_q[0];
          weight_q[2] <= weight_q[1];
          weight_q[3] <= weight_q[2];
        end
        default: begin
        end
      endcase
    end

    if (pe_en_i) begin
      data_q <= data_i;
      data_mode_q <= sanitized_mode;
    end

    if (adder_en_i)
      psum_q <= psum_comb;
  end

endmodule
