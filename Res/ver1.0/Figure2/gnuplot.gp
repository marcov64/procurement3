set datafile missing "nan" 
set term x11
set pointsize 1.000000
set xlabel "Skill_1_1"
plot 'data.gp' using 1:2  t "Trust_1_1(5000)"
pause -1 "(Close graph 1)"
