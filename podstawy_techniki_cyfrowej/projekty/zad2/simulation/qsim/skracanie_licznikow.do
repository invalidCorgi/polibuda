onerror {quit -f}
vlib work
vlog -work work skracanie_licznikow.vo
vlog -work work skracanie_licznikow.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.skracanie_licznikow_vlg_vec_tst
vcd file -direction skracanie_licznikow.msim.vcd
vcd add -internal skracanie_licznikow_vlg_vec_tst/*
vcd add -internal skracanie_licznikow_vlg_vec_tst/i1/*
add wave /*
run -all
