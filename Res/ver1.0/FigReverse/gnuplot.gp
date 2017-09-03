set datafile missing "nan" 
set term x11
set pointsize 1.000000
set yrange [0.377065:0.477317]
set xlabel "AvSelPressure_1"
set ticslevel 0.0
plot 'data.gp' using 1:2  t "AvSSkill(1)"
pause -1 "Close graph 4)"
