library verilog;
use verilog.vl_types.all;
entity zad5dudi is
    port(
        clock_27        : in     vl_logic;
        key             : in     vl_logic_vector(1 downto 1);
        ledg            : out    vl_logic_vector(0 to 1);
        hex0            : out    vl_logic_vector(0 to 6);
        hex1            : out    vl_logic_vector(0 to 6);
        hex2            : out    vl_logic_vector(0 to 6);
        hex3            : out    vl_logic_vector(0 to 6);
        hex4            : out    vl_logic_vector(0 to 6);
        hex5            : out    vl_logic_vector(0 to 6);
        hex6            : out    vl_logic_vector(0 to 6);
        hex7            : out    vl_logic_vector(0 to 6);
        ledr            : out    vl_logic_vector(0 to 3)
    );
end zad5dudi;
