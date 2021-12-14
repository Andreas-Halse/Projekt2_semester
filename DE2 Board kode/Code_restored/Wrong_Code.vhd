library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;

ENTITY Wrong_Code IS
    PORT (
	 --input
		  reset_WC : IN STD_LOGIC;
        err_event_WC : IN STD_LOGIC;
	 --output	  
		  failed_WC : OUT STD_LOGIC
    );
END Wrong_Code;

ARCHITECTURE BEHAVIOR OF Wrong_Code IS
    TYPE type_fstate IS (Err_0,Err_1,Err_2,Err_3);
    SIGNAL fstate : type_fstate;
    SIGNAL reg_fstate : type_fstate;
BEGIN
    PROCESS (err_event_WC,reg_fstate,reset_WC)
    BEGIN
		  IF (reset_WC='0') THEN
				fstate <= Err_0;
        ELSIF (rising_edge(err_event_WC)) THEN
            fstate <= reg_fstate;
        END IF;
    END PROCESS;

    PROCESS (fstate)
    BEGIN
            CASE fstate IS
				--ERR_0 STATE
               WHEN Err_0 =>
							failed_WC <= '0';
                     reg_fstate <= Err_1;
				--ERR_1 STATE
					WHEN Err_1 =>
							failed_WC <= '0';
							reg_fstate <= Err_2;
				--ERR_2 STATE
               WHEN Err_2 =>
							failed_WC <= '0';
                     reg_fstate <= Err_3;
				--ERR_3 STATE
					WHEN Err_3 =>
							failed_WC <= '1';
                     reg_fstate <= Err_3;		
					END CASE;
    END PROCESS;
END BEHAVIOR;
