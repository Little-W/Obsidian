module ram16x128 (A1,A2,CE1,CE2,WEB1,WEB2,OEB1,OEB2,CSB1,CSB2,IO1,IO2);
input [6:0] A1,A2;
input CE1,CE2,WEB1,WEB2,OEB1,OEB2,CSB1,CSB2;
inout [15:0] IO1,IO2;

reg [15:0] IO1, IO2;
reg [15:0] data_out1, data_out2;
reg [15:0] memory [0:127];

event WRITE_OP;
  
and u1 (RE1, ~CSB1, ~OEB1);
and u2 (WE1, ~CSB1, ~WEB1);
and u3 (RE2, ~CSB2, ~OEB2);
and u4 (WE2, ~CSB2, ~WEB2);
or  u5 (TS1, ~WEB1, OEB1);
or  u6 (TS2, ~WEB2, OEB2);

always @ (negedge CE1)
  if (RE1)
   data_out1 = memory[A1];

assign IO1 = 16'b0;
assign IO2 = 16'b0;

always @ (negedge CE2)
  if (RE2)
   data_out2 = memory[A2];


always @ (negedge CE1)
  if (WE1) begin
    memory[A1] = IO1;
    #0; -> WRITE_OP;
  end

always @ (negedge CE2)
  if (WE2) begin
    memory[A2] = IO2;
  #0; -> WRITE_OP;
  end

endmodule

module ram32x64 (A1,A2,CE1,CE2,WEB1,WEB2,OEB1,OEB2,CSB1,CSB2,IO1,IO2);
input [5:0] A1,A2;
input CE1,CE2,WEB1,WEB2,OEB1,OEB2,CSB1,CSB2;
inout [31:0] IO1,IO2;

reg [31:0] IO1, IO2;
reg [31:0] data_out1, data_out2;
reg [31:0] memory [0:63];

event WRITE_OP;
  
and u1 (RE1, ~CSB1, ~OEB1);
and u2 (WE1, ~CSB1, ~WEB1);
and u3 (RE2, ~CSB2, ~OEB2);
and u4 (WE2, ~CSB2, ~WEB2);
or  u5 (TS1, ~WEB1, OEB1);
or  u6 (TS2, ~WEB2, OEB2);

always @ (negedge CE1)
  if (RE1)
   data_out1 = memory[A1];

assign IO1 = 32'b0;
assign IO2 = 32'b0;

always @ (negedge CE2)
  if (RE2)
   data_out2 = memory[A2];


always @ (negedge CE1)
  if (WE1) begin
    memory[A1] = IO1;
    #0; -> WRITE_OP;
  end

always @ (negedge CE2)
  if (WE2) begin
    memory[A2] = IO2;
  #0; -> WRITE_OP;
  end

endmodule

module ram32x32 (A1,A2,CE1,CE2,WEB1,WEB2,OEB1,OEB2,CSB1,CSB2,IO1,IO2);
input [4:0] A1,A2;
input CE1,CE2,WEB1,WEB2,OEB1,OEB2,CSB1,CSB2;
inout [31:0] IO1,IO2;

reg [31:0] IO1, IO2;
reg [31:0] data_out1, data_out2;
reg [31:0] memory [0:31];

event WRITE_OP;
  
and u1 (RE1, ~CSB1, ~OEB1);
and u2 (WE1, ~CSB1, ~WEB1);
and u3 (RE2, ~CSB2, ~OEB2);
and u4 (WE2, ~CSB2, ~WEB2);
or  u5 (TS1, ~WEB1, OEB1);
or  u6 (TS2, ~WEB2, OEB2);

always @ (negedge CE1)
  if (RE1)
   data_out1 = memory[A1];

assign IO1 = 32'b0;
assign IO2 = 32'b0;

always @ (negedge CE2)
  if (RE2)
   data_out2 = memory[A2];


always @ (negedge CE1)
  if (WE1) begin
    memory[A1] = IO1;
  end

always @ (negedge CE2)
  if (WE2) begin
    memory[A2] = IO2;
  end

endmodule
