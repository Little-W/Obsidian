module dip_segmented_adder64 (
  input  logic [1:0]  mode_i,
  input  logic [63:0] a_i,
  input  logic [63:0] b_i,
  output logic [63:0] sum_o
);

  localparam logic [1:0] MODE_INT16 = 2'b00;
  localparam logic [1:0] MODE_INT8  = 2'b01;
  localparam logic [1:0] MODE_INT4  = 2'b10;

  logic [15:0] nibble_carry_in;
  logic [15:0] unused_nibble_carry_out;

  assign nibble_carry_in[0] = 1'b0;

  generate
    for (genvar nibble = 0; nibble < 16; nibble++) begin : gen_add4
      if (nibble > 0) begin : gen_carry_input
        always_comb begin
          // Carry is cut at the start of every independent accumulator lane:
          //   INT16: one 64-bit lane
          //   INT8 : two 32-bit lanes
          //   INT4 : four 16-bit lanes
          case (mode_i)
            MODE_INT8:
              nibble_carry_in[nibble] =
                (nibble == 8) ? 1'b0 :
                                unused_nibble_carry_out[nibble-1];
            MODE_INT4:
              nibble_carry_in[nibble] =
                ((nibble == 4) ||
                 (nibble == 8) ||
                 (nibble == 12)) ? 1'b0 :
                                   unused_nibble_carry_out[nibble-1];
            MODE_INT16:
              nibble_carry_in[nibble] =
                unused_nibble_carry_out[nibble-1];
            default:
              nibble_carry_in[nibble] =
                unused_nibble_carry_out[nibble-1];
          endcase
        end
      end

      dip_base_add4 u_add4 (
        .a_i(a_i[nibble * 4 +: 4]),
        .b_i(b_i[nibble * 4 +: 4]),
        .carry_i(nibble_carry_in[nibble]),
        .sum_o(sum_o[nibble * 4 +: 4]),
        .carry_o(unused_nibble_carry_out[nibble])
      );
    end
  endgenerate

endmodule
