LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY SDRAM_IF IS
  GENERIC (
    sd_a_width       : integer := 10;
    sd_dq_width      : integer := 16
  );
  PORT (
    sdram_clk           : IN  std_logic;

    sdram_rst_n         : IN  std_logic;

    risc_OUT_VALID      : IN  std_logic;
    risc_STACK_FULL     : IN  std_logic;
    risc_EndOfInstrn    : IN  std_logic;
    risc_PSW            : IN  std_logic_vector(10 DOWNTO 0);
    risc_Rd_Instr       : IN  std_logic;

    -- interface to SDRAM
    sd_A             : OUT std_logic_vector(sd_a_width-1 DOWNTO 0);
    sd_CK            : OUT std_logic;
    sd_CKn           : OUT std_logic;
    sd_LD            : OUT std_logic;
    sd_RW            : OUT std_logic;
    sd_BWS           : OUT std_logic_vector(1 DOWNTO 0);

    sd_DQ_in         : IN  std_logic_vector(sd_dq_width-1 DOWNTO 0);
    sd_DQ_out        : OUT std_logic_vector(sd_dq_width-1 DOWNTO 0);
    sd_DQ_en         : OUT std_logic_vector(sd_dq_width-1 DOWNTO 0);

    -- interface to FIFOs
    sd_wfifo_pop        : OUT std_logic;
    sd_wfifo_empty      : IN  std_logic;
    sd_rfifo_push       : OUT std_logic;
    sd_rfifo_full       : IN  std_logic;

    sd_rfifo_DQ_out     : OUT std_logic_vector(sd_dq_width*2-1 DOWNTO 0);
    sd_wfifo_DQ_in      : IN  std_logic_vector(sd_dq_width*2-1 DOWNTO 0)
  );

END SDRAM_IF;

ARCHITECTURE RTL OF SDRAM_IF IS
  SIGNAL u_control_bus          : std_logic_vector(14 DOWNTO 0);
  SIGNAL sync_control_bus       : std_logic_vector(14 DOWNTO 0);
  SIGNAL control_bus            : std_logic_vector(14 DOWNTO 0);
  
  SIGNAL out_control            : std_logic_vector(sd_a_width+7 DOWNTO 0);
  SIGNAL c_out_control          : std_logic_vector(sd_a_width+7 DOWNTO 0);

  SIGNAL DQ_in_0                : std_logic_vector(sd_dq_width-1 DOWNTO 0);
  SIGNAL DQ_in_1                : std_logic_vector(sd_dq_width-1 DOWNTO 0);

  SIGNAL DQ_out_0               : std_logic_vector(sd_dq_width-1 DOWNTO 0);
  SIGNAL DQ_out_1               : std_logic_vector(sd_dq_width-1 DOWNTO 0);

  SIGNAL ti_hi, ti_low          : std_logic;

  FUNCTION MUX_FUNC(I0, I1 : IN std_logic; S : IN std_logic) RETURN std_logic IS
    -- pragma map_to_entity mx02d4
    -- pragma return_port_name Z
    -- contents of this function are ignored but should match the
    -- functionality of the module MUX_ENTITY, so pre- and post
    -- simulation will match

  BEGIN
    IF(S = '0') THEN
      RETURN(I0);
    ELSE
      RETURN(I1);
    END IF;
  END;


  COMPONENT mx02d4
    PORT (
      I0  : IN  std_logic;
      I1  : IN  std_logic;
      S   : IN  std_logic;
      Z   : OUT std_logic
    );
  END COMPONENT;
  
  CONSTANT shift_size: integer := 30;   -- changed from 50 to 30

  TYPE   data_page IS ARRAY (0 TO shift_size) OF bit_vector(sd_dq_width-1 DOWNTO 0);
  SIGNAL mega_shift_0 : data_page;
  SIGNAL mega_shift_1 : data_page;


  FUNCTION word_mux (ein : IN bit_vector(sd_dq_width-1 DOWNTO 0) ) RETURN bit_vector IS
    VARIABLE word     : bit_vector(sd_dq_width-1 DOWNTO 0);
    VARIABLE rol_word : bit_vector(sd_dq_width-1 DOWNTO 0);
  BEGIN

    FOR i IN 0 TO sd_dq_width-1 LOOP
      rol_word := ein ROL i;
      FOR n IN 0 TO sd_dq_width-1 LOOP
        word(i) := rol_word(n) XOR word(i);
      END LOOP;
    END LOOP;

    RETURN word;
  END;

