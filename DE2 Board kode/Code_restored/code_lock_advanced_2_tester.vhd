library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;

entity code_lock_advanced_2_tester is
  port (
    --input
    CLOCK_50 : IN STD_LOGIC;
    KEY : IN STD_LOGIC_VECTOR(2 DOWNTO 1);
    SW : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    --output
	 LEDR : out STD_LOGIC_VECTOR(7 DOWNTO 0);
	 
	 --Her vil jeg gerne udskifte LEDG med GPIO_1 : out std_logic_vector(0 downto 0)
    LEDG : out STD_LOGIC_VECTOR(0 DOWNTO 0);
	 GPIO_1: out std_logic_vector(1 downto 0);
	 GPIO_0: in std_logic_vector(0 downto 0)
	 
  );
end code_lock_advanced_2_tester;


architecture code_lock_advanced_2_tester_impl of code_lock_advanced_2_tester is
begin
code_lock_advanced: entity work.code_lock_advanced_2(behavior_alt) port map
(
    --input
    clock   						=> CLOCK_50,
    reset   						=> KEY(1),
    code    						=> SW,	
    enter   						=> KEY(2), --GPIO_0(0),--KEY(2),
    --output
	 IDLE_STATE 					=> LEDR(0),
	 EVA_1_STATE 					=> LEDR(1),
	 GET_STATE 						=> LEDR(2),
	 EVA_2_STATE 					=> LEDR(3),
	 GOING_STATE 					=> LEDR(4),
	 WRONG_CODE_STATE 			=> LEDR(5),
	 PERMANENTLY_LOCKED_STATE 	=> LEDR(6),
	 UNLOCKED_LED					=> LEDR(7),
    lock		    					=> GPIO_1(0),  -- Her vil jeg gerne mappe lock til GPIO_1(0)
	 permlock		    			=> GPIO_1(1)  -- Her vil jeg gerne mappe PERMlock til GPIO_1(1)
	 
);
end code_lock_advanced_2_tester_impl ;