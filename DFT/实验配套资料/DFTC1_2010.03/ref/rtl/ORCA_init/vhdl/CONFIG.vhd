LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

entity CONFIG is
  PORT (
    CONF : IN std_logic;
    CONF_ENA : IN std_logic;
    CLK : IN std_logic;
    TM : OUT std_logic
  );
END ;

architecture RTL of CONFIG is
signal config_state : std_logic_vector(0 to 2);
begin
   TM <= '1' when (config_state(0) = '1' AND
	 config_state(1) = '0' AND
	 config_state(2) = '1') else '0';
  process begin
    wait until CLK'event and CLK='1';
    if (CONF_ENA = '1') then
       config_state <= CONF & config_state(0 to 1);
    end if;
  end process;
end RTL ;

