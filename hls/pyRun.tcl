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

set name [lindex $argv 2]
open_solution -reset $name
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default

source "./directives.tcl"

csynth_design
export_design -format ip_catalog
close_solution

close_project
quit
