!/usr/bin/gnuplot -persist

f(x)= (exp(-((1/x) - 1)**2)* ((1-x)**2))/x**4

plot f(x) title "gBar= ((1-t)^2 * exp(-((1/t)-1)^2)) / t^4" w l


#  TITLES
set title "phys3071 as09 melsom 42593249"
set xlabel "t"
set ylabel "gBar"

# AXES SETTINGS
set yrange [0:2]
set xrange [0:1]
#set size square
#set xtics ('-2pi' -2*pi, '-pi' -pi, 0, 'pi' pi, '2pi' 2*pi) 
#set ytics 1
#set tics scale 0.75

# LEGEND
#set key default
#set key top left
#set key outside
#set key top left

# FILE OUTPUT
set term postscript color
set output "as09-plot-melsom-42593249.ps"
replot
