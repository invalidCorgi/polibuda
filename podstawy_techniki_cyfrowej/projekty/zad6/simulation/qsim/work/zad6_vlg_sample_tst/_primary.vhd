library verilog;
use verilog.vl_types.all;
entity zad6_vlg_sample_tst is
    port(
        clock_27        : in     vl_logic;
        key             : in     vl_logic_vector(1 downto 1);
        sw              : in     vl_logic_vector(0 to 3);
        sampler_tx      : out    vl_logic
    );
end zad6_vlg_sample_tst;
