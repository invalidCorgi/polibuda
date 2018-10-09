library IEEE;                  -- dolaczenie standardowej biblioteki IEEE
use IEEE.STD_LOGIC_1164.all;

entity zad6 is                 -- glowny element projektu
   port ( 
      clock_27: in std_logic;
      key: in std_logic_vector(1 to 1);
		sw: in std_logic_vector(0 to 3);
      hex0: out std_logic_vector(0 to 6);
      hex1: out std_logic_vector(0 to 6);
      hex2: out std_logic_vector(0 to 6);
      hex3: out std_logic_vector(0 to 6);
      hex4: out std_logic_vector(0 to 6);
      hex5: out std_logic_vector(0 to 6);
      hex6: out std_logic_vector(0 to 6);
      hex7: out std_logic_vector(0 to 6);
		ledr: out std_logic_vector(0 to 9);
		ledg: out std_logic_vector(0 to 1)
   );
end zad6;

architecture ar_zad_6 of zad6 is

	signal muxj: std_logic_vector(0 to 3);--wyjscia funkcji j na muxach 
	signal muxk: std_logic_vector(0 to 3);--wyjscia funkcji k na muxach 
	signal muxd: std_logic_vector(0 to 3);--wyjscia funkcji d na muxach 
   signal jkOut: std_logic_vector(0 to 3);--wyjścia jk - 1 licznik
	signal dOut: std_logic_vector(0 to 3);--wyjście d - 2 licznik
   signal clk: std_logic := '0';
   signal i: integer := 0;
	signal wyk: std_logic := '0';--warunkowanie wykonania zadań

   component clock
      port(
			wyk: in std_logic;
         we: in std_logic;
         i: inout integer;
         wy: out std_logic
      );
   end component;

   component digit
      port( 
         we: in std_logic_vector(0 to 3);
         wy1: out std_logic_vector(0 to 6);
			wy2: out std_logic_vector(0 to 6)
      );
   end component;

   component jk
      port( 
         wej: in std_logic;
			wek: in std_logic;
         clk: in std_logic;
         res: in std_logic;
			reset_to: in std_logic;
         wy: out std_logic
      );
   end component;
	
	component d
      port( 
         we: in std_logic;
         clk: in std_logic;
         res: in std_logic;
			reset_to: in std_logic;
         wy: out std_logic
      );
   end component;
	
   component mux
      port( 
         weI: in std_logic_vector(0 to 7);
			weA: in std_logic_vector(0 to 2);
         wy: out std_logic
      );
   end component;
	
