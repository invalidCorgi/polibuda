LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY VHDL_reklama IS
	PORT (SW : IN STD_LOGIC_VECTOR(17 DOWNTO 0);
			HEX0 : OUT STD_LOGIC_VECTOR(0 TO 6);
			HEX1 : OUT STD_LOGIC_VECTOR(0 TO 6);
			HEX2 : OUT STD_LOGIC_VECTOR(0 TO 6);
			HEX3 : OUT STD_LOGIC_VECTOR(0 TO 6);
			HEX4 : OUT STD_LOGIC_VECTOR(0 TO 6);
			HEX5 : OUT STD_LOGIC_VECTOR(0 TO 6);
			HEX6 : OUT STD_LOGIC_VECTOR(0 TO 6);
			HEX7 : OUT STD_LOGIC_VECTOR(0 TO 6));
END VHDL_reklama;


ARCHITECTURE strukturalna OF VHDL_reklama IS
	CONSTANT SPACJA : STD_LOGIC_VECTOR(2 DOWNTO 0) := "000";
	SIGNAL M0 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL M1 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL M2 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL M3 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL M4 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL M5 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL M6 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL M7 : STD_LOGIC_VECTOR(2 DOWNTO 0);
	
	COMPONENT char7seg IS
		PORT (C : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
				Display : OUT STD_LOGIC_VECTOR(0 TO 6));
	END COMPONENT;
	
	COMPONENT mux3bit_8to1 --muliptekser
        PORT ( S, U0, U1, U2, U3, U4, U5, U6, U7: IN STD_LOGIC_VECTOR(2 DOWNTO 0); --WEKTOR STERUJĄCY I 8 wektorówINFORMACYJNYCH
                    M0: OUT    STD_LOGIC_VECTOR(2 DOWNTO 0)); 
    END COMPONENT; 
	
	BEGIN
	
	MUX0: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SPACJA, SPACJA, SPACJA, SW(2 DOWNTO 0), SW(5 DOWNTO 3), SW(8 DOWNTO 6), SW(11 DOWNTO 9), SW(14 DOWNTO 12), M0);
	MUX1: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SPACJA, SPACJA, SW(2 DOWNTO 0), SW(5 DOWNTO 3), SW(8 DOWNTO 6), SW(11 DOWNTO 9), SW(14 DOWNTO 12), SPACJA, M1);
	MUX2: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SPACJA, SW(2 DOWNTO 0), SW(5 DOWNTO 3), SW(8 DOWNTO 6), SW(11 DOWNTO 9), SW(14 DOWNTO 12), SPACJA, SPACJA, M2);
	MUX3: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SW(2 DOWNTO 0), SW(5 DOWNTO 3), SW(8 DOWNTO 6), SW(11 DOWNTO 9), SW(14 DOWNTO 12), SPACJA, SPACJA, SPACJA, M3);
	MUX4: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SW(5 DOWNTO 3), SW(8 DOWNTO 6), SW(11 DOWNTO 9), SW(14 DOWNTO 12), SPACJA, SPACJA, SPACJA, SW(2 DOWNTO 0), M4);
	MUX5: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SW(8 DOWNTO 6), SW(11 DOWNTO 9), SW(14 DOWNTO 12), SPACJA, SPACJA, SPACJA, SW(2 DOWNTO 0), SW(5 DOWNTO 3), M5);
	MUX6: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SW(11 DOWNTO 9), SW(14 DOWNTO 12), SPACJA, SPACJA, SPACJA, SW(2 DOWNTO 0), SW(5 DOWNTO 3), SW(8 DOWNTO 6), M6);
	MUX7: mux3bit_8to1 PORT MAP (SW(17 DOWNTO 15), SW(14 DOWNTO 12), SPACJA, SPACJA, SPACJA, SW(2 DOWNTO 0), SW(5 DOWNTO 3), SW(8 DOWNTO 6), SW(11 DOWNTO 9), M7);
	
	H0: char7seg PORT MAP (M0, HEX0);
	H1: char7seg PORT MAP (M1, HEX1);
	H2: char7seg PORT MAP (M2, HEX2);
	H3: char7seg PORT MAP (M3, HEX3);
	H4: char7seg PORT MAP (M4, HEX4);
	H5: char7seg PORT MAP (M5, HEX5);
	H6: char7seg PORT MAP (M6, HEX6);
	H7: char7seg PORT MAP (M7, HEX7);
	
END strukturalna;


LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY char7seg IS
	PORT (C : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
			Display : OUT STD_LOGIC_VECTOR(0 TO 6));
END char7seg;

ARCHITECTURE strukturalna OF char7seg IS
BEGIN

    process(C)
    begin
		Display(0) <= (not C(0) and not C(1) and not C(2));
		Display(1) <= (not C(0) and not C(1) and not C(2)) or (C(1) and C(0));
		Display(2) <= (not C(0) and not C(1) and not C(2)) or (C(1) and not C(0));
		Display(3) <= (not C(0));
		Display(4) <= (not C(0) and not C(1) and not C(2)) or (C(1) and C(0));
		Display(5) <= (not C(0) and not C(1) and not C(2));
		Display(6) <= (not C(2) and not C(1));
    end process;
		
END strukturalna;

--implementacja multipleksera 8 do 1 (wektor 3 bitowy)
LIBRARY ieee; 
USE ieee.std_logic_1164.all; 

ENTITY mux3bit_8to1 IS 
        PORT ( S, U0, U1, U2, U3, U4, U5, U6, U7: IN STD_LOGIC_VECTOR(2 DOWNTO 0);
                    M0: OUT    STD_LOGIC_VECTOR(2 DOWNTO 0)); 
END mux3bit_8to1;

ARCHITECTURE strukturalna OF mux3bit_8to1 IS 
BEGIN
    process(S, U0, U1, U2, U3, U4, U5, U6, U7)
		begin
		case S is
			when "000" => M0 <= U0;
			when "001" => M0 <= U1;
			when "011" => M0 <= U2;
			when "010" => M0 <= U3;
			when "110" => M0 <= U4;
			when "111" => M0 <= U5;
			when "101" => M0 <= U6;
			when "100" => M0 <= U7;
		end case;
    end process;
END strukturalna;