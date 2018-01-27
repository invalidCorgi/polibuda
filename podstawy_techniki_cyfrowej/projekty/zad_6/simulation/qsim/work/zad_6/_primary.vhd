library verilog;
use verilog.vl_types.all;
entity zad_6 is
    port(
        clock_28        : in     vl_logic;
        key             : in     vl_logic_vector(1 downto 1);
        sw              : in     vl_logic_vector(0 to 3);
        hex0            : out    vl_logic_vector(0 to 6);
        hex1            : out    vl_logic_vector(0 to 6);
        hex2            : out    vl_logic_vector(0 to 6);
        hex3            : out    vl_logic_vector(0 to 6);
        hex4            : out    vl_logic_vector(0 to 6);
        hex5            : out    vl_logic_vector(0 to 6);
        hex6            : out    vl_logic_vector(0 to 6);
        hex7            : out    vl_logic_vector(0 to 6);
        ledr            : out    vl_logic_vector(0 to 9);
        ledg            : out    vl_logic_vector(0 downto 0)
    );
end zad_6;
