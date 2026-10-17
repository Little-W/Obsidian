module mux2 (
  input logic a, b, sel,
  output logic y
);
  assign y = sel ? b : a;
endmodule
