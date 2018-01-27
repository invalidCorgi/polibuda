library verilog;
use verilog.vl_types.all;
entity skracanie_licznikow_vlg_check_tst is
    port(
        LEDR            : in     vl_logic_vector(4 downto 0);
        sampler_rx      : in     vl_logic
    );
end skracanie_licznikow_vlg_check_tst;
