library IEEE;
use IEEE.std_logic_1164.all;
use work.RISCTYPES.all;

entity DIV_CLK is
        port (  TEST_MODE,
        	INTERNAL_RESET,
                Clk	: in std_logic;            
                DIV_CLK : out std_logic
              );
end DIV_CLK;

architecture RTL of DIV_CLK is


  signal q : std_logic;

begin

   divclk: process (Clk,INTERNAL_RESET)

   begin 
	if INTERNAL_RESET = '0' then
		q <= '0';
	elsif clk'event and clk = '1' then
		q <= not q;
	end if;
   end process divclk;
   
  
   DIV_CLK <= Clk when TEST_MODE = '1' else q;

end RTL;
