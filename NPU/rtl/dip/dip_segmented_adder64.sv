module dip_segmented_adder64 (
  input  logic [1:0]  mode_i,
  input  logic [63:0] a_i,
  input  logic [63:0] b_i,
  output logic [63:0] sum_o
);

  localparam logic [1:0] MODE_INT8  = 2'b01;
  localparam logic [1:0] MODE_INT4  = 2'b10;

  logic [15:0] nibble_carry_in;
  logic [15:0] unused_nibble_carry_out;

  assign nibble_carry_in[0] = 1'b0;

  generate
    for (genvar nibble = 0; nibble < 16; nibble++) begin : gen_add4
      if (nibble > 0) begin : gen_carry_input
        /*
         * Carry control is needed only where an accumulator lane can start.
         * Every other 4-bit slice connects directly to the preceding carry.
         */
        if ((nibble == 4) || (nibble == 12)) begin : gen_int4_cut
          assign nibble_carry_in[nibble] =
            (mode_i == MODE_INT4) ? 1'b0 :
                                    unused_nibble_carry_out[nibble-1];
        end else if (nibble == 8) begin : gen_int4_int8_cut
          assign nibble_carry_in[nibble] =
            ((mode_i == MODE_INT4) || (mode_i == MODE_INT8)) ? 1'b0 :
              unused_nibble_carry_out[nibble-1];
        end else begin : gen_direct_carry
          assign nibble_carry_in[nibble] =
            unused_nibble_carry_out[nibble-1];
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
