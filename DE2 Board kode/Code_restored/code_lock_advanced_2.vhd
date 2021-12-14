LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE work.ALL;

ENTITY code_lock_advanced_2 IS
	PORT (
		--input
		clock : IN std_logic;
		reset : IN std_logic;
		enter : IN std_logic;
		code : IN std_logic_vector(3 DOWNTO 0);
		--output
		lock,permlock : OUT std_logic;
		IDLE_STATE, EVA_1_STATE, GET_STATE, EVA_2_STATE, GOING_STATE, WRONG_CODE_STATE, PERMANENTLY_LOCKED_STATE, UNLOCKED_LED : OUT std_logic
	);
END code_lock_advanced_2;

ARCHITECTURE BEHAVIOR OF code_lock_advanced_2 IS
	TYPE type_fstate IS (Idle, eva_code_1, get_code_2, eva_code_2, Wrong_CODE, unlocked, going_idle, Permanently_Locked); -- WRONG CODE skal måske ikke med?
	TYPE type_fstate2 IS (Err_0, Err_1, Err_2, Err_3);
	SIGNAL err_event : std_logic;
	SIGNAL failed : std_logic;
	SIGNAL fstate : type_fstate;
	SIGNAL reg_fstate : type_fstate;
	SIGNAL fstate2 : type_fstate2;
	SIGNAL reg_fstate2 : type_fstate2;
	SIGNAL code1, code2 : std_logic_vector(3 DOWNTO 0);
	-- Code Lock Process
