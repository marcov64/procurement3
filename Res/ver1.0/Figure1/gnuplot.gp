set datafile missing "nan" 
set term x11
set pointsize 1.000000
set xlabel "FinalBill_1_1"
plot 'data.gp' using 1:2  t "Win_1_1(5000)"
pause -1 "(Close graph 1)"
