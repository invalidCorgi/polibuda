onerror {quit -f}
vlib work
vlog -work work jk.vo
vlog -work work jk.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.jk_vlg_vec_tst
vcd file -direction jk.msim.vcd
vcd add -internal jk_vlg_vec_tst/*
vcd add -internal jk_vlg_vec_tst/i1/*
add wave /*
run -all