BEGIN
	PROCESS (clock, reset, reg_fstate)
	BEGIN
		IF (reset = '0') THEN
			fstate <= Idle;
		ELSIF (rising_edge(clock)) THEN
			fstate <= reg_fstate;
		END IF;
	END PROCESS;

	PROCESS (fstate, enter, code, code1, code2, failed)
	BEGIN
		code1 <= "1000";
		code2 <= "0111";
		CASE fstate IS

				--Idle State
			WHEN Idle =>
				--LED STATES
				lock <= '1';
				IDLE_STATE <= '1';
				EVA_1_STATE <= '0';
				GET_STATE <= '0';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				WRONG_CODE_STATE <= '0';
				PERMANENTLY_LOCKED_STATE <= '0';
				--LED STATES COMPLETE
				err_event <= '0';
				IF ((enter = '0')) THEN
					reg_fstate <= eva_code_1;
					-- Inserting 'else' block to prevent latch inference
				ELSE
					reg_fstate <= Idle;
				END IF;

				--Evaluation code 1    
			WHEN eva_code_1 =>
				--LED STATES
				lock <= '1';
				IDLE_STATE <= '0';
				EVA_1_STATE <= '1';
				GET_STATE <= '0';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				EVA_1_STATE <= '1';
				WRONG_CODE_STATE <= '0';
				PERMANENTLY_LOCKED_STATE <= '0';
				--LED STATES COMPLETE
				err_event <= '0';
				IF ((enter = '1') AND (code < code1 OR code > code1)) THEN --define code 1
					reg_fstate <= WRONG_CODE;
					err_event <= '1';
				ELSIF ((enter = '1') AND (code = code1)) THEN
					reg_fstate <= get_code_2;
					-- Inserting 'else' block to prevent latch inference
				ELSE
					reg_fstate <= eva_code_1;
				END IF;

				--Getting code 2    
			WHEN get_code_2 =>
				--LED STATES
				lock <= '1';
				IDLE_STATE <= '0';
				EVA_1_STATE <= '0';
				GET_STATE <= '1';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				WRONG_CODE_STATE <= '0';
				PERMANENTLY_LOCKED_STATE <= '0';
				--LED STATES COMPLETE
				err_event <= '0';
				IF (enter = '0') THEN
					reg_fstate <= eva_code_2;
				ELSE
					reg_fstate <= get_code_2;
				END IF;

				--WRONG CODE!						
			WHEN WRONG_CODE =>
				-- LED STATES
				lock <= '1';
				IDLE_STATE <= '0';
				EVA_1_STATE <= '0';
				GET_STATE <= '0';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				WRONG_CODE_STATE <= '1';
				PERMANENTLY_LOCKED_STATE <= '0';
				-- LED STATES COMPLETE

				err_event <= '0';
				IF (enter = '0') THEN
					IF (failed = '1') THEN
						reg_fstate <= Permanently_Locked;
					ELSE
						reg_fstate <= going_idle;
					END IF;
				ELSE
					reg_fstate <= WRONG_CODE;
				END IF;

					-- PERMANENTLY LOCKED
				WHEN Permanently_Locked =>
					--GPIO pin
					
					--LED STATES
					lock <= '1';
					IDLE_STATE <= '0';
					EVA_1_STATE <= '0';
					GET_STATE <= '0';
					EVA_2_STATE <= '0';
					GOING_STATE <= '0';
					WRONG_CODE_STATE <= '0';
					PERMANENTLY_LOCKED_STATE <= '1';
					--LED STATES COMPLETE
					err_event <= '0';
					reg_fstate <= Permanently_Locked;

					--Evaluation code 2    
				WHEN eva_code_2 =>
					--LED STATES
					lock <= '1';
					IDLE_STATE <= '0';
					EVA_1_STATE <= '0';
					GET_STATE <= '0';
					EVA_2_STATE <= '1';
					GOING_STATE <= '0';
					WRONG_CODE_STATE <= '0';
					PERMANENTLY_LOCKED_STATE <= '0';
					--LED STATES COMPLETE
					err_event <= '0';
					--IF ((enter = '1') AND (code < code2 OR code > code2)) THEN --define code 2
					IF ((enter = '1') AND (code /= code2)) THEN --define code 2 --forskellig fra
						reg_fstate <= WRONG_CODE;
						err_event <= '1';
					ELSIF ((enter = '1') AND (code = code2)) THEN
						reg_fstate <= Unlocked;

						-- Inserting 'else' block to prevent latch inference
					ELSE
						reg_fstate <= eva_code_2;

					END IF;

					--Unlocked    
				WHEN Unlocked =>
					lock <= '0';
					err_event <= '0';
					IF (enter = '0') THEN
						reg_fstate <= going_idle;
					ELSE
						reg_fstate <= Unlocked;
					END IF;
					--Going idle   
				WHEN going_idle =>
					-- LED STATES
					lock <= '1';
					IDLE_STATE <= '0';
					EVA_1_STATE <= '0';
					GET_STATE <= '0';
					EVA_2_STATE <= '0';
					GOING_STATE <= '1';
					WRONG_CODE_STATE <= '0';
					PERMANENTLY_LOCKED_STATE <= '0';
					-- LED STATES COMPLETE
					err_event <= '0';
					IF (enter = '1') THEN
						reg_fstate <= Idle;
					ELSE
						reg_fstate <= going_idle;
					END IF;
				WHEN OTHERS =>
					reg_fstate <= idle;
				END CASE;
		END PROCESS;
		wrong_code_component : ENTITY work.Wrong_Code PORT MAP
			(
			--input
			reset_WC => reset,
			err_event_WC => err_event,
			--output
			failed_WC => failed
			);

		-- CODE LOCK PROCESS END
		-------------------------------------------

		-------------------------------------------
		--Wrong Code Process
		--    PROCESS (clock,reset,reg_fstate2)
		--    BEGIN
		--        IF (rising_edge(err_event)) THEN
		--            fstate2 <= reg_fstate2;
		--        END IF;
		--    END PROCESS;	
		--	 
		--	  PROCESS (fstate2)
		--    BEGIN
		--            CASE fstate2 IS
		--				
		--				--Err_0 State
		--               WHEN Err_0 =>
		--						failed <= '0';
		--						reg_fstate2 <= Err_1;
		--				--Err_1 State		
		--					WHEN Err_1 =>
		--						failed <= '0';
		--						reg_fstate2 <= Err_2;
		--				--Err_2 State		
		--					WHEN Err_2 =>
		--						failed <= '0';
		--						reg_fstate2 <= Err_3;
		--				--Err_3 State	
		--					WHEN Err_3 =>
		--						failed <= '1';
		--						reg_fstate2 <= Err_3;
		--                
		--            END CASE;
		--    END PROCESS;
		--WRONG CODE PROCESS END
		-------------------------------------

	END BEHAVIOR;
	
	
	
	ARCHITECTURE BEHAVIOR_alt OF code_lock_advanced_2 IS
	TYPE type_fstate IS (Idle, eva_code_1, get_code_2, eva_code_2, Wrong_CODE, unlocked, going_idle, Permanently_Locked); -- WRONG CODE skal måske ikke med?
	TYPE type_fstate2 IS (Err_0, Err_1, Err_2, Err_3);
	SIGNAL err_event : std_logic;
	SIGNAL failed : std_logic;
	SIGNAL fstate : type_fstate;
	SIGNAL reg_fstate : type_fstate;
	SIGNAL fstate2 : type_fstate2;
	SIGNAL reg_fstate2 : type_fstate2;
	SIGNAL code1, code2 : std_logic_vector(3 DOWNTO 0);
	------------------------------------------------------
	signal enter_low, enter_high : std_logic;
	-------------------------------------
	-- Code Lock Process
