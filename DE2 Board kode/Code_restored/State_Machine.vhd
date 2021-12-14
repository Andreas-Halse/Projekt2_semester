library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;

ENTITY State_Machine IS
    PORT (
        clock : IN STD_LOGIC;
        reset : IN STD_LOGIC := '0';
        a : IN STD_LOGIC := '0';
        b : IN STD_LOGIC := '0';
        moo_out : OUT STD_LOGIC;
		  mee_out : OUT STD_LOGIC
    );
END State_Machine;

ARCHITECTURE BEHAVIOR OF State_Machine IS
    TYPE type_fstate IS (Idle,Init,Active);
    SIGNAL fstate : type_fstate;
    SIGNAL reg_fstate : type_fstate;
BEGIN
    PROCESS (clock,reset,reg_fstate)
    BEGIN
	     IF (reset='0') THEN
            fstate <= Idle;
        ELSIF (rising_edge(clock)) THEN
            fstate <= reg_fstate;
        END IF;
    END PROCESS;

    PROCESS (fstate,a,b)
    BEGIN
            CASE fstate IS
				
				--Idle State
               WHEN Idle =>
				   moo_out <= '0';
					mee_out <= '0';
                    IF ((b = '1')) THEN
                        reg_fstate <= Init;
								
                    ELSIF ((b = '0')) THEN
                        reg_fstate <= Idle;
                    -- Inserting 'else' block to prevent latch inference
                    ELSE
                        reg_fstate <= Idle;
                    END IF;

						  
				  --Init State
                WHEN Init =>
								moo_out <= '1';
                    IF (((b = '0') AND (a = '0'))) THEN
                        reg_fstate <= Idle;
								
                    ELSIF (((b = '0') AND (a = '1'))) THEN
                        reg_fstate <= Active;
								
                    ELSIF ((b = '1') AND (a = '0')) THEN
                        reg_fstate <= Init;
								mee_out <= '0';
								
						  ELSIF ((b = '1') AND (a = '1')) THEN
								reg_fstate <= Init;
								mee_out <= '1';
                    -- Inserting 'else' block to prevent latch inference
                    ELSE
                        reg_fstate <= Init;
                    END IF;
						  
					--Active State	  
                WHEN Active =>
					 	  mee_out <= '0';
                    moo_out <= '1';
						  reg_fstate <= Idle;
						  
                WHEN OTHERS => 
						  mee_out <= 'X';
                    moo_out <= 'X';
            END CASE;
    END PROCESS;
END BEHAVIOR;
