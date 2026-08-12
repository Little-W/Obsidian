/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Ultra(TM) in wire load mode
// Version   : V-2023.12-SP3
// Date      : Wed Aug 12 22:47:41 2026
/////////////////////////////////////////////////////////////


module CONTROL ( Clk, INTERNAL_RESET, .Crnt_Instrn({\Crnt_Instrn\[31\] , 
        \Crnt_Instrn\[30\] , \Crnt_Instrn\[29\] , \Crnt_Instrn\[28\] , 
        \Crnt_Instrn\[27\] , \Crnt_Instrn\[26\] , \Crnt_Instrn\[25\] , 
        \Crnt_Instrn\[24\] , \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] , 
        \Crnt_Instrn\[21\] , \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] , 
        \Crnt_Instrn\[18\] , \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] , 
        \Crnt_Instrn\[15\] , \Crnt_Instrn\[14\] , \Crnt_Instrn\[13\] , 
        \Crnt_Instrn\[12\] , \Crnt_Instrn\[11\] , \Crnt_Instrn\[10\] , 
        \Crnt_Instrn\[9\] , \Crnt_Instrn\[8\] , \Crnt_Instrn\[7\] , 
        \Crnt_Instrn\[6\] , \Crnt_Instrn\[5\] , \Crnt_Instrn\[4\] , 
        \Crnt_Instrn\[3\] , \Crnt_Instrn\[2\] , \Crnt_Instrn\[1\] , 
        \Crnt_Instrn\[0\] }), .Current_State({\Current_State\[2\] , 
        \Current_State\[1\] , \Current_State\[0\] }), Neg_Flag, Carry_Flag, 
        Zro_Flag, Latch_Instr, Rd_Oprnd_A, Rd_Oprnd_B, Latch_Flags, 
        Latch_Result, Write_RegC, UseData_Imm_Or_RegB, UseData_Imm_Or_ALU, 
        Reset_AluRegs, EndOfInstrn, PushEnbl, PopEnbl, OUT_VALID, test_si, 
        test_se );
  input Clk, INTERNAL_RESET, \Crnt_Instrn\[31\] , \Crnt_Instrn\[30\] ,
         \Crnt_Instrn\[29\] , \Crnt_Instrn\[28\] , \Crnt_Instrn\[27\] ,
         \Crnt_Instrn\[26\] , \Crnt_Instrn\[25\] , \Crnt_Instrn\[24\] ,
         \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] , \Crnt_Instrn\[21\] ,
         \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] , \Crnt_Instrn\[18\] ,
         \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] , \Crnt_Instrn\[15\] ,
         \Crnt_Instrn\[14\] , \Crnt_Instrn\[13\] , \Crnt_Instrn\[12\] ,
         \Crnt_Instrn\[11\] , \Crnt_Instrn\[10\] , \Crnt_Instrn\[9\] ,
         \Crnt_Instrn\[8\] , \Crnt_Instrn\[7\] , \Crnt_Instrn\[6\] ,
         \Crnt_Instrn\[5\] , \Crnt_Instrn\[4\] , \Crnt_Instrn\[3\] ,
         \Crnt_Instrn\[2\] , \Crnt_Instrn\[1\] , \Crnt_Instrn\[0\] ,
         \Current_State\[2\] , \Current_State\[1\] , \Current_State\[0\] ,
         Neg_Flag, Carry_Flag, Zro_Flag, test_si, test_se;
  output Latch_Instr, Rd_Oprnd_A, Rd_Oprnd_B, Latch_Flags, Latch_Result,
         Write_RegC, UseData_Imm_Or_RegB, UseData_Imm_Or_ALU, Reset_AluRegs,
         EndOfInstrn, PushEnbl, PopEnbl, OUT_VALID;
  wire   Crnt_Instrn_31, Crnt_Instrn_30, Crnt_Instrn_28, Crnt_Instrn_27,
         Latch_Instr, Data_Imm_Or_RegB, Data_Imm_Or_ALU, n26, n1, n2, n3, n4,
         n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19,
         n20, n21;
  assign Crnt_Instrn_31 = \Crnt_Instrn\[31\] ;
  assign Crnt_Instrn_30 = \Crnt_Instrn\[30\] ;
  assign Crnt_Instrn_28 = \Crnt_Instrn\[28\] ;
  assign Crnt_Instrn_27 = \Crnt_Instrn\[27\] ;
  assign Reset_AluRegs = Latch_Instr;

  sdcrq1 UseData_Imm_Or_ALU_reg ( .D(Data_Imm_Or_ALU), .SD(EndOfInstrn), .SC(
        test_se), .CP(Clk), .CDN(INTERNAL_RESET), .Q(UseData_Imm_Or_ALU) );
  sdcrq1 UseData_Imm_Or_RegB_reg ( .D(Data_Imm_Or_RegB), .SD(
        UseData_Imm_Or_ALU), .SC(test_se), .CP(Clk), .CDN(INTERNAL_RESET), .Q(
        UseData_Imm_Or_RegB) );
  sdnrq1 EndOfInstrn_reg ( .D(n26), .SD(test_si), .SC(test_se), .CP(Clk), .Q(
        EndOfInstrn) );
  nd02d0 U3 ( .A1(n1), .A2(\Current_State\[1\] ), .ZN(n14) );
  nd02d0 U4 ( .A1(n18), .A2(\Current_State\[0\] ), .ZN(n4) );
  nr03d0 U5 ( .A1(Crnt_Instrn_31), .A2(Crnt_Instrn_30), .A3(n4), .ZN(n17) );
  inv0d0 U6 ( .I(\Current_State\[0\] ), .ZN(n16) );
  nr03d0 U7 ( .A1(\Current_State\[1\] ), .A2(\Current_State\[0\] ), .A3(n1), 
        .ZN(n26) );
  inv0d0 U8 ( .I(\Current_State\[2\] ), .ZN(n1) );
  nr02d0 U9 ( .A1(Crnt_Instrn_31), .A2(Crnt_Instrn_30), .ZN(n15) );
  inv0d0 U10 ( .I(n15), .ZN(n3) );
  an02d0 U11 ( .A1(n26), .A2(n3), .Z(Write_RegC) );
  nr02d0 U12 ( .A1(\Current_State\[0\] ), .A2(n14), .ZN(n2) );
  nd02d0 U13 ( .A1(Crnt_Instrn_31), .A2(Crnt_Instrn_30), .ZN(n19) );
  ora211d1 U14 ( .C1(\Crnt_Instrn\[24\] ), .C2(n3), .A(n2), .B(n19), .Z(
        Rd_Oprnd_A) );
  inv0d0 U15 ( .I(n14), .ZN(n18) );
  nr02d0 U16 ( .A1(n15), .A2(n4), .ZN(Latch_Result) );
  an02d0 U17 ( .A1(Latch_Result), .A2(n19), .Z(Latch_Flags) );
  an02d0 U18 ( .A1(n17), .A2(Crnt_Instrn_27), .Z(PopEnbl) );
  nr04d0 U19 ( .A1(\Crnt_Instrn\[17\] ), .A2(\Crnt_Instrn\[20\] ), .A3(
        \Crnt_Instrn\[21\] ), .A4(\Crnt_Instrn\[18\] ), .ZN(n5) );
  nd12d0 U20 ( .A1(\Crnt_Instrn\[19\] ), .A2(n5), .ZN(n10) );
  an04d0 U21 ( .A1(\Crnt_Instrn\[19\] ), .A2(\Crnt_Instrn\[17\] ), .A3(
        \Crnt_Instrn\[21\] ), .A4(\Crnt_Instrn\[18\] ), .Z(n6) );
  nd03d0 U22 ( .A1(\Crnt_Instrn\[20\] ), .A2(\Crnt_Instrn\[16\] ), .A3(n6), 
        .ZN(n7) );
  aor211d1 U23 ( .C1(n10), .C2(n7), .A(\Crnt_Instrn\[22\] ), .B(
        \Crnt_Instrn\[23\] ), .Z(n8) );
  nr02d0 U24 ( .A1(\Crnt_Instrn\[25\] ), .A2(n8), .ZN(n12) );
  mx02d0 U25 ( .I0(Neg_Flag), .I1(Zro_Flag), .S(\Crnt_Instrn\[16\] ), .Z(n9)
         );
  nr04d0 U26 ( .A1(\Crnt_Instrn\[22\] ), .A2(\Crnt_Instrn\[23\] ), .A3(n10), 
        .A4(n9), .ZN(n11) );
  mx02d0 U27 ( .I0(n12), .I1(\Crnt_Instrn\[25\] ), .S(n11), .Z(n13) );
  an03d0 U28 ( .A1(n17), .A2(Crnt_Instrn_28), .A3(n13), .Z(PushEnbl) );
  nr03d0 U29 ( .A1(\Current_State\[0\] ), .A2(n15), .A3(n14), .ZN(Rd_Oprnd_B)
         );
  nr03d0 U30 ( .A1(\Current_State\[2\] ), .A2(\Current_State\[1\] ), .A3(n16), 
        .ZN(Latch_Instr) );
  an02d0 U31 ( .A1(n17), .A2(\Crnt_Instrn\[24\] ), .Z(OUT_VALID) );
  nr02d0 U32 ( .A1(n18), .A2(n26), .ZN(n21) );
  nr02d0 U33 ( .A1(n21), .A2(n19), .ZN(Data_Imm_Or_ALU) );
  inv0d0 U34 ( .I(Crnt_Instrn_31), .ZN(n20) );
  nr03d0 U35 ( .A1(Crnt_Instrn_30), .A2(n21), .A3(n20), .ZN(Data_Imm_Or_RegB)
         );
endmodule


module DIV_CLK ( TEST_MODE, INTERNAL_RESET, Clk, DIV_CLK, test_si, test_se );
  input TEST_MODE, INTERNAL_RESET, Clk, test_si, test_se;
  output DIV_CLK;
  wire   n3;

  inv0d0 U4 ( .I(DIV_CLK), .ZN(n3) );
  sdcrq2 q_reg ( .D(n3), .SD(test_si), .SC(test_se), .CP(Clk), .CDN(
        INTERNAL_RESET), .Q(DIV_CLK) );
endmodule


