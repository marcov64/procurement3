set datafile missing "nan" 
set term x11
set pointsize 1.000000
set xlabel "Skill_3_1"
plot 'data.gp' using 1:2  t "Win_3_1(10000)"
pause -1 "(Close graph 1)"
