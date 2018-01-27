library ieee;
use ieee.std_logic_1164.all;

entity transkoder is

	port 
	(
		sw: in std_logic_vector(0 to 3);
		ledr: out std_logic_vector(0 to 4)
	);

end entity;

architecture ar_tr of transkoder is
	--variable info :
begin
	
	multiplexerY0: process (sw)
	variable weAdresowe : std_logic_vector(1 to 3) := sw(1 to 3);
	variable weInformacyjne : std_logic_vector(0 to 7);
	begin
		weInformacyjne(0):=sw(0);
		weInformacyjne(1):=sw(0);
		weInformacyjne(2):='1';
		weInformacyjne(3):='0';
		weInformacyjne(4):='0';
		weInformacyjne(5):=not sw(0);
		weInformacyjne(6):='0';
		weInformacyjne(7):='1';
		case weAdresowe is
			when "000" =>
				ledr(0) <= weInformacyjne(0);
			when "100" =>
				ledr(0) <= weInformacyjne(1);
			when "010" =>
				ledr(0) <= weInformacyjne(2);
			when "110" =>
				ledr(0) <= weInformacyjne(3);
			when "001" =>
				ledr(0) <= weInformacyjne(4);
			when "101" =>
				ledr(0) <= weInformacyjne(5);
			when "011" =>
				ledr(0) <= weInformacyjne(6);
			when "111" =>
				ledr(0) <= weInformacyjne(7);
		end case;
	end process;

	multiplexerY1: process (sw)
	variable weAdresowe : std_logic_vector(1 to 3) := sw(1 to 3);
	variable weInformacyjne : std_logic_vector(0 to 7);
	begin
		weInformacyjne(0):=sw(0);
		weInformacyjne(1):='1';
		weInformacyjne(2):=sw(0);
		weInformacyjne(3):='0';
		weInformacyjne(4):=not sw(0);
		weInformacyjne(5):='0';
		weInformacyjne(6):='1';
		weInformacyjne(7):='0';
		case weAdresowe is
			when "000" =>
				ledr(1) <= weInformacyjne(0);
			when "100" =>
				ledr(1) <= weInformacyjne(1);
			when "010" =>
				ledr(1) <= weInformacyjne(2);
			when "110" =>
				ledr(1) <= weInformacyjne(3);
			when "001" =>
				ledr(1) <= weInformacyjne(4);
			when "101" =>
				ledr(1) <= weInformacyjne(5);
			when "011" =>
				ledr(1) <= weInformacyjne(6);
			when "111" =>
				ledr(1) <= weInformacyjne(7);
		end case;
	end process;
	
	multiplexerY2: process (sw)
	variable weAdresowe : std_logic_vector(1 to 3) := sw(1 to 3);
	variable weInformacyjne : std_logic_vector(0 to 7);
	begin
		weInformacyjne(0):='0';
		weInformacyjne(1):=not sw(0);
		weInformacyjne(2):=sw(0);
		weInformacyjne(3):='0';
		weInformacyjne(4):=sw(0);
		weInformacyjne(5):=not sw(0);
		weInformacyjne(6):='0';
		weInformacyjne(7):='1';
		case weAdresowe is
			when "000" =>
				ledr(2) <= weInformacyjne(0);
			when "100" =>
				ledr(2) <= weInformacyjne(1);
			when "010" =>
				ledr(2) <= weInformacyjne(2);
			when "110" =>
				ledr(2) <= weInformacyjne(3);
			when "001" =>
				ledr(2) <= weInformacyjne(4);
			when "101" =>
				ledr(2) <= weInformacyjne(5);
			when "011" =>
				ledr(2) <= weInformacyjne(6);
			when "111" =>
				ledr(2) <= weInformacyjne(7);
		end case;
	end process;
	
	multiplexerY3: process (sw)
	variable weAdresowe : std_logic_vector(1 to 3) := sw(1 to 3);
	variable weInformacyjne : std_logic_vector(0 to 7);
	begin
		weInformacyjne(0):=sw(0);
		weInformacyjne(1):=not sw(0);
		weInformacyjne(2):='1';
		weInformacyjne(3):='0';
		weInformacyjne(4):='1';
		weInformacyjne(5):=sw(0);
		weInformacyjne(6):='0';
		weInformacyjne(7):='1';
		case weAdresowe is
			when "000" =>
				ledr(3) <= weInformacyjne(0);
			when "100" =>
				ledr(3) <= weInformacyjne(1);
			when "010" =>
				ledr(3) <= weInformacyjne(2);
			when "110" =>
				ledr(3) <= weInformacyjne(3);
			when "001" =>
				ledr(3) <= weInformacyjne(4);
			when "101" =>
				ledr(3) <= weInformacyjne(5);
			when "011" =>
				ledr(3) <= weInformacyjne(6);
			when "111" =>
				ledr(3) <= weInformacyjne(7);
		end case;
	end process;
	
	multiplexerError: process (sw)
	variable weAdresowe : std_logic_vector(1 to 3) := sw(1 to 3);
	variable weInformacyjne : std_logic_vector(0 to 7);
	begin
		weInformacyjne(0):='0';
		weInformacyjne(1):='0';
		weInformacyjne(2):='0';
		weInformacyjne(3):='1';
		weInformacyjne(4):='0';
		weInformacyjne(5):='0';
		weInformacyjne(6):=sw(0);
		weInformacyjne(7):=sw(0);
		case weAdresowe is
			when "000" =>
				ledr(4) <= weInformacyjne(0);
			when "100" =>
				ledr(4) <= weInformacyjne(1);
			when "010" =>
				ledr(4) <= weInformacyjne(2);
			when "110" =>
				ledr(4) <= weInformacyjne(3);
			when "001" =>
				ledr(4) <= weInformacyjne(4);
			when "101" =>
				ledr(4) <= weInformacyjne(5);
			when "011" =>
				ledr(4) <= weInformacyjne(6);
			when "111" =>
				ledr(4) <= weInformacyjne(7);
		end case;
	end process;
end ar_tr;
