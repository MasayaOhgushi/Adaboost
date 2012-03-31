#!/bin/sh
#

gnuplot <<EOF
set out "sin.jpg"
set term post land
set xr [0:10]
set title "TITLE"
plot sin(x) 
EOF
