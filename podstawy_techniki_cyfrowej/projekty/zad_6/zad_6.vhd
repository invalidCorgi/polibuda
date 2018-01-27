library IEEE;                  -- dolaczenie standardowej biblioteki IEEE
use IEEE.STD_LOGIC_1164.all;

entity zad_6 is                 -- glowny element projektu
   port ( 
      clock_28: in std_logic;
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
		ledr: out std_logic_vector(0 to 10);
		ledg: out std_logic_vector(0 to 0)
   );
end zad_6;

architecture ar_zad_6 of zad_6 is

	signal mjk: std_logic_vector(0 to 2);--wyjście mux do przerzutników jk
   signal s: std_logic_vector(0 to 3);--wyjścia jk
	signal md: std_logic_vector(0 to 3);-- wyjścia mux do przerzutników d
	signal sd: std_logic_vector(0 to 3);--wyjście d
   signal clk: std_logic := '0';
   signal i: integer := 0;
	signal wykonuj: std_logic := '0';--warunkowanie wykonania zadań
	signal zatrzymaj: std_logic := '0';

   component clock
      port(
         we: in std_logic;
			wyk: in std_logic;
         i: inout integer;
         wy: out std_logic
      );
   end component;

   component jk
      port( 
         wej: in std_logic;
			wek: in std_logic;
         clk: in std_logic;
         res: in std_logic;
			res_val: in std_logic;
         wy: out std_logic
      );
   end component;
	
	component d
      port( 
         we: in std_logic;
         clk: in std_logic;
         res: in std_logic;
			res_val: in std_logic;
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
	
--	component fin
--      port( 
--			load: in std_logic;
--         sig: in std_logic_vector(0 to 3);
--         wyk: out std_logic;
--			wye: out std_logic;
--			error: out std_logic
--      );
--   end component;
	

begin
   hex2 <= "1111111";
   hex3 <= "1111111";
   hex4 <= "1111111";
   hex5 <= "1111111";
   hex6 <= "1111111";
   hex7 <= "1111111";
	
	process(key, s)
	begin 
		if(falling_edge(key(1))) then
			if (sw(0) = '1' and sw(1) = '1' and sw(2) = '1' and sw(3) = '1' ) or (sw(0) = '1' and sw(1) = '1' and sw(2) = '0' and sw(3) = '1') or (sw(0) = '0' and sw(1) = '0' and sw(2) = '1') then
				wykonuj <= '0';
				ledg(0) <= '1';
				ledr(0) <= '1';
			else
				wykonuj <= '1';
				ledg(0) <= '0';
				ledr(0) <= '0';
			end if;
		end if;
			if s="1110" then
				wykonuj <= '0';
				ledg(0) <= '1';
			end if;
		
	end process;
	
		i0: clock port map (clock_28, wykonuj, i, clk);
		i1: jk port map ((not s(3) or not s(1)),(s(3) or not s(2)), clk, key(1),sw(0), s(0)); --początek jk
		i2: jk port map (s(0),not s(2), clk, key(1),sw(1), s(1));
		i3: jk port map (mjk(0),(s(3) or s(1)), clk, key(1),sw(2), s(2));
		i4: jk port map (mjk(2),mjk(1), clk, key(1),sw(3), s(3));
		i5: mux port map (not s(3)&"1000000",s(0)&s(1)&s(2),mjk(0));
		i6: mux port map ("11000010",s(0)&s(1)&s(2),mjk(1));
		i7: mux port map ("01100000",s(0)&s(1)&s(2),mjk(2));--koniec jk
		
		i9: d port map (md(0),clk,key(1),'0',sd(0)); --początek d
		i10: d port map (md(1),clk,key(1),'1',sd(1));
		i11: d port map (md(2),clk,key(1),'0',sd(2));
		i12: d port map (md(3),clk,key(1),'0',sd(3));
		i13: mux port map ("0001"&sd(3)&"101",sd(0)&sd(1)&sd(2),md(3));
		i14: mux port map ('1'& not sd(3)&"110"&not sd(3)&"00",sd(0)&sd(1)&sd(2),md(2));
		i15: mux port map ('1'& not sd(3) & "00" & not sd(3) & sd(3) & "10",sd(0)&sd(1)&sd(2),md(1));
		i16: mux port map ("01" & not sd(3) & "01" & not sd(3) & "00",sd(0)&sd(1)&sd(2),md(0)); --koniec d 
		--i17: fin port map (key(1),s(0)&s(1)&s(2)&s(3),wykonuj, ledg(0),ledr(0)); --wykonywanie i zatrzymanie 
		
		dig00:mux port map ('0' & not sd(3) & '0' & sd(3) & not sd(3) & '0' & sd(3) & '0',sd(0)&sd(1)&sd(2),hex0(0));
		dig01:mux port map ("00000" & not sd(3)& not sd(3) & sd(3),sd(0)&sd(1)&sd(2),hex0(1));
		dig02:mux port map ("00" & not sd(3)& '0' & sd(3) & "000",sd(0)&sd(1)&sd(2),hex0(2));
		dig03:mux port map ('0' & not sd(3) & '0' & sd(3) & not sd(3) & '0' & sd(3) & not sd(3),sd(0)&sd(1)&sd(2),hex0(3));
		dig04:mux port map ("0101" & not sd(3) & '1' & sd(3) & '1' ,sd(0)&sd(1)&sd(2),hex0(4));
		dig05:mux port map ('0' & not sd(3) & not sd(3) & '1' & sd(3) & sd(3) & '0' & not sd(3) ,sd(0)&sd(1)&sd(2),hex0(5));
		dig06:mux port map (not sd(3) & not sd(3) & sd(3) & sd(3) & "000" & not sd(3) ,sd(0)&sd(1)&sd(2),hex0(6));
		hex1(0) <= '1';
		dig11:mux port map ("11" & not sd(3) & not sd(3) & not sd(3) & not sd(3) & not sd(3) & not sd(3),sd(0)&sd(1)&sd(2),hex1(1));
		dig12:mux port map ("11" & not sd(3) & not sd(3) & not sd(3) & not sd(3) & not sd(3) & not sd(3),sd(0)&sd(1)&sd(2),hex1(2));
		hex1(3) <= '1';
		hex1(4) <= '1';
		hex1(5) <= '1';
		hex1(6) <= '1';
		ledr(1) <= s(0);
		ledr(2) <= s(1);
		ledr(3) <= s(2);
		ledr(4) <= s(3);
		ledr(5) <= sd(0);
		ledr(6) <= sd(1);
		ledr(7) <= sd(2);
		ledr(8) <= sd(3);
		ledr(9) <= clk;
		ledr(10) <= wykonuj;
	 
end ar_zad_6;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity clock is                -- zmniejszenie czestotliwosci zegara systemowego
   port ( 
      we: in std_logic;
		wyk: in std_logic;
      i: inout integer;
      wy: out std_logic
   );
end clock;

architecture ar_zad_5 of clock is
begin
   process (we)
   begin
		if wyk = '0' then 
			wy <= '0'; 
		else
		wy <= we;
--			if rising_edge(we) then 
--				i <= i+1;
--				if i = 14000000 then
--					wy <= '1';
--				end if; 
--				if i = 28000000 then
--					i <= 0;
--					wy <= '0';
--				end if;
--			end if;
		end if;
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
		res_val: in std_logic;
      wy: out std_logic
   );