BEGIN

  ti_low <= '0';
  ti_hi  <= '1';

  u_control_bus <= risc_PSW &
                   risc_OUT_VALID &
                   risc_STACK_FULL &
                   risc_EndOfInstrn &
                   risc_Rd_Instr;
  
  sd_A    <= out_control(sd_a_width-1 DOWNTO 0);

  sd_LD   <= out_control(sd_a_width);
  sd_RW   <= out_control(sd_a_width+1);
  sd_BWS  <= out_control(sd_a_width+3 DOWNTO sd_a_width+2);
  
  sd_wfifo_pop <= out_control(sd_a_width+4);
  sd_rfifo_push <= out_control(sd_a_width+5);


  data_en_l: PROCESS (sdram_rst_n, sdram_clk)
  BEGIN
    IF sdram_rst_n = '0' THEN
      sd_DQ_en <= (OTHERS => '0');
    ELSIF sdram_clk'event AND sdram_clk='1' THEN 

      IF c_out_control(0) = '1' THEN 
        sd_DQ_en <= (OTHERS => '0');
      ELSE 
        sd_DQ_en <= (OTHERS => '1');
      END IF;
    END IF;
  END PROCESS;
  
  syncs: PROCESS
  BEGIN
    WAIT UNTIL sdram_clk'event AND sdram_clk='1';

    control_bus <= sync_control_bus;
    sync_control_bus <= u_control_bus;
  END PROCESS;

  sd_fsm: PROCESS (sdram_rst_n, sdram_clk, c_out_control)
  BEGIN
    IF sdram_rst_n='0' THEN
      out_control <= (OTHERS => '0');
    ELSIF sdram_clk'event AND sdram_clk='1' THEN 
      out_control <= c_out_control;
    END IF;
  END PROCESS;

  -- the most bogus fsm you've ever seen!!
  sd_states: PROCESS(control_bus, sd_wfifo_empty, sd_rfifo_full)
    VARIABLE temp : std_logic_vector(16 DOWNTO 0);
  BEGIN
    
    temp := control_bus & sd_rfifo_full & sd_wfifo_empty;

    CASE temp IS
      WHEN "01010101010101010" => 
        c_out_control <= (temp & "1") + 981;
      WHEN "10101010101010101" => 
        c_out_control <= (temp & "1") + 97632;
      WHEN "01101101101101101" => 
        c_out_control <= (temp & "1") + 13243;
      WHEN "10010010010010010" => 
        c_out_control <= (temp & "1") + 4565;
      WHEN "11011011011011011" => 
        c_out_control <= (temp & "1") + 92734;
      WHEN "11101010001101001" => 
        c_out_control <= (temp & "1") + 18273;
      WHEN "01001011010100110" =>
        c_out_control <= (temp & "1") + 7346;
      WHEN OTHERS => 
        c_out_control <= (temp & "1") + 3114;
    END CASE;
  END PROCESS;


  sd_data0_read: PROCESS
  BEGIN 
    WAIT UNTIL sdram_clk'event AND sdram_clk='1';

    DQ_in_0 <= sd_DQ_in;
  END PROCESS;

  sd_data1_read: PROCESS
  BEGIN 
    WAIT UNTIL sdram_clk'event AND sdram_clk='0';

    DQ_in_1 <= sd_DQ_in;
  END PROCESS;

  SD_DATAIN_BUS: PROCESS ( DQ_in_0, DQ_in_1 )
  begin
    sd_rfifo_DQ_out(sd_dq_width*2-1 DOWNTO sd_dq_width) <= DQ_in_1;
    sd_rfifo_DQ_out(sd_dq_width-1 DOWNTO 0) <= DQ_in_0;
  END PROCESS;
  
  
  sd_data0_write: PROCESS
  BEGIN 
    WAIT UNTIL sdram_clk'event AND sdram_clk='1';

    DQ_out_0 <= to_stdlogicvector(mega_shift_0(0));

    mega_shift_0(shift_size) <= to_bitvector(sd_wfifo_DQ_in(sd_dq_width-1 DOWNTO 0) );

    FOR i IN 0 TO shift_size-1 loop
      mega_shift_0(i) <= word_mux( mega_shift_0(i+1) );
    END LOOP;
  END PROCESS;

  sd_data1_write: PROCESS
  BEGIN 
    WAIT UNTIL sdram_clk'event AND sdram_clk='0';

    DQ_out_1 <= to_stdlogicvector(mega_shift_1(0));

    mega_shift_1(shift_size) <= to_bitvector(sd_wfifo_DQ_in(sd_dq_width*2-1 DOWNTO sd_dq_width) );

    FOR i IN 0 TO shift_size-1 loop
      mega_shift_1(i) <= word_mux( mega_shift_1(i+1) );
    END LOOP;
  END PROCESS;


--   sd_DQ_out <=      DQ_out_0 WHEN sdram_clk='0'
--                ELSE DQ_out_1;
--   sd_CK  <= MUX_FUNC('0', '1', sdram_clk);
--   sd_CKn <= MUX_FUNC('1', '0', sdram_clk);
  
  sd_mux_out_bus: FOR bit_index IN sd_dq_width-1 DOWNTO 0 GENERATE
    sd_mux_dq_out: mx02d4 PORT MAP (I0 => DQ_out_0(bit_index) , I1 => DQ_out_1(bit_index), S => sdram_clk,
                                    Z => sd_DQ_out(bit_index));
  END GENERATE sd_mux_out_bus;
  
  sd_mux_CK:  mx02d4 PORT MAP (I0 => ti_low, I1 => ti_hi,  S => sdram_clk, Z => sd_CK);
  sd_mux_CKn: mx02d4 PORT MAP (I0 => ti_hi,  I1 => ti_low, S => sdram_clk, Z => sd_CKn);
  
  
END RTL;
