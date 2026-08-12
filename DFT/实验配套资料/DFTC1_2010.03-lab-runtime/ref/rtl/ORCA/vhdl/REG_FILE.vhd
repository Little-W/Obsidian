LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_arith.ALL;

ENTITY REG_FILE IS
  PORT (
--    reset_n,                            -- Reset for initialising registers
    clk                                 -- CPU Clock
      : IN std_logic;
    Addr_A,                             -- Address for port A
    Addr_B,                             -- Address for port B
    Addr_C                              -- Address for port C
      : IN std_logic_vector (6 DOWNTO 0);

    RegPort_C                           -- Wr Data for port C
      : IN std_logic_vector (15 DOWNTO 0);

    Write_RegC
      : IN std_logic;

    RegPort_A,                          -- Data Out of port A
    RegPort_B                           -- Data Out of port A
      : OUT std_logic_vector ( 15 DOWNTO 0)
    );
END REG_FILE;
ARCHITECTURE RTL OF REG_FILE IS

  COMPONENT ram16x128
    PORT (A1   : in  std_logic_vector(6 DOWNTO 0);
          A2   : in  std_logic_vector(6 DOWNTO 0);
          CE1  : in std_logic;
          CE2  : in std_logic;
          WEB1 : in std_logic;
          WEB2 : in std_logic;
          OEB1 : in std_logic;
          OEB2 : in std_logic;
          CSB1 : in std_logic;
          CSB2 : in std_logic;
          IO1  : inout  std_logic_vector(15 DOWNTO 0);
          IO2  : inout  std_logic_vector(15 DOWNTO 0)
          );
  END COMPONENT;

  TYPE   regfile_type IS ARRAY (0 TO 3) OF std_logic_vector(15 DOWNTO 0);
  -- SIGNAL Reg_Array : regfile_type;
  SIGNAL ti_low : std_logic;
  SIGNAL ti_hi  : std_logic;
  SIGNAL we_n   : std_logic;

  SIGNAL data_in    : std_logic_vector(15 DOWNTO 0);
  SIGNAL data_out_A : std_logic_vector(15 DOWNTO 0);
  SIGNAL data_out_B : std_logic_vector(15 DOWNTO 0);

BEGIN

  ti_low <= '0';
  ti_hi <= '1';
  we_n <= NOT Write_RegC;

  data_in <= RegPort_C;
  RegPort_A <= data_out_A;
  RegPort_B <= data_out_B;

  
  REG_FILE_A_RAM : ram16x128
    PORT MAP (
      A1   => Addr_C,
      CE1  => clk,
      WEB1 => we_n,
      OEB1 => ti_hi,
      CSB1 => ti_low,
      IO1  => data_in,
      
      A2   => Addr_A,
      CE2  => clk,
      WEB2 => ti_hi,
      OEB2 => ti_low,
      CSB2 => ti_low,
      IO2  => data_out_A
    );
  REG_FILE_B_RAM : ram16x128
    PORT MAP (
      A1   => Addr_C,
      CE1  => clk,
      WEB1 => we_n,
      OEB1 => ti_hi,
      CSB1 => ti_low,
      IO1  => data_in,
      
      A2   => Addr_B,
      CE2  => clk,
      WEB2 => ti_hi,
      OEB2 => ti_low,
      CSB2 => ti_low,
      IO2  => data_out_B
    );

--   REG_FILE_A_RAM : rra16x128
--     PORT MAP (
--       WA   => Addr_C,
--       DI   => RegPort_C,
--       WEB  => we_n,
--       WCSB => clk,
--       RA   => Addr_A,
--       DO   => RegPort_A,
--       RCSB => clk,
--       REB  => ti_low,                   -- always enabled
--       OEB  => ti_low                    -- always enabled
--     );

--   REG_FILE_B_RAM : rra16x128
--     PORT MAP (
--       WA   => Addr_C,
--       DI   => RegPort_C,
--       WEB  => we_n,
--       WCSB => clk,
--       RA   => Addr_B,
--       DO   => RegPort_B,
--       RCSB => clk,
--       REB  => ti_low,                   -- always enabled
--       OEB  => ti_low                    -- always enabled
--     );

-- -- REG_FILE write
--   PROCESS (reset_n, clk, RegPort_C, Addr_C)
--   BEGIN
--     IF reset_n = '0' THEN
--       FOR i IN 0 TO 3 LOOP
--         Reg_Array(i) <= "0000000000000000";
--       END LOOP;
--     ELSIF clk'event AND clk = '1' THEN
--       IF Write_RegC = '1' THEN
--         Reg_Array(conv_integer(unsigned(Addr_C(1 DOWNTO 0)))) <= RegPort_C;
--       END IF;
--     END IF;
--   END PROCESS;

-- -- REG_FILE reads
--   PROCESS (Addr_A, Reg_Array)
--   BEGIN
--     RegPort_A <= Reg_Array(conv_integer(unsigned(Addr_A(1 DOWNTO 0))));
--   END PROCESS;

--   PROCESS (Addr_B, Reg_Array)
--   BEGIN
--     RegPort_B <= Reg_Array(conv_integer(unsigned(Addr_B(1 DOWNTO 0))));
--   END PROCESS;
  
END RTL;
