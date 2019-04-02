#!/usr/bin/gnuplot -p

unset key
set title 'Optical Time Domain Reflection'
set ylabel 'Reflected Intensity Signal (V)'
set xlabel 'Time After Pulse Emission ($\mu$s)'
set xrange [0:6]
set terminal epslatex colour
set output "volt_time.tex"
plot "volt_time.dat" using ($1 * 1e6):2:3 with lines

#set terminal epslatex colour
set key left bottom
set title 'Linear Regression of Rayleigh Scattering'
set ylabel 'Logarithmic Reflected Power (dBV)'
set xlabel 'Distance From Laser Diode (m)'
set xrange [80:500]
set output "dB_dist.tex"
plot "logvolt_dist.dat" using 1:2:3 with yerrorbars title "Relative received power", \
     -1.5690e-04 * x - 1.9651 with lines title "Regression before splice", \
     -1.5023e-04 * x - 1.9938 with lines title "Regression after splice"