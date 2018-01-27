onerror {quit -f}
vlib work
vlog -work work VHDL_reklama.vo
vlog -work work VHDL_reklama.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.VHDL_reklama_vlg_vec_tst
vcd file -direction VHDL_reklama.msim.vcd
vcd add -internal VHDL_reklama_vlg_vec_tst/*
vcd add -internal VHDL_reklama_vlg_vec_tst/i1/*
add wave /*
run -all
