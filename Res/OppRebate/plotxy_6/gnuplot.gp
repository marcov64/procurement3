set datafile missing "nan" 
set term x11
set pointsize 0.500000
set xlabel "OpportunisticRebate_3_1"
plot 'data.gp' using 1:2  t "Trust_3_1(10000)", 'data.gp' using 1:3  t "Trust_1_1(10000)"
pause -1 "(Close graph 6)"
