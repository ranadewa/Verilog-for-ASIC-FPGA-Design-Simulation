############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project finite_impulse_response_filter
set_top fir_loop_pipelining
add_files fir_top.h
add_files fir_top.cpp
add_files -tb main.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "3_ns_clock_not_optimised" -flow_target vivado
set_part {xcvu5p-flva2104-1-e}
create_clock -period 3.125 -name default
#source "./finite_impulse_response_filter/3_ns_clock_not_optimised/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
