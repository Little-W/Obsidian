always_comb begin
  tb_if.psel = 1'b0;
  tb_if.penable = 1'b0;
  tb_if.pwrite = 1'b0;
  tb_if.paddr = '0;
  tb_if.pwdata = '0;

  case (connect_scene)
    CONNECT_SCENE_DIRECT: begin
    end
    CONNECT_SCENE_HOLD_ZERO: begin
      tb_if.psel = 1'b0;
      tb_if.penable = 1'b0;
      tb_if.pwrite = 1'b0;
      tb_if.paddr = '0;
      tb_if.pwdata = '0;
    end
    default: begin
    end
  endcase
end
