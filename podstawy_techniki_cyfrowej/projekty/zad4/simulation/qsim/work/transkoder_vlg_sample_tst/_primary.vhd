library verilog;
use verilog.vl_types.all;
entity transkoder_vlg_sample_tst is
    port(
        sw              : in     vl_logic_vector(0 to 3);
        sampler_tx      : out    vl_logic
    );
end transkoder_vlg_sample_tst;
