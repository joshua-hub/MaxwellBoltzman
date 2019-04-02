!/usr/bin/gnuplot -persist

 
f(x)= (exp(-((1/x) - 1)**2)* ((1-x)**2))/x**4
 
set style line 1 lc rgb '#0060ad' linetype 1 linewidth 1
set style line 2 lc 'blue' pt 7   # circle
set style line 3 lc 'black' linetype 1 linewidth 1

#plot f(x) title "exp(-((1/t) - 1)^2)* ((1-t)^2))/t^4" w l linestyle 1
plot f(x) title "$\\displaystyle{ \\frac{ (1-t)^2 e^{-( \\frac{1}{t} - 1)^2} }{t^4}}$" w l linestyle 1


#  TITLES
set title "phys3071 as09 melsom 42593249"
set xlabel "t"
set ylabel "f(t)"

# AXES SETTINGS
set size square
set xrange[0:1]
set yrange[0:2]
set xlabel '$t$'
set ylabel '$\bar{g}(t)$'

# LEGEND
#set key bottom right

# FILE OUTPUT
set term epslatex color
set output "as09-plot-melsom-42593249.tex"
replot
