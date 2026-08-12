library IEEE;
use IEEE.std_logic_1164.all;
use WORK.RISCTYPES.all;

entity PRGRM_FSM is
        port (
                Clk,               -- CPU Clock
                INTERNAL_RESET             -- CPU Reset
			:  in std_logic;
                CurrentState      -- Current State of FSM
			:  out State_Type
              );
end PRGRM_FSM;

architecture RTL of PRGRM_FSM is

--    type State_Type is (RESET_STATE, FETCH_INSTR, READ_OPS, EXECUTE, WRITEBACK);
    signal Current_State, Next_State        : State_Type;

begin

    process (INTERNAL_RESET, Current_State)
    begin
        case Current_State is
            when RESET_STATE =>
                Next_State <= FETCH_INSTR;
            when FETCH_INSTR =>
                Next_State  <= READ_OPS;
            when READ_OPS =>
                Next_State <= EXECUTE;
            when EXECUTE =>
                Next_State <= WRITEBACK;
            when WRITEBACK =>
                Next_State <= FETCH_INSTR;
        end case;
    end process;

    process (clk , INTERNAL_RESET)
    begin
        
        if (INTERNAL_RESET = '0') then
            Current_State       <= RESET_STATE ;
        elsif clk'event and clk = '1' then
            Current_State       <= Next_State ;
        end if;
    end process;

    CurrentState <= Current_State;

end RTL;

