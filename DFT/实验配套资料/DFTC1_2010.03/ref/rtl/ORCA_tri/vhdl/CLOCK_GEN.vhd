LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY CLOCK_GEN IS
  
  PORT (
      pclk              : IN  std_logic;
      sdram_clk         : IN  std_logic;
      sys_clk           : IN  std_logic;

      pclk_fb           : IN  std_logic;
      sdram_clk_fb      : IN  std_logic;

      test_mode         : IN  std_logic;
--      test_sys2x_clk    : IN  std_logic;
      powersave         : IN  std_logic;

      o_pclk            : OUT std_logic;
      o_sdram_clk       : OUT std_logic;
      o_sys_clk         : OUT std_logic;
      o_sys_2x_clk      : OUT std_logic
  );

END CLOCK_GEN;

ARCHITECTURE RTL OF CLOCK_GEN IS


  COMPONENT PLL
    PORT (
      REF_CLK  : IN  std_logic;
      FB_CLK   : IN  std_logic;
      CLK      : OUT std_logic;
      CLK_2X   : OUT std_logic
    );
  END COMPONENT;
  
  COMPONENT CLKMUL
    PORT (
      CLK_IN  : IN  std_logic;
      CLK_1X  : OUT std_logic;
      CLK_2X  : OUT std_logic
    );
  END COMPONENT;

  SIGNAL net_pclk       : std_logic;
  SIGNAL net_sdram_clk  : std_logic;

  SIGNAL net_sys_clk    : std_logic;
  SIGNAL net_sys_2x_clk : std_logic;
  SIGNAL net_ps_sys_2x_clk : std_logic;
  
  
BEGIN  -- RTL

  
  I_PLL_PCI : PLL PORT MAP (
    REF_CLK     => pclk,
    FB_CLK      => pclk_fb,
    CLK         => net_pclk,
    CLK_2X      => open
  );

  I_PLL_SD : PLL PORT MAP (
    REF_CLk     => sdram_clk,
    FB_CLK      => sdram_clk_fb,
    CLK         => net_sdram_clk,
    CLK_2X      => open
  );

  I_CLKMUL : CLKMUL PORT MAP (
    CLK_IN      => sys_clk,
    CLK_1X      => net_sys_clk,
    CLK_2x      => net_sys_2x_clk
  );
    
  -- In powersave mode, the 2x clock runs at the same speed as the sys_clk
  net_ps_sys_2x_clk <= net_sys_clk WHEN powersave = '1' ELSE net_sys_2x_clk;
  
  -- All output clocks are muxed with their respective test clocks
  o_pclk <= pclk WHEN test_mode = '1' ELSE net_pclk;
  o_sdram_clk <= sdram_clk WHEN test_mode = '1' ELSE net_sdram_clk;
  o_sys_clk <= sys_clk WHEN test_mode = '1' ELSE net_sys_clk;
--  o_sys_2x_clk <= test_sys2x_clk WHEN test_mode = '1' ELSE net_ps_sys_2x_clk;
  o_sys_2x_clk <= sys_clk WHEN test_mode = '1' ELSE net_ps_sys_2x_clk;

END RTL;
