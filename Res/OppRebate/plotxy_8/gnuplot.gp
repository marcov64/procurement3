set datafile missing "nan" 
set term x11
set pointsize 0.500000
set xlabel "OpportunisticRebate_1_1"
plot 'data.gp' using 1:2  t "Rebate_1_1(10000)"
pause -1 "(Close graph 8)"
