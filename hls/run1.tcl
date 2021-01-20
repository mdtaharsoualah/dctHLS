############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project HlsTest1
set_top dct
add_files ../matrix_mult.cpp
add_files ../matrix_mult.h
add_files -tb ../matrix_mult_test.cpp

#set all_image_directives [list ap_ack ap_bus ap_memory ap_none ap_ovld ap_stable ap_vld  bram m_axi s_axilite]

	

set myArray(1) {0 0 0 0}
set myArray(2) {0 0 0 3}
set myArray(3) {0 0 0 4}
set myArray(4) {0 0 0 5}
set myArray(5) {0 0 0 6}

set myArray(6) {0 0 4 3}
set myArray(7) {0 0 5 3}
set myArray(8) {0 0 6 3}
set myArray(9) {0 0 5 4}
set myArray(10) {0 0 6 4}
set myArray(11) {0 0 6 5}
set myArray(12) {0 5 4 3}
set myArray(13) {0 6 4 3}
set myArray(14) {0 6 5 3}
set myArray(15) {0 6 5 4}
set myArray(16) {6 5 4 3}


for {set i 1} {$i < 17} {incr i} {

	open_solution -reset "solPipeline$i"
	set_part {xc7z020clg484-1} -tool vivado
	create_clock -period 10 -name default

	set_directive_resource -latency 2 dct accumulateur
	
	foreach k $myArray($i) {
		if {$k != 0} {
			set_directive_pipeline -enable_flush -rewind "dct/Loop$k"
		}
	}

	csynth_design
	close_solution
}


close_project
quit