begin
   hex4 <= "1111111";
   hex5 <= "1111111";
   hex6 <= "1111111";
   hex7 <= "1111111";
		
		process(key, jkOut)
		begin
		if(falling_edge(key(1))) then
			if ((sw(1)='1' and sw(2)='1' and sw(3)='0') or (sw(0)='1' and sw(2)='1' and sw(3)='1')) then
				ledr(0) <= '1';
				ledr(1) <= '0';
				wyk <= '0';
			else
				wyk <= '1';
				ledr(0) <= '0';
				ledr(1) <= '0';
			end if;
		end if;
		if jkOut="1000" then
			wyk <= '0';
			ledr(1) <= '1';
		end if;
		end process;
			
		i0: clock port map (wyk,clock_27, i, clk);
		muxj0: mux port map("00001111",jkOut(1)&jkOut(2)&jkOut(3),muxj(0));
		muxj1: mux port map("1100"&not jkOut(0)&"010",jkOut(1)&jkOut(2)&jkOut(3),muxj(1));
		muxj2: mux port map("01000"&not jkOut(0)&"00",jkOut(1)&jkOut(2)&jkOut(3),muxj(2));
		muxj3: mux port map(jkOut(0)&'1'&not jkOut(0)&"00000",jkOut(1)&jkOut(2)&jkOut(3),muxj(3));
		muxk0: mux port map("11111011",jkOut(1)&jkOut(2)&jkOut(3),muxk(0));
		muxk1: mux port map('0'&not jkOut(0)&"000101",jkOut(1)&jkOut(2)&jkOut(3),muxk(1));
		muxk2: mux port map("00"&not jkOut(0)&"01111",jkOut(1)&jkOut(2)&jkOut(3),muxk(2));
		muxk3: mux port map("00001100",jkOut(1)&jkOut(2)&jkOut(3),muxk(3));
		muxd3: mux port map("1111"&dOut(0)&'1'&not dOut(0)&'0',dOut(1)&dOut(2)&dOut(3),muxd(3));
		muxd2: mux port map('1'&not dOut(0)&"00"&dOut(0)&'0'&not dOut(0)&dOut(0),dOut(1)&dOut(2)&dOut(3),muxd(2));
		muxd1: mux port map("011110"&dOut(0)&'0',dOut(1)&dOut(2)&dOut(3),muxd(1));
		muxd0: mux port map("0011"&dOut(0)&not dOut(0)&'1'&dOut(0),dOut(1)&dOut(2)&dOut(3),muxd(0));
		muxDigitJK1a: mux port map(jkOut(0)&'0'&not jkOut(0)&"00"&jkOut(0)&'0'&not jkOut(0),jkOut(1)&jkOut(2)&jkOut(3),hex0(0));
		muxDigitJK1b: mux port map("00"&jkOut(0)&not jkOut(0)&"000"&jkOut(0),jkOut(1)&jkOut(2)&jkOut(3),hex0(1));
		muxDigitJK1c: mux port map('0'&not jkOut(0)&"0000"&not jkOut(0)&'0',jkOut(1)&jkOut(2)&jkOut(3),hex0(2));
		muxDigitJK1d: mux port map(jkOut(0)&'0'&not jkOut(0)&jkOut(0)&'0'&jkOut(0)&'0'&not jkOut(0),jkOut(1)&jkOut(2)&jkOut(3),hex0(3));
		muxDigitJK1e: mux port map(jkOut(0)&jkOut(0)&'1'&jkOut(0)&jkOut(0)&jkOut(0)&jkOut(0)&'1',jkOut(1)&jkOut(2)&jkOut(3),hex0(4));
		muxDigitJK1f: mux port map(jkOut(0)&"10"&jkOut(0)&'0'&jkOut(0)&"10",jkOut(1)&jkOut(2)&jkOut(3),hex0(5));
		muxDigitJK1g: mux port map("100"&jkOut(0)&"0100",jkOut(1)&jkOut(2)&jkOut(3),hex0(6));
		hex1(0) <= '1';
		muxDigitJK2b: mux port map("11111000",jkOut(1)&jkOut(2)&jkOut(3),hex1(1));
		muxDigitJK2c: mux port map("11111000",jkOut(1)&jkOut(2)&jkOut(3),hex1(2));
		hex1(3) <= '1';
		hex1(4) <= '1';
		hex1(5) <= '1';
		hex1(6) <= '1';
		muxDigitD1a: mux port map(dOut(0)&'0'&not dOut(0)&"00"&dOut(0)&'0'&not dOut(0),dOut(1)&dOut(2)&dOut(3),hex2(0));
		muxDigitD1b: mux port map("00"&dOut(0)&not dOut(0)&"000"&dOut(0),dOut(1)&dOut(2)&dOut(3),hex2(1));
		muxDigitD1c: mux port map('0'&not dOut(0)&"0000"&not dOut(0)&'0',dOut(1)&dOut(2)&dOut(3),hex2(2));
		muxDigitD1d: mux port map(dOut(0)&'0'&not dOut(0)&dOut(0)&'0'&dOut(0)&'0'&not dOut(0),dOut(1)&dOut(2)&dOut(3),hex2(3));
		muxDigitD1e: mux port map(dOut(0)&dOut(0)&'1'&dOut(0)&dOut(0)&dOut(0)&dOut(0)&'1',dOut(1)&dOut(2)&dOut(3),hex2(4));
		muxDigitD1f: mux port map(dOut(0)&"10"&dOut(0)&'0'&dOut(0)&"10",dOut(1)&dOut(2)&dOut(3),hex2(5));
		muxDigitD1g: mux port map("100"&dOut(0)&"0100",dOut(1)&dOut(2)&dOut(3),hex2(6));
		hex3(0) <= '1';
		muxDigitD2b: mux port map("11111000",dOut(1)&dOut(2)&dOut(3),hex3(1));
		muxDigitD2c: mux port map("11111000",dOut(1)&dOut(2)&dOut(3),hex3(2));
		hex3(3) <= '1';
		hex3(4) <= '1';
		hex3(5) <= '1';
		hex3(6) <= '1';
		jk0: jk port map(muxj(0),muxk(0),clk,key(1),sw(0),jkOut(0));
		jk1: jk port map(muxj(1),muxk(1),clk,key(1),sw(1),jkOut(1));
		jk2: jk port map(muxj(2),muxk(2),clk,key(1),sw(2),jkOut(2));
		jk3: jk port map(muxj(3),muxk(3),clk,key(1),sw(3),jkOut(3));
		d0: d port map(muxd(0),clk,key(1),'1',dOut(0));
		d1: d port map(muxd(1),clk,key(1),'1',dOut(1));
		d2: d port map(muxd(2),clk,key(1),'0',dOut(2));
		d3: d port map(muxd(3),clk,key(1),'1',dOut(3));
		ledr(2) <= jkOut(0);
		ledr(3) <= jkOut(1);
		ledr(4) <= jkOut(2);
		ledr(5) <= jkOut(3);
		ledr(6) <= dOut(0);
		ledr(7) <= dOut(1);
		ledr(8) <= dOut(2);
		ledr(9) <= dOut(3);
		ledg(0) <= clk;
		ledg(1) <= wyk;
	
