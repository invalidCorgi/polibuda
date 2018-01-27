onerror {quit -f}
vlib work
vlog -work work 74192mod27.vo
vlog -work work 74192mod27.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.74192mod27_vlg_vec_tst
vcd file -direction 74192mod27.msim.vcd
vcd add -internal 74192mod27_vlg_vec_tst/*
vcd add -internal 74192mod27_vlg_vec_tst/i1/*
add wave /*
run -all
