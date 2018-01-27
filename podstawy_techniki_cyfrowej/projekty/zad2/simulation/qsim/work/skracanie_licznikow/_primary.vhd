library verilog;
use verilog.vl_types.all;
entity skracanie_licznikow is
    port(
        LEDR            : out    vl_logic_vector(4 downto 0);
        KEY             : in     vl_logic_vector(3 downto 2)
    );
end skracanie_licznikow;