end ar_zad_6;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity clock is                -- zmniejszenie czestotliwosci zegara systemowego
   port ( 
		wyk: in std_logic;
      we: in std_logic;
      i: inout integer;
      wy: out std_logic
   );
end clock;

architecture ar_zad_5 of clock is
begin
   process (we)
   begin
	if(wyk = '1') then
		wy <= we;
	else
		wy <= '0';
	end if;
--      if rising_edge(we) then 
--         i <= i+1;
--         if i = 14000000 then
--            wy <= '1';
--         end if; 
--         if i = 28000000 then
--            i <= 0;
--            wy <= '0';
--         end if;
--      end if;
   end process;
end ar_zad_5;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity mux is                    -- multiplekser
   port ( 
         weI: in std_logic_vector(0 to 7);
			weA: in std_logic_vector(0 to 2);
         wy: out std_logic
   );
end mux;

architecture ar_mux of mux is
begin
process(weI, weA)
		begin
		case weA is
			when "000" => wy <= weI(0);
			when "100" => wy <= weI(1);
			when "010" => wy <= weI(2);
			when "110" => wy <= weI(3);
			when "001" => wy <= weI(4);
			when "101" => wy <= weI(5);
			when "011" => wy <= weI(6);
			when "111" => wy <= weI(7);
		end case;
end process;



end ar_mux;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity jk is                    -- przerzutnik JK
   port ( 
      wej: in std_logic;
		wek: in std_logic;
      clk: in std_logic;
      res: in std_logic;
		reset_to: in std_logic;
      wy: out std_logic
   );
end jk;

architecture ar_jk of jk is

signal temp: std_logic;

begin
   process (clk,res)
   begin
      if res='0' then 
         temp <= reset_to;
      else
         if rising_edge(clk) then
            if wej = '1' and wek = '1' then
					temp <= not temp;
				end if;
            if wej = '0' and wek = '1' then
					temp <= '0';
				end if;
            if wej = '1' and wek = '0' then
					temp <= '1';
				end if;
            if wej = '0' and wek = '0' then
					temp <= temp;
				end if;
         end if;
      end if;
		wy <= temp;
   end process;
	
end ar_jk;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity d is                    -- przerzutnik D
   port ( 
      we: in std_logic;
      clk: in std_logic;
      res: in std_logic;
		reset_to: in std_logic;
      wy: out std_logic
   );
end d;

architecture ar_d of d is
begin
   process (clk,res)
   begin
      if res='0' then  
         wy <= reset_to;
      else
         if rising_edge(clk) then
            wy <= we;
         end if;
      end if;
   end process;
end ar_d;