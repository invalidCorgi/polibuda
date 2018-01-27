library verilog;
use verilog.vl_types.all;
entity skracanie_licznikow_vlg_sample_tst is
    port(
        KEY             : in     vl_logic_vector(3 downto 2);
        sampler_tx      : out    vl_logic
    );
end skracanie_licznikow_vlg_sample_tst;