module DATA_PATH ( Clk, INTERNAL_RESET, Reset_AluRegs, Rd_Oprnd_A, Rd_Oprnd_B, 
        UseData_Imm_Or_RegB, UseData_Imm_Or_ALU, Latch_Flags, ALU_Zro, ALU_Neg, 
        ALU_Carry, PSW_Zro, PSW_Neg, PSW_Carry, .Crnt_Instrn({
        \Crnt_Instrn\[31\] , \Crnt_Instrn\[30\] , \Crnt_Instrn\[29\] , 
        \Crnt_Instrn\[28\] , \Crnt_Instrn\[27\] , \Crnt_Instrn\[26\] , 
        \Crnt_Instrn\[25\] , \Crnt_Instrn\[24\] , \Crnt_Instrn\[23\] , 
        \Crnt_Instrn\[22\] , \Crnt_Instrn\[21\] , \Crnt_Instrn\[20\] , 
        \Crnt_Instrn\[19\] , \Crnt_Instrn\[18\] , \Crnt_Instrn\[17\] , 
        \Crnt_Instrn\[16\] , \Crnt_Instrn\[15\] , \Crnt_Instrn\[14\] , 
        \Crnt_Instrn\[13\] , \Crnt_Instrn\[12\] , \Crnt_Instrn\[11\] , 
        \Crnt_Instrn\[10\] , \Crnt_Instrn\[9\] , \Crnt_Instrn\[8\] , 
        \Crnt_Instrn\[7\] , \Crnt_Instrn\[6\] , \Crnt_Instrn\[5\] , 
        \Crnt_Instrn\[4\] , \Crnt_Instrn\[3\] , \Crnt_Instrn\[2\] , 
        \Crnt_Instrn\[1\] , \Crnt_Instrn\[0\] }), .RegPort_A({
        \RegPort_A\[15\] , \RegPort_A\[14\] , \RegPort_A\[13\] , 
        \RegPort_A\[12\] , \RegPort_A\[11\] , \RegPort_A\[10\] , 
        \RegPort_A\[9\] , \RegPort_A\[8\] , \RegPort_A\[7\] , \RegPort_A\[6\] , 
        \RegPort_A\[5\] , \RegPort_A\[4\] , \RegPort_A\[3\] , \RegPort_A\[2\] , 
        \RegPort_A\[1\] , \RegPort_A\[0\] }), .RegPort_B({\RegPort_B\[15\] , 
        \RegPort_B\[14\] , \RegPort_B\[13\] , \RegPort_B\[12\] , 
        \RegPort_B\[11\] , \RegPort_B\[10\] , \RegPort_B\[9\] , 
        \RegPort_B\[8\] , \RegPort_B\[7\] , \RegPort_B\[6\] , \RegPort_B\[5\] , 
        \RegPort_B\[4\] , \RegPort_B\[3\] , \RegPort_B\[2\] , \RegPort_B\[1\] , 
        \RegPort_B\[0\] }), .Op_Result({\Op_Result\[15\] , \Op_Result\[14\] , 
        \Op_Result\[13\] , \Op_Result\[12\] , \Op_Result\[11\] , 
        \Op_Result\[10\] , \Op_Result\[9\] , \Op_Result\[8\] , 
        \Op_Result\[7\] , \Op_Result\[6\] , \Op_Result\[5\] , \Op_Result\[4\] , 
        \Op_Result\[3\] , \Op_Result\[2\] , \Op_Result\[1\] , \Op_Result\[0\] 
        }), Zro_Flag, Neg_Flag, Carry_Flag, .Addr_A({\Addr_A\[6\] , 
        \Addr_A\[5\] , \Addr_A\[4\] , \Addr_A\[3\] , \Addr_A\[2\] , 
        \Addr_A\[1\] , \Addr_A\[0\] }), .Oprnd_A({\Oprnd_A\[15\] , 
        \Oprnd_A\[14\] , \Oprnd_A\[13\] , \Oprnd_A\[12\] , \Oprnd_A\[11\] , 
        \Oprnd_A\[10\] , \Oprnd_A\[9\] , \Oprnd_A\[8\] , \Oprnd_A\[7\] , 
        \Oprnd_A\[6\] , \Oprnd_A\[5\] , \Oprnd_A\[4\] , \Oprnd_A\[3\] , 
        \Oprnd_A\[2\] , \Oprnd_A\[1\] , \Oprnd_A\[0\] }), .Oprnd_B({
        \Oprnd_B\[15\] , \Oprnd_B\[14\] , \Oprnd_B\[13\] , \Oprnd_B\[12\] , 
        \Oprnd_B\[11\] , \Oprnd_B\[10\] , \Oprnd_B\[9\] , \Oprnd_B\[8\] , 
        \Oprnd_B\[7\] , \Oprnd_B\[6\] , \Oprnd_B\[5\] , \Oprnd_B\[4\] , 
        \Oprnd_B\[3\] , \Oprnd_B\[2\] , \Oprnd_B\[1\] , \Oprnd_B\[0\] }), 
    .RegPort_C({\RegPort_C\[15\] , \RegPort_C\[14\] , \RegPort_C\[13\] , 
        \RegPort_C\[12\] , \RegPort_C\[11\] , \RegPort_C\[10\] , 
        \RegPort_C\[9\] , \RegPort_C\[8\] , \RegPort_C\[7\] , \RegPort_C\[6\] , 
        \RegPort_C\[5\] , \RegPort_C\[4\] , \RegPort_C\[3\] , \RegPort_C\[2\] , 
        \RegPort_C\[1\] , \RegPort_C\[0\] }), RISC_CORE_test_point_375_in, 
        test_so, test_se );
  input Clk, INTERNAL_RESET, Reset_AluRegs, Rd_Oprnd_A, Rd_Oprnd_B,
         UseData_Imm_Or_RegB, UseData_Imm_Or_ALU, Latch_Flags, ALU_Zro,
         ALU_Neg, ALU_Carry, PSW_Zro, PSW_Neg, PSW_Carry, \Crnt_Instrn\[31\] ,
         \Crnt_Instrn\[30\] , \Crnt_Instrn\[29\] , \Crnt_Instrn\[28\] ,
         \Crnt_Instrn\[27\] , \Crnt_Instrn\[26\] , \Crnt_Instrn\[25\] ,
         \Crnt_Instrn\[24\] , \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] ,
         \Crnt_Instrn\[21\] , \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] ,
         \Crnt_Instrn\[18\] , \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] ,
         \Crnt_Instrn\[15\] , \Crnt_Instrn\[14\] , \Crnt_Instrn\[13\] ,
         \Crnt_Instrn\[12\] , \Crnt_Instrn\[11\] , \Crnt_Instrn\[10\] ,
         \Crnt_Instrn\[9\] , \Crnt_Instrn\[8\] , \Crnt_Instrn\[7\] ,
         \Crnt_Instrn\[6\] , \Crnt_Instrn\[5\] , \Crnt_Instrn\[4\] ,
         \Crnt_Instrn\[3\] , \Crnt_Instrn\[2\] , \Crnt_Instrn\[1\] ,
         \Crnt_Instrn\[0\] , \RegPort_A\[15\] , \RegPort_A\[14\] ,
         \RegPort_A\[13\] , \RegPort_A\[12\] , \RegPort_A\[11\] ,
         \RegPort_A\[10\] , \RegPort_A\[9\] , \RegPort_A\[8\] ,
         \RegPort_A\[7\] , \RegPort_A\[6\] , \RegPort_A\[5\] ,
         \RegPort_A\[4\] , \RegPort_A\[3\] , \RegPort_A\[2\] ,
         \RegPort_A\[1\] , \RegPort_A\[0\] , \RegPort_B\[15\] ,
         \RegPort_B\[14\] , \RegPort_B\[13\] , \RegPort_B\[12\] ,
         \RegPort_B\[11\] , \RegPort_B\[10\] , \RegPort_B\[9\] ,
         \RegPort_B\[8\] , \RegPort_B\[7\] , \RegPort_B\[6\] ,
         \RegPort_B\[5\] , \RegPort_B\[4\] , \RegPort_B\[3\] ,
         \RegPort_B\[2\] , \RegPort_B\[1\] , \RegPort_B\[0\] ,
         \Op_Result\[15\] , \Op_Result\[14\] , \Op_Result\[13\] ,
         \Op_Result\[12\] , \Op_Result\[11\] , \Op_Result\[10\] ,
         \Op_Result\[9\] , \Op_Result\[8\] , \Op_Result\[7\] ,
         \Op_Result\[6\] , \Op_Result\[5\] , \Op_Result\[4\] ,
         \Op_Result\[3\] , \Op_Result\[2\] , \Op_Result\[1\] ,
         \Op_Result\[0\] , RISC_CORE_test_point_375_in, test_se;
  output Zro_Flag, Neg_Flag, Carry_Flag, \Addr_A\[6\] , \Addr_A\[5\] ,
         \Addr_A\[4\] , \Addr_A\[3\] , \Addr_A\[2\] , \Addr_A\[1\] ,
         \Addr_A\[0\] , \Oprnd_A\[15\] , \Oprnd_A\[14\] , \Oprnd_A\[13\] ,
         \Oprnd_A\[12\] , \Oprnd_A\[11\] , \Oprnd_A\[10\] , \Oprnd_A\[9\] ,
         \Oprnd_A\[8\] , \Oprnd_A\[7\] , \Oprnd_A\[6\] , \Oprnd_A\[5\] ,
         \Oprnd_A\[4\] , \Oprnd_A\[3\] , \Oprnd_A\[2\] , \Oprnd_A\[1\] ,
         \Oprnd_A\[0\] , \Oprnd_B\[15\] , \Oprnd_B\[14\] , \Oprnd_B\[13\] ,
         \Oprnd_B\[12\] , \Oprnd_B\[11\] , \Oprnd_B\[10\] , \Oprnd_B\[9\] ,
         \Oprnd_B\[8\] , \Oprnd_B\[7\] , \Oprnd_B\[6\] , \Oprnd_B\[5\] ,
         \Oprnd_B\[4\] , \Oprnd_B\[3\] , \Oprnd_B\[2\] , \Oprnd_B\[1\] ,
         \Oprnd_B\[0\] , \RegPort_C\[15\] , \RegPort_C\[14\] ,
         \RegPort_C\[13\] , \RegPort_C\[12\] , \RegPort_C\[11\] ,
         \RegPort_C\[10\] , \RegPort_C\[9\] , \RegPort_C\[8\] ,
         \RegPort_C\[7\] , \RegPort_C\[6\] , \RegPort_C\[5\] ,
         \RegPort_C\[4\] , \RegPort_C\[3\] , \RegPort_C\[2\] ,
         \RegPort_C\[1\] , \RegPort_C\[0\] , test_so;
  wire   Crnt_Instrn_31, Crnt_Instrn_30, Crnt_Instrn_29, Crnt_Instrn_28,
         Crnt_Instrn_27, Crnt_Instrn_26, Crnt_Instrn_25, Crnt_Instrn_24,
         PSWL_Zro, PSWL_Neg, n14, n16, n51, n52, n53, n54, n55, n56, n57, n58,
         n59, n60, n61, n62, n63, n64, n65, n66, n67, n68, n69, n70, n71, n72,
         n73, n74, n75, n76, n77, n78, n79, n80, n81, n82, n1, n2, n3, n4, n5,
         n6, n7, n8, n9, n10, n11;
  assign Crnt_Instrn_31 = \Crnt_Instrn\[31\] ;
  assign Crnt_Instrn_30 = \Crnt_Instrn\[30\] ;
  assign Crnt_Instrn_29 = \Crnt_Instrn\[29\] ;
  assign Crnt_Instrn_28 = \Crnt_Instrn\[28\] ;
  assign Crnt_Instrn_27 = \Crnt_Instrn\[27\] ;
  assign Crnt_Instrn_26 = \Crnt_Instrn\[26\] ;
  assign Crnt_Instrn_25 = \Crnt_Instrn\[25\] ;
  assign Crnt_Instrn_24 = \Crnt_Instrn\[24\] ;
  assign test_so = PSWL_Zro;

  sdnrq1 \Oprnd_A_reg\[15\]  ( .D(n82), .SD(\Oprnd_A\[14\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[15\] ) );
  sdnrq1 \Oprnd_A_reg\[14\]  ( .D(n81), .SD(\Oprnd_A\[13\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[14\] ) );
  sdnrq1 \Oprnd_A_reg\[13\]  ( .D(n80), .SD(\Oprnd_A\[12\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[13\] ) );
  sdnrq1 \Oprnd_A_reg\[12\]  ( .D(n79), .SD(\Oprnd_A\[11\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[12\] ) );
  sdnrq1 \Oprnd_A_reg\[11\]  ( .D(n78), .SD(\Oprnd_A\[10\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[11\] ) );
  sdnrq1 \Oprnd_A_reg\[10\]  ( .D(n77), .SD(\Oprnd_A\[9\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[10\] ) );
  sdnrq1 \Oprnd_A_reg\[9\]  ( .D(n76), .SD(\Oprnd_A\[8\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[9\] ) );
  sdnrq1 \Oprnd_A_reg\[8\]  ( .D(n75), .SD(\Oprnd_A\[7\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[8\] ) );
  sdnrq1 \Oprnd_A_reg\[7\]  ( .D(n74), .SD(\Oprnd_A\[6\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[7\] ) );
  sdnrq1 \Oprnd_A_reg\[6\]  ( .D(n73), .SD(\Oprnd_A\[5\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[6\] ) );
  sdnrq1 \Oprnd_A_reg\[5\]  ( .D(n72), .SD(\Oprnd_A\[4\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[5\] ) );
  sdnrq1 \Oprnd_A_reg\[4\]  ( .D(n71), .SD(\Oprnd_A\[3\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[4\] ) );
  sdnrq1 \Oprnd_A_reg\[3\]  ( .D(n70), .SD(\Oprnd_A\[2\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[3\] ) );
  sdnrq1 \Oprnd_A_reg\[2\]  ( .D(n69), .SD(\Oprnd_A\[1\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[2\] ) );
  sdnrq1 \Oprnd_A_reg\[1\]  ( .D(n68), .SD(\Oprnd_A\[0\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[1\] ) );
  sdnrq1 \Oprnd_A_reg\[0\]  ( .D(n67), .SD(UseData_Imm_Or_RegB), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_A\[0\] ) );
  sdnrq1 \Oprnd_B_reg\[15\]  ( .D(n66), .SD(\Oprnd_B\[14\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[15\] ) );
  sdnrq1 \Oprnd_B_reg\[14\]  ( .D(n65), .SD(\Oprnd_B\[13\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[14\] ) );
  sdnrq1 \Oprnd_B_reg\[13\]  ( .D(n64), .SD(\Oprnd_B\[12\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[13\] ) );
  sdnrq1 \Oprnd_B_reg\[12\]  ( .D(n63), .SD(\Oprnd_B\[11\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[12\] ) );
  sdnrq1 \Oprnd_B_reg\[11\]  ( .D(n62), .SD(\Oprnd_B\[10\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[11\] ) );
  sdnrq1 \Oprnd_B_reg\[10\]  ( .D(n61), .SD(\Oprnd_B\[9\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[10\] ) );
  sdnrq1 \Oprnd_B_reg\[9\]  ( .D(n60), .SD(\Oprnd_B\[8\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[9\] ) );
  sdnrq1 \Oprnd_B_reg\[8\]  ( .D(n59), .SD(\Oprnd_B\[7\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[8\] ) );
  sdnrq1 \Oprnd_B_reg\[7\]  ( .D(n58), .SD(\Oprnd_B\[6\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[7\] ) );
  sdnrq1 \Oprnd_B_reg\[6\]  ( .D(n57), .SD(\Oprnd_B\[5\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[6\] ) );
  sdnrq1 \Oprnd_B_reg\[5\]  ( .D(n56), .SD(\Oprnd_B\[4\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[5\] ) );
  sdnrq1 \Oprnd_B_reg\[4\]  ( .D(n55), .SD(\Oprnd_B\[3\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[4\] ) );
  sdnrq1 \Oprnd_B_reg\[3\]  ( .D(n54), .SD(\Oprnd_B\[2\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[3\] ) );
  sdnrq1 \Oprnd_B_reg\[2\]  ( .D(n53), .SD(\Oprnd_B\[1\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[2\] ) );
  sdnrq1 \Oprnd_B_reg\[1\]  ( .D(n52), .SD(\Oprnd_B\[0\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[1\] ) );
  sdnrq1 \Oprnd_B_reg\[0\]  ( .D(n51), .SD(\Oprnd_A\[15\] ), .SC(test_se), 
        .CP(RISC_CORE_test_point_375_in), .Q(\Oprnd_B\[0\] ) );
  sdcrq1 PSWL_Zro_reg ( .D(n16), .SD(PSWL_Neg), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .CDN(INTERNAL_RESET), .Q(PSWL_Zro) );
  sdcrq1 PSWL_Neg_reg ( .D(n14), .SD(\Oprnd_B\[15\] ), .SC(test_se), .CP(
        RISC_CORE_test_point_375_in), .CDN(INTERNAL_RESET), .Q(PSWL_Neg) );
  mx02d0 U3 ( .I0(\Op_Result\[11\] ), .I1(\Crnt_Instrn\[11\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[11\] ) );
  nr03d0 U4 ( .A1(Reset_AluRegs), .A2(n11), .A3(n6), .ZN(n7) );
  nr03d0 U5 ( .A1(UseData_Imm_Or_RegB), .A2(Reset_AluRegs), .A3(n11), .ZN(n10)
         );
  mx02d0 U6 ( .I0(ALU_Neg), .I1(PSWL_Neg), .S(n3), .Z(Neg_Flag) );
  mx02d0 U7 ( .I0(\Op_Result\[12\] ), .I1(\Crnt_Instrn\[12\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[12\] ) );
  mx02d0 U8 ( .I0(\Op_Result\[10\] ), .I1(\Crnt_Instrn\[10\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[10\] ) );
  mx02d0 U9 ( .I0(\Op_Result\[13\] ), .I1(\Crnt_Instrn\[13\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[13\] ) );
  mx02d0 U10 ( .I0(\Op_Result\[9\] ), .I1(\Crnt_Instrn\[9\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[9\] ) );
  mx02d0 U11 ( .I0(\Op_Result\[14\] ), .I1(\Crnt_Instrn\[14\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[14\] ) );
  mx02d0 U12 ( .I0(\Op_Result\[15\] ), .I1(\Crnt_Instrn\[15\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[15\] ) );
  mx02d0 U13 ( .I0(\Op_Result\[7\] ), .I1(\Crnt_Instrn\[7\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[7\] ) );
  mx02d0 U14 ( .I0(\Op_Result\[0\] ), .I1(\Crnt_Instrn\[0\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[0\] ) );
  mx02d0 U15 ( .I0(\Op_Result\[6\] ), .I1(\Crnt_Instrn\[6\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[6\] ) );
  mx02d0 U16 ( .I0(\Op_Result\[1\] ), .I1(\Crnt_Instrn\[1\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[1\] ) );
  mx02d0 U17 ( .I0(\Op_Result\[5\] ), .I1(\Crnt_Instrn\[5\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[5\] ) );
  mx02d0 U18 ( .I0(\Op_Result\[2\] ), .I1(\Crnt_Instrn\[2\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[2\] ) );
  mx02d0 U19 ( .I0(\Op_Result\[4\] ), .I1(\Crnt_Instrn\[4\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[4\] ) );
  mx02d0 U20 ( .I0(\Op_Result\[3\] ), .I1(\Crnt_Instrn\[3\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[3\] ) );
  mx02d0 U21 ( .I0(\Op_Result\[8\] ), .I1(\Crnt_Instrn\[8\] ), .S(
        UseData_Imm_Or_ALU), .Z(\RegPort_C\[8\] ) );
  mx02d0 U22 ( .I0(PSWL_Zro), .I1(PSW_Zro), .S(Latch_Flags), .Z(n16) );
  mx02d0 U23 ( .I0(PSWL_Neg), .I1(PSW_Neg), .S(Latch_Flags), .Z(n14) );
  nr04d0 U24 ( .A1(Crnt_Instrn_24), .A2(Crnt_Instrn_25), .A3(Crnt_Instrn_26), 
        .A4(Crnt_Instrn_28), .ZN(n1) );
  nr02d0 U25 ( .A1(Crnt_Instrn_30), .A2(Crnt_Instrn_31), .ZN(n4) );
  nd03d0 U26 ( .A1(n1), .A2(Crnt_Instrn_27), .A3(n4), .ZN(n2) );
  nr02d0 U27 ( .A1(Crnt_Instrn_29), .A2(n2), .ZN(n3) );
  mx02d0 U28 ( .I0(ALU_Zro), .I1(PSWL_Zro), .S(n3), .Z(Zro_Flag) );
  nd02d0 U29 ( .A1(n4), .A2(Crnt_Instrn_24), .ZN(n5) );
  mx02d1 U30 ( .I0(\Crnt_Instrn\[0\] ), .I1(\Crnt_Instrn\[8\] ), .S(n5), .Z(
        \Addr_A\[0\] ) );
  mx02d1 U31 ( .I0(\Crnt_Instrn\[1\] ), .I1(\Crnt_Instrn\[9\] ), .S(n5), .Z(
        \Addr_A\[1\] ) );
  nr02d0 U32 ( .A1(Reset_AluRegs), .A2(Rd_Oprnd_B), .ZN(n11) );
  inv0d0 U33 ( .I(UseData_Imm_Or_RegB), .ZN(n6) );
  aor222d1 U34 ( .A1(n11), .A2(\Oprnd_B\[7\] ), .B1(\RegPort_B\[7\] ), .B2(n10), .C1(\Crnt_Instrn\[7\] ), .C2(n7), .Z(n58) );
  aor222d1 U35 ( .A1(n11), .A2(\Oprnd_B\[2\] ), .B1(n7), .B2(
        \Crnt_Instrn\[2\] ), .C1(\RegPort_B\[2\] ), .C2(n10), .Z(n53) );
  aor222d1 U36 ( .A1(n11), .A2(\Oprnd_B\[0\] ), .B1(n7), .B2(
        \Crnt_Instrn\[0\] ), .C1(\RegPort_B\[0\] ), .C2(n10), .Z(n51) );
  aor222d1 U37 ( .A1(n11), .A2(\Oprnd_B\[4\] ), .B1(n7), .B2(
        \Crnt_Instrn\[4\] ), .C1(\RegPort_B\[4\] ), .C2(n10), .Z(n55) );
  aor222d1 U38 ( .A1(n11), .A2(\Oprnd_B\[6\] ), .B1(n7), .B2(
        \Crnt_Instrn\[6\] ), .C1(\RegPort_B\[6\] ), .C2(n10), .Z(n57) );
  aor222d1 U39 ( .A1(n11), .A2(\Oprnd_B\[3\] ), .B1(n7), .B2(
        \Crnt_Instrn\[3\] ), .C1(\RegPort_B\[3\] ), .C2(n10), .Z(n54) );
  aor222d1 U40 ( .A1(n11), .A2(\Oprnd_B\[5\] ), .B1(n7), .B2(
        \Crnt_Instrn\[5\] ), .C1(\RegPort_B\[5\] ), .C2(n10), .Z(n56) );
  aor222d1 U41 ( .A1(n11), .A2(\Oprnd_B\[1\] ), .B1(n7), .B2(
        \Crnt_Instrn\[1\] ), .C1(\RegPort_B\[1\] ), .C2(n10), .Z(n52) );
  nr02d0 U42 ( .A1(Reset_AluRegs), .A2(Rd_Oprnd_A), .ZN(n9) );
  nr02d0 U43 ( .A1(Reset_AluRegs), .A2(n9), .ZN(n8) );
  aor22d1 U44 ( .A1(n9), .A2(\Oprnd_A\[15\] ), .B1(n8), .B2(\RegPort_A\[15\] ), 
        .Z(n82) );
  aor22d1 U45 ( .A1(n9), .A2(\Oprnd_A\[14\] ), .B1(n8), .B2(\RegPort_A\[14\] ), 
        .Z(n81) );
  aor22d1 U46 ( .A1(n9), .A2(\Oprnd_A\[13\] ), .B1(n8), .B2(\RegPort_A\[13\] ), 
        .Z(n80) );
  aor22d1 U47 ( .A1(n9), .A2(\Oprnd_A\[12\] ), .B1(n8), .B2(\RegPort_A\[12\] ), 
        .Z(n79) );
  aor22d1 U48 ( .A1(n9), .A2(\Oprnd_A\[11\] ), .B1(n8), .B2(\RegPort_A\[11\] ), 
        .Z(n78) );
  aor22d1 U49 ( .A1(n9), .A2(\Oprnd_A\[10\] ), .B1(n8), .B2(\RegPort_A\[10\] ), 
        .Z(n77) );
  aor22d1 U50 ( .A1(n9), .A2(\Oprnd_A\[9\] ), .B1(n8), .B2(\RegPort_A\[9\] ), 
        .Z(n76) );
  aor22d1 U51 ( .A1(n9), .A2(\Oprnd_A\[8\] ), .B1(n8), .B2(\RegPort_A\[8\] ), 
        .Z(n75) );
  aor22d1 U52 ( .A1(n9), .A2(\Oprnd_A\[7\] ), .B1(n8), .B2(\RegPort_A\[7\] ), 
        .Z(n74) );
  aor22d1 U53 ( .A1(n9), .A2(\Oprnd_A\[6\] ), .B1(n8), .B2(\RegPort_A\[6\] ), 
        .Z(n73) );
  aor22d1 U54 ( .A1(n9), .A2(\Oprnd_A\[5\] ), .B1(n8), .B2(\RegPort_A\[5\] ), 
        .Z(n72) );
  aor22d1 U55 ( .A1(n9), .A2(\Oprnd_A\[4\] ), .B1(n8), .B2(\RegPort_A\[4\] ), 
        .Z(n71) );
  aor22d1 U56 ( .A1(n9), .A2(\Oprnd_A\[3\] ), .B1(n8), .B2(\RegPort_A\[3\] ), 
        .Z(n70) );
  aor22d1 U57 ( .A1(n9), .A2(\Oprnd_A\[2\] ), .B1(n8), .B2(\RegPort_A\[2\] ), 
        .Z(n69) );
  aor22d1 U58 ( .A1(n9), .A2(\Oprnd_A\[1\] ), .B1(n8), .B2(\RegPort_A\[1\] ), 
        .Z(n68) );
  aor22d1 U59 ( .A1(n9), .A2(\Oprnd_A\[0\] ), .B1(n8), .B2(\RegPort_A\[0\] ), 
        .Z(n67) );
  aor22d1 U60 ( .A1(n11), .A2(\Oprnd_B\[15\] ), .B1(n10), .B2(
        \RegPort_B\[15\] ), .Z(n66) );
  aor22d1 U61 ( .A1(n11), .A2(\Oprnd_B\[14\] ), .B1(n10), .B2(
        \RegPort_B\[14\] ), .Z(n65) );
  aor22d1 U62 ( .A1(n11), .A2(\Oprnd_B\[13\] ), .B1(n10), .B2(
        \RegPort_B\[13\] ), .Z(n64) );
  aor22d1 U63 ( .A1(n11), .A2(\Oprnd_B\[12\] ), .B1(n10), .B2(
        \RegPort_B\[12\] ), .Z(n63) );
  aor22d1 U64 ( .A1(n11), .A2(\Oprnd_B\[11\] ), .B1(n10), .B2(
        \RegPort_B\[11\] ), .Z(n62) );
  aor22d1 U65 ( .A1(n11), .A2(\Oprnd_B\[10\] ), .B1(n10), .B2(
        \RegPort_B\[10\] ), .Z(n61) );
  aor22d1 U66 ( .A1(n11), .A2(\Oprnd_B\[9\] ), .B1(n10), .B2(\RegPort_B\[9\] ), 
        .Z(n60) );
  aor22d1 U67 ( .A1(n11), .A2(\Oprnd_B\[8\] ), .B1(n10), .B2(\RegPort_B\[8\] ), 
        .Z(n59) );
endmodule


module INSTRN_LAT ( Clk, .Instrn({\Instrn\[31\] , \Instrn\[30\] , 
        \Instrn\[29\] , \Instrn\[28\] , \Instrn\[27\] , \Instrn\[26\] , 
        \Instrn\[25\] , \Instrn\[24\] , \Instrn\[23\] , \Instrn\[22\] , 
        \Instrn\[21\] , \Instrn\[20\] , \Instrn\[19\] , \Instrn\[18\] , 
        \Instrn\[17\] , \Instrn\[16\] , \Instrn\[15\] , \Instrn\[14\] , 
        \Instrn\[13\] , \Instrn\[12\] , \Instrn\[11\] , \Instrn\[10\] , 
        \Instrn\[9\] , \Instrn\[8\] , \Instrn\[7\] , \Instrn\[6\] , 
        \Instrn\[5\] , \Instrn\[4\] , \Instrn\[3\] , \Instrn\[2\] , 
        \Instrn\[1\] , \Instrn\[0\] }), Latch_Instr, .Crnt_Instrn_1({
        \Crnt_Instrn_1\[31\] , \Crnt_Instrn_1\[30\] , \Crnt_Instrn_1\[29\] , 
        \Crnt_Instrn_1\[28\] , \Crnt_Instrn_1\[27\] , \Crnt_Instrn_1\[26\] , 
        \Crnt_Instrn_1\[25\] , \Crnt_Instrn_1\[24\] , \Crnt_Instrn_1\[23\] , 
        \Crnt_Instrn_1\[22\] , \Crnt_Instrn_1\[21\] , \Crnt_Instrn_1\[20\] , 
        \Crnt_Instrn_1\[19\] , \Crnt_Instrn_1\[18\] , \Crnt_Instrn_1\[17\] , 
        \Crnt_Instrn_1\[16\] , \Crnt_Instrn_1\[15\] , \Crnt_Instrn_1\[14\] , 
        \Crnt_Instrn_1\[13\] , \Crnt_Instrn_1\[12\] , \Crnt_Instrn_1\[11\] , 
        \Crnt_Instrn_1\[10\] , \Crnt_Instrn_1\[9\] , \Crnt_Instrn_1\[8\] , 
        \Crnt_Instrn_1\[7\] , \Crnt_Instrn_1\[6\] , \Crnt_Instrn_1\[5\] , 
        \Crnt_Instrn_1\[4\] , \Crnt_Instrn_1\[3\] , \Crnt_Instrn_1\[2\] , 
        \Crnt_Instrn_1\[1\] , \Crnt_Instrn_1\[0\] }), .Crnt_Instrn_2({
        \Crnt_Instrn_2\[31\] , \Crnt_Instrn_2\[30\] , \Crnt_Instrn_2\[29\] , 
        \Crnt_Instrn_2\[28\] , \Crnt_Instrn_2\[27\] , \Crnt_Instrn_2\[26\] , 
        \Crnt_Instrn_2\[25\] , \Crnt_Instrn_2\[24\] , \Crnt_Instrn_2\[23\] , 
        \Crnt_Instrn_2\[22\] , \Crnt_Instrn_2\[21\] , \Crnt_Instrn_2\[20\] , 
        \Crnt_Instrn_2\[19\] , \Crnt_Instrn_2\[18\] , \Crnt_Instrn_2\[17\] , 
        \Crnt_Instrn_2\[16\] , \Crnt_Instrn_2\[15\] , \Crnt_Instrn_2\[14\] , 
        \Crnt_Instrn_2\[13\] , \Crnt_Instrn_2\[12\] , \Crnt_Instrn_2\[11\] , 
        \Crnt_Instrn_2\[10\] , \Crnt_Instrn_2\[9\] , \Crnt_Instrn_2\[8\] , 
        \Crnt_Instrn_2\[7\] , \Crnt_Instrn_2\[6\] , \Crnt_Instrn_2\[5\] , 
        \Crnt_Instrn_2\[4\] , \Crnt_Instrn_2\[3\] , \Crnt_Instrn_2\[2\] , 
        \Crnt_Instrn_2\[1\] , \Crnt_Instrn_2\[0\] }), test_si, test_se );
  input Clk, \Instrn\[31\] , \Instrn\[30\] , \Instrn\[29\] , \Instrn\[28\] ,
         \Instrn\[27\] , \Instrn\[26\] , \Instrn\[25\] , \Instrn\[24\] ,
         \Instrn\[23\] , \Instrn\[22\] , \Instrn\[21\] , \Instrn\[20\] ,
         \Instrn\[19\] , \Instrn\[18\] , \Instrn\[17\] , \Instrn\[16\] ,
         \Instrn\[15\] , \Instrn\[14\] , \Instrn\[13\] , \Instrn\[12\] ,
         \Instrn\[11\] , \Instrn\[10\] , \Instrn\[9\] , \Instrn\[8\] ,
         \Instrn\[7\] , \Instrn\[6\] , \Instrn\[5\] , \Instrn\[4\] ,
         \Instrn\[3\] , \Instrn\[2\] , \Instrn\[1\] , \Instrn\[0\] ,
         Latch_Instr, test_si, test_se;
  output \Crnt_Instrn_1\[31\] , \Crnt_Instrn_1\[30\] , \Crnt_Instrn_1\[29\] ,
         \Crnt_Instrn_1\[28\] , \Crnt_Instrn_1\[27\] , \Crnt_Instrn_1\[26\] ,
         \Crnt_Instrn_1\[25\] , \Crnt_Instrn_1\[24\] , \Crnt_Instrn_1\[23\] ,
         \Crnt_Instrn_1\[22\] , \Crnt_Instrn_1\[21\] , \Crnt_Instrn_1\[20\] ,
         \Crnt_Instrn_1\[19\] , \Crnt_Instrn_1\[18\] , \Crnt_Instrn_1\[17\] ,
         \Crnt_Instrn_1\[16\] , \Crnt_Instrn_1\[15\] , \Crnt_Instrn_1\[14\] ,
         \Crnt_Instrn_1\[13\] , \Crnt_Instrn_1\[12\] , \Crnt_Instrn_1\[11\] ,
         \Crnt_Instrn_1\[10\] , \Crnt_Instrn_1\[9\] , \Crnt_Instrn_1\[8\] ,
         \Crnt_Instrn_1\[7\] , \Crnt_Instrn_1\[6\] , \Crnt_Instrn_1\[5\] ,
         \Crnt_Instrn_1\[4\] , \Crnt_Instrn_1\[3\] , \Crnt_Instrn_1\[2\] ,
         \Crnt_Instrn_1\[1\] , \Crnt_Instrn_1\[0\] , \Crnt_Instrn_2\[31\] ,
         \Crnt_Instrn_2\[30\] , \Crnt_Instrn_2\[29\] , \Crnt_Instrn_2\[28\] ,
         \Crnt_Instrn_2\[27\] , \Crnt_Instrn_2\[26\] , \Crnt_Instrn_2\[25\] ,
         \Crnt_Instrn_2\[24\] , \Crnt_Instrn_2\[23\] , \Crnt_Instrn_2\[22\] ,
         \Crnt_Instrn_2\[21\] , \Crnt_Instrn_2\[20\] , \Crnt_Instrn_2\[19\] ,
         \Crnt_Instrn_2\[18\] , \Crnt_Instrn_2\[17\] , \Crnt_Instrn_2\[16\] ,
         \Crnt_Instrn_2\[15\] , \Crnt_Instrn_2\[14\] , \Crnt_Instrn_2\[13\] ,
         \Crnt_Instrn_2\[12\] , \Crnt_Instrn_2\[11\] , \Crnt_Instrn_2\[10\] ,
         \Crnt_Instrn_2\[9\] , \Crnt_Instrn_2\[8\] , \Crnt_Instrn_2\[7\] ,
         \Crnt_Instrn_2\[6\] , \Crnt_Instrn_2\[5\] , \Crnt_Instrn_2\[4\] ,
         \Crnt_Instrn_2\[3\] , \Crnt_Instrn_2\[2\] , \Crnt_Instrn_2\[1\] ,
         \Crnt_Instrn_2\[0\] ;
  wire   \Crnt_Instrn_1\[31\] , \Crnt_Instrn_1\[30\] , \Crnt_Instrn_1\[29\] ,
         \Crnt_Instrn_1\[28\] , \Crnt_Instrn_1\[27\] , \Crnt_Instrn_1\[26\] ,
         \Crnt_Instrn_1\[25\] , \Crnt_Instrn_1\[24\] , \Crnt_Instrn_1\[23\] ,
         \Crnt_Instrn_1\[22\] , \Crnt_Instrn_1\[21\] , \Crnt_Instrn_1\[20\] ,
         \Crnt_Instrn_1\[19\] , \Crnt_Instrn_1\[18\] , \Crnt_Instrn_1\[17\] ,
         \Crnt_Instrn_1\[16\] , \Crnt_Instrn_1\[15\] , \Crnt_Instrn_1\[14\] ,
         \Crnt_Instrn_1\[13\] , \Crnt_Instrn_1\[12\] , \Crnt_Instrn_1\[11\] ,
         \Crnt_Instrn_1\[10\] , \Crnt_Instrn_1\[9\] , \Crnt_Instrn_1\[8\] ,
         \Crnt_Instrn_1\[7\] , \Crnt_Instrn_1\[6\] , \Crnt_Instrn_1\[5\] ,
         \Crnt_Instrn_1\[4\] , \Crnt_Instrn_1\[3\] , \Crnt_Instrn_1\[2\] ,
         \Crnt_Instrn_1\[1\] , \Crnt_Instrn_1\[0\] , n3, n5, n7, n9, n11, n13,
         n15, n17, n19, n21, n23, n25, n27, n29, n31, n33, n35, n37, n39, n41,
         n43, n45, n47, n49, n51, n53, n55, n57, n59, n61, n63, n65, n1, n4,
         n6, n8, n10, n12;
  assign \Crnt_Instrn_2\[31\]  = \Crnt_Instrn_1\[31\] ;
  assign \Crnt_Instrn_2\[30\]  = \Crnt_Instrn_1\[30\] ;
  assign \Crnt_Instrn_2\[29\]  = \Crnt_Instrn_1\[29\] ;
  assign \Crnt_Instrn_2\[28\]  = \Crnt_Instrn_1\[28\] ;
  assign \Crnt_Instrn_2\[27\]  = \Crnt_Instrn_1\[27\] ;
  assign \Crnt_Instrn_2\[26\]  = \Crnt_Instrn_1\[26\] ;
  assign \Crnt_Instrn_2\[25\]  = \Crnt_Instrn_1\[25\] ;
  assign \Crnt_Instrn_2\[24\]  = \Crnt_Instrn_1\[24\] ;
  assign \Crnt_Instrn_2\[23\]  = \Crnt_Instrn_1\[23\] ;
  assign \Crnt_Instrn_2\[22\]  = \Crnt_Instrn_1\[22\] ;
  assign \Crnt_Instrn_2\[21\]  = \Crnt_Instrn_1\[21\] ;
  assign \Crnt_Instrn_2\[20\]  = \Crnt_Instrn_1\[20\] ;
  assign \Crnt_Instrn_2\[19\]  = \Crnt_Instrn_1\[19\] ;
  assign \Crnt_Instrn_2\[18\]  = \Crnt_Instrn_1\[18\] ;
  assign \Crnt_Instrn_2\[17\]  = \Crnt_Instrn_1\[17\] ;
  assign \Crnt_Instrn_2\[16\]  = \Crnt_Instrn_1\[16\] ;
  assign \Crnt_Instrn_2\[15\]  = \Crnt_Instrn_1\[15\] ;
  assign \Crnt_Instrn_2\[14\]  = \Crnt_Instrn_1\[14\] ;
  assign \Crnt_Instrn_2\[13\]  = \Crnt_Instrn_1\[13\] ;
  assign \Crnt_Instrn_2\[12\]  = \Crnt_Instrn_1\[12\] ;
  assign \Crnt_Instrn_2\[11\]  = \Crnt_Instrn_1\[11\] ;
  assign \Crnt_Instrn_2\[10\]  = \Crnt_Instrn_1\[10\] ;
  assign \Crnt_Instrn_2\[9\]  = \Crnt_Instrn_1\[9\] ;
  assign \Crnt_Instrn_2\[8\]  = \Crnt_Instrn_1\[8\] ;
  assign \Crnt_Instrn_2\[7\]  = \Crnt_Instrn_1\[7\] ;
  assign \Crnt_Instrn_2\[6\]  = \Crnt_Instrn_1\[6\] ;
  assign \Crnt_Instrn_2\[5\]  = \Crnt_Instrn_1\[5\] ;
  assign \Crnt_Instrn_2\[4\]  = \Crnt_Instrn_1\[4\] ;
  assign \Crnt_Instrn_2\[3\]  = \Crnt_Instrn_1\[3\] ;
  assign \Crnt_Instrn_2\[2\]  = \Crnt_Instrn_1\[2\] ;
  assign \Crnt_Instrn_2\[1\]  = \Crnt_Instrn_1\[1\] ;
  assign \Crnt_Instrn_2\[0\]  = \Crnt_Instrn_1\[0\] ;

  sdnrq1 \Crnt_Instrn_1_reg\[31\]  ( .D(n65), .SD(\Crnt_Instrn_1\[30\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[31\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[30\]  ( .D(n63), .SD(\Crnt_Instrn_1\[29\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[30\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[29\]  ( .D(n61), .SD(\Crnt_Instrn_1\[28\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[29\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[28\]  ( .D(n59), .SD(\Crnt_Instrn_1\[27\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[28\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[27\]  ( .D(n57), .SD(\Crnt_Instrn_1\[26\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[27\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[26\]  ( .D(n55), .SD(\Crnt_Instrn_1\[25\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[26\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[25\]  ( .D(n53), .SD(\Crnt_Instrn_1\[24\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[25\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[24\]  ( .D(n51), .SD(\Crnt_Instrn_1\[23\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[24\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[23\]  ( .D(n49), .SD(\Crnt_Instrn_1\[22\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[23\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[22\]  ( .D(n47), .SD(\Crnt_Instrn_1\[21\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[22\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[21\]  ( .D(n45), .SD(\Crnt_Instrn_1\[20\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[21\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[20\]  ( .D(n43), .SD(\Crnt_Instrn_1\[19\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[20\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[19\]  ( .D(n41), .SD(\Crnt_Instrn_1\[18\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[19\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[18\]  ( .D(n39), .SD(\Crnt_Instrn_1\[17\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[18\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[17\]  ( .D(n37), .SD(\Crnt_Instrn_1\[16\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[17\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[16\]  ( .D(n35), .SD(\Crnt_Instrn_1\[15\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[16\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[15\]  ( .D(n33), .SD(\Crnt_Instrn_1\[14\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[15\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[14\]  ( .D(n31), .SD(\Crnt_Instrn_1\[13\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[14\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[13\]  ( .D(n29), .SD(\Crnt_Instrn_1\[12\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[13\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[12\]  ( .D(n27), .SD(\Crnt_Instrn_1\[11\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[12\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[11\]  ( .D(n25), .SD(\Crnt_Instrn_1\[10\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[11\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[10\]  ( .D(n23), .SD(\Crnt_Instrn_1\[9\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[10\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[9\]  ( .D(n21), .SD(\Crnt_Instrn_1\[8\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[9\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[8\]  ( .D(n19), .SD(\Crnt_Instrn_1\[7\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[8\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[7\]  ( .D(n17), .SD(\Crnt_Instrn_1\[6\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[7\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[6\]  ( .D(n15), .SD(\Crnt_Instrn_1\[5\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[6\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[5\]  ( .D(n13), .SD(\Crnt_Instrn_1\[4\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[5\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[4\]  ( .D(n11), .SD(\Crnt_Instrn_1\[3\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[4\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[3\]  ( .D(n9), .SD(\Crnt_Instrn_1\[2\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[3\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[2\]  ( .D(n7), .SD(\Crnt_Instrn_1\[1\] ), .SC(
        test_se), .CP(n10), .Q(\Crnt_Instrn_1\[2\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[1\]  ( .D(n5), .SD(\Crnt_Instrn_1\[0\] ), .SC(
        test_se), .CP(n12), .Q(\Crnt_Instrn_1\[1\] ) );
  sdnrq1 \Crnt_Instrn_1_reg\[0\]  ( .D(n3), .SD(test_si), .SC(test_se), .CP(
        n10), .Q(\Crnt_Instrn_1\[0\] ) );
  inv0d0 U2 ( .I(Clk), .ZN(n4) );
  inv0d0 U3 ( .I(Latch_Instr), .ZN(n1) );
  inv0d0 U4 ( .I(n1), .ZN(n6) );
  mx02d0 U5 ( .I0(\Crnt_Instrn_1\[26\] ), .I1(\Instrn\[26\] ), .S(n6), .Z(n55)
         );
  mx02d0 U6 ( .I0(\Crnt_Instrn_1\[25\] ), .I1(\Instrn\[25\] ), .S(n6), .Z(n53)
         );
  mx02d0 U7 ( .I0(\Crnt_Instrn_1\[23\] ), .I1(\Instrn\[23\] ), .S(n6), .Z(n49)
         );
  mx02d0 U8 ( .I0(\Crnt_Instrn_1\[22\] ), .I1(\Instrn\[22\] ), .S(n6), .Z(n47)
         );
  mx02d0 U9 ( .I0(\Crnt_Instrn_1\[21\] ), .I1(\Instrn\[21\] ), .S(n6), .Z(n45)
         );
  inv0d0 U10 ( .I(n1), .ZN(n8) );
  mx02d0 U11 ( .I0(\Crnt_Instrn_1\[20\] ), .I1(\Instrn\[20\] ), .S(n8), .Z(n43) );
  mx02d0 U12 ( .I0(\Crnt_Instrn_1\[19\] ), .I1(\Instrn\[19\] ), .S(Latch_Instr), .Z(n41) );
  mx02d0 U13 ( .I0(\Crnt_Instrn_1\[18\] ), .I1(\Instrn\[18\] ), .S(n6), .Z(n39) );
  mx02d0 U14 ( .I0(\Crnt_Instrn_1\[15\] ), .I1(\Instrn\[15\] ), .S(n8), .Z(n33) );
  mx02d0 U15 ( .I0(\Crnt_Instrn_1\[14\] ), .I1(\Instrn\[14\] ), .S(Latch_Instr), .Z(n31) );
  mx02d0 U16 ( .I0(\Crnt_Instrn_1\[13\] ), .I1(\Instrn\[13\] ), .S(Latch_Instr), .Z(n29) );
  mx02d0 U17 ( .I0(\Crnt_Instrn_1\[12\] ), .I1(\Instrn\[12\] ), .S(Latch_Instr), .Z(n27) );
  mx02d0 U18 ( .I0(\Crnt_Instrn_1\[11\] ), .I1(\Instrn\[11\] ), .S(Latch_Instr), .Z(n25) );
  mx02d0 U19 ( .I0(\Crnt_Instrn_1\[10\] ), .I1(\Instrn\[10\] ), .S(Latch_Instr), .Z(n23) );
  mx02d0 U20 ( .I0(\Crnt_Instrn_1\[9\] ), .I1(\Instrn\[9\] ), .S(n8), .Z(n21)
         );
  mx02d0 U21 ( .I0(\Crnt_Instrn_1\[8\] ), .I1(\Instrn\[8\] ), .S(n8), .Z(n19)
         );
  mx02d0 U22 ( .I0(\Crnt_Instrn_1\[7\] ), .I1(\Instrn\[7\] ), .S(n8), .Z(n17)
         );
  mx02d0 U23 ( .I0(\Crnt_Instrn_1\[6\] ), .I1(\Instrn\[6\] ), .S(n8), .Z(n15)
         );
  mx02d0 U24 ( .I0(\Crnt_Instrn_1\[5\] ), .I1(\Instrn\[5\] ), .S(n8), .Z(n13)
         );
  mx02d0 U25 ( .I0(\Crnt_Instrn_1\[4\] ), .I1(\Instrn\[4\] ), .S(n8), .Z(n11)
         );
  mx02d0 U26 ( .I0(\Crnt_Instrn_1\[3\] ), .I1(\Instrn\[3\] ), .S(n8), .Z(n9)
         );
  mx02d0 U27 ( .I0(\Crnt_Instrn_1\[2\] ), .I1(\Instrn\[2\] ), .S(n8), .Z(n7)
         );
  inv0d0 U28 ( .I(n4), .ZN(n10) );
  inv0d0 U29 ( .I(n4), .ZN(n12) );
  mx02d0 U30 ( .I0(\Crnt_Instrn_1\[28\] ), .I1(\Instrn\[28\] ), .S(n6), .Z(n59) );
  mx02d0 U31 ( .I0(\Crnt_Instrn_1\[1\] ), .I1(\Instrn\[1\] ), .S(n8), .Z(n5)
         );
  mx02d0 U32 ( .I0(\Crnt_Instrn_1\[24\] ), .I1(\Instrn\[24\] ), .S(n6), .Z(n51) );
  mx02d0 U33 ( .I0(\Crnt_Instrn_1\[27\] ), .I1(\Instrn\[27\] ), .S(n6), .Z(n57) );
  mx02d0 U34 ( .I0(\Crnt_Instrn_1\[29\] ), .I1(\Instrn\[29\] ), .S(n6), .Z(n61) );
  mx02d0 U35 ( .I0(\Crnt_Instrn_1\[0\] ), .I1(\Instrn\[0\] ), .S(n8), .Z(n3)
         );
  mx02d0 U36 ( .I0(\Crnt_Instrn_1\[31\] ), .I1(\Instrn\[31\] ), .S(n6), .Z(n65) );
  mx02d0 U37 ( .I0(\Crnt_Instrn_1\[30\] ), .I1(\Instrn\[30\] ), .S(n6), .Z(n63) );
  mx02d0 U38 ( .I0(\Crnt_Instrn_1\[17\] ), .I1(\Instrn\[17\] ), .S(n8), .Z(n37) );
  mx02d0 U39 ( .I0(\Crnt_Instrn_1\[16\] ), .I1(\Instrn\[16\] ), .S(Latch_Instr), .Z(n35) );
endmodule


module PRGRM_FSM ( Clk, INTERNAL_RESET, .CurrentState({\CurrentState\[2\] , 
        \CurrentState\[1\] , \CurrentState\[0\] }), test_si, test_se );
  input Clk, INTERNAL_RESET, test_si, test_se;
  output \CurrentState\[2\] , \CurrentState\[1\] , \CurrentState\[0\] ;
  wire   \Next_State\[2\] , \Next_State\[1\] , \Next_State\[0\] , n1, n2, n3;

  sdcrq1 \Current_State_reg\[0\]  ( .D(\Next_State\[0\] ), .SD(test_si), .SC(
        test_se), .CP(Clk), .CDN(INTERNAL_RESET), .Q(\CurrentState\[0\] ) );
  sdcrq1 \Current_State_reg\[2\]  ( .D(\Next_State\[2\] ), .SD(
        \CurrentState\[1\] ), .SC(test_se), .CP(Clk), .CDN(INTERNAL_RESET), 
        .Q(\CurrentState\[2\] ) );
  sdcrq1 \Current_State_reg\[1\]  ( .D(\Next_State\[1\] ), .SD(
        \CurrentState\[0\] ), .SC(test_se), .CP(Clk), .CDN(INTERNAL_RESET), 
        .Q(\CurrentState\[1\] ) );
  aoi21d1 U3 ( .B1(\CurrentState\[1\] ), .B2(\CurrentState\[2\] ), .A(
        \CurrentState\[0\] ), .ZN(\Next_State\[0\] ) );
  nr02d0 U4 ( .A1(\CurrentState\[1\] ), .A2(\CurrentState\[0\] ), .ZN(n2) );
  nd02d0 U5 ( .A1(\CurrentState\[1\] ), .A2(\CurrentState\[0\] ), .ZN(n3) );
  inv0d0 U6 ( .I(n3), .ZN(n1) );
  nr03d0 U7 ( .A1(n2), .A2(\CurrentState\[2\] ), .A3(n1), .ZN(
        \Next_State\[1\] ) );
  nr02d0 U8 ( .A1(\CurrentState\[2\] ), .A2(n3), .ZN(\Next_State\[2\] ) );
endmodule


module PRGRM_DECODE ( Zro_Flag, Carry_Flag, Neg_Flag, .CurrentState({
        \CurrentState\[2\] , \CurrentState\[1\] , \CurrentState\[0\] }), 
    .Crnt_Instrn({\Crnt_Instrn\[31\] , \Crnt_Instrn\[30\] , 
        \Crnt_Instrn\[29\] , \Crnt_Instrn\[28\] , \Crnt_Instrn\[27\] , 
        \Crnt_Instrn\[26\] , \Crnt_Instrn\[25\] , \Crnt_Instrn\[24\] , 
        \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] , \Crnt_Instrn\[21\] , 
        \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] , \Crnt_Instrn\[18\] , 
        \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] , \Crnt_Instrn\[15\] , 
        \Crnt_Instrn\[14\] , \Crnt_Instrn\[13\] , \Crnt_Instrn\[12\] , 
        \Crnt_Instrn\[11\] , \Crnt_Instrn\[10\] , \Crnt_Instrn\[9\] , 
        \Crnt_Instrn\[8\] , \Crnt_Instrn\[7\] , \Crnt_Instrn\[6\] , 
        \Crnt_Instrn\[5\] , \Crnt_Instrn\[4\] , \Crnt_Instrn\[3\] , 
        \Crnt_Instrn\[2\] , \Crnt_Instrn\[1\] , \Crnt_Instrn\[0\] }), 
        Incrmnt_PC, Ld_Brnch_Addr, Ld_Rtn_Addr );
  input Zro_Flag, Carry_Flag, Neg_Flag, \CurrentState\[2\] ,
         \CurrentState\[1\] , \CurrentState\[0\] , \Crnt_Instrn\[31\] ,
         \Crnt_Instrn\[30\] , \Crnt_Instrn\[29\] , \Crnt_Instrn\[28\] ,
         \Crnt_Instrn\[27\] , \Crnt_Instrn\[26\] , \Crnt_Instrn\[25\] ,
         \Crnt_Instrn\[24\] , \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] ,
         \Crnt_Instrn\[21\] , \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] ,
         \Crnt_Instrn\[18\] , \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] ,
         \Crnt_Instrn\[15\] , \Crnt_Instrn\[14\] , \Crnt_Instrn\[13\] ,
         \Crnt_Instrn\[12\] , \Crnt_Instrn\[11\] , \Crnt_Instrn\[10\] ,
         \Crnt_Instrn\[9\] , \Crnt_Instrn\[8\] , \Crnt_Instrn\[7\] ,
         \Crnt_Instrn\[6\] , \Crnt_Instrn\[5\] , \Crnt_Instrn\[4\] ,
         \Crnt_Instrn\[3\] , \Crnt_Instrn\[2\] , \Crnt_Instrn\[1\] ,
         \Crnt_Instrn\[0\] ;
  output Incrmnt_PC, Ld_Brnch_Addr, Ld_Rtn_Addr;
  wire   Crnt_Instrn_31, Crnt_Instrn_30, Crnt_Instrn_29, Crnt_Instrn_28,
         Crnt_Instrn_27, Crnt_Instrn_25, n1, n2, n3, n4, n5, n6, n7, n8, n9,
         n10, n11, n12, n13, n14, n15;
  assign Crnt_Instrn_31 = \Crnt_Instrn\[31\] ;
  assign Crnt_Instrn_30 = \Crnt_Instrn\[30\] ;
  assign Crnt_Instrn_29 = \Crnt_Instrn\[29\] ;
  assign Crnt_Instrn_28 = \Crnt_Instrn\[28\] ;
  assign Crnt_Instrn_27 = \Crnt_Instrn\[27\] ;
  assign Crnt_Instrn_25 = \Crnt_Instrn\[25\] ;

  nr02d0 U2 ( .A1(\CurrentState\[0\] ), .A2(\CurrentState\[1\] ), .ZN(n1) );
  nd02d0 U3 ( .A1(\CurrentState\[2\] ), .A2(n1), .ZN(n15) );
  nr03d0 U4 ( .A1(Crnt_Instrn_30), .A2(Crnt_Instrn_31), .A3(n15), .ZN(n14) );
  an02d0 U5 ( .A1(n14), .A2(Crnt_Instrn_27), .Z(Ld_Rtn_Addr) );
  nr04d0 U6 ( .A1(\Crnt_Instrn\[22\] ), .A2(\Crnt_Instrn\[23\] ), .A3(
        \Crnt_Instrn\[20\] ), .A4(\Crnt_Instrn\[19\] ), .ZN(n8) );
  mx02d0 U7 ( .I0(Neg_Flag), .I1(Zro_Flag), .S(\Crnt_Instrn\[16\] ), .Z(n2) );
  nd02d0 U8 ( .A1(n8), .A2(n2), .ZN(n3) );
  nr04d0 U9 ( .A1(\Crnt_Instrn\[21\] ), .A2(\Crnt_Instrn\[18\] ), .A3(
        \Crnt_Instrn\[17\] ), .A4(n3), .ZN(n10) );
  nd02d0 U10 ( .A1(\Crnt_Instrn\[16\] ), .A2(\Crnt_Instrn\[17\] ), .ZN(n6) );
  nd04d0 U11 ( .A1(\Crnt_Instrn\[21\] ), .A2(\Crnt_Instrn\[18\] ), .A3(
        \Crnt_Instrn\[20\] ), .A4(\Crnt_Instrn\[19\] ), .ZN(n4) );
  nr04d0 U12 ( .A1(\Crnt_Instrn\[22\] ), .A2(\Crnt_Instrn\[23\] ), .A3(n6), 
        .A4(n4), .ZN(n5) );
  or02d0 U13 ( .A1(n10), .A2(n5), .Z(n12) );
  nr02d0 U14 ( .A1(\Crnt_Instrn\[21\] ), .A2(\Crnt_Instrn\[18\] ), .ZN(n7) );
  nd03d0 U15 ( .A1(n8), .A2(n7), .A3(n6), .ZN(n9) );
  nr02d0 U16 ( .A1(n10), .A2(n9), .ZN(n11) );
  mx02d0 U17 ( .I0(n12), .I1(n11), .S(Crnt_Instrn_25), .Z(n13) );
  ora211d1 U18 ( .C1(Crnt_Instrn_29), .C2(Crnt_Instrn_28), .A(n14), .B(n13), 
        .Z(Ld_Brnch_Addr) );
  nr03d0 U19 ( .A1(Ld_Brnch_Addr), .A2(Ld_Rtn_Addr), .A3(n15), .ZN(Incrmnt_PC)
         );
endmodule


module PRGRM_CNT ( INTERNAL_RESET, Clk, Incrmnt_PC, Ld_Brnch_Addr, Ld_Rtn_Addr, 
    .Imm_Addr({\Imm_Addr\[7\] , \Imm_Addr\[6\] , \Imm_Addr\[5\] , 
        \Imm_Addr\[4\] , \Imm_Addr\[3\] , \Imm_Addr\[2\] , \Imm_Addr\[1\] , 
        \Imm_Addr\[0\] }), .Return_Addr({\Return_Addr\[7\] , 
        \Return_Addr\[6\] , \Return_Addr\[5\] , \Return_Addr\[4\] , 
        \Return_Addr\[3\] , \Return_Addr\[2\] , \Return_Addr\[1\] , 
        \Return_Addr\[0\] }), .PC({\PC\[7\] , \PC\[6\] , \PC\[5\] , \PC\[4\] , 
        \PC\[3\] , \PC\[2\] , \PC\[1\] , \PC\[0\] }), test_si, test_se );
  input INTERNAL_RESET, Clk, Incrmnt_PC, Ld_Brnch_Addr, Ld_Rtn_Addr,
         \Imm_Addr\[7\] , \Imm_Addr\[6\] , \Imm_Addr\[5\] , \Imm_Addr\[4\] ,
         \Imm_Addr\[3\] , \Imm_Addr\[2\] , \Imm_Addr\[1\] , \Imm_Addr\[0\] ,
         \Return_Addr\[7\] , \Return_Addr\[6\] , \Return_Addr\[5\] ,
         \Return_Addr\[4\] , \Return_Addr\[3\] , \Return_Addr\[2\] ,
         \Return_Addr\[1\] , \Return_Addr\[0\] , test_si, test_se;
  output \PC\[7\] , \PC\[6\] , \PC\[5\] , \PC\[4\] , \PC\[3\] , \PC\[2\] ,
         \PC\[1\] , \PC\[0\] ;
  wire   n15, n16, n17, n18, n19, n20, n21, n22, n1, n2, n3, n4, n5, n6, n7,
         n8, n9, n10, n11, n12, n13, n23, n24, n25, n26, n27, n28, n29, n30,
         n31, n32, n33, n34, n35, n36, n37, n38, n39, n40, n41, n42, n43, n44,
         n45, n46, n47, n48, n49, n50;

  sdcrq1 \PCint_reg\[7\]  ( .D(n21), .SD(\PC\[6\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[7\] ) );
  sdcrq1 \PCint_reg\[6\]  ( .D(n20), .SD(\PC\[5\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[6\] ) );
  sdcrq1 \PCint_reg\[5\]  ( .D(n19), .SD(\PC\[4\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[5\] ) );
  sdcrq1 \PCint_reg\[4\]  ( .D(n18), .SD(\PC\[3\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[4\] ) );
  sdcrq1 \PCint_reg\[3\]  ( .D(n17), .SD(\PC\[2\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[3\] ) );
  sdcrq1 \PCint_reg\[2\]  ( .D(n16), .SD(\PC\[1\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[2\] ) );
  sdcrq1 \PCint_reg\[1\]  ( .D(n15), .SD(\PC\[0\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[1\] ) );
  sdcrq1 \PCint_reg\[0\]  ( .D(n22), .SD(test_si), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\PC\[0\] ) );
  nd03d0 U3 ( .A1(\PC\[0\] ), .A2(\PC\[1\] ), .A3(\PC\[2\] ), .ZN(n32) );
  nr03d0 U4 ( .A1(Ld_Brnch_Addr), .A2(Incrmnt_PC), .A3(Ld_Rtn_Addr), .ZN(n37)
         );
  aor21d1 U5 ( .B1(Incrmnt_PC), .B2(n32), .A(n37), .Z(n35) );
  inv0d0 U6 ( .I(Incrmnt_PC), .ZN(n44) );
  an02d0 U7 ( .A1(Ld_Rtn_Addr), .A2(n44), .Z(n47) );
  inv0d0 U8 ( .I(\PC\[3\] ), .ZN(n1) );
  nr02d0 U9 ( .A1(n32), .A2(n1), .ZN(n5) );
  mx02d0 U10 ( .I0(n5), .I1(n1), .S(\PC\[4\] ), .Z(n3) );
  inv0d0 U11 ( .I(Ld_Brnch_Addr), .ZN(n2) );
  nr03d0 U12 ( .A1(Incrmnt_PC), .A2(Ld_Rtn_Addr), .A3(n2), .ZN(n46) );
  aoi2222d1 U13 ( .A1(n35), .A2(\PC\[4\] ), .B1(n47), .B2(\Return_Addr\[4\] ), 
        .C1(n3), .C2(Incrmnt_PC), .D1(\Imm_Addr\[4\] ), .D2(n46), .ZN(n4) );
  inv0d0 U14 ( .I(n4), .ZN(n18) );
  nd02d0 U15 ( .A1(\PC\[4\] ), .A2(n5), .ZN(n6) );
  aor21d1 U16 ( .B1(Incrmnt_PC), .B2(n6), .A(n37), .Z(n11) );
  inv0d0 U17 ( .I(\PC\[5\] ), .ZN(n8) );
  nr02d0 U18 ( .A1(n44), .A2(n6), .ZN(n13) );
  aor22d1 U19 ( .A1(n47), .A2(\Return_Addr\[5\] ), .B1(n46), .B2(
        \Imm_Addr\[5\] ), .Z(n7) );
  aor221d1 U20 ( .B1(\PC\[5\] ), .B2(n11), .C1(n8), .C2(n13), .A(n7), .Z(n19)
         );
  nr02d0 U21 ( .A1(\PC\[0\] ), .A2(n44), .ZN(n36) );
  aor22d1 U22 ( .A1(n47), .A2(\Return_Addr\[0\] ), .B1(n46), .B2(
        \Imm_Addr\[0\] ), .Z(n9) );
  aor211d1 U23 ( .C1(\PC\[0\] ), .C2(n37), .A(n36), .B(n9), .Z(n22) );
  inv0d0 U24 ( .I(\PC\[6\] ), .ZN(n23) );
  nd02d0 U25 ( .A1(n23), .A2(Incrmnt_PC), .ZN(n12) );
  nr02d0 U26 ( .A1(\PC\[5\] ), .A2(n44), .ZN(n10) );
  nr02d0 U27 ( .A1(n11), .A2(n10), .ZN(n27) );
  nd02d0 U28 ( .A1(n12), .A2(n27), .ZN(n26) );
  nd02d0 U29 ( .A1(\PC\[5\] ), .A2(n13), .ZN(n28) );
  nr03d0 U30 ( .A1(\PC\[7\] ), .A2(n23), .A3(n28), .ZN(n25) );
  aor22d1 U31 ( .A1(n47), .A2(\Return_Addr\[7\] ), .B1(n46), .B2(
        \Imm_Addr\[7\] ), .Z(n24) );
  aor211d1 U32 ( .C1(\PC\[7\] ), .C2(n26), .A(n25), .B(n24), .Z(n21) );
  nd02d0 U33 ( .A1(n47), .A2(\Return_Addr\[6\] ), .ZN(n31) );
  mx02d0 U34 ( .I0(n28), .I1(n27), .S(\PC\[6\] ), .Z(n30) );
  nd02d0 U35 ( .A1(n46), .A2(\Imm_Addr\[6\] ), .ZN(n29) );
  nd03d0 U36 ( .A1(n31), .A2(n30), .A3(n29), .ZN(n20) );
  nr03d0 U37 ( .A1(\PC\[3\] ), .A2(n32), .A3(n44), .ZN(n34) );
  aor22d1 U38 ( .A1(n47), .A2(\Return_Addr\[3\] ), .B1(n46), .B2(
        \Imm_Addr\[3\] ), .Z(n33) );
  aor211d1 U39 ( .C1(\PC\[3\] ), .C2(n35), .A(n34), .B(n33), .Z(n17) );
  nd02d0 U40 ( .A1(\Return_Addr\[2\] ), .A2(n47), .ZN(n42) );
  nr02d0 U41 ( .A1(n37), .A2(n36), .ZN(n43) );
  inv0d0 U42 ( .I(\PC\[2\] ), .ZN(n39) );
  aoim22d1 U43 ( .A1(n46), .A2(\Imm_Addr\[2\] ), .B1(n43), .B2(n39), .Z(n41)
         );
  nd02d0 U44 ( .A1(\PC\[0\] ), .A2(\PC\[1\] ), .ZN(n38) );
  aor221d1 U45 ( .B1(\PC\[2\] ), .B2(\PC\[1\] ), .C1(n39), .C2(n38), .A(n44), 
        .Z(n40) );
  nd03d0 U46 ( .A1(n42), .A2(n41), .A3(n40), .ZN(n16) );
  inv0d0 U47 ( .I(n43), .ZN(n50) );
  inv0d0 U48 ( .I(\PC\[0\] ), .ZN(n45) );
  nr03d0 U49 ( .A1(\PC\[1\] ), .A2(n45), .A3(n44), .ZN(n49) );
  aor22d1 U50 ( .A1(n47), .A2(\Return_Addr\[1\] ), .B1(n46), .B2(
        \Imm_Addr\[1\] ), .Z(n48) );
  aor211d1 U51 ( .C1(\PC\[1\] ), .C2(n50), .A(n49), .B(n48), .Z(n15) );
endmodule


module PRGRM_CNT_TOP ( Clk, INTERNAL_RESET, .Crnt_Instrn({\Crnt_Instrn\[31\] , 
        \Crnt_Instrn\[30\] , \Crnt_Instrn\[29\] , \Crnt_Instrn\[28\] , 
        \Crnt_Instrn\[27\] , \Crnt_Instrn\[26\] , \Crnt_Instrn\[25\] , 
        \Crnt_Instrn\[24\] , \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] , 
        \Crnt_Instrn\[21\] , \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] , 
        \Crnt_Instrn\[18\] , \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] , 
        \Crnt_Instrn\[15\] , \Crnt_Instrn\[14\] , \Crnt_Instrn\[13\] , 
        \Crnt_Instrn\[12\] , \Crnt_Instrn\[11\] , \Crnt_Instrn\[10\] , 
        \Crnt_Instrn\[9\] , \Crnt_Instrn\[8\] , \Crnt_Instrn\[7\] , 
        \Crnt_Instrn\[6\] , \Crnt_Instrn\[5\] , \Crnt_Instrn\[4\] , 
        \Crnt_Instrn\[3\] , \Crnt_Instrn\[2\] , \Crnt_Instrn\[1\] , 
        \Crnt_Instrn\[0\] }), Zro_Flag, Carry_Flag, Neg_Flag, .Return_Addr({
        \Return_Addr\[7\] , \Return_Addr\[6\] , \Return_Addr\[5\] , 
        \Return_Addr\[4\] , \Return_Addr\[3\] , \Return_Addr\[2\] , 
        \Return_Addr\[1\] , \Return_Addr\[0\] }), .Current_State({
        \Current_State\[2\] , \Current_State\[1\] , \Current_State\[0\] }), 
    .PC({\PC\[7\] , \PC\[6\] , \PC\[5\] , \PC\[4\] , \PC\[3\] , \PC\[2\] , 
        \PC\[1\] , \PC\[0\] }), test_se );
  input Clk, INTERNAL_RESET, \Crnt_Instrn\[31\] , \Crnt_Instrn\[30\] ,
         \Crnt_Instrn\[29\] , \Crnt_Instrn\[28\] , \Crnt_Instrn\[27\] ,
         \Crnt_Instrn\[26\] , \Crnt_Instrn\[25\] , \Crnt_Instrn\[24\] ,
         \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] , \Crnt_Instrn\[21\] ,
         \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] , \Crnt_Instrn\[18\] ,
         \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] , \Crnt_Instrn\[15\] ,
         \Crnt_Instrn\[14\] , \Crnt_Instrn\[13\] , \Crnt_Instrn\[12\] ,
         \Crnt_Instrn\[11\] , \Crnt_Instrn\[10\] , \Crnt_Instrn\[9\] ,
         \Crnt_Instrn\[8\] , \Crnt_Instrn\[7\] , \Crnt_Instrn\[6\] ,
         \Crnt_Instrn\[5\] , \Crnt_Instrn\[4\] , \Crnt_Instrn\[3\] ,
         \Crnt_Instrn\[2\] , \Crnt_Instrn\[1\] , \Crnt_Instrn\[0\] , Zro_Flag,
         Carry_Flag, Neg_Flag, \Return_Addr\[7\] , \Return_Addr\[6\] ,
         \Return_Addr\[5\] , \Return_Addr\[4\] , \Return_Addr\[3\] ,
         \Return_Addr\[2\] , \Return_Addr\[1\] , \Return_Addr\[0\] , test_se;
  output \Current_State\[2\] , \Current_State\[1\] , \Current_State\[0\] ,
         \PC\[7\] , \PC\[6\] , \PC\[5\] , \PC\[4\] , \PC\[3\] , \PC\[2\] ,
         \PC\[1\] , \PC\[0\] ;
  wire   Incrmnt_PC, Ld_Brnch_Addr, Ld_Rtn_Addr, n19;

  PRGRM_FSM I_PRGRM_FSM ( .Clk(Clk), .INTERNAL_RESET(n19), .CurrentState({
        \Current_State\[2\] , \Current_State\[1\] , \Current_State\[0\] }), 
        .test_si(\PC\[7\] ), .test_se(test_se) );
  PRGRM_DECODE I_PRGRM_DECODE ( .Zro_Flag(Zro_Flag), .Carry_Flag(1'b0), 
        .Neg_Flag(Neg_Flag), .CurrentState({\Current_State\[2\] , 
        \Current_State\[1\] , \Current_State\[0\] }), .Crnt_Instrn({
        \Crnt_Instrn\[31\] , \Crnt_Instrn\[30\] , \Crnt_Instrn\[29\] , 
        \Crnt_Instrn\[28\] , \Crnt_Instrn\[27\] , 1'b0, \Crnt_Instrn\[25\] , 
        1'b0, \Crnt_Instrn\[23\] , \Crnt_Instrn\[22\] , \Crnt_Instrn\[21\] , 
        \Crnt_Instrn\[20\] , \Crnt_Instrn\[19\] , \Crnt_Instrn\[18\] , 
        \Crnt_Instrn\[17\] , \Crnt_Instrn\[16\] , 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0}), 
        .Incrmnt_PC(Incrmnt_PC), .Ld_Brnch_Addr(Ld_Brnch_Addr), .Ld_Rtn_Addr(
        Ld_Rtn_Addr) );
  PRGRM_CNT I_PRGRM_CNT ( .INTERNAL_RESET(n19), .Clk(Clk), .Incrmnt_PC(
        Incrmnt_PC), .Ld_Brnch_Addr(Ld_Brnch_Addr), .Ld_Rtn_Addr(Ld_Rtn_Addr), 
        .Imm_Addr({\Crnt_Instrn\[7\] , \Crnt_Instrn\[6\] , \Crnt_Instrn\[5\] , 
        \Crnt_Instrn\[4\] , \Crnt_Instrn\[3\] , \Crnt_Instrn\[2\] , 
        \Crnt_Instrn\[1\] , \Crnt_Instrn\[0\] }), .Return_Addr({
        \Return_Addr\[7\] , \Return_Addr\[6\] , \Return_Addr\[5\] , 
        \Return_Addr\[4\] , \Return_Addr\[3\] , \Return_Addr\[2\] , 
        \Return_Addr\[1\] , \Return_Addr\[0\] }), .PC({\PC\[7\] , \PC\[6\] , 
        \PC\[5\] , \PC\[4\] , \PC\[3\] , \PC\[2\] , \PC\[1\] , \PC\[0\] }), 
        .test_si(\Crnt_Instrn\[31\] ), .test_se(test_se) );
  buffd1 U2 ( .I(INTERNAL_RESET), .Z(n19) );
endmodule


module REG_FILE ( INTERNAL_RESET, Clk, .Addr_A({\Addr_A\[6\] , \Addr_A\[5\] , 
        \Addr_A\[4\] , \Addr_A\[3\] , \Addr_A\[2\] , \Addr_A\[1\] , 
        \Addr_A\[0\] }), .Addr_B({\Addr_B\[6\] , \Addr_B\[5\] , \Addr_B\[4\] , 
        \Addr_B\[3\] , \Addr_B\[2\] , \Addr_B\[1\] , \Addr_B\[0\] }), 
    .Addr_C({\Addr_C\[6\] , \Addr_C\[5\] , \Addr_C\[4\] , \Addr_C\[3\] , 
        \Addr_C\[2\] , \Addr_C\[1\] , \Addr_C\[0\] }), .RegPort_C({
        \RegPort_C\[15\] , \RegPort_C\[14\] , \RegPort_C\[13\] , 
        \RegPort_C\[12\] , \RegPort_C\[11\] , \RegPort_C\[10\] , 
        \RegPort_C\[9\] , \RegPort_C\[8\] , \RegPort_C\[7\] , \RegPort_C\[6\] , 
        \RegPort_C\[5\] , \RegPort_C\[4\] , \RegPort_C\[3\] , \RegPort_C\[2\] , 
        \RegPort_C\[1\] , \RegPort_C\[0\] }), Write_RegC, .RegPort_A({
        \RegPort_A\[15\] , \RegPort_A\[14\] , \RegPort_A\[13\] , 
        \RegPort_A\[12\] , \RegPort_A\[11\] , \RegPort_A\[10\] , 
        \RegPort_A\[9\] , \RegPort_A\[8\] , \RegPort_A\[7\] , \RegPort_A\[6\] , 
        \RegPort_A\[5\] , \RegPort_A\[4\] , \RegPort_A\[3\] , \RegPort_A\[2\] , 
        \RegPort_A\[1\] , \RegPort_A\[0\] }), .RegPort_B({\RegPort_B\[15\] , 
        \RegPort_B\[14\] , \RegPort_B\[13\] , \RegPort_B\[12\] , 
        \RegPort_B\[11\] , \RegPort_B\[10\] , \RegPort_B\[9\] , 
        \RegPort_B\[8\] , \RegPort_B\[7\] , \RegPort_B\[6\] , \RegPort_B\[5\] , 
        \RegPort_B\[4\] , \RegPort_B\[3\] , \RegPort_B\[2\] , \RegPort_B\[1\] , 
        \RegPort_B\[0\] }), RISC_CORE_test_point_375_in, test_si, test_so, 
        test_se );
  input INTERNAL_RESET, Clk, \Addr_A\[6\] , \Addr_A\[5\] , \Addr_A\[4\] ,
         \Addr_A\[3\] , \Addr_A\[2\] , \Addr_A\[1\] , \Addr_A\[0\] ,
         \Addr_B\[6\] , \Addr_B\[5\] , \Addr_B\[4\] , \Addr_B\[3\] ,
         \Addr_B\[2\] , \Addr_B\[1\] , \Addr_B\[0\] , \Addr_C\[6\] ,
         \Addr_C\[5\] , \Addr_C\[4\] , \Addr_C\[3\] , \Addr_C\[2\] ,
         \Addr_C\[1\] , \Addr_C\[0\] , \RegPort_C\[15\] , \RegPort_C\[14\] ,
         \RegPort_C\[13\] , \RegPort_C\[12\] , \RegPort_C\[11\] ,
         \RegPort_C\[10\] , \RegPort_C\[9\] , \RegPort_C\[8\] ,
         \RegPort_C\[7\] , \RegPort_C\[6\] , \RegPort_C\[5\] ,
         \RegPort_C\[4\] , \RegPort_C\[3\] , \RegPort_C\[2\] ,
         \RegPort_C\[1\] , \RegPort_C\[0\] , Write_RegC,
         RISC_CORE_test_point_375_in, test_si, test_se;
  output \RegPort_A\[15\] , \RegPort_A\[14\] , \RegPort_A\[13\] ,
         \RegPort_A\[12\] , \RegPort_A\[11\] , \RegPort_A\[10\] ,
         \RegPort_A\[9\] , \RegPort_A\[8\] , \RegPort_A\[7\] ,
         \RegPort_A\[6\] , \RegPort_A\[5\] , \RegPort_A\[4\] ,
         \RegPort_A\[3\] , \RegPort_A\[2\] , \RegPort_A\[1\] ,
         \RegPort_A\[0\] , \RegPort_B\[15\] , \RegPort_B\[14\] ,
         \RegPort_B\[13\] , \RegPort_B\[12\] , \RegPort_B\[11\] ,
         \RegPort_B\[10\] , \RegPort_B\[9\] , \RegPort_B\[8\] ,
         \RegPort_B\[7\] , \RegPort_B\[6\] , \RegPort_B\[5\] ,
         \RegPort_B\[4\] , \RegPort_B\[3\] , \RegPort_B\[2\] ,
         \RegPort_B\[1\] , \RegPort_B\[0\] , test_so;
  wire   \Reg_Array\[0\]\[15\] , \Reg_Array\[0\]\[14\] ,
         \Reg_Array\[0\]\[13\] , \Reg_Array\[0\]\[12\] ,
         \Reg_Array\[0\]\[11\] , \Reg_Array\[0\]\[10\] , \Reg_Array\[0\]\[9\] ,
         \Reg_Array\[0\]\[8\] , \Reg_Array\[0\]\[7\] , \Reg_Array\[0\]\[6\] ,
         \Reg_Array\[0\]\[5\] , \Reg_Array\[0\]\[4\] , \Reg_Array\[0\]\[3\] ,
         \Reg_Array\[0\]\[2\] , \Reg_Array\[0\]\[1\] , \Reg_Array\[0\]\[0\] ,
         \Reg_Array\[1\]\[15\] , \Reg_Array\[1\]\[14\] ,
         \Reg_Array\[1\]\[13\] , \Reg_Array\[1\]\[12\] ,
         \Reg_Array\[1\]\[11\] , \Reg_Array\[1\]\[10\] , \Reg_Array\[1\]\[9\] ,
         \Reg_Array\[1\]\[8\] , \Reg_Array\[1\]\[7\] , \Reg_Array\[1\]\[6\] ,
         \Reg_Array\[1\]\[5\] , \Reg_Array\[1\]\[4\] , \Reg_Array\[1\]\[3\] ,
         \Reg_Array\[1\]\[2\] , \Reg_Array\[1\]\[1\] , \Reg_Array\[1\]\[0\] ,
         \Reg_Array\[2\]\[15\] , \Reg_Array\[2\]\[14\] ,
         \Reg_Array\[2\]\[13\] , \Reg_Array\[2\]\[12\] ,
         \Reg_Array\[2\]\[11\] , \Reg_Array\[2\]\[10\] , \Reg_Array\[2\]\[9\] ,
         \Reg_Array\[2\]\[8\] , \Reg_Array\[2\]\[7\] , \Reg_Array\[2\]\[6\] ,
         \Reg_Array\[2\]\[5\] , \Reg_Array\[2\]\[4\] , \Reg_Array\[2\]\[3\] ,
         \Reg_Array\[2\]\[2\] , \Reg_Array\[2\]\[1\] , \Reg_Array\[2\]\[0\] ,
         \Reg_Array\[3\]\[15\] , \Reg_Array\[3\]\[14\] ,
         \Reg_Array\[3\]\[13\] , \Reg_Array\[3\]\[12\] ,
         \Reg_Array\[3\]\[11\] , \Reg_Array\[3\]\[10\] , \Reg_Array\[3\]\[9\] ,
         \Reg_Array\[3\]\[8\] , \Reg_Array\[3\]\[7\] , \Reg_Array\[3\]\[6\] ,
         \Reg_Array\[3\]\[5\] , \Reg_Array\[3\]\[4\] , \Reg_Array\[3\]\[3\] ,
         \Reg_Array\[3\]\[2\] , \Reg_Array\[3\]\[1\] , \Reg_Array\[3\]\[0\] ,
         n136, n137, n138, n139, n140, n141, n142, n143, n144, n145, n146,
         n147, n148, n149, n150, n151, n152, n153, n154, n155, n156, n157,
         n158, n159, n160, n161, n162, n163, n164, n165, n166, n167, n168,
         n169, n170, n171, n172, n173, n174, n175, n176, n177, n178, n179,
         n180, n181, n182, n183, n184, n185, n186, n187, n188, n189, n190,
         n191, n192, n193, n194, n195, n196, n197, n198, n199, n1, n2, n3, n4,
         n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17;
  assign test_so = \Reg_Array\[3\]\[15\] ;

  sdcrq1 \Reg_Array_reg\[0\]\[15\]  ( .D(n199), .SD(\Reg_Array\[0\]\[14\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[15\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[14\]  ( .D(n198), .SD(\Reg_Array\[0\]\[13\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[14\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[13\]  ( .D(n197), .SD(\Reg_Array\[0\]\[12\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[13\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[12\]  ( .D(n196), .SD(\Reg_Array\[0\]\[11\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[12\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[11\]  ( .D(n195), .SD(\Reg_Array\[0\]\[10\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[11\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[10\]  ( .D(n194), .SD(\Reg_Array\[0\]\[9\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[10\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[9\]  ( .D(n193), .SD(\Reg_Array\[0\]\[8\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[9\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[8\]  ( .D(n192), .SD(\Reg_Array\[0\]\[7\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[8\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[7\]  ( .D(n191), .SD(\Reg_Array\[0\]\[6\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[7\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[6\]  ( .D(n190), .SD(\Reg_Array\[0\]\[5\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[6\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[5\]  ( .D(n189), .SD(\Reg_Array\[0\]\[4\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[5\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[4\]  ( .D(n188), .SD(\Reg_Array\[0\]\[3\] ), 
        .SC(test_se), .CP(n17), .CDN(n10), .Q(\Reg_Array\[0\]\[4\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[3\]  ( .D(n187), .SD(\Reg_Array\[0\]\[2\] ), 
        .SC(test_se), .CP(n17), .CDN(n11), .Q(\Reg_Array\[0\]\[3\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[2\]  ( .D(n186), .SD(\Reg_Array\[0\]\[1\] ), 
        .SC(test_se), .CP(n17), .CDN(n11), .Q(\Reg_Array\[0\]\[2\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[1\]  ( .D(n185), .SD(\Reg_Array\[0\]\[0\] ), 
        .SC(test_se), .CP(n17), .CDN(n11), .Q(\Reg_Array\[0\]\[1\] ) );
  sdcrq1 \Reg_Array_reg\[0\]\[0\]  ( .D(n184), .SD(test_si), .SC(test_se), 
        .CP(n17), .CDN(n11), .Q(\Reg_Array\[0\]\[0\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[15\]  ( .D(n183), .SD(\Reg_Array\[1\]\[14\] ), 
        .SC(test_se), .CP(n17), .CDN(n11), .Q(\Reg_Array\[1\]\[15\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[14\]  ( .D(n182), .SD(\Reg_Array\[1\]\[13\] ), 
        .SC(test_se), .CP(n17), .CDN(n11), .Q(\Reg_Array\[1\]\[14\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[13\]  ( .D(n181), .SD(\Reg_Array\[1\]\[12\] ), 
        .SC(test_se), .CP(n17), .CDN(n11), .Q(\Reg_Array\[1\]\[13\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[12\]  ( .D(n180), .SD(\Reg_Array\[1\]\[11\] ), 
        .SC(test_se), .CP(n17), .CDN(n11), .Q(\Reg_Array\[1\]\[12\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[11\]  ( .D(n179), .SD(\Reg_Array\[1\]\[10\] ), 
        .SC(test_se), .CP(n16), .CDN(n11), .Q(\Reg_Array\[1\]\[11\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[10\]  ( .D(n178), .SD(\Reg_Array\[1\]\[9\] ), 
        .SC(test_se), .CP(n16), .CDN(n11), .Q(\Reg_Array\[1\]\[10\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[9\]  ( .D(n177), .SD(\Reg_Array\[1\]\[8\] ), 
        .SC(test_se), .CP(n16), .CDN(n11), .Q(\Reg_Array\[1\]\[9\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[8\]  ( .D(n176), .SD(\Reg_Array\[1\]\[7\] ), 
        .SC(test_se), .CP(n16), .CDN(n11), .Q(\Reg_Array\[1\]\[8\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[7\]  ( .D(n175), .SD(\Reg_Array\[1\]\[6\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[7\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[6\]  ( .D(n174), .SD(\Reg_Array\[1\]\[5\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[6\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[5\]  ( .D(n173), .SD(\Reg_Array\[1\]\[4\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[5\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[4\]  ( .D(n172), .SD(\Reg_Array\[1\]\[3\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[4\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[3\]  ( .D(n171), .SD(\Reg_Array\[1\]\[2\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[3\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[2\]  ( .D(n170), .SD(\Reg_Array\[1\]\[1\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[2\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[1\]  ( .D(n169), .SD(\Reg_Array\[1\]\[0\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[1\] ) );
  sdcrq1 \Reg_Array_reg\[1\]\[0\]  ( .D(n168), .SD(\Reg_Array\[0\]\[15\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[1\]\[0\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[15\]  ( .D(n167), .SD(\Reg_Array\[2\]\[14\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[2\]\[15\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[14\]  ( .D(n166), .SD(\Reg_Array\[2\]\[13\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[2\]\[14\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[13\]  ( .D(n165), .SD(\Reg_Array\[2\]\[12\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[2\]\[13\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[12\]  ( .D(n164), .SD(\Reg_Array\[2\]\[11\] ), 
        .SC(test_se), .CP(n16), .CDN(n12), .Q(\Reg_Array\[2\]\[12\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[11\]  ( .D(n163), .SD(\Reg_Array\[2\]\[10\] ), 
        .SC(test_se), .CP(n16), .CDN(n13), .Q(\Reg_Array\[2\]\[11\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[10\]  ( .D(n162), .SD(\Reg_Array\[2\]\[9\] ), 
        .SC(test_se), .CP(n16), .CDN(n13), .Q(\Reg_Array\[2\]\[10\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[9\]  ( .D(n161), .SD(\Reg_Array\[2\]\[8\] ), 
        .SC(test_se), .CP(n16), .CDN(n13), .Q(\Reg_Array\[2\]\[9\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[8\]  ( .D(n160), .SD(\Reg_Array\[2\]\[7\] ), 
        .SC(test_se), .CP(n16), .CDN(n13), .Q(\Reg_Array\[2\]\[8\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[7\]  ( .D(n159), .SD(\Reg_Array\[2\]\[6\] ), 
        .SC(test_se), .CP(n16), .CDN(n13), .Q(\Reg_Array\[2\]\[7\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[6\]  ( .D(n158), .SD(\Reg_Array\[2\]\[5\] ), 
        .SC(test_se), .CP(n16), .CDN(n13), .Q(\Reg_Array\[2\]\[6\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[5\]  ( .D(n157), .SD(\Reg_Array\[2\]\[4\] ), 
        .SC(test_se), .CP(n15), .CDN(n13), .Q(\Reg_Array\[2\]\[5\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[4\]  ( .D(n156), .SD(\Reg_Array\[2\]\[3\] ), 
        .SC(test_se), .CP(n15), .CDN(n13), .Q(\Reg_Array\[2\]\[4\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[3\]  ( .D(n155), .SD(\Reg_Array\[2\]\[2\] ), 
        .SC(test_se), .CP(n15), .CDN(n13), .Q(\Reg_Array\[2\]\[3\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[2\]  ( .D(n154), .SD(\Reg_Array\[2\]\[1\] ), 
        .SC(test_se), .CP(n15), .CDN(n13), .Q(\Reg_Array\[2\]\[2\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[1\]  ( .D(n153), .SD(\Reg_Array\[2\]\[0\] ), 
        .SC(test_se), .CP(n15), .CDN(n13), .Q(\Reg_Array\[2\]\[1\] ) );
  sdcrq1 \Reg_Array_reg\[2\]\[0\]  ( .D(n152), .SD(\Reg_Array\[1\]\[15\] ), 
        .SC(test_se), .CP(n15), .CDN(n13), .Q(\Reg_Array\[2\]\[0\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[15\]  ( .D(n151), .SD(\Reg_Array\[3\]\[14\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[15\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[14\]  ( .D(n150), .SD(\Reg_Array\[3\]\[13\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[14\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[13\]  ( .D(n149), .SD(\Reg_Array\[3\]\[12\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[13\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[12\]  ( .D(n148), .SD(\Reg_Array\[3\]\[11\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[12\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[11\]  ( .D(n147), .SD(\Reg_Array\[3\]\[10\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[11\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[10\]  ( .D(n146), .SD(\Reg_Array\[3\]\[9\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[10\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[9\]  ( .D(n145), .SD(\Reg_Array\[3\]\[8\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[9\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[8\]  ( .D(n144), .SD(\Reg_Array\[3\]\[7\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[8\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[7\]  ( .D(n143), .SD(\Reg_Array\[3\]\[6\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[7\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[6\]  ( .D(n142), .SD(\Reg_Array\[3\]\[5\] ), 
        .SC(test_se), .CP(n15), .CDN(n10), .Q(\Reg_Array\[3\]\[6\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[5\]  ( .D(n141), .SD(\Reg_Array\[3\]\[4\] ), 
        .SC(test_se), .CP(n15), .CDN(n11), .Q(\Reg_Array\[3\]\[5\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[4\]  ( .D(n140), .SD(\Reg_Array\[3\]\[3\] ), 
        .SC(test_se), .CP(n15), .CDN(n12), .Q(\Reg_Array\[3\]\[4\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[3\]  ( .D(n139), .SD(\Reg_Array\[3\]\[2\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[3\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[2\]  ( .D(n138), .SD(\Reg_Array\[3\]\[1\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[2\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[1\]  ( .D(n137), .SD(\Reg_Array\[3\]\[0\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[1\] ) );
  sdcrq1 \Reg_Array_reg\[3\]\[0\]  ( .D(n136), .SD(\Reg_Array\[2\]\[15\] ), 
        .SC(test_se), .CP(n15), .CDN(n14), .Q(\Reg_Array\[3\]\[0\] ) );
  nd03d1 U2 ( .A1(Write_RegC), .A2(\Addr_C\[1\] ), .A3(n6), .ZN(n7) );
  inv0d0 U3 ( .I(Write_RegC), .ZN(n2) );
  nr03d1 U4 ( .A1(\Addr_C\[1\] ), .A2(\Addr_C\[0\] ), .A3(n2), .ZN(n1) );
  mx02d0 U5 ( .I0(\Reg_Array\[0\]\[15\] ), .I1(\RegPort_C\[15\] ), .S(n1), .Z(
        n199) );
  mx02d0 U6 ( .I0(\Reg_Array\[0\]\[14\] ), .I1(\RegPort_C\[14\] ), .S(n1), .Z(
        n198) );
  mx02d0 U7 ( .I0(\Reg_Array\[0\]\[13\] ), .I1(\RegPort_C\[13\] ), .S(n1), .Z(
        n197) );
  mx02d0 U8 ( .I0(\Reg_Array\[0\]\[12\] ), .I1(\RegPort_C\[12\] ), .S(n1), .Z(
        n196) );
  mx02d0 U9 ( .I0(\Reg_Array\[0\]\[11\] ), .I1(\RegPort_C\[11\] ), .S(n1), .Z(
        n195) );
  mx02d0 U10 ( .I0(\Reg_Array\[0\]\[10\] ), .I1(\RegPort_C\[10\] ), .S(n1), 
        .Z(n194) );
  mx02d0 U11 ( .I0(\Reg_Array\[0\]\[9\] ), .I1(\RegPort_C\[9\] ), .S(n1), .Z(
        n193) );
  mx02d0 U12 ( .I0(\Reg_Array\[0\]\[8\] ), .I1(\RegPort_C\[8\] ), .S(n1), .Z(
        n192) );
  mx02d0 U13 ( .I0(\Reg_Array\[0\]\[7\] ), .I1(\RegPort_C\[7\] ), .S(n1), .Z(
        n191) );
  mx02d0 U14 ( .I0(\Reg_Array\[0\]\[6\] ), .I1(\RegPort_C\[6\] ), .S(n1), .Z(
        n190) );
  mx02d0 U15 ( .I0(\Reg_Array\[0\]\[5\] ), .I1(\RegPort_C\[5\] ), .S(n1), .Z(
        n189) );
  mx02d0 U16 ( .I0(\Reg_Array\[0\]\[4\] ), .I1(\RegPort_C\[4\] ), .S(n1), .Z(
        n188) );
  mx02d0 U17 ( .I0(\Reg_Array\[0\]\[3\] ), .I1(\RegPort_C\[3\] ), .S(n1), .Z(
        n187) );
  mx02d0 U18 ( .I0(\Reg_Array\[0\]\[2\] ), .I1(\RegPort_C\[2\] ), .S(n1), .Z(
        n186) );
  mx02d0 U19 ( .I0(\Reg_Array\[0\]\[1\] ), .I1(\RegPort_C\[1\] ), .S(n1), .Z(
        n185) );
  mx02d0 U20 ( .I0(\Reg_Array\[0\]\[0\] ), .I1(\RegPort_C\[0\] ), .S(n1), .Z(
        n184) );
  inv0d0 U21 ( .I(\Addr_C\[0\] ), .ZN(n6) );
  nr03d1 U22 ( .A1(\Addr_C\[1\] ), .A2(n2), .A3(n6), .ZN(n3) );
  mx02d0 U23 ( .I0(\Reg_Array\[1\]\[15\] ), .I1(\RegPort_C\[15\] ), .S(n3), 
        .Z(n183) );
  mx02d0 U24 ( .I0(\Reg_Array\[1\]\[14\] ), .I1(\RegPort_C\[14\] ), .S(n3), 
        .Z(n182) );
  mx02d0 U25 ( .I0(\Reg_Array\[1\]\[13\] ), .I1(\RegPort_C\[13\] ), .S(n3), 
        .Z(n181) );
  mx02d0 U26 ( .I0(\Reg_Array\[1\]\[12\] ), .I1(\RegPort_C\[12\] ), .S(n3), 
        .Z(n180) );
  mx02d0 U27 ( .I0(\Reg_Array\[1\]\[11\] ), .I1(\RegPort_C\[11\] ), .S(n3), 
        .Z(n179) );
  mx02d0 U28 ( .I0(\Reg_Array\[1\]\[10\] ), .I1(\RegPort_C\[10\] ), .S(n3), 
        .Z(n178) );
  mx02d0 U29 ( .I0(\Reg_Array\[1\]\[9\] ), .I1(\RegPort_C\[9\] ), .S(n3), .Z(
        n177) );
  mx02d0 U30 ( .I0(\Reg_Array\[1\]\[8\] ), .I1(\RegPort_C\[8\] ), .S(n3), .Z(
        n176) );
  mx02d0 U31 ( .I0(\Reg_Array\[1\]\[7\] ), .I1(\RegPort_C\[7\] ), .S(n3), .Z(
        n175) );
  mx02d0 U32 ( .I0(\Reg_Array\[1\]\[0\] ), .I1(\RegPort_C\[0\] ), .S(n3), .Z(
        n168) );
  mx02d0 U33 ( .I0(\Reg_Array\[1\]\[6\] ), .I1(\RegPort_C\[6\] ), .S(n3), .Z(
        n174) );
  mx02d0 U34 ( .I0(\Reg_Array\[1\]\[1\] ), .I1(\RegPort_C\[1\] ), .S(n3), .Z(
        n169) );
  mx02d0 U35 ( .I0(\Reg_Array\[1\]\[5\] ), .I1(\RegPort_C\[5\] ), .S(n3), .Z(
        n173) );
  mx02d0 U36 ( .I0(\Reg_Array\[1\]\[2\] ), .I1(\RegPort_C\[2\] ), .S(n3), .Z(
        n170) );
  mx02d0 U37 ( .I0(\Reg_Array\[1\]\[4\] ), .I1(\RegPort_C\[4\] ), .S(n3), .Z(
        n172) );
  mx02d0 U38 ( .I0(\Reg_Array\[1\]\[3\] ), .I1(\RegPort_C\[3\] ), .S(n3), .Z(
        n171) );
  inv0d0 U39 ( .I(RISC_CORE_test_point_375_in), .ZN(n4) );
  inv0d1 U40 ( .I(n4), .ZN(n17) );
  inv0d1 U41 ( .I(n4), .ZN(n15) );
  inv0d1 U42 ( .I(n4), .ZN(n16) );
  inv0d0 U43 ( .I(INTERNAL_RESET), .ZN(n5) );
  inv0d0 U44 ( .I(n5), .ZN(n14) );
  inv0d0 U45 ( .I(n5), .ZN(n10) );
  inv0d0 U46 ( .I(n5), .ZN(n13) );
  inv0d0 U47 ( .I(n5), .ZN(n11) );
  inv0d0 U48 ( .I(n5), .ZN(n12) );
  nd03d1 U49 ( .A1(\Addr_C\[1\] ), .A2(Write_RegC), .A3(\Addr_C\[0\] ), .ZN(n8) );
  mx02d0 U50 ( .I0(\RegPort_C\[0\] ), .I1(\Reg_Array\[3\]\[0\] ), .S(n8), .Z(
        n136) );
  mx02d0 U51 ( .I0(\RegPort_C\[1\] ), .I1(\Reg_Array\[3\]\[1\] ), .S(n8), .Z(
        n137) );
  mx02d0 U52 ( .I0(\RegPort_C\[2\] ), .I1(\Reg_Array\[3\]\[2\] ), .S(n8), .Z(
        n138) );
  mx02d0 U53 ( .I0(\RegPort_C\[3\] ), .I1(\Reg_Array\[3\]\[3\] ), .S(n8), .Z(
        n139) );
  mx02d0 U54 ( .I0(\RegPort_C\[4\] ), .I1(\Reg_Array\[3\]\[4\] ), .S(n8), .Z(
        n140) );
  mx02d0 U55 ( .I0(\RegPort_C\[5\] ), .I1(\Reg_Array\[3\]\[5\] ), .S(n8), .Z(
        n141) );
  mx02d0 U56 ( .I0(\RegPort_C\[6\] ), .I1(\Reg_Array\[3\]\[6\] ), .S(n8), .Z(
        n142) );
  mx02d0 U57 ( .I0(\RegPort_C\[7\] ), .I1(\Reg_Array\[3\]\[7\] ), .S(n8), .Z(
        n143) );
  mx02d0 U58 ( .I0(\RegPort_C\[9\] ), .I1(\Reg_Array\[3\]\[9\] ), .S(n8), .Z(
        n145) );
  mx02d0 U59 ( .I0(\RegPort_C\[10\] ), .I1(\Reg_Array\[3\]\[10\] ), .S(n8), 
        .Z(n146) );
  mx02d0 U60 ( .I0(\RegPort_C\[11\] ), .I1(\Reg_Array\[3\]\[11\] ), .S(n8), 
        .Z(n147) );
  mx02d0 U61 ( .I0(\RegPort_C\[12\] ), .I1(\Reg_Array\[3\]\[12\] ), .S(n8), 
        .Z(n148) );
  mx02d0 U62 ( .I0(\RegPort_C\[13\] ), .I1(\Reg_Array\[3\]\[13\] ), .S(n8), 
        .Z(n149) );
  mx02d0 U63 ( .I0(\RegPort_C\[14\] ), .I1(\Reg_Array\[3\]\[14\] ), .S(n8), 
        .Z(n150) );
  mx02d0 U64 ( .I0(\RegPort_C\[15\] ), .I1(\Reg_Array\[3\]\[15\] ), .S(n8), 
        .Z(n151) );
  mx02d0 U65 ( .I0(\RegPort_C\[0\] ), .I1(\Reg_Array\[2\]\[0\] ), .S(n7), .Z(
        n152) );
  mx02d0 U66 ( .I0(\RegPort_C\[1\] ), .I1(\Reg_Array\[2\]\[1\] ), .S(n7), .Z(
        n153) );
  mx02d0 U67 ( .I0(\RegPort_C\[2\] ), .I1(\Reg_Array\[2\]\[2\] ), .S(n7), .Z(
        n154) );
  mx02d0 U68 ( .I0(\RegPort_C\[3\] ), .I1(\Reg_Array\[2\]\[3\] ), .S(n7), .Z(
        n155) );
  mx02d0 U69 ( .I0(\RegPort_C\[4\] ), .I1(\Reg_Array\[2\]\[4\] ), .S(n7), .Z(
        n156) );
  mx02d0 U70 ( .I0(\RegPort_C\[5\] ), .I1(\Reg_Array\[2\]\[5\] ), .S(n7), .Z(
        n157) );
  mx02d0 U71 ( .I0(\RegPort_C\[6\] ), .I1(\Reg_Array\[2\]\[6\] ), .S(n7), .Z(
        n158) );
  mx02d0 U72 ( .I0(\RegPort_C\[7\] ), .I1(\Reg_Array\[2\]\[7\] ), .S(n7), .Z(
        n159) );
  mx02d0 U73 ( .I0(\RegPort_C\[8\] ), .I1(\Reg_Array\[2\]\[8\] ), .S(n7), .Z(
        n160) );
  mx02d0 U74 ( .I0(\RegPort_C\[9\] ), .I1(\Reg_Array\[2\]\[9\] ), .S(n7), .Z(
        n161) );
  mx02d0 U75 ( .I0(\RegPort_C\[10\] ), .I1(\Reg_Array\[2\]\[10\] ), .S(n7), 
        .Z(n162) );
  mx02d0 U76 ( .I0(\RegPort_C\[11\] ), .I1(\Reg_Array\[2\]\[11\] ), .S(n7), 
        .Z(n163) );
  mx02d0 U77 ( .I0(\RegPort_C\[12\] ), .I1(\Reg_Array\[2\]\[12\] ), .S(n7), 
        .Z(n164) );
  mx02d0 U78 ( .I0(\RegPort_C\[13\] ), .I1(\Reg_Array\[2\]\[13\] ), .S(n7), 
        .Z(n165) );
  mx02d0 U79 ( .I0(\RegPort_C\[14\] ), .I1(\Reg_Array\[2\]\[14\] ), .S(n7), 
        .Z(n166) );
  mx02d0 U80 ( .I0(\RegPort_C\[15\] ), .I1(\Reg_Array\[2\]\[15\] ), .S(n7), 
        .Z(n167) );
  mx02d0 U81 ( .I0(\RegPort_C\[8\] ), .I1(\Reg_Array\[3\]\[8\] ), .S(n8), .Z(
        n144) );
  buffd1 U82 ( .I(\Addr_B\[0\] ), .Z(n9) );
  mx04d0 U83 ( .I0(\Reg_Array\[0\]\[10\] ), .I1(\Reg_Array\[2\]\[10\] ), .I2(
        \Reg_Array\[1\]\[10\] ), .I3(\Reg_Array\[3\]\[10\] ), .S0(
        \Addr_B\[1\] ), .S1(n9), .Z(\RegPort_B\[10\] ) );
  mx04d0 U84 ( .I0(\Reg_Array\[0\]\[14\] ), .I1(\Reg_Array\[2\]\[14\] ), .I2(
        \Reg_Array\[1\]\[14\] ), .I3(\Reg_Array\[3\]\[14\] ), .S0(
        \Addr_B\[1\] ), .S1(n9), .Z(\RegPort_B\[14\] ) );
  mx04d0 U85 ( .I0(\Reg_Array\[0\]\[9\] ), .I1(\Reg_Array\[2\]\[9\] ), .I2(
        \Reg_Array\[1\]\[9\] ), .I3(\Reg_Array\[3\]\[9\] ), .S0(\Addr_B\[1\] ), 
        .S1(n9), .Z(\RegPort_B\[9\] ) );
  mx04d0 U86 ( .I0(\Reg_Array\[0\]\[15\] ), .I1(\Reg_Array\[2\]\[15\] ), .I2(
        \Reg_Array\[1\]\[15\] ), .I3(\Reg_Array\[3\]\[15\] ), .S0(
        \Addr_B\[1\] ), .S1(n9), .Z(\RegPort_B\[15\] ) );
  mx04d0 U87 ( .I0(\Reg_Array\[0\]\[7\] ), .I1(\Reg_Array\[2\]\[7\] ), .I2(
        \Reg_Array\[1\]\[7\] ), .I3(\Reg_Array\[3\]\[7\] ), .S0(\Addr_B\[1\] ), 
        .S1(n9), .Z(\RegPort_B\[7\] ) );
  mx04d0 U88 ( .I0(\Reg_Array\[0\]\[2\] ), .I1(\Reg_Array\[2\]\[2\] ), .I2(
        \Reg_Array\[1\]\[2\] ), .I3(\Reg_Array\[3\]\[2\] ), .S0(\Addr_B\[1\] ), 
        .S1(\Addr_B\[0\] ), .Z(\RegPort_B\[2\] ) );
  mx04d0 U89 ( .I0(\Reg_Array\[0\]\[0\] ), .I1(\Reg_Array\[2\]\[0\] ), .I2(
        \Reg_Array\[1\]\[0\] ), .I3(\Reg_Array\[3\]\[0\] ), .S0(\Addr_B\[1\] ), 
        .S1(\Addr_B\[0\] ), .Z(\RegPort_B\[0\] ) );
  mx04d0 U90 ( .I0(\Reg_Array\[0\]\[13\] ), .I1(\Reg_Array\[2\]\[13\] ), .I2(
        \Reg_Array\[1\]\[13\] ), .I3(\Reg_Array\[3\]\[13\] ), .S0(
        \Addr_B\[1\] ), .S1(n9), .Z(\RegPort_B\[13\] ) );
  mx04d0 U91 ( .I0(\Reg_Array\[0\]\[12\] ), .I1(\Reg_Array\[2\]\[12\] ), .I2(
        \Reg_Array\[1\]\[12\] ), .I3(\Reg_Array\[3\]\[12\] ), .S0(
        \Addr_B\[1\] ), .S1(\Addr_B\[0\] ), .Z(\RegPort_B\[12\] ) );
  mx04d0 U92 ( .I0(\Reg_Array\[0\]\[11\] ), .I1(\Reg_Array\[2\]\[11\] ), .I2(
        \Reg_Array\[1\]\[11\] ), .I3(\Reg_Array\[3\]\[11\] ), .S0(
        \Addr_B\[1\] ), .S1(n9), .Z(\RegPort_B\[11\] ) );
  mx04d0 U93 ( .I0(\Reg_Array\[0\]\[4\] ), .I1(\Reg_Array\[2\]\[4\] ), .I2(
        \Reg_Array\[1\]\[4\] ), .I3(\Reg_Array\[3\]\[4\] ), .S0(\Addr_B\[1\] ), 
        .S1(\Addr_B\[0\] ), .Z(\RegPort_B\[4\] ) );
  mx04d0 U94 ( .I0(\Reg_Array\[0\]\[6\] ), .I1(\Reg_Array\[2\]\[6\] ), .I2(
        \Reg_Array\[1\]\[6\] ), .I3(\Reg_Array\[3\]\[6\] ), .S0(\Addr_B\[1\] ), 
        .S1(\Addr_B\[0\] ), .Z(\RegPort_B\[6\] ) );
  mx04d0 U95 ( .I0(\Reg_Array\[0\]\[8\] ), .I1(\Reg_Array\[2\]\[8\] ), .I2(
        \Reg_Array\[1\]\[8\] ), .I3(\Reg_Array\[3\]\[8\] ), .S0(\Addr_B\[1\] ), 
        .S1(\Addr_B\[0\] ), .Z(\RegPort_B\[8\] ) );
  mx04d0 U96 ( .I0(\Reg_Array\[0\]\[3\] ), .I1(\Reg_Array\[2\]\[3\] ), .I2(
        \Reg_Array\[1\]\[3\] ), .I3(\Reg_Array\[3\]\[3\] ), .S0(\Addr_B\[1\] ), 
        .S1(n9), .Z(\RegPort_B\[3\] ) );
  mx04d0 U97 ( .I0(\Reg_Array\[0\]\[5\] ), .I1(\Reg_Array\[2\]\[5\] ), .I2(
        \Reg_Array\[1\]\[5\] ), .I3(\Reg_Array\[3\]\[5\] ), .S0(\Addr_B\[1\] ), 
        .S1(n9), .Z(\RegPort_B\[5\] ) );
  mx04d0 U98 ( .I0(\Reg_Array\[0\]\[1\] ), .I1(\Reg_Array\[2\]\[1\] ), .I2(
        \Reg_Array\[1\]\[1\] ), .I3(\Reg_Array\[3\]\[1\] ), .S0(\Addr_B\[1\] ), 
        .S1(n9), .Z(\RegPort_B\[1\] ) );
  mx04d0 U99 ( .I0(\Reg_Array\[0\]\[0\] ), .I1(\Reg_Array\[1\]\[0\] ), .I2(
        \Reg_Array\[2\]\[0\] ), .I3(\Reg_Array\[3\]\[0\] ), .S0(\Addr_A\[0\] ), 
        .S1(\Addr_A\[1\] ), .Z(\RegPort_A\[0\] ) );
  mx04d0 U100 ( .I0(\Reg_Array\[0\]\[2\] ), .I1(\Reg_Array\[2\]\[2\] ), .I2(
        \Reg_Array\[1\]\[2\] ), .I3(\Reg_Array\[3\]\[2\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[2\] ) );
  mx04d0 U101 ( .I0(\Reg_Array\[0\]\[3\] ), .I1(\Reg_Array\[2\]\[3\] ), .I2(
        \Reg_Array\[1\]\[3\] ), .I3(\Reg_Array\[3\]\[3\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[3\] ) );
  mx04d0 U102 ( .I0(\Reg_Array\[0\]\[4\] ), .I1(\Reg_Array\[2\]\[4\] ), .I2(
        \Reg_Array\[1\]\[4\] ), .I3(\Reg_Array\[3\]\[4\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[4\] ) );
  mx04d0 U103 ( .I0(\Reg_Array\[0\]\[5\] ), .I1(\Reg_Array\[2\]\[5\] ), .I2(
        \Reg_Array\[1\]\[5\] ), .I3(\Reg_Array\[3\]\[5\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[5\] ) );
  mx04d0 U104 ( .I0(\Reg_Array\[0\]\[6\] ), .I1(\Reg_Array\[2\]\[6\] ), .I2(
        \Reg_Array\[1\]\[6\] ), .I3(\Reg_Array\[3\]\[6\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[6\] ) );
  mx04d0 U105 ( .I0(\Reg_Array\[0\]\[7\] ), .I1(\Reg_Array\[2\]\[7\] ), .I2(
        \Reg_Array\[1\]\[7\] ), .I3(\Reg_Array\[3\]\[7\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[7\] ) );
  mx04d0 U106 ( .I0(\Reg_Array\[0\]\[8\] ), .I1(\Reg_Array\[2\]\[8\] ), .I2(
        \Reg_Array\[1\]\[8\] ), .I3(\Reg_Array\[3\]\[8\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[8\] ) );
  mx04d0 U107 ( .I0(\Reg_Array\[0\]\[9\] ), .I1(\Reg_Array\[2\]\[9\] ), .I2(
        \Reg_Array\[1\]\[9\] ), .I3(\Reg_Array\[3\]\[9\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[9\] ) );
  mx04d0 U108 ( .I0(\Reg_Array\[0\]\[10\] ), .I1(\Reg_Array\[2\]\[10\] ), .I2(
        \Reg_Array\[1\]\[10\] ), .I3(\Reg_Array\[3\]\[10\] ), .S0(
        \Addr_A\[1\] ), .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[10\] ) );
  mx04d0 U109 ( .I0(\Reg_Array\[0\]\[11\] ), .I1(\Reg_Array\[2\]\[11\] ), .I2(
        \Reg_Array\[1\]\[11\] ), .I3(\Reg_Array\[3\]\[11\] ), .S0(
        \Addr_A\[1\] ), .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[11\] ) );
  mx04d0 U110 ( .I0(\Reg_Array\[0\]\[12\] ), .I1(\Reg_Array\[2\]\[12\] ), .I2(
        \Reg_Array\[1\]\[12\] ), .I3(\Reg_Array\[3\]\[12\] ), .S0(
        \Addr_A\[1\] ), .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[12\] ) );
  mx04d0 U111 ( .I0(\Reg_Array\[0\]\[13\] ), .I1(\Reg_Array\[2\]\[13\] ), .I2(
        \Reg_Array\[1\]\[13\] ), .I3(\Reg_Array\[3\]\[13\] ), .S0(
        \Addr_A\[1\] ), .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[13\] ) );
  mx04d0 U112 ( .I0(\Reg_Array\[0\]\[14\] ), .I1(\Reg_Array\[2\]\[14\] ), .I2(
        \Reg_Array\[1\]\[14\] ), .I3(\Reg_Array\[3\]\[14\] ), .S0(
        \Addr_A\[1\] ), .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[14\] ) );
  mx04d0 U113 ( .I0(\Reg_Array\[0\]\[15\] ), .I1(\Reg_Array\[2\]\[15\] ), .I2(
        \Reg_Array\[1\]\[15\] ), .I3(\Reg_Array\[3\]\[15\] ), .S0(
        \Addr_A\[1\] ), .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[15\] ) );
  mx04d0 U114 ( .I0(\Reg_Array\[0\]\[1\] ), .I1(\Reg_Array\[2\]\[1\] ), .I2(
        \Reg_Array\[1\]\[1\] ), .I3(\Reg_Array\[3\]\[1\] ), .S0(\Addr_A\[1\] ), 
        .S1(\Addr_A\[0\] ), .Z(\RegPort_A\[1\] ) );
endmodule


module RST ( TEST_MODE, Reset, Clk, INTERNAL_RESET, RISC_CORE_TEST_MODE_in, 
        test_si, test_so, test_se );
  input TEST_MODE, Reset, Clk, RISC_CORE_TEST_MODE_in, test_si, test_se;
  output INTERNAL_RESET, test_so;
  wire   q1;

  sdcrq1 q1_reg ( .D(1'b1), .SD(test_si), .SC(test_se), .CP(Clk), .CDN(Reset), 
        .Q(q1) );
  dfcrq1 q2_reg ( .D(q1), .CP(Clk), .CDN(Reset), .Q(test_so) );
  mx02d1 U3 ( .I0(test_so), .I1(Reset), .S(RISC_CORE_TEST_MODE_in), .Z(
        INTERNAL_RESET) );
endmodule


module STACK_FSM ( INTERNAL_RESET, Clk, PushEnbl, PopEnbl, .TOS({\TOS\[0\] , 
        \TOS\[1\] , \TOS\[2\] }), STACK_FULL, test_si2, test_si1, test_se );
  input INTERNAL_RESET, Clk, PushEnbl, PopEnbl, test_si2, test_si1, test_se;
  output \TOS\[0\] , \TOS\[1\] , \TOS\[2\] , STACK_FULL;
  wire   \Next_Stack\[1\] , \Next_Stack\[0\] , \Crnt_Stack\[1\] ,
         \Crnt_Stack\[0\] , N64, n37, n38, n39, n1, n2, n3, n4, n5, n6, n7, n8,
         n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22,
         n23, n24, n25, n26;

  sdcrq1 \TOS_int_reg\[1\]  ( .D(n37), .SD(\TOS\[0\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\TOS\[1\] ) );
  sdcrq1 \Crnt_Stack_reg\[1\]  ( .D(\Next_Stack\[1\] ), .SD(\Crnt_Stack\[0\] ), 
        .SC(test_se), .CP(Clk), .CDN(INTERNAL_RESET), .Q(\Crnt_Stack\[1\] ) );
  sdcrq1 \TOS_int_reg\[0\]  ( .D(n38), .SD(\Crnt_Stack\[1\] ), .SC(test_se), 
        .CP(Clk), .CDN(INTERNAL_RESET), .Q(\TOS\[0\] ) );
  sdcrq1 STACK_FULL_reg ( .D(N64), .SD(test_si2), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(STACK_FULL) );
  sdcrq1 \TOS_int_reg\[2\]  ( .D(n39), .SD(\TOS\[1\] ), .SC(test_se), .CP(Clk), 
        .CDN(INTERNAL_RESET), .Q(\TOS\[2\] ) );
  sdcrq1 \Crnt_Stack_reg\[0\]  ( .D(\Next_Stack\[0\] ), .SD(test_si1), .SC(
        test_se), .CP(Clk), .CDN(INTERNAL_RESET), .Q(\Crnt_Stack\[0\] ) );
  nd03d0 U3 ( .A1(\TOS\[2\] ), .A2(\TOS\[0\] ), .A3(\TOS\[1\] ), .ZN(n20) );
  inv0d0 U4 ( .I(n20), .ZN(n3) );
  aor21d1 U5 ( .B1(PushEnbl), .B2(n3), .A(\Crnt_Stack\[1\] ), .Z(n11) );
  inv0d0 U6 ( .I(PopEnbl), .ZN(n9) );
  inv0d0 U7 ( .I(\Crnt_Stack\[1\] ), .ZN(n23) );
  inv0d0 U8 ( .I(PushEnbl), .ZN(n8) );
  oai322d1 U9 ( .C1(n9), .C2(\Crnt_Stack\[1\] ), .C3(\Crnt_Stack\[0\] ), .A1(
        n23), .A2(PopEnbl), .B1(n8), .B2(n9), .ZN(n1) );
  aor21d1 U10 ( .B1(\Crnt_Stack\[0\] ), .B2(n11), .A(n1), .Z(\Next_Stack\[1\] ) );
  nr03d0 U11 ( .A1(\Crnt_Stack\[0\] ), .A2(n23), .A3(n20), .ZN(N64) );
  nr02d0 U12 ( .A1(\TOS\[0\] ), .A2(\TOS\[1\] ), .ZN(n2) );
  nd03d0 U13 ( .A1(\Crnt_Stack\[0\] ), .A2(\TOS\[2\] ), .A3(n2), .ZN(n7) );
  inv0d0 U14 ( .I(\Crnt_Stack\[0\] ), .ZN(n18) );
  nr03d0 U15 ( .A1(PushEnbl), .A2(PopEnbl), .A3(n18), .ZN(n6) );
  nd02d0 U16 ( .A1(\Crnt_Stack\[0\] ), .A2(n3), .ZN(n4) );
  aor22d1 U17 ( .A1(\Crnt_Stack\[0\] ), .A2(\Crnt_Stack\[1\] ), .B1(PushEnbl), 
        .B2(n4), .Z(n5) );
  aor211d1 U18 ( .C1(PopEnbl), .C2(n7), .A(n6), .B(n5), .Z(\Next_Stack\[0\] )
         );
  nr04d0 U19 ( .A1(\Crnt_Stack\[1\] ), .A2(PushEnbl), .A3(PopEnbl), .A4(n18), 
        .ZN(n26) );
  nr02d0 U20 ( .A1(n9), .A2(n8), .ZN(n10) );
  nr02d0 U21 ( .A1(n26), .A2(n10), .ZN(n25) );
  inv0d0 U22 ( .I(\TOS\[2\] ), .ZN(n17) );
  aor221d1 U23 ( .B1(\Crnt_Stack\[0\] ), .B2(n17), .C1(n18), .C2(PushEnbl), 
        .A(n11), .Z(n12) );
  aor22d1 U24 ( .A1(n26), .A2(\TOS\[2\] ), .B1(n25), .B2(n12), .Z(n39) );
  ora31d1 U25 ( .B1(PushEnbl), .B2(\TOS\[2\] ), .B3(\TOS\[1\] ), .A(\TOS\[0\] ), .Z(n14) );
  nr04d0 U26 ( .A1(\TOS\[0\] ), .A2(\TOS\[2\] ), .A3(PushEnbl), .A4(\TOS\[1\] ), .ZN(n13) );
  aor311d1 U27 ( .C1(\TOS\[2\] ), .C2(PushEnbl), .C3(\TOS\[1\] ), .A(n14), .B(
        n13), .Z(n15) );
  aor21d1 U28 ( .B1(\Crnt_Stack\[0\] ), .B2(n15), .A(\Crnt_Stack\[1\] ), .Z(
        n16) );
  aor22d1 U29 ( .A1(n26), .A2(\TOS\[0\] ), .B1(n25), .B2(n16), .Z(n38) );
  mx02d0 U30 ( .I0(n17), .I1(\TOS\[2\] ), .S(\TOS\[1\] ), .Z(n21) );
  nr02d0 U31 ( .A1(PushEnbl), .A2(n21), .ZN(n19) );
  aor311d1 U32 ( .C1(n21), .C2(PushEnbl), .C3(n20), .A(n19), .B(n18), .Z(n22)
         );
  nd02d0 U33 ( .A1(n23), .A2(n22), .ZN(n24) );
  aor22d1 U34 ( .A1(n26), .A2(\TOS\[1\] ), .B1(n25), .B2(n24), .Z(n37) );
endmodule


module STACK_TOP ( INTERNAL_RESET, Clk, PushEnbl, PopEnbl, .PushDataIn({
        \PushDataIn\[11\] , \PushDataIn\[10\] , \PushDataIn\[9\] , 
        \PushDataIn\[8\] , \PushDataIn\[7\] , \PushDataIn\[6\] , 
        \PushDataIn\[5\] , \PushDataIn\[4\] , \PushDataIn\[3\] , 
        \PushDataIn\[2\] , \PushDataIn\[1\] , \PushDataIn\[0\] }), 
    .PopDataOut({\PopDataOut\[11\] , \PopDataOut\[10\] , \PopDataOut\[9\] , 
        \PopDataOut\[8\] , \PopDataOut\[7\] , \PopDataOut\[6\] , 
        \PopDataOut\[5\] , \PopDataOut\[4\] , \PopDataOut\[3\] , 
        \PopDataOut\[2\] , \PopDataOut\[1\] , \PopDataOut\[0\] }), STACK_FULL, 
        test_si2, test_si1, test_so1, test_se );
  input INTERNAL_RESET, Clk, PushEnbl, PopEnbl, \PushDataIn\[11\] ,
         \PushDataIn\[10\] , \PushDataIn\[9\] , \PushDataIn\[8\] ,
         \PushDataIn\[7\] , \PushDataIn\[6\] , \PushDataIn\[5\] ,
         \PushDataIn\[4\] , \PushDataIn\[3\] , \PushDataIn\[2\] ,
         \PushDataIn\[1\] , \PushDataIn\[0\] , test_si2, test_si1, test_se;
  output \PopDataOut\[11\] , \PopDataOut\[10\] , \PopDataOut\[9\] ,
         \PopDataOut\[8\] , \PopDataOut\[7\] , \PopDataOut\[6\] ,
         \PopDataOut\[5\] , \PopDataOut\[4\] , \PopDataOut\[3\] ,
         \PopDataOut\[2\] , \PopDataOut\[1\] , \PopDataOut\[0\] , STACK_FULL,
         test_so1;
  wire   \TOS\[0\] , \TOS\[1\] , \TOS\[2\] , \I1_STACK_MEM/n109 ,
         \I1_STACK_MEM/n108 , \I1_STACK_MEM/n107 , \I1_STACK_MEM/n106 ,
         \I1_STACK_MEM/n105 , \I1_STACK_MEM/n104 , \I1_STACK_MEM/n103 ,
         \I1_STACK_MEM/n102 , \I1_STACK_MEM/n101 , \I1_STACK_MEM/n100 ,
         \I1_STACK_MEM/n99 , \I1_STACK_MEM/n98 , \I1_STACK_MEM/n97 ,
         \I1_STACK_MEM/n96 , \I1_STACK_MEM/n95 , \I1_STACK_MEM/n94 ,
         \I1_STACK_MEM/n93 , \I1_STACK_MEM/n92 , \I1_STACK_MEM/n91 ,
         \I1_STACK_MEM/n90 , \I1_STACK_MEM/n89 , \I1_STACK_MEM/n88 ,
         \I1_STACK_MEM/n87 , \I1_STACK_MEM/n86 , \I1_STACK_MEM/n85 ,
         \I1_STACK_MEM/n84 , \I1_STACK_MEM/n83 , \I1_STACK_MEM/n82 ,
         \I1_STACK_MEM/n81 , \I1_STACK_MEM/n80 , \I1_STACK_MEM/n79 ,
         \I1_STACK_MEM/n78 , \I1_STACK_MEM/n45 , \I1_STACK_MEM/n43 ,
         \I1_STACK_MEM/n41 , \I1_STACK_MEM/n39 ,
         \I1_STACK_MEM/Stack_Mem\[0\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[0\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[0\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[0\]\[0\] ,
         \I1_STACK_MEM/Stack_Mem\[1\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[1\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[1\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[1\]\[0\] ,
         \I1_STACK_MEM/Stack_Mem\[2\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[2\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[2\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[2\]\[0\] ,
         \I1_STACK_MEM/Stack_Mem\[3\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[3\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[3\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[3\]\[0\] ,
         \I1_STACK_MEM/Stack_Mem\[4\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[4\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[4\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[4\]\[0\] ,
         \I1_STACK_MEM/Stack_Mem\[5\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[5\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[5\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[5\]\[0\] ,
         \I1_STACK_MEM/Stack_Mem\[6\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[6\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[6\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[6\]\[0\] ,
         \I1_STACK_MEM/Stack_Mem\[7\]\[3\] ,
         \I1_STACK_MEM/Stack_Mem\[7\]\[2\] ,
         \I1_STACK_MEM/Stack_Mem\[7\]\[1\] ,
         \I1_STACK_MEM/Stack_Mem\[7\]\[0\] , \I3_STACK_MEM/n88 ,
         \I3_STACK_MEM/n87 , \I3_STACK_MEM/n85 , \I3_STACK_MEM/n84 ,
         \I3_STACK_MEM/n82 , \I3_STACK_MEM/n81 , \I3_STACK_MEM/n79 ,
         \I3_STACK_MEM/n78 , \I3_STACK_MEM/n76 , \I3_STACK_MEM/n75 ,
         \I3_STACK_MEM/n73 , \I3_STACK_MEM/n72 , \I3_STACK_MEM/n70 ,
         \I3_STACK_MEM/n69 , \I3_STACK_MEM/n67 , \I3_STACK_MEM/n66 ,
         \I3_STACK_MEM/n40 , \I3_STACK_MEM/n38 ,
         \I3_STACK_MEM/Stack_Mem\[0\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[0\]\[1\] ,
         \I3_STACK_MEM/Stack_Mem\[1\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[1\]\[1\] ,
         \I3_STACK_MEM/Stack_Mem\[2\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[2\]\[1\] ,
         \I3_STACK_MEM/Stack_Mem\[3\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[3\]\[1\] ,
         \I3_STACK_MEM/Stack_Mem\[4\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[4\]\[1\] ,
         \I3_STACK_MEM/Stack_Mem\[5\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[5\]\[1\] ,
         \I3_STACK_MEM/Stack_Mem\[6\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[6\]\[1\] ,
         \I3_STACK_MEM/Stack_Mem\[7\]\[2\] ,
         \I3_STACK_MEM/Stack_Mem\[7\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[0\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[0\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[0\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[0\]\[0\] ,
         \I2_STACK_MEM/Stack_Mem\[1\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[1\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[1\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[1\]\[0\] ,
         \I2_STACK_MEM/Stack_Mem\[2\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[2\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[2\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[2\]\[0\] ,
         \I2_STACK_MEM/Stack_Mem\[3\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[3\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[3\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[3\]\[0\] ,
         \I2_STACK_MEM/Stack_Mem\[4\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[4\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[4\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[4\]\[0\] ,
         \I2_STACK_MEM/Stack_Mem\[5\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[5\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[5\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[5\]\[0\] ,
         \I2_STACK_MEM/Stack_Mem\[6\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[6\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[6\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[6\]\[0\] ,
         \I2_STACK_MEM/Stack_Mem\[7\]\[3\] ,
         \I2_STACK_MEM/Stack_Mem\[7\]\[2\] ,
         \I2_STACK_MEM/Stack_Mem\[7\]\[1\] ,
         \I2_STACK_MEM/Stack_Mem\[7\]\[0\] , n2, n3, n4, n5, n6, n7, n8, n9,
         n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23,
         n24, n25, n26, n27, n28, n29, n30, n31, n32, n33, n34, n35, n36, n37,
         n38, n39, n40, n41, n42, n43, n44, n45, n46, n47, n48, n49, n50, n51,
         n52, n53, n54, n55, n56, n57, n58, n59, n60, n61, n62, n63, n64, n65,
         n66, n67, n68, n69, n70, n72, n73, n74, n75, n76, n77, n78, n79, n80,
         n81, n82, n83, n84, n85, n86, n87, n88, n89, n90, n91, n92, n93, n94,
         n95, n96, n97, n98, n99, n100, n101, n102, n103, n104, n105, n106,
         n107;
  assign test_so1 = \TOS\[2\] ;

  STACK_FSM I_STACK_FSM ( .INTERNAL_RESET(INTERNAL_RESET), .Clk(n70), 
        .PushEnbl(PushEnbl), .PopEnbl(PopEnbl), .TOS({\TOS\[0\] , \TOS\[1\] , 
        \TOS\[2\] }), .STACK_FULL(STACK_FULL), .test_si2(test_si2), .test_si1(
        \I3_STACK_MEM/Stack_Mem\[7\]\[2\] ), .test_se(test_se) );
  sdnrq1 \I1_STACK_MEM/PopDataOut_reg\[0\]  ( .D(\I1_STACK_MEM/n39 ), .SD(
        test_si1), .SC(test_se), .CP(n70), .Q(\PopDataOut\[0\] ) );
  sdnrq1 \I1_STACK_MEM/PopDataOut_reg\[1\]  ( .D(\I1_STACK_MEM/n41 ), .SD(
        \PopDataOut\[0\] ), .SC(test_se), .CP(n69), .Q(\PopDataOut\[1\] ) );
  sdnrq1 \I1_STACK_MEM/PopDataOut_reg\[2\]  ( .D(\I1_STACK_MEM/n43 ), .SD(
        \PopDataOut\[1\] ), .SC(test_se), .CP(n70), .Q(\PopDataOut\[2\] ) );
  sdnrq1 \I1_STACK_MEM/PopDataOut_reg\[3\]  ( .D(\I1_STACK_MEM/n45 ), .SD(
        \PopDataOut\[2\] ), .SC(test_se), .CP(n69), .Q(\PopDataOut\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[7\]\[0\]  ( .D(\I1_STACK_MEM/n78 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[6\]\[3\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[7\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[7\]\[1\]  ( .D(\I1_STACK_MEM/n79 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[7\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[7\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[7\]\[2\]  ( .D(\I1_STACK_MEM/n80 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[7\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[7\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[7\]\[3\]  ( .D(\I1_STACK_MEM/n81 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[7\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[7\]\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[6\]\[0\]  ( .D(\I1_STACK_MEM/n82 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[5\]\[3\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[6\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[6\]\[1\]  ( .D(\I1_STACK_MEM/n83 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[6\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[6\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[6\]\[2\]  ( .D(\I1_STACK_MEM/n84 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[6\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[6\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[6\]\[3\]  ( .D(\I1_STACK_MEM/n85 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[6\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[6\]\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[5\]\[0\]  ( .D(\I1_STACK_MEM/n86 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[4\]\[3\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[5\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[5\]\[1\]  ( .D(\I1_STACK_MEM/n87 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[5\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[5\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[5\]\[2\]  ( .D(\I1_STACK_MEM/n88 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[5\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[5\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[5\]\[3\]  ( .D(\I1_STACK_MEM/n89 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[5\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[5\]\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[4\]\[0\]  ( .D(\I1_STACK_MEM/n90 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[3\]\[3\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[4\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[4\]\[1\]  ( .D(\I1_STACK_MEM/n91 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[4\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[4\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[4\]\[2\]  ( .D(\I1_STACK_MEM/n92 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[4\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[4\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[4\]\[3\]  ( .D(\I1_STACK_MEM/n93 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[4\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[4\]\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[3\]\[0\]  ( .D(\I1_STACK_MEM/n94 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[2\]\[3\] ), .SC(test_se), .CP(Clk), .Q(
        \I1_STACK_MEM/Stack_Mem\[3\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[3\]\[1\]  ( .D(\I1_STACK_MEM/n95 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[3\]\[0\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[3\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[3\]\[2\]  ( .D(\I1_STACK_MEM/n96 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[3\]\[1\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[3\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[3\]\[3\]  ( .D(\I1_STACK_MEM/n97 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[3\]\[2\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[3\]\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[2\]\[0\]  ( .D(\I1_STACK_MEM/n98 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[1\]\[3\] ), .SC(test_se), .CP(Clk), .Q(
        \I1_STACK_MEM/Stack_Mem\[2\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[2\]\[1\]  ( .D(\I1_STACK_MEM/n99 ), .SD(
        \I1_STACK_MEM/Stack_Mem\[2\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[2\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[2\]\[2\]  ( .D(\I1_STACK_MEM/n100 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[2\]\[1\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[2\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[2\]\[3\]  ( .D(\I1_STACK_MEM/n101 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[2\]\[2\] ), .SC(test_se), .CP(Clk), .Q(
        \I1_STACK_MEM/Stack_Mem\[2\]\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[1\]\[0\]  ( .D(\I1_STACK_MEM/n102 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[0\]\[3\] ), .SC(test_se), .CP(Clk), .Q(
        \I1_STACK_MEM/Stack_Mem\[1\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[1\]\[1\]  ( .D(\I1_STACK_MEM/n103 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[1\]\[0\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[1\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[1\]\[2\]  ( .D(\I1_STACK_MEM/n104 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[1\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[1\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[1\]\[3\]  ( .D(\I1_STACK_MEM/n105 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[1\]\[2\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[1\]\[3\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[0\]\[0\]  ( .D(\I1_STACK_MEM/n106 ), 
        .SD(\PopDataOut\[3\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[0\]\[0\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[0\]\[1\]  ( .D(\I1_STACK_MEM/n107 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[0\]\[0\] ), .SC(test_se), .CP(Clk), .Q(
        \I1_STACK_MEM/Stack_Mem\[0\]\[1\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[0\]\[2\]  ( .D(\I1_STACK_MEM/n108 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[0\]\[1\] ), .SC(test_se), .CP(n69), .Q(
        \I1_STACK_MEM/Stack_Mem\[0\]\[2\] ) );
  sdnrq1 \I1_STACK_MEM/Stack_Mem_reg\[0\]\[3\]  ( .D(\I1_STACK_MEM/n109 ), 
        .SD(\I1_STACK_MEM/Stack_Mem\[0\]\[2\] ), .SC(test_se), .CP(n70), .Q(
        \I1_STACK_MEM/Stack_Mem\[0\]\[3\] ) );
  sdnrq1 \I3_STACK_MEM/PopDataOut_reg\[1\]  ( .D(\I3_STACK_MEM/n38 ), .SD(
        \I2_STACK_MEM/Stack_Mem\[7\]\[3\] ), .SC(test_se), .CP(Clk), .Q(
        \PopDataOut\[9\] ) );
  sdnrq1 \I3_STACK_MEM/PopDataOut_reg\[2\]  ( .D(\I3_STACK_MEM/n40 ), .SD(
        \PopDataOut\[9\] ), .SC(test_se), .CP(n70), .Q(\PopDataOut\[10\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[7\]\[1\]  ( .D(\I3_STACK_MEM/n66 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[6\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I3_STACK_MEM/Stack_Mem\[7\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[7\]\[2\]  ( .D(\I3_STACK_MEM/n67 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[7\]\[1\] ), .SC(test_se), .CP(Clk), .Q(
        \I3_STACK_MEM/Stack_Mem\[7\]\[2\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[6\]\[1\]  ( .D(\I3_STACK_MEM/n69 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[5\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I3_STACK_MEM/Stack_Mem\[6\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[6\]\[2\]  ( .D(\I3_STACK_MEM/n70 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[6\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I3_STACK_MEM/Stack_Mem\[6\]\[2\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[5\]\[1\]  ( .D(\I3_STACK_MEM/n72 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[4\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I3_STACK_MEM/Stack_Mem\[5\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[5\]\[2\]  ( .D(\I3_STACK_MEM/n73 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[5\]\[1\] ), .SC(test_se), .CP(n69), .Q(
        \I3_STACK_MEM/Stack_Mem\[5\]\[2\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[4\]\[1\]  ( .D(\I3_STACK_MEM/n75 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[3\]\[2\] ), .SC(test_se), .CP(n70), .Q(
        \I3_STACK_MEM/Stack_Mem\[4\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[4\]\[2\]  ( .D(\I3_STACK_MEM/n76 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[4\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I3_STACK_MEM/Stack_Mem\[4\]\[2\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[3\]\[1\]  ( .D(\I3_STACK_MEM/n78 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[2\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I3_STACK_MEM/Stack_Mem\[3\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[3\]\[2\]  ( .D(\I3_STACK_MEM/n79 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[3\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I3_STACK_MEM/Stack_Mem\[3\]\[2\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[2\]\[1\]  ( .D(\I3_STACK_MEM/n81 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[1\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I3_STACK_MEM/Stack_Mem\[2\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[2\]\[2\]  ( .D(\I3_STACK_MEM/n82 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[2\]\[1\] ), .SC(test_se), .CP(Clk), .Q(
        \I3_STACK_MEM/Stack_Mem\[2\]\[2\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[1\]\[1\]  ( .D(\I3_STACK_MEM/n84 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[0\]\[2\] ), .SC(test_se), .CP(Clk), .Q(
        \I3_STACK_MEM/Stack_Mem\[1\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[1\]\[2\]  ( .D(\I3_STACK_MEM/n85 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[1\]\[1\] ), .SC(test_se), .CP(Clk), .Q(
        \I3_STACK_MEM/Stack_Mem\[1\]\[2\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[0\]\[1\]  ( .D(\I3_STACK_MEM/n87 ), .SD(
        \PopDataOut\[10\] ), .SC(test_se), .CP(n70), .Q(
        \I3_STACK_MEM/Stack_Mem\[0\]\[1\] ) );
  sdnrq1 \I3_STACK_MEM/Stack_Mem_reg\[0\]\[2\]  ( .D(\I3_STACK_MEM/n88 ), .SD(
        \I3_STACK_MEM/Stack_Mem\[0\]\[1\] ), .SC(test_se), .CP(n69), .Q(
        \I3_STACK_MEM/Stack_Mem\[0\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/PopDataOut_reg\[0\]  ( .D(n72), .SD(
        \I1_STACK_MEM/Stack_Mem\[7\]\[3\] ), .SC(test_se), .CP(Clk), .Q(
        \PopDataOut\[4\] ) );
  sdnrq1 \I2_STACK_MEM/PopDataOut_reg\[1\]  ( .D(n73), .SD(\PopDataOut\[4\] ), 
        .SC(test_se), .CP(Clk), .Q(\PopDataOut\[5\] ) );
  sdnrq1 \I2_STACK_MEM/PopDataOut_reg\[2\]  ( .D(n74), .SD(\PopDataOut\[5\] ), 
        .SC(test_se), .CP(n70), .Q(\PopDataOut\[6\] ) );
  sdnrq1 \I2_STACK_MEM/PopDataOut_reg\[3\]  ( .D(n75), .SD(\PopDataOut\[6\] ), 
        .SC(test_se), .CP(n69), .Q(\PopDataOut\[7\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[7\]\[0\]  ( .D(n76), .SD(
        \I2_STACK_MEM/Stack_Mem\[6\]\[3\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[7\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[7\]\[1\]  ( .D(n77), .SD(
        \I2_STACK_MEM/Stack_Mem\[7\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[7\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[7\]\[2\]  ( .D(n78), .SD(
        \I2_STACK_MEM/Stack_Mem\[7\]\[1\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[7\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[7\]\[3\]  ( .D(n79), .SD(
        \I2_STACK_MEM/Stack_Mem\[7\]\[2\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[7\]\[3\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[6\]\[0\]  ( .D(n80), .SD(
        \I2_STACK_MEM/Stack_Mem\[5\]\[3\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[6\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[6\]\[1\]  ( .D(n81), .SD(
        \I2_STACK_MEM/Stack_Mem\[6\]\[0\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[6\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[6\]\[2\]  ( .D(n82), .SD(
        \I2_STACK_MEM/Stack_Mem\[6\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[6\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[6\]\[3\]  ( .D(n83), .SD(
        \I2_STACK_MEM/Stack_Mem\[6\]\[2\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[6\]\[3\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[5\]\[0\]  ( .D(n84), .SD(
        \I2_STACK_MEM/Stack_Mem\[4\]\[3\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[5\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[5\]\[1\]  ( .D(n85), .SD(
        \I2_STACK_MEM/Stack_Mem\[5\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[5\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[5\]\[2\]  ( .D(n86), .SD(
        \I2_STACK_MEM/Stack_Mem\[5\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[5\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[5\]\[3\]  ( .D(n87), .SD(
        \I2_STACK_MEM/Stack_Mem\[5\]\[2\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[5\]\[3\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[4\]\[0\]  ( .D(n88), .SD(
        \I2_STACK_MEM/Stack_Mem\[3\]\[3\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[4\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[4\]\[1\]  ( .D(n89), .SD(
        \I2_STACK_MEM/Stack_Mem\[4\]\[0\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[4\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[4\]\[2\]  ( .D(n90), .SD(
        \I2_STACK_MEM/Stack_Mem\[4\]\[1\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[4\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[4\]\[3\]  ( .D(n91), .SD(
        \I2_STACK_MEM/Stack_Mem\[4\]\[2\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[4\]\[3\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[3\]\[0\]  ( .D(n92), .SD(
        \I2_STACK_MEM/Stack_Mem\[2\]\[3\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[3\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[3\]\[1\]  ( .D(n93), .SD(
        \I2_STACK_MEM/Stack_Mem\[3\]\[0\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[3\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[3\]\[2\]  ( .D(n94), .SD(
        \I2_STACK_MEM/Stack_Mem\[3\]\[1\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[3\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[3\]\[3\]  ( .D(n95), .SD(
        \I2_STACK_MEM/Stack_Mem\[3\]\[2\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[3\]\[3\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[2\]\[0\]  ( .D(n96), .SD(
        \I2_STACK_MEM/Stack_Mem\[1\]\[3\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[2\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[2\]\[1\]  ( .D(n97), .SD(
        \I2_STACK_MEM/Stack_Mem\[2\]\[0\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[2\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[2\]\[2\]  ( .D(n98), .SD(
        \I2_STACK_MEM/Stack_Mem\[2\]\[1\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[2\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[2\]\[3\]  ( .D(n99), .SD(
        \I2_STACK_MEM/Stack_Mem\[2\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[2\]\[3\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[1\]\[0\]  ( .D(n100), .SD(
        \I2_STACK_MEM/Stack_Mem\[0\]\[3\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[1\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[1\]\[1\]  ( .D(n101), .SD(
        \I2_STACK_MEM/Stack_Mem\[1\]\[0\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[1\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[1\]\[2\]  ( .D(n102), .SD(
        \I2_STACK_MEM/Stack_Mem\[1\]\[1\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[1\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[1\]\[3\]  ( .D(n103), .SD(
        \I2_STACK_MEM/Stack_Mem\[1\]\[2\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[1\]\[3\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[0\]\[0\]  ( .D(n104), .SD(
        \PopDataOut\[7\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[0\]\[0\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[0\]\[1\]  ( .D(n105), .SD(
        \I2_STACK_MEM/Stack_Mem\[0\]\[0\] ), .SC(test_se), .CP(n70), .Q(
        \I2_STACK_MEM/Stack_Mem\[0\]\[1\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[0\]\[2\]  ( .D(n106), .SD(
        \I2_STACK_MEM/Stack_Mem\[0\]\[1\] ), .SC(test_se), .CP(Clk), .Q(
        \I2_STACK_MEM/Stack_Mem\[0\]\[2\] ) );
  sdnrq1 \I2_STACK_MEM/Stack_Mem_reg\[0\]\[3\]  ( .D(n107), .SD(
        \I2_STACK_MEM/Stack_Mem\[0\]\[2\] ), .SC(test_se), .CP(n69), .Q(
        \I2_STACK_MEM/Stack_Mem\[0\]\[3\] ) );
  invbd2 U1 ( .I(n68), .ZN(n70) );
  inv0d0 U2 ( .I(\TOS\[2\] ), .ZN(n26) );
  nr03d0 U3 ( .A1(\TOS\[1\] ), .A2(\TOS\[0\] ), .A3(n24), .ZN(n66) );
  inv0d0 U4 ( .I(\TOS\[0\] ), .ZN(n25) );
  nd02d0 U5 ( .A1(\TOS\[2\] ), .A2(PushEnbl), .ZN(n22) );
  nr03d0 U6 ( .A1(\TOS\[1\] ), .A2(n25), .A3(n22), .ZN(n43) );
  mx02d0 U7 ( .I0(\I3_STACK_MEM/Stack_Mem\[5\]\[1\] ), .I1(\PushDataIn\[9\] ), 
        .S(n43), .Z(\I3_STACK_MEM/n72 ) );
  inv0d0 U8 ( .I(\TOS\[1\] ), .ZN(n23) );
  nd02d0 U9 ( .A1(PushEnbl), .A2(n26), .ZN(n24) );
  nr03d0 U10 ( .A1(n23), .A2(n25), .A3(n24), .ZN(n48) );
  mx02d0 U11 ( .I0(\I3_STACK_MEM/Stack_Mem\[6\]\[2\] ), .I1(\PushDataIn\[10\] ), .S(n48), .Z(\I3_STACK_MEM/n70 ) );
  mx02d0 U12 ( .I0(\I3_STACK_MEM/Stack_Mem\[6\]\[1\] ), .I1(\PushDataIn\[9\] ), 
        .S(n48), .Z(\I3_STACK_MEM/n69 ) );
  nr03d0 U13 ( .A1(n23), .A2(n25), .A3(n22), .ZN(n49) );
  mx02d0 U14 ( .I0(\I3_STACK_MEM/Stack_Mem\[7\]\[2\] ), .I1(\PushDataIn\[10\] ), .S(n49), .Z(\I3_STACK_MEM/n67 ) );
  mx02d0 U15 ( .I0(\I3_STACK_MEM/Stack_Mem\[7\]\[1\] ), .I1(\PushDataIn\[9\] ), 
        .S(n49), .Z(\I3_STACK_MEM/n66 ) );
  mx02d0 U16 ( .I0(\TOS\[2\] ), .I1(n26), .S(STACK_FULL), .Z(n20) );
  nr03d0 U17 ( .A1(STACK_FULL), .A2(\TOS\[2\] ), .A3(\TOS\[1\] ), .ZN(n3) );
  mx02d0 U18 ( .I0(\TOS\[0\] ), .I1(n25), .S(n3), .Z(n62) );
  inv0d0 U19 ( .I(n62), .ZN(n12) );
  nr02d0 U20 ( .A1(STACK_FULL), .A2(\TOS\[2\] ), .ZN(n2) );
  nr02d0 U21 ( .A1(n2), .A2(n23), .ZN(n27) );
  aor221d1 U22 ( .B1(n62), .B2(\I3_STACK_MEM/Stack_Mem\[4\]\[2\] ), .C1(n12), 
        .C2(\I3_STACK_MEM/Stack_Mem\[0\]\[2\] ), .A(n27), .Z(n9) );
  inv0d0 U23 ( .I(n27), .ZN(n11) );
  aor221d1 U24 ( .B1(n62), .B2(\I3_STACK_MEM/Stack_Mem\[6\]\[2\] ), .C1(n12), 
        .C2(\I3_STACK_MEM/Stack_Mem\[2\]\[2\] ), .A(n11), .Z(n8) );
  inv0d0 U25 ( .I(n20), .ZN(n16) );
  mx02d0 U26 ( .I0(\I3_STACK_MEM/Stack_Mem\[3\]\[2\] ), .I1(
        \I3_STACK_MEM/Stack_Mem\[7\]\[2\] ), .S(n62), .Z(n5) );
  mx02d0 U27 ( .I0(\I3_STACK_MEM/Stack_Mem\[1\]\[2\] ), .I1(
        \I3_STACK_MEM/Stack_Mem\[5\]\[2\] ), .S(n62), .Z(n4) );
  nr02d0 U28 ( .A1(n3), .A2(n27), .ZN(n29) );
  mx02d0 U29 ( .I0(n5), .I1(n4), .S(n29), .Z(n6) );
  an02d0 U30 ( .A1(n16), .A2(n6), .Z(n7) );
  aor31d1 U31 ( .B1(n20), .B2(n9), .B3(n8), .A(n7), .Z(n10) );
  mx02d0 U32 ( .I0(\PopDataOut\[10\] ), .I1(n10), .S(PopEnbl), .Z(
        \I3_STACK_MEM/n40 ) );
  aor221d1 U33 ( .B1(n62), .B2(\I3_STACK_MEM/Stack_Mem\[4\]\[1\] ), .C1(n12), 
        .C2(\I3_STACK_MEM/Stack_Mem\[0\]\[1\] ), .A(n27), .Z(n19) );
  aor221d1 U34 ( .B1(n62), .B2(\I3_STACK_MEM/Stack_Mem\[6\]\[1\] ), .C1(n12), 
        .C2(\I3_STACK_MEM/Stack_Mem\[2\]\[1\] ), .A(n11), .Z(n18) );
  mx02d0 U35 ( .I0(\I3_STACK_MEM/Stack_Mem\[3\]\[1\] ), .I1(
        \I3_STACK_MEM/Stack_Mem\[7\]\[1\] ), .S(n62), .Z(n14) );
  mx02d0 U36 ( .I0(\I3_STACK_MEM/Stack_Mem\[1\]\[1\] ), .I1(
        \I3_STACK_MEM/Stack_Mem\[5\]\[1\] ), .S(n62), .Z(n13) );
  mx02d0 U37 ( .I0(n14), .I1(n13), .S(n29), .Z(n15) );
  an02d0 U38 ( .A1(n16), .A2(n15), .Z(n17) );
  aor31d1 U39 ( .B1(n20), .B2(n19), .B3(n18), .A(n17), .Z(n21) );
  mx02d0 U40 ( .I0(\PopDataOut\[9\] ), .I1(n21), .S(PopEnbl), .Z(
        \I3_STACK_MEM/n38 ) );
  mx02d0 U41 ( .I0(\I1_STACK_MEM/Stack_Mem\[0\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n66), .Z(\I1_STACK_MEM/n109 ) );
  mx02d0 U42 ( .I0(\I1_STACK_MEM/Stack_Mem\[0\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n66), .Z(\I1_STACK_MEM/n108 ) );
  mx02d0 U43 ( .I0(\I1_STACK_MEM/Stack_Mem\[0\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n66), .Z(\I1_STACK_MEM/n107 ) );
  mx02d0 U44 ( .I0(\I1_STACK_MEM/Stack_Mem\[0\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n66), .Z(\I1_STACK_MEM/n106 ) );
  nr03d0 U45 ( .A1(\TOS\[1\] ), .A2(\TOS\[0\] ), .A3(n22), .ZN(n67) );
  mx02d0 U46 ( .I0(\I1_STACK_MEM/Stack_Mem\[1\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n67), .Z(\I1_STACK_MEM/n105 ) );
  mx02d0 U47 ( .I0(\I1_STACK_MEM/Stack_Mem\[1\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n67), .Z(\I1_STACK_MEM/n104 ) );
  mx02d0 U48 ( .I0(\I1_STACK_MEM/Stack_Mem\[1\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n67), .Z(\I1_STACK_MEM/n103 ) );
  mx02d0 U49 ( .I0(\I1_STACK_MEM/Stack_Mem\[1\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n67), .Z(\I1_STACK_MEM/n102 ) );
  nr03d0 U50 ( .A1(\TOS\[0\] ), .A2(n23), .A3(n24), .ZN(n57) );
  mx02d0 U51 ( .I0(\I1_STACK_MEM/Stack_Mem\[2\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n57), .Z(\I1_STACK_MEM/n101 ) );
  mx02d0 U52 ( .I0(\I1_STACK_MEM/Stack_Mem\[2\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n57), .Z(\I1_STACK_MEM/n100 ) );
  mx02d0 U53 ( .I0(\I1_STACK_MEM/Stack_Mem\[2\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n57), .Z(\I1_STACK_MEM/n99 ) );
  mx02d0 U54 ( .I0(\I1_STACK_MEM/Stack_Mem\[2\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n57), .Z(\I1_STACK_MEM/n98 ) );
  nr03d0 U55 ( .A1(\TOS\[0\] ), .A2(n23), .A3(n22), .ZN(n50) );
  mx02d0 U56 ( .I0(\I1_STACK_MEM/Stack_Mem\[3\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n50), .Z(\I1_STACK_MEM/n97 ) );
  mx02d0 U57 ( .I0(\I1_STACK_MEM/Stack_Mem\[3\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n50), .Z(\I1_STACK_MEM/n96 ) );
  mx02d0 U58 ( .I0(\I1_STACK_MEM/Stack_Mem\[3\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n50), .Z(\I1_STACK_MEM/n95 ) );
  mx02d0 U59 ( .I0(\I1_STACK_MEM/Stack_Mem\[3\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n50), .Z(\I1_STACK_MEM/n94 ) );
  nr03d0 U60 ( .A1(\TOS\[1\] ), .A2(n25), .A3(n24), .ZN(n44) );
  mx02d0 U61 ( .I0(\I1_STACK_MEM/Stack_Mem\[4\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n44), .Z(\I1_STACK_MEM/n93 ) );
  mx02d0 U62 ( .I0(\I1_STACK_MEM/Stack_Mem\[4\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n44), .Z(\I1_STACK_MEM/n92 ) );
  mx02d0 U63 ( .I0(\I1_STACK_MEM/Stack_Mem\[4\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n44), .Z(\I1_STACK_MEM/n91 ) );
  mx02d0 U64 ( .I0(\I1_STACK_MEM/Stack_Mem\[4\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n44), .Z(\I1_STACK_MEM/n90 ) );
  mx02d0 U65 ( .I0(\I1_STACK_MEM/Stack_Mem\[5\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n43), .Z(\I1_STACK_MEM/n89 ) );
  mx02d0 U66 ( .I0(\I1_STACK_MEM/Stack_Mem\[5\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n43), .Z(\I1_STACK_MEM/n88 ) );
  mx02d0 U67 ( .I0(\I1_STACK_MEM/Stack_Mem\[5\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n43), .Z(\I1_STACK_MEM/n87 ) );
  mx02d0 U68 ( .I0(\I1_STACK_MEM/Stack_Mem\[5\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n43), .Z(\I1_STACK_MEM/n86 ) );
  mx02d0 U69 ( .I0(\I1_STACK_MEM/Stack_Mem\[6\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n48), .Z(\I1_STACK_MEM/n85 ) );
  mx02d0 U70 ( .I0(\I1_STACK_MEM/Stack_Mem\[6\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n48), .Z(\I1_STACK_MEM/n84 ) );
  mx02d0 U71 ( .I0(\I1_STACK_MEM/Stack_Mem\[6\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n48), .Z(\I1_STACK_MEM/n83 ) );
  mx02d0 U72 ( .I0(\I1_STACK_MEM/Stack_Mem\[6\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n48), .Z(\I1_STACK_MEM/n82 ) );
  mx02d0 U73 ( .I0(\I1_STACK_MEM/Stack_Mem\[7\]\[3\] ), .I1(\PushDataIn\[3\] ), 
        .S(n49), .Z(\I1_STACK_MEM/n81 ) );
  mx02d0 U74 ( .I0(\I1_STACK_MEM/Stack_Mem\[7\]\[2\] ), .I1(\PushDataIn\[2\] ), 
        .S(n49), .Z(\I1_STACK_MEM/n80 ) );
  mx02d0 U75 ( .I0(\I1_STACK_MEM/Stack_Mem\[7\]\[1\] ), .I1(\PushDataIn\[1\] ), 
        .S(n49), .Z(\I1_STACK_MEM/n79 ) );
  mx02d0 U76 ( .I0(\I1_STACK_MEM/Stack_Mem\[7\]\[0\] ), .I1(\PushDataIn\[0\] ), 
        .S(n49), .Z(\I1_STACK_MEM/n78 ) );
  mx02d0 U77 ( .I0(n26), .I1(\TOS\[2\] ), .S(STACK_FULL), .Z(n28) );
  nr02d0 U78 ( .A1(n27), .A2(n28), .ZN(n61) );
  inv0d0 U79 ( .I(n28), .ZN(n30) );
  an02d0 U80 ( .A1(n27), .A2(n30), .Z(n59) );
  an02d0 U81 ( .A1(n28), .A2(n29), .Z(n60) );
  nr02d0 U82 ( .A1(n30), .A2(n29), .ZN(n58) );
  aoi2222d1 U83 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[0\]\[3\] ), .B1(n59), 
        .B2(\I1_STACK_MEM/Stack_Mem\[2\]\[3\] ), .C1(n60), .C2(
        \I1_STACK_MEM/Stack_Mem\[1\]\[3\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[3\]\[3\] ), .ZN(n32) );
  aoi2222d1 U84 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[4\]\[3\] ), .B1(n60), 
        .B2(\I1_STACK_MEM/Stack_Mem\[5\]\[3\] ), .C1(n59), .C2(
        \I1_STACK_MEM/Stack_Mem\[6\]\[3\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[7\]\[3\] ), .ZN(n31) );
  mi02d0 U85 ( .I0(n32), .I1(n31), .S(n62), .ZN(n33) );
  mx02d0 U86 ( .I0(\PopDataOut\[3\] ), .I1(n33), .S(PopEnbl), .Z(
        \I1_STACK_MEM/n45 ) );
  aoi2222d1 U87 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[0\]\[2\] ), .B1(n60), 
        .B2(\I1_STACK_MEM/Stack_Mem\[1\]\[2\] ), .C1(n59), .C2(
        \I1_STACK_MEM/Stack_Mem\[2\]\[2\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[3\]\[2\] ), .ZN(n35) );
  aoi2222d1 U88 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[4\]\[2\] ), .B1(n60), 
        .B2(\I1_STACK_MEM/Stack_Mem\[5\]\[2\] ), .C1(n59), .C2(
        \I1_STACK_MEM/Stack_Mem\[6\]\[2\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[7\]\[2\] ), .ZN(n34) );
  mi02d0 U89 ( .I0(n35), .I1(n34), .S(n62), .ZN(n36) );
  mx02d0 U90 ( .I0(\PopDataOut\[2\] ), .I1(n36), .S(PopEnbl), .Z(
        \I1_STACK_MEM/n43 ) );
  aoi2222d1 U91 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[0\]\[1\] ), .B1(n60), 
        .B2(\I1_STACK_MEM/Stack_Mem\[1\]\[1\] ), .C1(n59), .C2(
        \I1_STACK_MEM/Stack_Mem\[2\]\[1\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[3\]\[1\] ), .ZN(n38) );
  aoi2222d1 U92 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[4\]\[1\] ), .B1(n60), 
        .B2(\I1_STACK_MEM/Stack_Mem\[5\]\[1\] ), .C1(n59), .C2(
        \I1_STACK_MEM/Stack_Mem\[6\]\[1\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[7\]\[1\] ), .ZN(n37) );
  mi02d0 U93 ( .I0(n38), .I1(n37), .S(n62), .ZN(n39) );
  mx02d0 U94 ( .I0(\PopDataOut\[1\] ), .I1(n39), .S(PopEnbl), .Z(
        \I1_STACK_MEM/n41 ) );
  aoi2222d1 U95 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[0\]\[0\] ), .B1(n60), 
        .B2(\I1_STACK_MEM/Stack_Mem\[1\]\[0\] ), .C1(n59), .C2(
        \I1_STACK_MEM/Stack_Mem\[2\]\[0\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[3\]\[0\] ), .ZN(n41) );
  aoi2222d1 U96 ( .A1(n61), .A2(\I1_STACK_MEM/Stack_Mem\[4\]\[0\] ), .B1(n60), 
        .B2(\I1_STACK_MEM/Stack_Mem\[5\]\[0\] ), .C1(n59), .C2(
        \I1_STACK_MEM/Stack_Mem\[6\]\[0\] ), .D1(n58), .D2(
        \I1_STACK_MEM/Stack_Mem\[7\]\[0\] ), .ZN(n40) );
  mi02d0 U97 ( .I0(n41), .I1(n40), .S(n62), .ZN(n42) );
  mx02d0 U98 ( .I0(\PopDataOut\[0\] ), .I1(n42), .S(PopEnbl), .Z(
        \I1_STACK_MEM/n39 ) );
  mx02d0 U99 ( .I0(\I3_STACK_MEM/Stack_Mem\[5\]\[2\] ), .I1(\PushDataIn\[10\] ), .S(n43), .Z(\I3_STACK_MEM/n73 ) );
  mx02d0 U100 ( .I0(\I2_STACK_MEM/Stack_Mem\[0\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n66), .Z(n107) );
  mx02d0 U101 ( .I0(\I2_STACK_MEM/Stack_Mem\[0\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n66), .Z(n106) );
  mx02d0 U102 ( .I0(\I2_STACK_MEM/Stack_Mem\[0\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n66), .Z(n105) );
  mx02d0 U103 ( .I0(\I2_STACK_MEM/Stack_Mem\[0\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n66), .Z(n104) );
  mx02d0 U104 ( .I0(\I2_STACK_MEM/Stack_Mem\[1\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n67), .Z(n103) );
  mx02d0 U105 ( .I0(\I2_STACK_MEM/Stack_Mem\[1\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n67), .Z(n102) );
  mx02d0 U106 ( .I0(\I2_STACK_MEM/Stack_Mem\[1\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n67), .Z(n101) );
  mx02d0 U107 ( .I0(\I2_STACK_MEM/Stack_Mem\[1\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n67), .Z(n100) );
  mx02d0 U108 ( .I0(\I2_STACK_MEM/Stack_Mem\[2\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n57), .Z(n99) );
  mx02d0 U109 ( .I0(\I2_STACK_MEM/Stack_Mem\[2\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n57), .Z(n98) );
  mx02d0 U110 ( .I0(\I2_STACK_MEM/Stack_Mem\[2\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n57), .Z(n97) );
  mx02d0 U111 ( .I0(\I2_STACK_MEM/Stack_Mem\[2\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n57), .Z(n96) );
  mx02d0 U112 ( .I0(\I2_STACK_MEM/Stack_Mem\[3\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n50), .Z(n95) );
  mx02d0 U113 ( .I0(\I2_STACK_MEM/Stack_Mem\[3\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n50), .Z(n94) );
  mx02d0 U114 ( .I0(\I2_STACK_MEM/Stack_Mem\[3\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n50), .Z(n93) );
  mx02d0 U115 ( .I0(\I2_STACK_MEM/Stack_Mem\[3\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n50), .Z(n92) );
  mx02d0 U116 ( .I0(\I2_STACK_MEM/Stack_Mem\[4\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n44), .Z(n91) );
  mx02d0 U117 ( .I0(\I2_STACK_MEM/Stack_Mem\[4\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n44), .Z(n90) );
  mx02d0 U118 ( .I0(\I2_STACK_MEM/Stack_Mem\[4\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n44), .Z(n89) );
  mx02d0 U119 ( .I0(\I2_STACK_MEM/Stack_Mem\[4\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n44), .Z(n88) );
  mx02d0 U120 ( .I0(\I2_STACK_MEM/Stack_Mem\[5\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n43), .Z(n87) );
  mx02d0 U121 ( .I0(\I3_STACK_MEM/Stack_Mem\[4\]\[1\] ), .I1(\PushDataIn\[9\] ), .S(n44), .Z(\I3_STACK_MEM/n75 ) );
  mx02d0 U122 ( .I0(\I2_STACK_MEM/Stack_Mem\[5\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n43), .Z(n86) );
  mx02d0 U123 ( .I0(\I2_STACK_MEM/Stack_Mem\[5\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n43), .Z(n85) );
  mx02d0 U124 ( .I0(\I3_STACK_MEM/Stack_Mem\[2\]\[1\] ), .I1(\PushDataIn\[9\] ), .S(n57), .Z(\I3_STACK_MEM/n81 ) );
  mx02d0 U125 ( .I0(\I2_STACK_MEM/Stack_Mem\[5\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n43), .Z(n84) );
  mx02d0 U126 ( .I0(\I2_STACK_MEM/Stack_Mem\[7\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n49), .Z(n79) );
  mx02d0 U127 ( .I0(\I2_STACK_MEM/Stack_Mem\[6\]\[3\] ), .I1(\PushDataIn\[7\] ), .S(n48), .Z(n83) );
  mx02d0 U128 ( .I0(\I3_STACK_MEM/Stack_Mem\[4\]\[2\] ), .I1(
        \PushDataIn\[10\] ), .S(n44), .Z(\I3_STACK_MEM/n76 ) );
  mx02d0 U129 ( .I0(\I2_STACK_MEM/Stack_Mem\[6\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n48), .Z(n82) );
  mx02d0 U130 ( .I0(\I2_STACK_MEM/Stack_Mem\[7\]\[2\] ), .I1(\PushDataIn\[6\] ), .S(n49), .Z(n78) );
  mx02d0 U131 ( .I0(\I2_STACK_MEM/Stack_Mem\[6\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n48), .Z(n81) );
  aoi2222d1 U132 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[0\]\[1\] ), .B1(n60), 
        .B2(\I2_STACK_MEM/Stack_Mem\[1\]\[1\] ), .C1(n59), .C2(
        \I2_STACK_MEM/Stack_Mem\[2\]\[1\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[3\]\[1\] ), .ZN(n46) );
  aoi2222d1 U133 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[4\]\[1\] ), .B1(n60), 
        .B2(\I2_STACK_MEM/Stack_Mem\[5\]\[1\] ), .C1(n59), .C2(
        \I2_STACK_MEM/Stack_Mem\[6\]\[1\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[7\]\[1\] ), .ZN(n45) );
  mi02d0 U134 ( .I0(n46), .I1(n45), .S(n62), .ZN(n47) );
  mx02d0 U135 ( .I0(\PopDataOut\[5\] ), .I1(n47), .S(PopEnbl), .Z(n73) );
  mx02d0 U136 ( .I0(\I2_STACK_MEM/Stack_Mem\[7\]\[1\] ), .I1(\PushDataIn\[5\] ), .S(n49), .Z(n77) );
  mx02d0 U137 ( .I0(\I2_STACK_MEM/Stack_Mem\[6\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n48), .Z(n80) );
  mx02d0 U138 ( .I0(\I3_STACK_MEM/Stack_Mem\[3\]\[1\] ), .I1(\PushDataIn\[9\] ), .S(n50), .Z(\I3_STACK_MEM/n78 ) );
  mx02d0 U139 ( .I0(\I2_STACK_MEM/Stack_Mem\[7\]\[0\] ), .I1(\PushDataIn\[4\] ), .S(n49), .Z(n76) );
  mx02d0 U140 ( .I0(\I3_STACK_MEM/Stack_Mem\[3\]\[2\] ), .I1(
        \PushDataIn\[10\] ), .S(n50), .Z(\I3_STACK_MEM/n79 ) );
  aoi2222d1 U141 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[0\]\[3\] ), .B1(n59), 
        .B2(\I2_STACK_MEM/Stack_Mem\[2\]\[3\] ), .C1(n60), .C2(
        \I2_STACK_MEM/Stack_Mem\[1\]\[3\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[3\]\[3\] ), .ZN(n52) );
  aoi2222d1 U142 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[4\]\[3\] ), .B1(n60), 
        .B2(\I2_STACK_MEM/Stack_Mem\[5\]\[3\] ), .C1(n59), .C2(
        \I2_STACK_MEM/Stack_Mem\[6\]\[3\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[7\]\[3\] ), .ZN(n51) );
  mi02d0 U143 ( .I0(n52), .I1(n51), .S(n62), .ZN(n53) );
  mx02d0 U144 ( .I0(\PopDataOut\[7\] ), .I1(n53), .S(PopEnbl), .Z(n75) );
  aoi2222d1 U145 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[0\]\[0\] ), .B1(n60), 
        .B2(\I2_STACK_MEM/Stack_Mem\[1\]\[0\] ), .C1(n59), .C2(
        \I2_STACK_MEM/Stack_Mem\[2\]\[0\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[3\]\[0\] ), .ZN(n55) );
  aoi2222d1 U146 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[4\]\[0\] ), .B1(n60), 
        .B2(\I2_STACK_MEM/Stack_Mem\[5\]\[0\] ), .C1(n59), .C2(
        \I2_STACK_MEM/Stack_Mem\[6\]\[0\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[7\]\[0\] ), .ZN(n54) );
  mi02d0 U147 ( .I0(n55), .I1(n54), .S(n62), .ZN(n56) );
  mx02d0 U148 ( .I0(\PopDataOut\[4\] ), .I1(n56), .S(PopEnbl), .Z(n72) );
  mx02d0 U149 ( .I0(\I3_STACK_MEM/Stack_Mem\[2\]\[2\] ), .I1(
        \PushDataIn\[10\] ), .S(n57), .Z(\I3_STACK_MEM/n82 ) );
  mx02d0 U150 ( .I0(\I3_STACK_MEM/Stack_Mem\[0\]\[2\] ), .I1(
        \PushDataIn\[10\] ), .S(n66), .Z(\I3_STACK_MEM/n88 ) );
  aoi2222d1 U151 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[0\]\[2\] ), .B1(n60), 
        .B2(\I2_STACK_MEM/Stack_Mem\[1\]\[2\] ), .C1(n59), .C2(
        \I2_STACK_MEM/Stack_Mem\[2\]\[2\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[3\]\[2\] ), .ZN(n64) );
  aoi2222d1 U152 ( .A1(n61), .A2(\I2_STACK_MEM/Stack_Mem\[4\]\[2\] ), .B1(n60), 
        .B2(\I2_STACK_MEM/Stack_Mem\[5\]\[2\] ), .C1(n59), .C2(
        \I2_STACK_MEM/Stack_Mem\[6\]\[2\] ), .D1(n58), .D2(
        \I2_STACK_MEM/Stack_Mem\[7\]\[2\] ), .ZN(n63) );
  mi02d0 U153 ( .I0(n64), .I1(n63), .S(n62), .ZN(n65) );
  mx02d0 U154 ( .I0(\PopDataOut\[6\] ), .I1(n65), .S(PopEnbl), .Z(n74) );
  mx02d0 U155 ( .I0(\I3_STACK_MEM/Stack_Mem\[0\]\[1\] ), .I1(\PushDataIn\[9\] ), .S(n66), .Z(\I3_STACK_MEM/n87 ) );
  mx02d0 U156 ( .I0(\I3_STACK_MEM/Stack_Mem\[1\]\[1\] ), .I1(\PushDataIn\[9\] ), .S(n67), .Z(\I3_STACK_MEM/n84 ) );
  mx02d0 U157 ( .I0(\I3_STACK_MEM/Stack_Mem\[1\]\[2\] ), .I1(
        \PushDataIn\[10\] ), .S(n67), .Z(\I3_STACK_MEM/n85 ) );
  inv0d0 U158 ( .I(Clk), .ZN(n68) );
  inv0d1 U159 ( .I(n68), .ZN(n69) );
endmodule


module RISC_CORE ( Clk, Reset, .Instrn({\Instrn\[31\] , \Instrn\[30\] , 
        \Instrn\[29\] , \Instrn\[28\] , \Instrn\[27\] , \Instrn\[26\] , 
        \Instrn\[25\] , \Instrn\[24\] , \Instrn\[23\] , \Instrn\[22\] , 
        \Instrn\[21\] , \Instrn\[20\] , \Instrn\[19\] , \Instrn\[18\] , 
        \Instrn\[17\] , \Instrn\[16\] , \Instrn\[15\] , \Instrn\[14\] , 
        \Instrn\[13\] , \Instrn\[12\] , \Instrn\[11\] , \Instrn\[10\] , 
        \Instrn\[9\] , \Instrn\[8\] , \Instrn\[7\] , \Instrn\[6\] , 
        \Instrn\[5\] , \Instrn\[4\] , \Instrn\[3\] , \Instrn\[2\] , 
        \Instrn\[1\] , \Instrn\[0\] }), .Xecutng_Instrn({
        \Xecutng_Instrn\[31\] , \Xecutng_Instrn\[30\] , \Xecutng_Instrn\[29\] , 
        \Xecutng_Instrn\[28\] , \Xecutng_Instrn\[27\] , \Xecutng_Instrn\[26\] , 
        \Xecutng_Instrn\[25\] , \Xecutng_Instrn\[24\] , \Xecutng_Instrn\[23\] , 
        \Xecutng_Instrn\[22\] , \Xecutng_Instrn\[21\] , \Xecutng_Instrn\[20\] , 
        \Xecutng_Instrn\[19\] , \Xecutng_Instrn\[18\] , \Xecutng_Instrn\[17\] , 
        \Xecutng_Instrn\[16\] , \Xecutng_Instrn\[15\] , \Xecutng_Instrn\[14\] , 
        \Xecutng_Instrn\[13\] , \Xecutng_Instrn\[12\] , \Xecutng_Instrn\[11\] , 
        \Xecutng_Instrn\[10\] , \Xecutng_Instrn\[9\] , \Xecutng_Instrn\[8\] , 
        \Xecutng_Instrn\[7\] , \Xecutng_Instrn\[6\] , \Xecutng_Instrn\[5\] , 
        \Xecutng_Instrn\[4\] , \Xecutng_Instrn\[3\] , \Xecutng_Instrn\[2\] , 
        \Xecutng_Instrn\[1\] , \Xecutng_Instrn\[0\] }), EndOfInstrn, .PSW({
        \PSW\[10\] , \PSW\[9\] , \PSW\[8\] , \PSW\[7\] , \PSW\[6\] , 
        \PSW\[5\] , \PSW\[4\] , \PSW\[3\] , \PSW\[2\] , \PSW\[1\] , \PSW\[0\] 
        }), Rd_Instr, .RESULT_DATA({\RESULT_DATA\[15\] , \RESULT_DATA\[14\] , 
        \RESULT_DATA\[13\] , \RESULT_DATA\[12\] , \RESULT_DATA\[11\] , 
        \RESULT_DATA\[10\] , \RESULT_DATA\[9\] , \RESULT_DATA\[8\] , 
        \RESULT_DATA\[7\] , \RESULT_DATA\[6\] , \RESULT_DATA\[5\] , 
        \RESULT_DATA\[4\] , \RESULT_DATA\[3\] , \RESULT_DATA\[2\] , 
        \RESULT_DATA\[1\] , \RESULT_DATA\[0\] }), OUT_VALID, STACK_FULL, 
        TEST_SE, TEST_MODE );
  input Clk, Reset, \Instrn\[31\] , \Instrn\[30\] , \Instrn\[29\] ,
         \Instrn\[28\] , \Instrn\[27\] , \Instrn\[26\] , \Instrn\[25\] ,
         \Instrn\[24\] , \Instrn\[23\] , \Instrn\[22\] , \Instrn\[21\] ,
         \Instrn\[20\] , \Instrn\[19\] , \Instrn\[18\] , \Instrn\[17\] ,
         \Instrn\[16\] , \Instrn\[15\] , \Instrn\[14\] , \Instrn\[13\] ,
         \Instrn\[12\] , \Instrn\[11\] , \Instrn\[10\] , \Instrn\[9\] ,
         \Instrn\[8\] , \Instrn\[7\] , \Instrn\[6\] , \Instrn\[5\] ,
         \Instrn\[4\] , \Instrn\[3\] , \Instrn\[2\] , \Instrn\[1\] ,
         \Instrn\[0\] , TEST_SE, TEST_MODE;
  output \Xecutng_Instrn\[31\] , \Xecutng_Instrn\[30\] ,
         \Xecutng_Instrn\[29\] , \Xecutng_Instrn\[28\] ,
         \Xecutng_Instrn\[27\] , \Xecutng_Instrn\[26\] ,
         \Xecutng_Instrn\[25\] , \Xecutng_Instrn\[24\] ,
         \Xecutng_Instrn\[23\] , \Xecutng_Instrn\[22\] ,
         \Xecutng_Instrn\[21\] , \Xecutng_Instrn\[20\] ,
         \Xecutng_Instrn\[19\] , \Xecutng_Instrn\[18\] ,
         \Xecutng_Instrn\[17\] , \Xecutng_Instrn\[16\] ,
         \Xecutng_Instrn\[15\] , \Xecutng_Instrn\[14\] ,
         \Xecutng_Instrn\[13\] , \Xecutng_Instrn\[12\] ,
         \Xecutng_Instrn\[11\] , \Xecutng_Instrn\[10\] , \Xecutng_Instrn\[9\] ,
         \Xecutng_Instrn\[8\] , \Xecutng_Instrn\[7\] , \Xecutng_Instrn\[6\] ,
         \Xecutng_Instrn\[5\] , \Xecutng_Instrn\[4\] , \Xecutng_Instrn\[3\] ,
         \Xecutng_Instrn\[2\] , \Xecutng_Instrn\[1\] , \Xecutng_Instrn\[0\] ,
         EndOfInstrn, \PSW\[10\] , \PSW\[9\] , \PSW\[8\] , \PSW\[7\] ,
         \PSW\[6\] , \PSW\[5\] , \PSW\[4\] , \PSW\[3\] , \PSW\[2\] ,
         \PSW\[1\] , \PSW\[0\] , Rd_Instr, \RESULT_DATA\[15\] ,
         \RESULT_DATA\[14\] , \RESULT_DATA\[13\] , \RESULT_DATA\[12\] ,
         \RESULT_DATA\[11\] , \RESULT_DATA\[10\] , \RESULT_DATA\[9\] ,
         \RESULT_DATA\[8\] , \RESULT_DATA\[7\] , \RESULT_DATA\[6\] ,
         \RESULT_DATA\[5\] , \RESULT_DATA\[4\] , \RESULT_DATA\[3\] ,
         \RESULT_DATA\[2\] , \RESULT_DATA\[1\] , \RESULT_DATA\[0\] , OUT_VALID,
         STACK_FULL;
  wire   n274, \Return_Addr\[7\] , \Return_Addr\[6\] , \Return_Addr\[5\] ,
         \Return_Addr\[4\] , \Return_Addr\[3\] , \Return_Addr\[2\] ,
         \Return_Addr\[1\] , \Return_Addr\[0\] , \PopDataOut\[10\] ,
         \PopDataOut\[9\] , INTERNAL_RESET, Div_Clk_sig, \Oprnd_A\[15\] ,
         \Oprnd_A\[14\] , \Oprnd_A\[13\] , \Oprnd_A\[12\] , \Oprnd_A\[11\] ,
         \Oprnd_A\[10\] , \Oprnd_A\[9\] , \Oprnd_A\[8\] , \Oprnd_A\[7\] ,
         \Oprnd_A\[6\] , \Oprnd_A\[5\] , \Oprnd_A\[4\] , \Oprnd_A\[3\] ,
         \Oprnd_A\[2\] , \Oprnd_A\[1\] , \Oprnd_A\[0\] , \Oprnd_B\[15\] ,
         \Oprnd_B\[14\] , \Oprnd_B\[13\] , \Oprnd_B\[12\] , \Oprnd_B\[11\] ,
         \Oprnd_B\[10\] , \Oprnd_B\[9\] , \Oprnd_B\[8\] , \Oprnd_B\[7\] ,
         \Oprnd_B\[6\] , \Oprnd_B\[5\] , \Oprnd_B\[4\] , \Oprnd_B\[3\] ,
         \Oprnd_B\[2\] , \Oprnd_B\[1\] , \Oprnd_B\[0\] , Latch_Result,
         Latch_Flags, \Op_Result\[15\] , \Op_Result\[14\] , \Op_Result\[13\] ,
         \Op_Result\[12\] , \Op_Result\[11\] , \Op_Result\[10\] ,
         \Op_Result\[9\] , \Op_Result\[8\] , \Op_Result\[7\] ,
         \Op_Result\[6\] , \Op_Result\[5\] , \Op_Result\[4\] ,
         \Op_Result\[3\] , \Op_Result\[2\] , \Op_Result\[1\] ,
         \Op_Result\[0\] , ALU_Zro, ALU_Neg, \Crnt_Instrn_2\[31\] ,
         \Crnt_Instrn_2\[30\] , \Crnt_Instrn_2\[29\] , \Crnt_Instrn_2\[28\] ,
         \Crnt_Instrn_2\[27\] , \Crnt_Instrn_2\[26\] , \Crnt_Instrn_2\[25\] ,
         \Crnt_Instrn_2\[24\] , \Crnt_Instrn_2\[23\] , \Crnt_Instrn_2\[22\] ,
         \Crnt_Instrn_2\[21\] , \Crnt_Instrn_2\[20\] , \Crnt_Instrn_2\[19\] ,
         \Crnt_Instrn_2\[18\] , \Crnt_Instrn_2\[17\] , \Crnt_Instrn_2\[16\] ,
         \Crnt_Instrn_2\[15\] , \Crnt_Instrn_2\[14\] , \Crnt_Instrn_2\[13\] ,
         \Crnt_Instrn_2\[12\] , \Crnt_Instrn_2\[11\] , \Crnt_Instrn_2\[10\] ,
         \Crnt_Instrn_2\[9\] , \Crnt_Instrn_2\[8\] , \Crnt_Instrn_2\[7\] ,
         \Crnt_Instrn_2\[6\] , \Crnt_Instrn_2\[5\] , \Crnt_Instrn_2\[4\] ,
         \Crnt_Instrn_2\[3\] , \Crnt_Instrn_2\[2\] , \Crnt_Instrn_2\[1\] ,
         \Crnt_Instrn_2\[0\] , \Current_State\[0\] , \Current_State\[1\] ,
         \Current_State\[2\] , Rd_Oprnd_A, Rd_Oprnd_B, Write_RegC,
         UseData_Imm_Or_RegB, UseData_Imm_Or_ALU, Reset_AluRegs, PushEnbl,
         PopEnbl, \RegPort_B\[15\] , \RegPort_B\[14\] , \RegPort_B\[13\] ,
         \RegPort_B\[12\] , \RegPort_B\[11\] , \RegPort_B\[10\] ,
         \RegPort_B\[9\] , \RegPort_B\[8\] , \RegPort_B\[7\] ,
         \RegPort_B\[6\] , \RegPort_B\[5\] , \RegPort_B\[4\] ,
         \RegPort_B\[3\] , \RegPort_B\[2\] , \RegPort_B\[1\] ,
         \RegPort_B\[0\] , \Addr_A\[1\] , \Addr_A\[0\] , \RegPort_C\[15\] ,
         \RegPort_C\[14\] , \RegPort_C\[13\] , \RegPort_C\[12\] ,
         \RegPort_C\[11\] , \RegPort_C\[10\] , \RegPort_C\[9\] ,
         \RegPort_C\[8\] , \RegPort_C\[7\] , \RegPort_C\[6\] ,
         \RegPort_C\[5\] , \RegPort_C\[4\] , \RegPort_C\[3\] ,
         \RegPort_C\[2\] , \RegPort_C\[1\] , \RegPort_C\[0\] , \I_ALU/n178 ,
         \I_ALU/n177 , \I_ALU/n176 , \I_ALU/n175 , \I_ALU/n174 , \I_ALU/n173 ,
         \I_ALU/n172 , \I_ALU/n171 , \I_ALU/n170 , \I_ALU/n169 , \I_ALU/n168 ,
         \I_ALU/n167 , \I_ALU/n166 , \I_ALU/n165 , \I_ALU/n164 , \I_ALU/n163 ,
         \I_ALU/n162 , \I_ALU/n161 , \I_ALU/C3/DATA19_14 ,
         \I_ALU/C3/DATA19_13 , \I_ALU/C3/DATA19_12 , \I_ALU/C3/DATA19_11 ,
         \I_ALU/C3/DATA19_10 , \I_ALU/C3/DATA19_9 , \I_ALU/C3/DATA19_8 ,
         \I_ALU/C3/DATA19_7 , \I_ALU/C3/DATA19_6 , \I_ALU/C3/DATA19_5 ,
         \I_ALU/C3/DATA19_4 , \I_ALU/C3/DATA19_3 , \I_ALU/C3/DATA19_2 ,
         \I_ALU/C3/DATA19_1 , \I_ALU/N181 , \I_ALU/N180 , \I_ALU/N179 ,
         \I_ALU/N178 , \I_ALU/N177 , \I_ALU/N176 , \I_ALU/N175 , \I_ALU/N174 ,
         \I_ALU/N173 , \I_ALU/N172 , \I_ALU/N171 , \I_ALU/N170 , \I_ALU/N169 ,
         \I_ALU/N168 , \I_ALU/N117 , \I_ALU/N116 , \I_ALU/N115 , \I_ALU/N114 ,
         \I_ALU/N113 , \I_ALU/N112 , \I_ALU/N111 , \I_ALU/N110 , \I_ALU/N109 ,
         \I_ALU/N108 , \I_ALU/N107 , \I_ALU/N106 , \I_ALU/N105 , \I_ALU/N104 ,
         \I_ALU/N103 , \I_ALU/C1/Z_0 , \I_ALU/DP_OP_47J1_122_1374/n129 ,
         \I_ALU/DP_OP_47J1_122_1374/n128 , \I_ALU/DP_OP_47J1_122_1374/n127 ,
         \I_ALU/DP_OP_47J1_122_1374/n126 , \I_ALU/DP_OP_47J1_122_1374/n125 ,
         \I_ALU/DP_OP_47J1_122_1374/n124 , \I_ALU/DP_OP_47J1_122_1374/n123 ,
         \I_ALU/DP_OP_47J1_122_1374/n122 , \I_ALU/DP_OP_47J1_122_1374/n121 ,
         \I_ALU/DP_OP_47J1_122_1374/n120 , \I_ALU/DP_OP_47J1_122_1374/n119 ,
         \I_ALU/DP_OP_47J1_122_1374/n118 , \I_ALU/DP_OP_47J1_122_1374/n117 ,
         \I_ALU/DP_OP_47J1_122_1374/n116 , \I_ALU/DP_OP_47J1_122_1374/n111 ,
         \I_ALU/DP_OP_47J1_122_1374/n110 , \I_ALU/DP_OP_47J1_122_1374/n109 ,
         \I_ALU/DP_OP_47J1_122_1374/n108 , \I_ALU/DP_OP_47J1_122_1374/n107 ,
         \I_ALU/DP_OP_47J1_122_1374/n106 , \I_ALU/DP_OP_47J1_122_1374/n105 ,
         \I_ALU/DP_OP_47J1_122_1374/n104 , \I_ALU/DP_OP_47J1_122_1374/n103 ,
         \I_ALU/DP_OP_47J1_122_1374/n102 , \I_ALU/DP_OP_47J1_122_1374/n101 ,
         \I_ALU/DP_OP_47J1_122_1374/n100 , \I_ALU/DP_OP_47J1_122_1374/n99 ,
         \I_ALU/DP_OP_47J1_122_1374/n98 , \I_ALU/DP_OP_47J1_122_1374/n97 ,
         \I_ALU/DP_OP_47J1_122_1374/n79 , \I_ALU/DP_OP_47J1_122_1374/n78 ,
         \I_ALU/DP_OP_47J1_122_1374/n77 , \I_ALU/DP_OP_47J1_122_1374/n76 ,
         \I_ALU/DP_OP_47J1_122_1374/n75 , \I_ALU/DP_OP_47J1_122_1374/n74 ,
         \I_ALU/DP_OP_47J1_122_1374/n73 , \I_ALU/DP_OP_47J1_122_1374/n72 ,
         \I_ALU/DP_OP_47J1_122_1374/n71 , \I_ALU/DP_OP_47J1_122_1374/n70 ,
         \I_ALU/DP_OP_47J1_122_1374/n69 , \I_ALU/DP_OP_47J1_122_1374/n68 ,
         \I_ALU/DP_OP_47J1_122_1374/n67 , \I_ALU/DP_OP_47J1_122_1374/n66 ,
         \I_ALU/DP_OP_47J1_122_1374/n65 , \I_ALU/DP_OP_47J1_122_1374/n16 ,
         \I_ALU/DP_OP_47J1_122_1374/n15 , \I_ALU/DP_OP_47J1_122_1374/n14 ,
         \I_ALU/DP_OP_47J1_122_1374/n13 , \I_ALU/DP_OP_47J1_122_1374/n12 ,
         \I_ALU/DP_OP_47J1_122_1374/n11 , \I_ALU/DP_OP_47J1_122_1374/n10 ,
         \I_ALU/DP_OP_47J1_122_1374/n9 , \I_ALU/DP_OP_47J1_122_1374/n8 ,
         \I_ALU/DP_OP_47J1_122_1374/n7 , \I_ALU/DP_OP_47J1_122_1374/n6 ,
         \I_ALU/DP_OP_47J1_122_1374/n5 , \I_ALU/DP_OP_47J1_122_1374/n4 ,
         \I_ALU/DP_OP_47J1_122_1374/n3 , \I_ALU/DP_OP_47J1_122_1374/n2 , n55,
         n56, n57, n58, n59, n60, n61, n62, n63, n64, n65, n66, n67, n68, n69,
         n70, n71, n72, n73, n74, n75, n76, n77, n78, n79, n80, n81, n82, n83,
         n84, n85, n86, n87, n88, n89, n90, n91, n92, n93, n94, n95, n96, n97,
         n98, n99, n100, n101, n102, n103, n104, n105, n106, n107, n108, n109,
         n110, n111, n112, n113, n114, n115, n116, n117, n118, n119, n120,
         n121, n122, n123, n124, n125, n126, n127, n128, n129, n130, n131,
         n132, n133, n134, n135, n136, n137, n138, n139, n140, n141, n142,
         n143, n144, n145, n146, n147, n148, n149, n150, n151, n152, n153,
         n154, n155, n156, n157, n158, n159, n160, n161, n162, n163, n164,
         n165, n166, n167, n168, n169, n170, n171, n172, n173, n174, n175,
         n176, n177, n178, n179, n180, n181, n182, n183, n184, n185, n186,
         n187, n188, n189, n190, n191, n192, n193, n194, n195, n196, n197,
         n198, n199, n200, n201, n202, n203, n204, n205, n206, n207, n208,
         n209, n210, n211, n212, n213, n214, n215, n216, n217, n218, n219,
         n220, n221, n222, n223, n224, n225, n226, n227, n228, n229, n230,
         n231, n232, n233, n234, n235, n236, n237, n238, n239, n240, n241,
         n242, n243, n244, n245, n246, n247, n248, n249, n250, n251, n252,
         n253, n254, n255, n256, n257, n258, n259, n260, n261, n262, n263,
         n264, n268, n269, n270, n271, n272, n275, n276, n277, n278, n279;
  wire   SYNOPSYS_UNCONNECTED__0, SYNOPSYS_UNCONNECTED__1, 
        SYNOPSYS_UNCONNECTED__2, SYNOPSYS_UNCONNECTED__3, 
        SYNOPSYS_UNCONNECTED__4, SYNOPSYS_UNCONNECTED__5, 
        SYNOPSYS_UNCONNECTED__6;
  assign \PSW\[0\]  = 1'b0;

  CONTROL I_CONTROL ( .Clk(n57), .INTERNAL_RESET(INTERNAL_RESET), 
        .Crnt_Instrn({\Crnt_Instrn_2\[31\] , \Crnt_Instrn_2\[30\] , 1'b0, 
        \Crnt_Instrn_2\[28\] , \Crnt_Instrn_2\[27\] , 1'b0, 
        \Crnt_Instrn_2\[25\] , \Crnt_Instrn_2\[24\] , \Crnt_Instrn_2\[23\] , 
        \Crnt_Instrn_2\[22\] , \Crnt_Instrn_2\[21\] , \Crnt_Instrn_2\[20\] , 
        \Crnt_Instrn_2\[19\] , \Crnt_Instrn_2\[18\] , \Crnt_Instrn_2\[17\] , 
        \Crnt_Instrn_2\[16\] , 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0}), .Current_State({
        \Current_State\[0\] , \Current_State\[1\] , \Current_State\[2\] }), 
        .Neg_Flag(\PSW\[1\] ), .Carry_Flag(1'b0), .Zro_Flag(\PSW\[2\] ), 
        .Latch_Instr(Rd_Instr), .Rd_Oprnd_A(Rd_Oprnd_A), .Rd_Oprnd_B(
        Rd_Oprnd_B), .Latch_Flags(Latch_Flags), .Latch_Result(Latch_Result), 
        .Write_RegC(Write_RegC), .UseData_Imm_Or_RegB(UseData_Imm_Or_RegB), 
        .UseData_Imm_Or_ALU(UseData_Imm_Or_ALU), .Reset_AluRegs(Reset_AluRegs), 
        .EndOfInstrn(EndOfInstrn), .PushEnbl(PushEnbl), .PopEnbl(PopEnbl), 
        .OUT_VALID(OUT_VALID), .test_si(ALU_Zro), .test_se(n278) );
  DIV_CLK I_DIV_CLK ( .TEST_MODE(1'b0), .INTERNAL_RESET(INTERNAL_RESET), .Clk(
        Clk), .DIV_CLK(Div_Clk_sig), .test_si(n271), .test_se(n278) );
  DATA_PATH I_DATA_PATH ( .Clk(Div_Clk_sig), .INTERNAL_RESET(INTERNAL_RESET), 
        .Reset_AluRegs(Reset_AluRegs), .Rd_Oprnd_A(Rd_Oprnd_A), .Rd_Oprnd_B(
        Rd_Oprnd_B), .UseData_Imm_Or_RegB(UseData_Imm_Or_RegB), 
        .UseData_Imm_Or_ALU(UseData_Imm_Or_ALU), .Latch_Flags(Latch_Flags), 
        .ALU_Zro(ALU_Zro), .ALU_Neg(ALU_Neg), .ALU_Carry(1'b0), .PSW_Zro(
        \PopDataOut\[10\] ), .PSW_Neg(\PopDataOut\[9\] ), .PSW_Carry(1'b0), 
        .Crnt_Instrn({\Crnt_Instrn_2\[31\] , \Crnt_Instrn_2\[30\] , 
        \Crnt_Instrn_2\[29\] , \Crnt_Instrn_2\[28\] , \Crnt_Instrn_2\[27\] , 
        \Crnt_Instrn_2\[26\] , \Crnt_Instrn_2\[25\] , \Crnt_Instrn_2\[24\] , 
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, \Crnt_Instrn_2\[15\] , 
        \Crnt_Instrn_2\[14\] , \Crnt_Instrn_2\[13\] , \Crnt_Instrn_2\[12\] , 
        \Crnt_Instrn_2\[11\] , \Crnt_Instrn_2\[10\] , \Crnt_Instrn_2\[9\] , 
        \Crnt_Instrn_2\[8\] , \Crnt_Instrn_2\[7\] , \Crnt_Instrn_2\[6\] , 
        \Crnt_Instrn_2\[5\] , \Crnt_Instrn_2\[4\] , \Crnt_Instrn_2\[3\] , 
        \Crnt_Instrn_2\[2\] , \Crnt_Instrn_2\[1\] , \Crnt_Instrn_2\[0\] }), 
        .RegPort_A({\RESULT_DATA\[15\] , \RESULT_DATA\[14\] , 
        \RESULT_DATA\[13\] , \RESULT_DATA\[12\] , \RESULT_DATA\[11\] , 
        \RESULT_DATA\[10\] , \RESULT_DATA\[9\] , \RESULT_DATA\[8\] , 
        \RESULT_DATA\[7\] , \RESULT_DATA\[6\] , \RESULT_DATA\[5\] , 
        \RESULT_DATA\[4\] , \RESULT_DATA\[3\] , \RESULT_DATA\[2\] , 
        \RESULT_DATA\[1\] , \RESULT_DATA\[0\] }), .RegPort_B({
        \RegPort_B\[15\] , \RegPort_B\[14\] , \RegPort_B\[13\] , 
        \RegPort_B\[12\] , \RegPort_B\[11\] , \RegPort_B\[10\] , 
        \RegPort_B\[9\] , \RegPort_B\[8\] , \RegPort_B\[7\] , \RegPort_B\[6\] , 
        \RegPort_B\[5\] , \RegPort_B\[4\] , \RegPort_B\[3\] , \RegPort_B\[2\] , 
        \RegPort_B\[1\] , \RegPort_B\[0\] }), .Op_Result({\Op_Result\[15\] , 
        \Op_Result\[14\] , \Op_Result\[13\] , \Op_Result\[12\] , 
        \Op_Result\[11\] , \Op_Result\[10\] , \Op_Result\[9\] , 
        \Op_Result\[8\] , \Op_Result\[7\] , \Op_Result\[6\] , \Op_Result\[5\] , 
        \Op_Result\[4\] , \Op_Result\[3\] , \Op_Result\[2\] , \Op_Result\[1\] , 
        \Op_Result\[0\] }), .Zro_Flag(\PSW\[2\] ), .Neg_Flag(\PSW\[1\] ), 
        .Addr_A({SYNOPSYS_UNCONNECTED__0, SYNOPSYS_UNCONNECTED__1, 
        SYNOPSYS_UNCONNECTED__2, SYNOPSYS_UNCONNECTED__3, 
        SYNOPSYS_UNCONNECTED__4, \Addr_A\[1\] , \Addr_A\[0\] }), .Oprnd_A({
        \Oprnd_A\[15\] , \Oprnd_A\[14\] , \Oprnd_A\[13\] , \Oprnd_A\[12\] , 
        \Oprnd_A\[11\] , \Oprnd_A\[10\] , \Oprnd_A\[9\] , \Oprnd_A\[8\] , 
        \Oprnd_A\[7\] , \Oprnd_A\[6\] , \Oprnd_A\[5\] , \Oprnd_A\[4\] , 
        \Oprnd_A\[3\] , \Oprnd_A\[2\] , \Oprnd_A\[1\] , \Oprnd_A\[0\] }), 
        .Oprnd_B({\Oprnd_B\[15\] , \Oprnd_B\[14\] , \Oprnd_B\[13\] , 
        \Oprnd_B\[12\] , \Oprnd_B\[11\] , \Oprnd_B\[10\] , \Oprnd_B\[9\] , 
        \Oprnd_B\[8\] , \Oprnd_B\[7\] , \Oprnd_B\[6\] , \Oprnd_B\[5\] , 
        \Oprnd_B\[4\] , \Oprnd_B\[3\] , \Oprnd_B\[2\] , \Oprnd_B\[1\] , 
        \Oprnd_B\[0\] }), .RegPort_C({\RegPort_C\[15\] , \RegPort_C\[14\] , 
        \RegPort_C\[13\] , \RegPort_C\[12\] , \RegPort_C\[11\] , 
        \RegPort_C\[10\] , \RegPort_C\[9\] , \RegPort_C\[8\] , 
        \RegPort_C\[7\] , \RegPort_C\[6\] , \RegPort_C\[5\] , \RegPort_C\[4\] , 
        \RegPort_C\[3\] , \RegPort_C\[2\] , \RegPort_C\[1\] , \RegPort_C\[0\] }), .RISC_CORE_test_point_375_in(n272), .test_so(n271), .test_se(n278) );
  INSTRN_LAT I_INSTRN_LAT ( .Clk(n57), .Instrn({\Instrn\[31\] , \Instrn\[30\] , 
        \Instrn\[29\] , \Instrn\[28\] , \Instrn\[27\] , \Instrn\[26\] , 
        \Instrn\[25\] , \Instrn\[24\] , \Instrn\[23\] , \Instrn\[22\] , 
        \Instrn\[21\] , \Instrn\[20\] , \Instrn\[19\] , \Instrn\[18\] , 
        \Instrn\[17\] , \Instrn\[16\] , \Instrn\[15\] , \Instrn\[14\] , 
        \Instrn\[13\] , \Instrn\[12\] , \Instrn\[11\] , \Instrn\[10\] , 
        \Instrn\[9\] , \Instrn\[8\] , \Instrn\[7\] , \Instrn\[6\] , 
        \Instrn\[5\] , \Instrn\[4\] , \Instrn\[3\] , \Instrn\[2\] , 
        \Instrn\[1\] , \Instrn\[0\] }), .Latch_Instr(Rd_Instr), 
        .Crnt_Instrn_1({\Xecutng_Instrn\[31\] , \Xecutng_Instrn\[30\] , 
        \Xecutng_Instrn\[29\] , \Xecutng_Instrn\[28\] , \Xecutng_Instrn\[27\] , 
        \Xecutng_Instrn\[26\] , \Xecutng_Instrn\[25\] , \Xecutng_Instrn\[24\] , 
        \Xecutng_Instrn\[23\] , \Xecutng_Instrn\[22\] , \Xecutng_Instrn\[21\] , 
        \Xecutng_Instrn\[20\] , \Xecutng_Instrn\[19\] , \Xecutng_Instrn\[18\] , 
        \Xecutng_Instrn\[17\] , \Xecutng_Instrn\[16\] , \Xecutng_Instrn\[15\] , 
        \Xecutng_Instrn\[14\] , \Xecutng_Instrn\[13\] , \Xecutng_Instrn\[12\] , 
        \Xecutng_Instrn\[11\] , \Xecutng_Instrn\[10\] , \Xecutng_Instrn\[9\] , 
        \Xecutng_Instrn\[8\] , \Xecutng_Instrn\[7\] , \Xecutng_Instrn\[6\] , 
        \Xecutng_Instrn\[5\] , \Xecutng_Instrn\[4\] , \Xecutng_Instrn\[3\] , 
        \Xecutng_Instrn\[2\] , \Xecutng_Instrn\[1\] , n274}), .Crnt_Instrn_2({
        \Crnt_Instrn_2\[31\] , \Crnt_Instrn_2\[30\] , \Crnt_Instrn_2\[29\] , 
        \Crnt_Instrn_2\[28\] , \Crnt_Instrn_2\[27\] , \Crnt_Instrn_2\[26\] , 
        \Crnt_Instrn_2\[25\] , \Crnt_Instrn_2\[24\] , \Crnt_Instrn_2\[23\] , 
        \Crnt_Instrn_2\[22\] , \Crnt_Instrn_2\[21\] , \Crnt_Instrn_2\[20\] , 
        \Crnt_Instrn_2\[19\] , \Crnt_Instrn_2\[18\] , \Crnt_Instrn_2\[17\] , 
        \Crnt_Instrn_2\[16\] , \Crnt_Instrn_2\[15\] , \Crnt_Instrn_2\[14\] , 
        \Crnt_Instrn_2\[13\] , \Crnt_Instrn_2\[12\] , \Crnt_Instrn_2\[11\] , 
        \Crnt_Instrn_2\[10\] , \Crnt_Instrn_2\[9\] , \Crnt_Instrn_2\[8\] , 
        \Crnt_Instrn_2\[7\] , \Crnt_Instrn_2\[6\] , \Crnt_Instrn_2\[5\] , 
        \Crnt_Instrn_2\[4\] , \Crnt_Instrn_2\[3\] , \Crnt_Instrn_2\[2\] , 
        \Crnt_Instrn_2\[1\] , \Crnt_Instrn_2\[0\] }), .test_si(Div_Clk_sig), 
        .test_se(n279) );
  PRGRM_CNT_TOP I_PRGRM_CNT_TOP ( .Clk(n250), .INTERNAL_RESET(INTERNAL_RESET), 
        .Crnt_Instrn({\Crnt_Instrn_2\[31\] , \Crnt_Instrn_2\[30\] , 
        \Crnt_Instrn_2\[29\] , \Crnt_Instrn_2\[28\] , \Crnt_Instrn_2\[27\] , 
        1'b0, \Crnt_Instrn_2\[25\] , 1'b0, \Crnt_Instrn_2\[23\] , 
        \Crnt_Instrn_2\[22\] , \Crnt_Instrn_2\[21\] , \Crnt_Instrn_2\[20\] , 
        \Crnt_Instrn_2\[19\] , \Crnt_Instrn_2\[18\] , \Crnt_Instrn_2\[17\] , 
        \Crnt_Instrn_2\[16\] , 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 
        \Crnt_Instrn_2\[7\] , \Crnt_Instrn_2\[6\] , \Crnt_Instrn_2\[5\] , 
        \Crnt_Instrn_2\[4\] , \Crnt_Instrn_2\[3\] , \Crnt_Instrn_2\[2\] , 
        \Crnt_Instrn_2\[1\] , \Crnt_Instrn_2\[0\] }), .Zro_Flag(\PSW\[2\] ), 
        .Carry_Flag(1'b0), .Neg_Flag(\PSW\[1\] ), .Return_Addr({
        \Return_Addr\[7\] , \Return_Addr\[6\] , \Return_Addr\[5\] , 
        \Return_Addr\[4\] , \Return_Addr\[3\] , \Return_Addr\[2\] , 
        \Return_Addr\[1\] , \Return_Addr\[0\] }), .Current_State({
        \Current_State\[0\] , \Current_State\[1\] , \Current_State\[2\] }), 
        .PC({\PSW\[10\] , \PSW\[9\] , \PSW\[8\] , \PSW\[7\] , \PSW\[6\] , 
        \PSW\[5\] , \PSW\[4\] , \PSW\[3\] }), .test_se(n279) );
  REG_FILE I_REG_FILE ( .INTERNAL_RESET(INTERNAL_RESET), .Clk(Div_Clk_sig), 
        .Addr_A({1'b0, 1'b0, 1'b0, 1'b0, 1'b0, \Addr_A\[1\] , \Addr_A\[0\] }), 
        .Addr_B({1'b0, 1'b0, 1'b0, 1'b0, 1'b0, \Xecutng_Instrn\[1\] , n274}), 
        .Addr_C({1'b0, 1'b0, 1'b0, 1'b0, 1'b0, \Xecutng_Instrn\[17\] , 
        \Xecutng_Instrn\[16\] }), .RegPort_C({\RegPort_C\[15\] , 
        \RegPort_C\[14\] , \RegPort_C\[13\] , \RegPort_C\[12\] , 
        \RegPort_C\[11\] , \RegPort_C\[10\] , \RegPort_C\[9\] , 
        \RegPort_C\[8\] , \RegPort_C\[7\] , \RegPort_C\[6\] , \RegPort_C\[5\] , 
        \RegPort_C\[4\] , \RegPort_C\[3\] , \RegPort_C\[2\] , \RegPort_C\[1\] , 
        \RegPort_C\[0\] }), .Write_RegC(Write_RegC), .RegPort_A({
        \RESULT_DATA\[15\] , \RESULT_DATA\[14\] , \RESULT_DATA\[13\] , 
        \RESULT_DATA\[12\] , \RESULT_DATA\[11\] , \RESULT_DATA\[10\] , 
        \RESULT_DATA\[9\] , \RESULT_DATA\[8\] , \RESULT_DATA\[7\] , 
        \RESULT_DATA\[6\] , \RESULT_DATA\[5\] , \RESULT_DATA\[4\] , 
        \RESULT_DATA\[3\] , \RESULT_DATA\[2\] , \RESULT_DATA\[1\] , 
        \RESULT_DATA\[0\] }), .RegPort_B({\RegPort_B\[15\] , \RegPort_B\[14\] , 
        \RegPort_B\[13\] , \RegPort_B\[12\] , \RegPort_B\[11\] , 
        \RegPort_B\[10\] , \RegPort_B\[9\] , \RegPort_B\[8\] , 
        \RegPort_B\[7\] , \RegPort_B\[6\] , \RegPort_B\[5\] , \RegPort_B\[4\] , 
        \RegPort_B\[3\] , \RegPort_B\[2\] , \RegPort_B\[1\] , \RegPort_B\[0\] }), .RISC_CORE_test_point_375_in(n272), .test_si(\Current_State\[0\] ), 
        .test_so(n270), .test_se(n277) );
  RST I_RST ( .TEST_MODE(1'b0), .Reset(Reset), .Clk(Clk), .INTERNAL_RESET(
        INTERNAL_RESET), .RISC_CORE_TEST_MODE_in(TEST_MODE), .test_si(n269), 
        .test_so(n268), .test_se(n278) );
  STACK_TOP I_STACK_TOP ( .INTERNAL_RESET(INTERNAL_RESET), .Clk(n56), 
        .PushEnbl(PushEnbl), .PopEnbl(PopEnbl), .PushDataIn({1'b0, \PSW\[2\] , 
        \PSW\[1\] , 1'b0, \PSW\[10\] , \PSW\[9\] , \PSW\[8\] , \PSW\[7\] , 
        \PSW\[6\] , \PSW\[5\] , \PSW\[4\] , \PSW\[3\] }), .PopDataOut({
        SYNOPSYS_UNCONNECTED__5, \PopDataOut\[10\] , \PopDataOut\[9\] , 
        SYNOPSYS_UNCONNECTED__6, \Return_Addr\[7\] , \Return_Addr\[6\] , 
        \Return_Addr\[5\] , \Return_Addr\[4\] , \Return_Addr\[3\] , 
        \Return_Addr\[2\] , \Return_Addr\[1\] , \Return_Addr\[0\] }), 
        .STACK_FULL(STACK_FULL), .test_si2(n268), .test_si1(n270), .test_so1(
        n269), .test_se(n276) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[0\]  ( .D(\I_ALU/n161 ), .SD(\Instrn\[0\] ), 
        .SC(n279), .CP(n272), .Q(\Op_Result\[0\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[1\]  ( .D(\I_ALU/n162 ), .SD(
        \Op_Result\[0\] ), .SC(n278), .CP(n57), .Q(\Op_Result\[1\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[2\]  ( .D(\I_ALU/n163 ), .SD(
        \Op_Result\[1\] ), .SC(n279), .CP(n55), .Q(\Op_Result\[2\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[3\]  ( .D(\I_ALU/n164 ), .SD(
        \Op_Result\[2\] ), .SC(n278), .CP(n57), .Q(\Op_Result\[3\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[4\]  ( .D(\I_ALU/n165 ), .SD(
        \Op_Result\[3\] ), .SC(n279), .CP(n272), .Q(\Op_Result\[4\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[5\]  ( .D(\I_ALU/n166 ), .SD(
        \Op_Result\[4\] ), .SC(n278), .CP(n57), .Q(\Op_Result\[5\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[6\]  ( .D(\I_ALU/n167 ), .SD(
        \Op_Result\[5\] ), .SC(n278), .CP(n55), .Q(\Op_Result\[6\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[7\]  ( .D(\I_ALU/n168 ), .SD(
        \Op_Result\[6\] ), .SC(n278), .CP(n57), .Q(\Op_Result\[7\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[8\]  ( .D(\I_ALU/n169 ), .SD(
        \Op_Result\[7\] ), .SC(n278), .CP(n272), .Q(\Op_Result\[8\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[9\]  ( .D(\I_ALU/n170 ), .SD(
        \Op_Result\[8\] ), .SC(n278), .CP(n57), .Q(\Op_Result\[9\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[10\]  ( .D(\I_ALU/n171 ), .SD(
        \Op_Result\[9\] ), .SC(n278), .CP(n55), .Q(\Op_Result\[10\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[11\]  ( .D(\I_ALU/n172 ), .SD(
        \Op_Result\[10\] ), .SC(n278), .CP(n55), .Q(\Op_Result\[11\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[12\]  ( .D(\I_ALU/n173 ), .SD(
        \Op_Result\[11\] ), .SC(n278), .CP(n272), .Q(\Op_Result\[12\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[13\]  ( .D(\I_ALU/n174 ), .SD(
        \Op_Result\[12\] ), .SC(n278), .CP(n55), .Q(\Op_Result\[13\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[14\]  ( .D(\I_ALU/n175 ), .SD(
        \Op_Result\[13\] ), .SC(n278), .CP(n55), .Q(\Op_Result\[14\] ) );
  sdnrq1 \I_ALU/Lachd_Result_reg\[15\]  ( .D(\I_ALU/n176 ), .SD(
        \Op_Result\[14\] ), .SC(n278), .CP(n55), .Q(\Op_Result\[15\] ) );
  sdcrq1 \I_ALU/Neg_Flag_reg  ( .D(\I_ALU/n177 ), .SD(\Op_Result\[15\] ), .SC(
        n277), .CP(n272), .CDN(INTERNAL_RESET), .Q(ALU_Neg) );
  sdcrq1 \I_ALU/Zro_Flag_reg  ( .D(\I_ALU/n178 ), .SD(ALU_Neg), .SC(n279), 
        .CP(n55), .CDN(INTERNAL_RESET), .Q(ALU_Zro) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U3  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n129 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n3 ), 
        .CO(\I_ALU/DP_OP_47J1_122_1374/n2 ), .S(\I_ALU/C3/DATA19_14 ) );
  ah01d0 \I_ALU/DP_OP_47J1_122_1374/U131  ( .A(\Oprnd_B\[0\] ), .B(
        \Oprnd_A\[0\] ), .CO(\I_ALU/DP_OP_47J1_122_1374/n111 ), .S(
        \I_ALU/N103 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U96  ( .A(\Oprnd_A\[1\] ), .B(n264), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n79 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n78 ), 
        .S(\I_ALU/N168 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U130  ( .A(\Oprnd_B\[1\] ), .B(
        \Oprnd_A\[1\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n111 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n110 ), .S(\I_ALU/N104 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U16  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n16 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n116 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n15 ), .S(\I_ALU/C3/DATA19_1 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U95  ( .A(\Oprnd_A\[2\] ), .B(n263), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n78 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n77 ), 
        .S(\I_ALU/N169 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U129  ( .A(\Oprnd_B\[2\] ), .B(
        \Oprnd_A\[2\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n110 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n109 ), .S(\I_ALU/N105 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U15  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n117 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n15 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n14 ), .S(\I_ALU/C3/DATA19_2 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U94  ( .A(\Oprnd_A\[3\] ), .B(n262), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n77 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n76 ), 
        .S(\I_ALU/N170 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U128  ( .A(\Oprnd_B\[3\] ), .B(
        \Oprnd_A\[3\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n109 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n108 ), .S(\I_ALU/N106 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U14  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n118 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n14 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n13 ), .S(\I_ALU/C3/DATA19_3 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U93  ( .A(\Oprnd_A\[4\] ), .B(n261), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n76 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n75 ), 
        .S(\I_ALU/N171 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U127  ( .A(\Oprnd_B\[4\] ), .B(
        \Oprnd_A\[4\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n108 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n107 ), .S(\I_ALU/N107 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U13  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n119 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n13 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n12 ), .S(\I_ALU/C3/DATA19_4 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U92  ( .A(\Oprnd_A\[5\] ), .B(n260), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n75 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n74 ), 
        .S(\I_ALU/N172 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U126  ( .A(\Oprnd_B\[5\] ), .B(
        \Oprnd_A\[5\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n107 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n106 ), .S(\I_ALU/N108 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U12  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n120 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n12 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n11 ), .S(\I_ALU/C3/DATA19_5 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U91  ( .A(\Oprnd_A\[6\] ), .B(n259), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n74 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n73 ), 
        .S(\I_ALU/N173 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U125  ( .A(\Oprnd_B\[6\] ), .B(
        \Oprnd_A\[6\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n106 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n105 ), .S(\I_ALU/N109 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U11  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n121 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n11 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n10 ), .S(\I_ALU/C3/DATA19_6 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U90  ( .A(\Oprnd_A\[7\] ), .B(n258), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n73 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n72 ), 
        .S(\I_ALU/N174 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U124  ( .A(\Oprnd_B\[7\] ), .B(
        \Oprnd_A\[7\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n105 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n104 ), .S(\I_ALU/N110 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U10  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n122 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n10 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n9 ), .S(\I_ALU/C3/DATA19_7 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U89  ( .A(\Oprnd_A\[8\] ), .B(n257), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n72 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n71 ), 
        .S(\I_ALU/N175 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U123  ( .A(\Oprnd_B\[8\] ), .B(
        \Oprnd_A\[8\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n104 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n103 ), .S(\I_ALU/N111 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U9  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n123 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n9 ), 
        .CO(\I_ALU/DP_OP_47J1_122_1374/n8 ), .S(\I_ALU/C3/DATA19_8 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U88  ( .A(\Oprnd_A\[9\] ), .B(n256), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n71 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n70 ), 
        .S(\I_ALU/N176 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U122  ( .A(\Oprnd_B\[9\] ), .B(
        \Oprnd_A\[9\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n103 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n102 ), .S(\I_ALU/N112 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U8  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n124 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n8 ), 
        .CO(\I_ALU/DP_OP_47J1_122_1374/n7 ), .S(\I_ALU/C3/DATA19_9 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U87  ( .A(\Oprnd_A\[10\] ), .B(n255), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n70 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n69 ), 
        .S(\I_ALU/N177 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U121  ( .A(\Oprnd_B\[10\] ), .B(
        \Oprnd_A\[10\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n102 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n101 ), .S(\I_ALU/N113 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U7  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n125 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n7 ), 
        .CO(\I_ALU/DP_OP_47J1_122_1374/n6 ), .S(\I_ALU/C3/DATA19_10 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U86  ( .A(\Oprnd_A\[11\] ), .B(n254), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n69 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n68 ), 
        .S(\I_ALU/N178 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U120  ( .A(\Oprnd_B\[11\] ), .B(
        \Oprnd_A\[11\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n101 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n100 ), .S(\I_ALU/N114 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U6  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n126 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n6 ), 
        .CO(\I_ALU/DP_OP_47J1_122_1374/n5 ), .S(\I_ALU/C3/DATA19_11 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U85  ( .A(\Oprnd_A\[12\] ), .B(n253), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n68 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n67 ), 
        .S(\I_ALU/N179 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U119  ( .A(\Oprnd_B\[12\] ), .B(
        \Oprnd_A\[12\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n100 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n99 ), .S(\I_ALU/N115 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U5  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n127 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n5 ), 
        .CO(\I_ALU/DP_OP_47J1_122_1374/n4 ), .S(\I_ALU/C3/DATA19_12 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U84  ( .A(\Oprnd_A\[13\] ), .B(n252), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n67 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n66 ), 
        .S(\I_ALU/N180 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U118  ( .A(\Oprnd_B\[13\] ), .B(
        \Oprnd_A\[13\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n99 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n98 ), .S(\I_ALU/N116 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U4  ( .A(\I_ALU/C1/Z_0 ), .B(
        \I_ALU/DP_OP_47J1_122_1374/n128 ), .CI(\I_ALU/DP_OP_47J1_122_1374/n4 ), 
        .CO(\I_ALU/DP_OP_47J1_122_1374/n3 ), .S(\I_ALU/C3/DATA19_13 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U83  ( .A(\Oprnd_A\[14\] ), .B(n251), .CI(
        \I_ALU/DP_OP_47J1_122_1374/n66 ), .CO(\I_ALU/DP_OP_47J1_122_1374/n65 ), 
        .S(\I_ALU/N181 ) );
  ad01d0 \I_ALU/DP_OP_47J1_122_1374/U117  ( .A(\Oprnd_B\[14\] ), .B(
        \Oprnd_A\[14\] ), .CI(\I_ALU/DP_OP_47J1_122_1374/n98 ), .CO(
        \I_ALU/DP_OP_47J1_122_1374/n97 ), .S(\I_ALU/N117 ) );
  inv0d0 U3 ( .I(n185), .ZN(n55) );
  inv0d1 U4 ( .I(n185), .ZN(n56) );
  inv0d0 U5 ( .I(n185), .ZN(n57) );
  nr02d0 U6 ( .A1(n67), .A2(n73), .ZN(n177) );
  nr02d0 U7 ( .A1(\Xecutng_Instrn\[29\] ), .A2(n249), .ZN(n248) );
  inv0d0 U8 ( .I(\Xecutng_Instrn\[27\] ), .ZN(n60) );
  nd02d0 U9 ( .A1(\Xecutng_Instrn\[25\] ), .A2(n60), .ZN(n65) );
  nr02d0 U10 ( .A1(\Xecutng_Instrn\[28\] ), .A2(n65), .ZN(n75) );
  inv0d0 U11 ( .I(\Xecutng_Instrn\[24\] ), .ZN(n58) );
  nd02d0 U12 ( .A1(\Xecutng_Instrn\[26\] ), .A2(n58), .ZN(n71) );
  inv0d0 U13 ( .I(n71), .ZN(n77) );
  inv0d0 U14 ( .I(\Xecutng_Instrn\[25\] ), .ZN(n59) );
  inv0d0 U15 ( .I(\Xecutng_Instrn\[28\] ), .ZN(n64) );
  nd03d0 U16 ( .A1(n60), .A2(n59), .A3(n64), .ZN(n73) );
  nr02d0 U17 ( .A1(n73), .A2(n71), .ZN(n227) );
  aor21d1 U18 ( .B1(n75), .B2(n77), .A(n227), .Z(\I_ALU/C1/Z_0 ) );
  inv0d0 U19 ( .I(\Xecutng_Instrn\[29\] ), .ZN(n183) );
  nd02d0 U20 ( .A1(\Xecutng_Instrn\[24\] ), .A2(\Xecutng_Instrn\[26\] ), .ZN(
        n67) );
  xr02d1 U21 ( .A1(\Oprnd_A\[15\] ), .A2(\Oprnd_B\[15\] ), .Z(n62) );
  inv0d0 U22 ( .I(n62), .ZN(n61) );
  xr02d1 U23 ( .A1(\I_ALU/DP_OP_47J1_122_1374/n65 ), .A2(n61), .Z(n88) );
  xr02d1 U24 ( .A1(\I_ALU/DP_OP_47J1_122_1374/n97 ), .A2(n62), .Z(n86) );
  nr03d0 U25 ( .A1(\Xecutng_Instrn\[26\] ), .A2(\Xecutng_Instrn\[24\] ), .A3(
        n73), .ZN(n175) );
  nr02d0 U26 ( .A1(n64), .A2(n65), .ZN(n166) );
  inv0d0 U27 ( .I(\Oprnd_B\[15\] ), .ZN(n68) );
  an02d0 U28 ( .A1(\Xecutng_Instrn\[28\] ), .A2(\Xecutng_Instrn\[27\] ), .Z(
        n165) );
  an02d0 U29 ( .A1(\Xecutng_Instrn\[25\] ), .A2(n165), .Z(n164) );
  aor221d1 U30 ( .B1(\Oprnd_B\[15\] ), .B2(n166), .C1(n68), .C2(n165), .A(n164), .Z(n70) );
  inv0d0 U31 ( .I(\Xecutng_Instrn\[26\] ), .ZN(n63) );
  nd02d0 U32 ( .A1(\Xecutng_Instrn\[24\] ), .A2(n63), .ZN(n74) );
  nr02d0 U33 ( .A1(n64), .A2(n74), .ZN(n169) );
  nr02d0 U34 ( .A1(n64), .A2(n71), .ZN(n168) );
  or02d0 U35 ( .A1(\Xecutng_Instrn\[24\] ), .A2(\Xecutng_Instrn\[26\] ), .Z(
        n66) );
  aoi222d1 U36 ( .A1(n67), .A2(\Xecutng_Instrn\[28\] ), .B1(n67), .B2(n66), 
        .C1(n65), .C2(n64), .ZN(n167) );
  aor221d1 U37 ( .B1(\Oprnd_B\[15\] ), .B2(n169), .C1(n68), .C2(n168), .A(n167), .Z(n69) );
  mx02d0 U38 ( .I0(n70), .I1(n69), .S(\Oprnd_A\[15\] ), .Z(n85) );
  an02d0 U39 ( .A1(n74), .A2(n71), .Z(n72) );
  nr03d0 U40 ( .A1(n72), .A2(\Xecutng_Instrn\[28\] ), .A3(
        \Xecutng_Instrn\[27\] ), .ZN(n172) );
  nr02d0 U41 ( .A1(n73), .A2(n74), .ZN(n226) );
  nd02d0 U42 ( .A1(n86), .A2(n226), .ZN(n80) );
  nd02d0 U43 ( .A1(n88), .A2(n227), .ZN(n79) );
  inv0d0 U44 ( .I(n74), .ZN(n76) );
  ora21d1 U45 ( .B1(n77), .B2(n76), .A(n75), .Z(n228) );
  nd02d0 U46 ( .A1(n228), .A2(\Oprnd_A\[15\] ), .ZN(n78) );
  nd03d0 U47 ( .A1(n80), .A2(n79), .A3(n78), .ZN(n81) );
  xr02d1 U48 ( .A1(n81), .A2(\I_ALU/C1/Z_0 ), .Z(n82) );
  xr02d1 U49 ( .A1(n82), .A2(\I_ALU/DP_OP_47J1_122_1374/n2 ), .Z(n83) );
  an02d0 U50 ( .A1(n172), .A2(n83), .Z(n84) );
  aor211d1 U51 ( .C1(n86), .C2(n175), .A(n85), .B(n84), .Z(n87) );
  aor21d1 U52 ( .B1(n177), .B2(n88), .A(n87), .Z(n232) );
  an02d0 U53 ( .A1(n183), .A2(n232), .Z(n89) );
  mx02d0 U54 ( .I0(ALU_Neg), .I1(n89), .S(Latch_Flags), .Z(\I_ALU/n177 ) );
  inv0d0 U55 ( .I(\Oprnd_B\[0\] ), .ZN(n186) );
  xn02d1 U56 ( .A1(n186), .A2(\Oprnd_A\[0\] ), .ZN(n98) );
  nd02d0 U57 ( .A1(n98), .A2(n227), .ZN(n91) );
  aoi22d1 U58 ( .A1(\I_ALU/N103 ), .A2(n226), .B1(n228), .B2(\Oprnd_A\[0\] ), 
        .ZN(n90) );
  nd02d0 U59 ( .A1(n91), .A2(n90), .ZN(\I_ALU/DP_OP_47J1_122_1374/n16 ) );
  inv0d0 U60 ( .I(\Oprnd_B\[1\] ), .ZN(n264) );
  inv0d0 U61 ( .I(\Oprnd_B\[2\] ), .ZN(n263) );
  inv0d0 U62 ( .I(\Oprnd_B\[3\] ), .ZN(n262) );
  inv0d0 U63 ( .I(\Oprnd_B\[4\] ), .ZN(n261) );
  inv0d0 U64 ( .I(\Oprnd_B\[5\] ), .ZN(n260) );
  inv0d0 U65 ( .I(\Oprnd_B\[6\] ), .ZN(n259) );
  inv0d0 U66 ( .I(\Oprnd_B\[7\] ), .ZN(n258) );
  inv0d0 U67 ( .I(\Oprnd_B\[8\] ), .ZN(n257) );
  inv0d0 U68 ( .I(\Oprnd_B\[9\] ), .ZN(n256) );
  inv0d0 U69 ( .I(\Oprnd_B\[10\] ), .ZN(n255) );
  inv0d0 U70 ( .I(\Oprnd_B\[11\] ), .ZN(n254) );
  inv0d0 U71 ( .I(\Oprnd_B\[12\] ), .ZN(n253) );
  inv0d0 U72 ( .I(\Oprnd_B\[13\] ), .ZN(n252) );
  inv0d0 U73 ( .I(\Oprnd_B\[14\] ), .ZN(n251) );
  aor221d1 U74 ( .B1(\Oprnd_B\[0\] ), .B2(n166), .C1(n186), .C2(n165), .A(n164), .Z(n93) );
  aor221d1 U75 ( .B1(\Oprnd_B\[0\] ), .B2(n169), .C1(n186), .C2(n168), .A(n167), .Z(n92) );
  mx02d0 U76 ( .I0(n93), .I1(n92), .S(\Oprnd_A\[0\] ), .Z(n96) );
  inv0d0 U77 ( .I(\I_ALU/DP_OP_47J1_122_1374/n16 ), .ZN(n94) );
  an02d0 U78 ( .A1(n172), .A2(n94), .Z(n95) );
  aor211d1 U79 ( .C1(\I_ALU/N103 ), .C2(n175), .A(n96), .B(n95), .Z(n97) );
  aor21d1 U80 ( .B1(n177), .B2(n98), .A(n97), .Z(n247) );
  aor221d1 U81 ( .B1(\Oprnd_B\[1\] ), .B2(n166), .C1(n264), .C2(n165), .A(n164), .Z(n100) );
  aor221d1 U82 ( .B1(\Oprnd_B\[1\] ), .B2(n169), .C1(n264), .C2(n168), .A(n167), .Z(n99) );
  mx02d0 U83 ( .I0(n100), .I1(n99), .S(\Oprnd_A\[1\] ), .Z(n102) );
  an02d0 U84 ( .A1(n172), .A2(\I_ALU/C3/DATA19_1 ), .Z(n101) );
  aor211d1 U85 ( .C1(\I_ALU/N104 ), .C2(n175), .A(n102), .B(n101), .Z(n103) );
  aor21d1 U86 ( .B1(n177), .B2(\I_ALU/N168 ), .A(n103), .Z(n246) );
  aor221d1 U87 ( .B1(\Oprnd_B\[2\] ), .B2(n166), .C1(n263), .C2(n165), .A(n164), .Z(n105) );
  aor221d1 U88 ( .B1(\Oprnd_B\[2\] ), .B2(n169), .C1(n263), .C2(n168), .A(n167), .Z(n104) );
  mx02d0 U89 ( .I0(n105), .I1(n104), .S(\Oprnd_A\[2\] ), .Z(n107) );
  an02d0 U90 ( .A1(n172), .A2(\I_ALU/C3/DATA19_2 ), .Z(n106) );
  aor211d1 U91 ( .C1(\I_ALU/N105 ), .C2(n175), .A(n107), .B(n106), .Z(n108) );
  aor21d1 U92 ( .B1(n177), .B2(\I_ALU/N169 ), .A(n108), .Z(n245) );
  aor221d1 U93 ( .B1(\Oprnd_B\[3\] ), .B2(n166), .C1(n262), .C2(n165), .A(n164), .Z(n110) );
  aor221d1 U94 ( .B1(\Oprnd_B\[3\] ), .B2(n169), .C1(n262), .C2(n168), .A(n167), .Z(n109) );
  mx02d0 U95 ( .I0(n110), .I1(n109), .S(\Oprnd_A\[3\] ), .Z(n112) );
  an02d0 U96 ( .A1(n172), .A2(\I_ALU/C3/DATA19_3 ), .Z(n111) );
  aor211d1 U97 ( .C1(\I_ALU/N106 ), .C2(n175), .A(n112), .B(n111), .Z(n113) );
  aor21d1 U98 ( .B1(n177), .B2(\I_ALU/N170 ), .A(n113), .Z(n244) );
  nr04d0 U99 ( .A1(n247), .A2(n246), .A3(n245), .A4(n244), .ZN(n181) );
  aor221d1 U100 ( .B1(\Oprnd_B\[4\] ), .B2(n166), .C1(n261), .C2(n165), .A(
        n164), .Z(n115) );
  aor221d1 U101 ( .B1(\Oprnd_B\[4\] ), .B2(n169), .C1(n261), .C2(n168), .A(
        n167), .Z(n114) );
  mx02d0 U102 ( .I0(n115), .I1(n114), .S(\Oprnd_A\[4\] ), .Z(n117) );
  an02d0 U103 ( .A1(n172), .A2(\I_ALU/C3/DATA19_4 ), .Z(n116) );
  aor211d1 U104 ( .C1(\I_ALU/N107 ), .C2(n175), .A(n117), .B(n116), .Z(n118)
         );
  aor21d1 U105 ( .B1(n177), .B2(\I_ALU/N171 ), .A(n118), .Z(n243) );
  aor221d1 U106 ( .B1(\Oprnd_B\[5\] ), .B2(n166), .C1(n260), .C2(n165), .A(
        n164), .Z(n120) );
  aor221d1 U107 ( .B1(\Oprnd_B\[5\] ), .B2(n169), .C1(n260), .C2(n168), .A(
        n167), .Z(n119) );
  mx02d0 U108 ( .I0(n120), .I1(n119), .S(\Oprnd_A\[5\] ), .Z(n122) );
  an02d0 U109 ( .A1(n172), .A2(\I_ALU/C3/DATA19_5 ), .Z(n121) );
  aor211d1 U110 ( .C1(\I_ALU/N108 ), .C2(n175), .A(n122), .B(n121), .Z(n123)
         );
  aor21d1 U111 ( .B1(n177), .B2(\I_ALU/N172 ), .A(n123), .Z(n242) );
  aor221d1 U112 ( .B1(\Oprnd_B\[6\] ), .B2(n166), .C1(n259), .C2(n165), .A(
        n164), .Z(n125) );
  aor221d1 U113 ( .B1(\Oprnd_B\[6\] ), .B2(n169), .C1(n259), .C2(n168), .A(
        n167), .Z(n124) );
  mx02d0 U114 ( .I0(n125), .I1(n124), .S(\Oprnd_A\[6\] ), .Z(n127) );
  an02d0 U115 ( .A1(n172), .A2(\I_ALU/C3/DATA19_6 ), .Z(n126) );
  aor211d1 U116 ( .C1(\I_ALU/N109 ), .C2(n175), .A(n127), .B(n126), .Z(n128)
         );
  aor21d1 U117 ( .B1(n177), .B2(\I_ALU/N173 ), .A(n128), .Z(n241) );
  aor221d1 U118 ( .B1(\Oprnd_B\[7\] ), .B2(n166), .C1(n258), .C2(n165), .A(
        n164), .Z(n130) );
  aor221d1 U119 ( .B1(\Oprnd_B\[7\] ), .B2(n169), .C1(n258), .C2(n168), .A(
        n167), .Z(n129) );
  mx02d0 U120 ( .I0(n130), .I1(n129), .S(\Oprnd_A\[7\] ), .Z(n132) );
  an02d0 U121 ( .A1(n172), .A2(\I_ALU/C3/DATA19_7 ), .Z(n131) );
  aor211d1 U122 ( .C1(\I_ALU/N110 ), .C2(n175), .A(n132), .B(n131), .Z(n133)
         );
  aor21d1 U123 ( .B1(n177), .B2(\I_ALU/N174 ), .A(n133), .Z(n240) );
  nr04d0 U124 ( .A1(n243), .A2(n242), .A3(n241), .A4(n240), .ZN(n180) );
  aor221d1 U125 ( .B1(\Oprnd_B\[8\] ), .B2(n166), .C1(n257), .C2(n165), .A(
        n164), .Z(n135) );
  aor221d1 U126 ( .B1(\Oprnd_B\[8\] ), .B2(n169), .C1(n257), .C2(n168), .A(
        n167), .Z(n134) );
  mx02d0 U127 ( .I0(n135), .I1(n134), .S(\Oprnd_A\[8\] ), .Z(n137) );
  an02d0 U128 ( .A1(n172), .A2(\I_ALU/C3/DATA19_8 ), .Z(n136) );
  aor211d1 U129 ( .C1(\I_ALU/N111 ), .C2(n175), .A(n137), .B(n136), .Z(n138)
         );
  aor21d1 U130 ( .B1(n177), .B2(\I_ALU/N175 ), .A(n138), .Z(n239) );
  aor221d1 U131 ( .B1(\Oprnd_B\[9\] ), .B2(n166), .C1(n256), .C2(n165), .A(
        n164), .Z(n140) );
  aor221d1 U132 ( .B1(\Oprnd_B\[9\] ), .B2(n169), .C1(n256), .C2(n168), .A(
        n167), .Z(n139) );
  mx02d0 U133 ( .I0(n140), .I1(n139), .S(\Oprnd_A\[9\] ), .Z(n142) );
  an02d0 U134 ( .A1(n172), .A2(\I_ALU/C3/DATA19_9 ), .Z(n141) );
  aor211d1 U135 ( .C1(\I_ALU/N112 ), .C2(n175), .A(n142), .B(n141), .Z(n143)
         );
  aor21d1 U136 ( .B1(n177), .B2(\I_ALU/N176 ), .A(n143), .Z(n238) );
  aor221d1 U137 ( .B1(\Oprnd_B\[10\] ), .B2(n166), .C1(n255), .C2(n165), .A(
        n164), .Z(n145) );
  aor221d1 U138 ( .B1(\Oprnd_B\[10\] ), .B2(n169), .C1(n255), .C2(n168), .A(
        n167), .Z(n144) );
  mx02d0 U139 ( .I0(n145), .I1(n144), .S(\Oprnd_A\[10\] ), .Z(n147) );
  an02d0 U140 ( .A1(n172), .A2(\I_ALU/C3/DATA19_10 ), .Z(n146) );
  aor211d1 U141 ( .C1(\I_ALU/N113 ), .C2(n175), .A(n147), .B(n146), .Z(n148)
         );
  aor21d1 U142 ( .B1(n177), .B2(\I_ALU/N177 ), .A(n148), .Z(n237) );
  aor221d1 U143 ( .B1(\Oprnd_B\[11\] ), .B2(n166), .C1(n254), .C2(n165), .A(
        n164), .Z(n150) );
  aor221d1 U144 ( .B1(\Oprnd_B\[11\] ), .B2(n169), .C1(n254), .C2(n168), .A(
        n167), .Z(n149) );
  mx02d0 U145 ( .I0(n150), .I1(n149), .S(\Oprnd_A\[11\] ), .Z(n152) );
  an02d0 U146 ( .A1(n172), .A2(\I_ALU/C3/DATA19_11 ), .Z(n151) );
  aor211d1 U147 ( .C1(\I_ALU/N114 ), .C2(n175), .A(n152), .B(n151), .Z(n153)
         );
  aor21d1 U148 ( .B1(n177), .B2(\I_ALU/N178 ), .A(n153), .Z(n236) );
  nr04d0 U149 ( .A1(n239), .A2(n238), .A3(n237), .A4(n236), .ZN(n179) );
  aor221d1 U150 ( .B1(\Oprnd_B\[12\] ), .B2(n166), .C1(n253), .C2(n165), .A(
        n164), .Z(n155) );
  aor221d1 U151 ( .B1(\Oprnd_B\[12\] ), .B2(n169), .C1(n253), .C2(n168), .A(
        n167), .Z(n154) );
  mx02d0 U152 ( .I0(n155), .I1(n154), .S(\Oprnd_A\[12\] ), .Z(n157) );
  an02d0 U153 ( .A1(n172), .A2(\I_ALU/C3/DATA19_12 ), .Z(n156) );
  aor211d1 U154 ( .C1(\I_ALU/N115 ), .C2(n175), .A(n157), .B(n156), .Z(n158)
         );
  aor21d1 U155 ( .B1(n177), .B2(\I_ALU/N179 ), .A(n158), .Z(n235) );
  aor221d1 U156 ( .B1(\Oprnd_B\[13\] ), .B2(n166), .C1(n252), .C2(n165), .A(
        n164), .Z(n160) );
  aor221d1 U157 ( .B1(\Oprnd_B\[13\] ), .B2(n169), .C1(n252), .C2(n168), .A(
        n167), .Z(n159) );
  mx02d0 U158 ( .I0(n160), .I1(n159), .S(\Oprnd_A\[13\] ), .Z(n162) );
  an02d0 U159 ( .A1(n172), .A2(\I_ALU/C3/DATA19_13 ), .Z(n161) );
  aor211d1 U160 ( .C1(\I_ALU/N116 ), .C2(n175), .A(n162), .B(n161), .Z(n163)
         );
  aor21d1 U161 ( .B1(n177), .B2(\I_ALU/N180 ), .A(n163), .Z(n234) );
  aor221d1 U162 ( .B1(\Oprnd_B\[14\] ), .B2(n166), .C1(n251), .C2(n165), .A(
        n164), .Z(n171) );
  aor221d1 U163 ( .B1(\Oprnd_B\[14\] ), .B2(n169), .C1(n251), .C2(n168), .A(
        n167), .Z(n170) );
  mx02d0 U164 ( .I0(n171), .I1(n170), .S(\Oprnd_A\[14\] ), .Z(n174) );
  an02d0 U165 ( .A1(n172), .A2(\I_ALU/C3/DATA19_14 ), .Z(n173) );
  aor211d1 U166 ( .C1(\I_ALU/N117 ), .C2(n175), .A(n174), .B(n173), .Z(n176)
         );
  aor21d1 U167 ( .B1(n177), .B2(\I_ALU/N181 ), .A(n176), .Z(n233) );
  nr04d0 U168 ( .A1(n235), .A2(n234), .A3(n233), .A4(n232), .ZN(n178) );
  nd04d0 U169 ( .A1(n181), .A2(n180), .A3(n179), .A4(n178), .ZN(n182) );
  nd02d0 U170 ( .A1(n183), .A2(n182), .ZN(n184) );
  mx02d0 U171 ( .I0(ALU_Zro), .I1(n184), .S(Latch_Flags), .Z(\I_ALU/n178 ) );
  inv0d0 U172 ( .I(n272), .ZN(n185) );
  inv0d0 U173 ( .I(n185), .ZN(n250) );
  or02d0 U174 ( .A1(n186), .A2(\Oprnd_A\[0\] ), .Z(
        \I_ALU/DP_OP_47J1_122_1374/n79 ) );
  nd02d0 U175 ( .A1(\I_ALU/N117 ), .A2(n226), .ZN(n189) );
  nd02d0 U176 ( .A1(\I_ALU/N181 ), .A2(n227), .ZN(n188) );
  nd02d0 U177 ( .A1(n228), .A2(\Oprnd_A\[14\] ), .ZN(n187) );
  nd03d0 U178 ( .A1(n189), .A2(n188), .A3(n187), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n129 ) );
  nd02d0 U179 ( .A1(\I_ALU/N116 ), .A2(n226), .ZN(n192) );
  nd02d0 U180 ( .A1(\I_ALU/N180 ), .A2(n227), .ZN(n191) );
  nd02d0 U181 ( .A1(n228), .A2(\Oprnd_A\[13\] ), .ZN(n190) );
  nd03d0 U182 ( .A1(n192), .A2(n191), .A3(n190), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n128 ) );
  nd02d0 U183 ( .A1(\I_ALU/N115 ), .A2(n226), .ZN(n195) );
  nd02d0 U184 ( .A1(\I_ALU/N179 ), .A2(n227), .ZN(n194) );
  nd02d0 U185 ( .A1(n228), .A2(\Oprnd_A\[12\] ), .ZN(n193) );
  nd03d0 U186 ( .A1(n195), .A2(n194), .A3(n193), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n127 ) );
  nd02d0 U187 ( .A1(\I_ALU/N114 ), .A2(n226), .ZN(n198) );
  nd02d0 U188 ( .A1(\I_ALU/N178 ), .A2(n227), .ZN(n197) );
  nd02d0 U189 ( .A1(n228), .A2(\Oprnd_A\[11\] ), .ZN(n196) );
  nd03d0 U190 ( .A1(n198), .A2(n197), .A3(n196), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n126 ) );
  nd02d0 U191 ( .A1(\I_ALU/N113 ), .A2(n226), .ZN(n201) );
  nd02d0 U192 ( .A1(\I_ALU/N177 ), .A2(n227), .ZN(n200) );
  nd02d0 U193 ( .A1(n228), .A2(\Oprnd_A\[10\] ), .ZN(n199) );
  nd03d0 U194 ( .A1(n201), .A2(n200), .A3(n199), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n125 ) );
  nd02d0 U195 ( .A1(\I_ALU/N112 ), .A2(n226), .ZN(n204) );
  nd02d0 U196 ( .A1(\I_ALU/N176 ), .A2(n227), .ZN(n203) );
  nd02d0 U197 ( .A1(n228), .A2(\Oprnd_A\[9\] ), .ZN(n202) );
  nd03d0 U198 ( .A1(n204), .A2(n203), .A3(n202), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n124 ) );
  nd02d0 U199 ( .A1(\I_ALU/N111 ), .A2(n226), .ZN(n207) );
  nd02d0 U200 ( .A1(\I_ALU/N175 ), .A2(n227), .ZN(n206) );
  nd02d0 U201 ( .A1(n228), .A2(\Oprnd_A\[8\] ), .ZN(n205) );
  nd03d0 U202 ( .A1(n207), .A2(n206), .A3(n205), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n123 ) );
  nd02d0 U203 ( .A1(\I_ALU/N110 ), .A2(n226), .ZN(n210) );
  nd02d0 U204 ( .A1(\I_ALU/N174 ), .A2(n227), .ZN(n209) );
  nd02d0 U205 ( .A1(n228), .A2(\Oprnd_A\[7\] ), .ZN(n208) );
  nd03d0 U206 ( .A1(n210), .A2(n209), .A3(n208), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n122 ) );
  nd02d0 U207 ( .A1(\I_ALU/N109 ), .A2(n226), .ZN(n213) );
  nd02d0 U208 ( .A1(\I_ALU/N173 ), .A2(n227), .ZN(n212) );
  nd02d0 U209 ( .A1(n228), .A2(\Oprnd_A\[6\] ), .ZN(n211) );
  nd03d0 U210 ( .A1(n213), .A2(n212), .A3(n211), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n121 ) );
  nd02d0 U211 ( .A1(\I_ALU/N108 ), .A2(n226), .ZN(n216) );
  nd02d0 U212 ( .A1(\I_ALU/N172 ), .A2(n227), .ZN(n215) );
  nd02d0 U213 ( .A1(n228), .A2(\Oprnd_A\[5\] ), .ZN(n214) );
  nd03d0 U214 ( .A1(n216), .A2(n215), .A3(n214), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n120 ) );
  nd02d0 U215 ( .A1(\I_ALU/N107 ), .A2(n226), .ZN(n219) );
  nd02d0 U216 ( .A1(\I_ALU/N171 ), .A2(n227), .ZN(n218) );
  nd02d0 U217 ( .A1(n228), .A2(\Oprnd_A\[4\] ), .ZN(n217) );
  nd03d0 U218 ( .A1(n219), .A2(n218), .A3(n217), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n119 ) );
  nd02d0 U219 ( .A1(\I_ALU/N106 ), .A2(n226), .ZN(n222) );
  nd02d0 U220 ( .A1(\I_ALU/N170 ), .A2(n227), .ZN(n221) );
  nd02d0 U221 ( .A1(n228), .A2(\Oprnd_A\[3\] ), .ZN(n220) );
  nd03d0 U222 ( .A1(n222), .A2(n221), .A3(n220), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n118 ) );
  nd02d0 U223 ( .A1(\I_ALU/N105 ), .A2(n226), .ZN(n225) );
  nd02d0 U224 ( .A1(\I_ALU/N169 ), .A2(n227), .ZN(n224) );
  nd02d0 U225 ( .A1(n228), .A2(\Oprnd_A\[2\] ), .ZN(n223) );
  nd03d0 U226 ( .A1(n225), .A2(n224), .A3(n223), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n117 ) );
  nd02d0 U227 ( .A1(\I_ALU/N104 ), .A2(n226), .ZN(n231) );
  nd02d0 U228 ( .A1(\I_ALU/N168 ), .A2(n227), .ZN(n230) );
  nd02d0 U229 ( .A1(n228), .A2(\Oprnd_A\[1\] ), .ZN(n229) );
  nd03d0 U230 ( .A1(n231), .A2(n230), .A3(n229), .ZN(
        \I_ALU/DP_OP_47J1_122_1374/n116 ) );
  inv0d0 U231 ( .I(Latch_Result), .ZN(n249) );
  aor22d1 U232 ( .A1(\Op_Result\[15\] ), .A2(n249), .B1(n248), .B2(n232), .Z(
        \I_ALU/n176 ) );
  aor22d1 U233 ( .A1(\Op_Result\[14\] ), .A2(n249), .B1(n248), .B2(n233), .Z(
        \I_ALU/n175 ) );
  aor22d1 U234 ( .A1(\Op_Result\[13\] ), .A2(n249), .B1(n248), .B2(n234), .Z(
        \I_ALU/n174 ) );
  aor22d1 U235 ( .A1(\Op_Result\[12\] ), .A2(n249), .B1(n248), .B2(n235), .Z(
        \I_ALU/n173 ) );
  aor22d1 U236 ( .A1(n249), .A2(\Op_Result\[11\] ), .B1(n248), .B2(n236), .Z(
        \I_ALU/n172 ) );
  aor22d1 U237 ( .A1(n249), .A2(\Op_Result\[10\] ), .B1(n248), .B2(n237), .Z(
        \I_ALU/n171 ) );
  aor22d1 U238 ( .A1(n249), .A2(\Op_Result\[9\] ), .B1(n248), .B2(n238), .Z(
        \I_ALU/n170 ) );
  aor22d1 U239 ( .A1(n249), .A2(\Op_Result\[8\] ), .B1(n248), .B2(n239), .Z(
        \I_ALU/n169 ) );
  aor22d1 U240 ( .A1(n249), .A2(\Op_Result\[7\] ), .B1(n248), .B2(n240), .Z(
        \I_ALU/n168 ) );
  aor22d1 U241 ( .A1(n249), .A2(\Op_Result\[6\] ), .B1(n248), .B2(n241), .Z(
        \I_ALU/n167 ) );
  aor22d1 U242 ( .A1(n249), .A2(\Op_Result\[5\] ), .B1(n248), .B2(n242), .Z(
        \I_ALU/n166 ) );
  aor22d1 U243 ( .A1(n249), .A2(\Op_Result\[4\] ), .B1(n248), .B2(n243), .Z(
        \I_ALU/n165 ) );
  aor22d1 U244 ( .A1(n249), .A2(\Op_Result\[3\] ), .B1(n248), .B2(n244), .Z(
        \I_ALU/n164 ) );
  aor22d1 U245 ( .A1(n249), .A2(\Op_Result\[2\] ), .B1(n248), .B2(n245), .Z(
        \I_ALU/n163 ) );
  aor22d1 U246 ( .A1(n249), .A2(\Op_Result\[1\] ), .B1(n248), .B2(n246), .Z(
        \I_ALU/n162 ) );
  aor22d1 U247 ( .A1(n249), .A2(\Op_Result\[0\] ), .B1(n248), .B2(n247), .Z(
        \I_ALU/n161 ) );
  mx02d0 U250 ( .I0(n274), .I1(STACK_FULL), .S(n279), .Z(\Xecutng_Instrn\[0\] ) );
  mx02d1 U251 ( .I0(Div_Clk_sig), .I1(Clk), .S(TEST_MODE), .Z(n272) );
  inv0d1 U252 ( .I(TEST_SE), .ZN(n275) );
  invbd4 U253 ( .I(n275), .ZN(n276) );
  invbd2 U254 ( .I(n275), .ZN(n277) );
  invbd2 U255 ( .I(n275), .ZN(n278) );
  invbd2 U256 ( .I(n275), .ZN(n279) );
endmodule

