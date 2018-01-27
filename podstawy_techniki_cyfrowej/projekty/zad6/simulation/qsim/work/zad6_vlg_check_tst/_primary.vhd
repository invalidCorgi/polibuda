library verilog;
use verilog.vl_types.all;
entity zad6_vlg_check_tst is
    port(
        hex0            : in     vl_logic_vector(0 to 6);
        hex1            : in     vl_logic_vector(0 to 6);
        hex2            : in     vl_logic_vector(0 to 6);
        hex3            : in     vl_logic_vector(0 to 6);
        hex4            : in     vl_logic_vector(0 to 6);
        hex5            : in     vl_logic_vector(0 to 6);
        hex6            : in     vl_logic_vector(0 to 6);
        hex7            : in     vl_logic_vector(0 to 6);
        ledg            : in     vl_logic_vector(0 to 1);
        ledr            : in     vl_logic_vector(0 to 9);
        sampler_rx      : in     vl_logic
    );
end zad6_vlg_check_tst;
