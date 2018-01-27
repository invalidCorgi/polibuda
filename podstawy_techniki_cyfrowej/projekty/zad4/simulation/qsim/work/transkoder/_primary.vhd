library verilog;
use verilog.vl_types.all;
entity transkoder is
    port(
        sw              : in     vl_logic_vector(0 to 3);
        ledr            : out    vl_logic_vector(0 to 4)
    );
end transkoder;
