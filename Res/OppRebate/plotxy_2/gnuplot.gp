set datafile missing "nan" 
set term x11
set pointsize 1.000000
set xlabel "OpportunisticRebate_1_1"
plot 'data.gp' using 1:2  t "Win_1_1(0)", 'data.gp' using 1:3  t "Win_3_1(0)"
pause -1 "(Close graph 2)"
