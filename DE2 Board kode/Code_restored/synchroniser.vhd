Library ieee;
Use ieee.std_logic_1164.All;
Use ieee.numeric_std.All;
use work.all;
-- Producing a synchronous edge-detect pulse for the leading and trailing
-- edges of a long (many clocks) asynchronous pulse.

Entity synchroniser Is
	Port (
		async_sig : In Std_logic;
		clk : In Std_logic;
		reset : In Std_logic;
		rise      : out std_logic;
		fall : Out Std_logic;
		synced	  : out std_logic);
End;

Architecture synchroniser_impl Of synchroniser Is
Begin
	sync1 : Process (clk, reset)
		Variable resync : Std_logic_vector(1 To 3);
	Begin
		If reset = '0' Then
			fall <= '0';
		Elsif rising_edge(clk) Then
			-- detect rising and falling edges.
			rise <= resync(2) and not resync(3);
			fall <= resync(3) And Not resync(2);
			synced<=resync(2);
			-- update history shifter.
			resync := async_sig & resync(1 To 2);
		End If;
	End Process;

End Architecture;