library verilog;
use verilog.vl_types.all;
entity zad_6_vlg_sample_tst is
    port(
        clock_28        : in     vl_logic;
        key             : in     vl_logic_vector(1 downto 1);
        sw              : in     vl_logic_vector(0 to 3);
        sampler_tx      : out    vl_logic
    );
end zad_6_vlg_sample_tst;
