module dip_segmented_adder64 (
  input  logic [1:0]  mode_i,
  input  logic [63:0] a_i,
  input  logic [63:0] b_i,
  output logic [63:0] sum_o
);

  localparam logic [1:0] MODE_INT8  = 2'b01;
  localparam logic [1:0] MODE_INT4  = 2'b10;

  always_comb begin
    case (mode_i)
      MODE_INT8: begin
        sum_o[31:0]  = a_i[31:0]  + b_i[31:0];
        sum_o[63:32] = a_i[63:32] + b_i[63:32];
      end
      MODE_INT4: begin
        sum_o[15:0]  = a_i[15:0]  + b_i[15:0];
        sum_o[31:16] = a_i[31:16] + b_i[31:16];
        sum_o[47:32] = a_i[47:32] + b_i[47:32];
        sum_o[63:48] = a_i[63:48] + b_i[63:48];
      end
      default: begin
        sum_o = a_i + b_i;
      end
    endcase
  end

endmodule