BEGIN
	PROCESS (clock, reset, reg_fstate)
	BEGIN
		IF (reset = '0') THEN
			fstate <= Idle;
		ELSIF (rising_edge(clock)) THEN
			fstate <= reg_fstate;
		END IF;
	END PROCESS;

	PROCESS (fstate, enter_low, enter_high, code, code1, code2, failed)
	BEGIN
		code1 <= "1000";
		code2 <= "0111";
		CASE fstate IS

				--Idle State
			WHEN Idle =>
			permlock <= '0';
				--LED STATES
				UNLOCKED_LED <= '0'; 
				lock <= '0';
				IDLE_STATE <= '1';
				EVA_1_STATE <= '0';
				GET_STATE <= '0';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				WRONG_CODE_STATE <= '0';
				PERMANENTLY_LOCKED_STATE <= '0';
				--LED STATES COMPLETE
				err_event <= '0';
				IF ((enter_low = '1')) THEN
					reg_fstate <= eva_code_1;
					-- Inserting 'else' block to prevent latch inference
				ELSE
					reg_fstate <= Idle;
				END IF;

				--Evaluation code 1    
			WHEN eva_code_1 =>
			permlock <= '0';
				--LED STATES
				lock <= '0';
				IDLE_STATE <= '0';
				EVA_1_STATE <= '1';
				GET_STATE <= '0';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				EVA_1_STATE <= '1';
				WRONG_CODE_STATE <= '0';
				PERMANENTLY_LOCKED_STATE <= '0';
				--LED STATES COMPLETE
				err_event <= '0';
				IF ((enter_high= '1') AND (code < code1 OR code > code1)) THEN --define code 1
					reg_fstate <= WRONG_CODE;
					err_event <= '1';
				ELSIF ((enter_high = '1') AND (code = code1)) THEN
					reg_fstate <= get_code_2;
					-- Inserting 'else' block to prevent latch inference
				ELSE
					reg_fstate <= eva_code_1;
				END IF;

				--Getting code 2    
			WHEN get_code_2 =>
			permlock <= '0';
				--LED STATES
				lock <= '0';
				IDLE_STATE <= '0';
				EVA_1_STATE <= '0';
				GET_STATE <= '1';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				WRONG_CODE_STATE <= '0';
				PERMANENTLY_LOCKED_STATE <= '0';
				--LED STATES COMPLETE
				err_event <= '0';
				IF (enter_low = '1') THEN
					reg_fstate <= eva_code_2;
				ELSE
					reg_fstate <= get_code_2;
				END IF;

				--WRONG CODE!						
			WHEN WRONG_CODE =>
			permlock <= '0';
				-- LED STATES
				lock <= '0';
				IDLE_STATE <= '0';
				EVA_1_STATE <= '0';
				GET_STATE <= '0';
				EVA_2_STATE <= '0';
				GOING_STATE <= '0';
				WRONG_CODE_STATE <= '1';
				PERMANENTLY_LOCKED_STATE <= '0';
				-- LED STATES COMPLETE

				err_event <= '0';
				IF (enter_low = '1') THEN
					IF (failed = '1') THEN
						reg_fstate <= Permanently_Locked;
					ELSE
						reg_fstate <= going_idle;
					END IF;
				ELSE
					reg_fstate <= WRONG_CODE;
				END IF;

					-- PERMANENTLY LOCKED
				WHEN Permanently_Locked =>
					permlock <= '1';
					--LED STATES
					lock <= '0';
					IDLE_STATE <= '0';
					EVA_1_STATE <= '0';
					GET_STATE <= '0';
					EVA_2_STATE <= '0';
					GOING_STATE <= '0';
					WRONG_CODE_STATE <= '0';
					PERMANENTLY_LOCKED_STATE <= '1';
					--LED STATES COMPLETE
					err_event <= '0';
					reg_fstate <= Permanently_Locked;

					--Evaluation code 2    
				WHEN eva_code_2 =>
				permlock <= '0';
					--LED STATES
					lock <= '0';
					IDLE_STATE <= '0';
					EVA_1_STATE <= '0';
					GET_STATE <= '0';
					EVA_2_STATE <= '1';
					GOING_STATE <= '0';
					WRONG_CODE_STATE <= '0';
					PERMANENTLY_LOCKED_STATE <= '0';
					--LED STATES COMPLETE
					err_event <= '0';
					--IF ((enter_high = '1') AND (code < code2 OR code > code2)) THEN --define code 2
					IF ((enter_high = '1') AND (code /= code2)) THEN --define code 2 --forskellig fra
						reg_fstate <= WRONG_CODE;
						err_event <= '1';
					ELSIF ((enter_high = '1') AND (code = code2)) THEN
						reg_fstate <= Unlocked;

						-- Inserting 'else' block to prevent latch inference
					ELSE
						reg_fstate <= eva_code_2;

					END IF;

					--Unlocked    
				WHEN Unlocked =>
					permlock <= '0';
					UNLOCKED_LED <= '1'; 
					lock <= '1';
					err_event <= '0';
					IF (enter_low = '1') THEN
						UNLOCKED_LED <= '0'; 
						reg_fstate <= going_idle;
					ELSE
						reg_fstate <= Unlocked;
					END IF;
					--Going idle   
				WHEN going_idle =>
					-- LED STATES
					lock <= '0';
					IDLE_STATE <= '0';
					EVA_1_STATE <= '0';
					GET_STATE <= '0';
					EVA_2_STATE <= '0';
					GOING_STATE <= '1';
					WRONG_CODE_STATE <= '0';
					PERMANENTLY_LOCKED_STATE <= '0';
					-- LED STATES COMPLETE
					err_event <= '0';
					IF (enter_high = '1') THEN
						reg_fstate <= Idle;
					ELSE
						reg_fstate <= going_idle;
					END IF;
				WHEN OTHERS =>
					reg_fstate <= idle;
				END CASE;
		END PROCESS;
		wrong_code_component : ENTITY work.Wrong_Code PORT MAP
			(
			--input
			reset_WC => reset,
			err_event_WC => err_event,
			--output
			failed_WC => failed
			);

		-- CODE LOCK PROCESS END
		-------------------------------------------

		-------------------------------------------
		--Wrong Code Process
		--    PROCESS (clock,reset,reg_fstate2)
		--    BEGIN
		--        IF (rising_edge(err_event)) THEN
		--            fstate2 <= reg_fstate2;
		--        END IF;
		--    END PROCESS;	
		--	 
		--	  PROCESS (fstate2)
		--    BEGIN
		--            CASE fstate2 IS
		--				
		--				--Err_0 State
		--               WHEN Err_0 =>
		--						failed <= '0';
		--						reg_fstate2 <= Err_1;
		--				--Err_1 State		
		--					WHEN Err_1 =>
		--						failed <= '0';
		--						reg_fstate2 <= Err_2;
		--				--Err_2 State		
		--					WHEN Err_2 =>
		--						failed <= '0';
		--						reg_fstate2 <= Err_3;
		--				--Err_3 State	
		--					WHEN Err_3 =>
		--						failed <= '1';
		--						reg_fstate2 <= Err_3;
		--                
		--            END CASE;
		--    END PROCESS;
		--WRONG CODE PROCESS END
		-------------------------------------
		
		synchroniser_component : ENTITY work.synchroniser PORT MAP
			(
			--input
			async_sig => enter,
			clk => clock,
			reset=>reset,
			--output
			fall => enter_low,
			rise => enter_high,
			synced =>open
			);
		

	END BEHAVIOR_alt;