set datafile missing "nan" 
set term x11
set pointsize 1.000000
set xlabel "Skill_2_1"
plot 'data.gp' using 1:2  t "Win_1_1(10000)", 'data.gp' using 1:3  t "Win_2_1(10000)"
pause -1 "(Close graph 1)"
