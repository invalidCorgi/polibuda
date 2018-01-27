library verilog;
use verilog.vl_types.all;
entity zad5dudi_vlg_sample_tst is
    port(
        clock_27        : in     vl_logic;
        key             : in     vl_logic_vector(1 downto 1);
        sampler_tx      : out    vl_logic
    );
end zad5dudi_vlg_sample_tst;