end jk;

architecture ar_jk of jk is

signal temp: std_logic;

begin
   process (clk,res)
   begin
      if res='0' then 
         temp <= res_val;
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
		res_val: in std_logic;
      wy: out std_logic
   );
end d;

architecture ar_d of d is
begin
   process (clk,res)
   begin
      if res='0' then 
         wy <= res_val;
      else
         if rising_edge(clk) then
            wy <= we;
         end if;
      end if;
   end process;
end ar_d;

--library IEEE;                  
--use IEEE.STD_LOGIC_1164.all; 
--entity fin is                   
--   port ( 
--			load: in std_logic;
--         sig: in std_logic_vector(0 to 3);
--         wyk: out std_logic;
--			wye: out std_logic;
--			error: out std_logic
--   );
--end fin;
--
--architecture ar_fin of fin is
--begin 
--	process(load, sig)
--	begin 
--		if(falling_edge(load)) then
--			if (sig(0) = '1' and sig(1) = '1' and sig(2) = '1' and sig(3) = '1' ) or (sig(0) = '1' and sig(1) = '1' and sig(2) = '0' and sig(3) = '1') or (sig(0) = '0' and sig(1) = '0' and sig(2) = '1') then
--				wyk <= '0';
--				wye <= '1';
--				error <= '1';
--			else
--				wyk <= '1';
--				wye <= '0';
--				error <= '0';
--			end if;
--			if (sig(0) = '1' and sig(1) = '1' and sig(2) = '1' and sig(3) = '0') then
--				wyk <= '0';
--				wye <= '1';
--			end if;
--		end if;
--	end process;
--end ar_fin;