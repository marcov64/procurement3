set datafile missing "nan" 
set term x11
set pointsize 0.500000
set xlabel "Win_3_1"
plot 'data.gp' using 1:2  t "Trust_3_1(10000)"
pause -1 "(Close graph 3)"
