library IEEE;                  -- dolaczenie standardowej biblioteki IEEE
use IEEE.STD_LOGIC_1164.all;

entity zad5dudi is                 -- glowny element projektu
   port ( 
      clock_27: in std_logic;
      key: in std_logic_vector(1 to 1);
      ledg: out std_logic_vector(0 to 1);
      hex0: out std_logic_vector(0 to 6);
      hex1: out std_logic_vector(0 to 6);
      hex2: out std_logic_vector(0 to 6);
      hex3: out std_logic_vector(0 to 6);
      hex4: out std_logic_vector(0 to 6);
      hex5: out std_logic_vector(0 to 6);
      hex6: out std_logic_vector(0 to 6);
      hex7: out std_logic_vector(0 to 6);
		ledr: out std_logic_vector(0 to 3)
   );
end zad5dudi;

architecture ar_zad_5 of zad5dudi is

   signal s: std_logic_vector(0 to 3);
   signal clk: std_logic := '0';
   signal i: integer := 0;

   component clock
      port(
         we: in std_logic;
         i: inout integer;
         wy: out std_logic
      );
   end component;

   component digit
      port( 
         we: in std_logic_vector(0 to 3);
         wy: out std_logic_vector(0 to 6)
      );
   end component;

   component jk
      port( 
         wej: in std_logic;
			wek: in std_logic;
         clk: in std_logic;
         res: in std_logic;
         wy: out std_logic
      );
   end component;

begin
   hex1 <= "1111111";
   hex2 <= "1111111";
   hex3 <= "1111111";
   hex4 <= "1111111";
   hex5 <= "1111111";
   hex6 <= "1111111";
   hex7 <= "1111111";
   ledg(0) <= clk;
   ledg(1) <= key(1);
   i0: clock port map (clock_27, i, clk);
   i1: jk port map (not s(0),s(0), clk, not key(1) or (not s(0) and s(1) and s(2) and s(3)), s(0));
   i2: jk port map (not s(1),s(1), not s(0), not key(1) or (not s(0) and s(1) and s(2) and s(3)), s(1));
	i3: jk port map (not s(2),s(2), not s(1), not key(1) or (not s(0) and s(1) and s(2) and s(3)), s(2));
	i4: jk port map (not s(3),s(3), not s(2), not key(1) or (not s(0) and s(1) and s(2) and s(3)), s(3));
   i5: digit port map (s, hex0);
	ledr(0) <= s(0);
	ledr(1) <= s(1);
	ledr(2) <= s(2);
	ledr(3) <= s(3);
end ar_zad_5;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity clock is                -- zmniejszenie czestotliwosci zegara systemowego
   port ( 
      we: in std_logic;
      i: inout integer;
      wy: out std_logic
   );
end clock;

architecture ar_zad_5 of clock is
begin
   process (we)
   begin
	wy <= we;
--      if rising_edge(we) then 
--         i <= i+1;
--         if i = 13500000 then
--            wy <= '1';
--         end if; 
--         if i = 27000000 then
--            i <= 0;
--            wy <= '0';
--         end if;
--      end if;
   end process;
end ar_zad_5;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity digit is                -- translacja wektora binarnego na cyfre dziesietna
   port ( 
      we: in std_logic_vector(0 to 3);
      wy: out std_logic_vector(0 to 6)
   );
end digit;

architecture ar_di of digit is
begin
   wy(0) <= ((not we(3) and not we(2) and not we(1) and we(0)) or (not we(3) and we(2) and not we(1) and not we(0)) or (we(3) and we(2) and not we(1) and we(0)) or (we(3) and not we(2) and we(1) and we(0)));
   wy(1) <= ((not we(3) and we(2) and not we(1) and we(0)) or (we(2) and we(1) and not we(0)) or (we(2) and we(1) and not we(0)) or (we(3) and we(1) and we(0)));
   wy(2) <= ((not we(3) and not we(2) and we(1) and not we(0)) or (we(3) and we(2) and not we(0)) or (we(3) and we(2) and we(1)));
   wy(3) <= ((not we(3) and not we(2) and not we(1) and we(0))or (not we(3) and we(2) and not we(1) and not we(0)) or (we(2) and we(1) and we(0)) or (we(3) and not we(2) and we(1) and not we(0)));
   wy(4) <= ((we(3) and we(2) and not we(1) and we(0)) or (not we(3) and we(2) and not we(1)) or (not we(3) and we(0)));
   wy(5) <= ((not we(3) and we(1) and we(0)) or (not we(3) and not we(2) and we(0)) or (not we(3) and not we(2) and we(1)) or (we(3) and we(2) and not we(1) and we(0)));
   wy(6) <= ((not we(3) and not we(2) and not we(1)) or (not we(3) and we(2) and we(1) and we(0)) or (not we(3) and we(2) and we(1) and we(0)));
end ar_di;

library IEEE;                  
use IEEE.STD_LOGIC_1164.all; 
entity jk is                    -- przerzutnik JK
   port ( 
      wej: in std_logic;
		wek: in std_logic;
      clk: in std_logic;
      res: in std_logic;
      wy: out std_logic
   );
end jk;

architecture ar_jk of jk is

signal temp: std_logic := '0';

begin
   process (clk,res)
   begin
      if res='1' then 
         temp <= '0';
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