library IEEE;
use IEEE.std_logic_1164.all;
use work.RISCTYPES.all;

entity RST is
        port (  TEST_MODE,
        	Reset,
                Clk		: in std_logic;
                INTERNAL_RESET	: out std_logic
              );
end RST;

architecture RTL of RST is


  signal q1,q2 : std_logic;

begin


   ff_sync: process (Clk,Reset)
   
   begin
        if Reset = '0' then
		q1 <= '0';
		q2 <= '0';
        elsif clk'event and clk = '1' then
		q1 <= '1';
		q2 <= q1;
	end if;
   end process ff_sync;
   
   INTERNAL_RESET <= q2;
   
   
end RTL; 
