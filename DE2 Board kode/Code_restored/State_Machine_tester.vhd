library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;

entity State_Machine_Tester is
port 
(
    --input
    KEY0, KEY1, SW0, SW1 : in std_logic;
    --output
    LEDR : out std_logic_vector(1 downto 0)
) ;
end State_Machine_Tester;


architecture State_Machine_Tester_impl of State_Machine_Tester is
begin
    mee_moo : entity work.State_Machine port map 
    (
        --input
        clock => KEY0,
        reset => KEY1,
        a     => SW0,
        b     => SW1,
        --output
        moo_out => LEDR(0),
        mee_out => LEDR(1)
    );
end State_Machine_Tester_impl ; -- 
