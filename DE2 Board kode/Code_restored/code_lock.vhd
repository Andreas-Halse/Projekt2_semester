library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;

ENTITY code_lock IS
    PORT (
    --input
        clock : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        enter : IN STD_LOGIC;
        code : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    --output
        lock : OUT STD_LOGIC;
		  IDLE_STATE, EVA_1_STATE, GET_STATE,EVA_2_STATE, GOING_STATE : OUT STD_LOGIC
    );
END code_lock;

ARCHITECTURE BEHAVIOR OF code_lock IS
    TYPE type_fstate IS (Idle,eva_code_1,get_code_2,eva_code_2,unlocked,going_idle); 
    SIGNAL fstate : type_fstate;
    SIGNAL reg_fstate : type_fstate;
	SIGNAL code1, code2 : STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN
    PROCESS (clock,reset,reg_fstate)
    BEGIN
	    IF (reset='0') THEN
            fstate <= Idle;
        ELSIF (rising_edge(clock)) THEN
            fstate <= reg_fstate;
        END IF;
    END PROCESS;

    PROCESS (fstate,enter,code,code1,code2)
    BEGIN
				code1 <= "1000";
				code2 <= "0111";
            CASE fstate IS
				
					 --Idle State
                WHEN Idle =>
                lock 			<= '1';
					 IDLE_STATE 	<= '1';
					 EVA_1_STATE 	<= '0';
					 GET_STATE 		<= '0';
					 EVA_2_STATE 	<= '0';
					 GOING_STATE 	<= '0';
                    IF ((enter = '0')) THEN
                        reg_fstate <= eva_code_1;
                    -- Inserting 'else' block to prevent latch inference
                    ELSE
                        reg_fstate <= Idle;
                    END IF;

                --Evaluation code 1    
                WHEN eva_code_1 =>
                lock 			<= '1';
					 IDLE_STATE 	<= '0';
					 EVA_1_STATE 	<= '1';
					 GET_STATE 		<= '0';
					 EVA_2_STATE 	<= '0';
					 GOING_STATE 	<= '0';
					 EVA_1_STATE <= '1';
                    IF ((enter = '1') AND (code<code1 OR code>code1)) THEN     --define code 1
                        reg_fstate <= Idle;
                    ELSIF ((enter = '1') AND  (code = code1)) then
                        reg_fstate <= get_code_2;
                    -- Inserting 'else' block to prevent latch inference
                    ELSE
                        reg_fstate <= eva_code_1;
                    END IF;

                --Getting code 2    
                WHEN get_code_2 =>
                lock 			<= '1';
					 IDLE_STATE 	<= '0';
					 EVA_1_STATE 	<= '0';
					 GET_STATE 		<= '1';
					 EVA_2_STATE 	<= '0';
					 GOING_STATE 	<= '0';
                    IF (enter = '0') THEN 
                        reg_fstate <= eva_code_2;
                    ELSE
                        reg_fstate <= get_code_2;
                    END IF;

					--Evaluation code 2    
                WHEN eva_code_2 =>
                lock 			<= '1';
					 IDLE_STATE 	<= '0';
					 EVA_1_STATE 	<= '0';
					 GET_STATE 		<= '0';
					 EVA_2_STATE 	<= '1';
					 GOING_STATE 	<= '0';
                    IF ((enter = '1') AND (code<code2 OR code>code2)) THEN     --define code 2
                        reg_fstate <= idle;
                    ELSIF ((enter = '1') AND  (code = code2)) then
                        reg_fstate <= Unlocked;
                       
                    -- Inserting 'else' block to prevent latch inference
                    ELSE
                       reg_fstate <= eva_code_2;
                       
                    END IF;

                --Unlocked    
                WHEN Unlocked =>
                lock 			<= '0';
                    IF (enter = '0') THEN 
                        reg_fstate <= going_idle;
                    ELSE
                        reg_fstate <= Unlocked;
                    END IF;

                
                --Going idle   
                WHEN going_idle =>
                lock 			<= '1';
					 IDLE_STATE 	<= '0';
					 EVA_1_STATE 	<= '0';
					 GET_STATE 		<= '0';
					 EVA_2_STATE 	<= '0';
					 GOING_STATE 	<= '1';
                    IF (enter = '1') THEN 
                        reg_fstate <= Idle;
                    ELSE
                        reg_fstate <= going_idle;
                    END IF;
            END CASE;
    END PROCESS;
END BEHAVIOR;
