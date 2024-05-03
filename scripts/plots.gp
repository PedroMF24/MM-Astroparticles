reset
set tics front

id = 3

# set size 0.8,0.5
# set style fill transparent solid 0.5
# set terminal pngcairo dashed enhanced font "arial,20" lw 2 crop  size 900,1200
 set terminal pngcairo enhanced font "Arial,12"

set grid
set key right top
set key font ",8"
set mxtics 5
set mytics 10

set pointsize 0.15        
set style line 1 lt 1 lc 1 lw 2 pt 7 ps 0.20
set style line 111 lt 1 lc 1 lw 2 pt 7 ps 1
set style line 112 lt 1 lc 2 lw 2 pt 7 ps 1
set style line 116 lt 1 lc rgbcolor "black" lw 2 pt 7 ps 1
set style line 2 lt 1 lc 2 lw 2 pt 7 ps 0.25
set style line 22 lt 2 lc 2 lw 1 pt 7 ps 0.30
set style line 3 lt 1 lc 3 lw 2 pt 7 ps 0.20
set style line 33 lt 2 lc 3 lw 0.5 pt 7 ps 0.25
set style line 333 lt 1 lc 3 lw 2 pt 2 ps 2
set style line 4 lt 1 lc 4 lw 2 pt 7 ps 0.20
set style line 5 lt 2 lc 5 lw 2 pt 2 ps 0.50
set style line 6 lt 1 lc rgbcolor "black" lw 2 pt 7 ps 0.20
set style line 7 lt 2 lc rgbcolor "orange" lw 2 pt 7 ps 0.15
set style line 8 lt 2 lc 7 lw 2 pt 2 ps 0.15
set style line 9 lt 5 lc 7 lw 2 pt 2 ps 0.15
set style line 10 lt 1 lc 0 lw 2 pt 7 ps 0.15
set style line 41 lt 1 lc rgbcolor "#FFA07A" lw 2 pt 7 ps 0.2  #salmon
set style line 42 lt 1 lc rgbcolor "#FF0000" lw 2 pt 7 ps 0.2  #red
set style line 43 lt 1 lc rgbcolor "#8B0000" lw 2 pt 7 ps 0.2  #darkred

set key at graph 1.25, 1
# set key font ",15"

# set terminal pngcairo enhanced font "Arial,12"
# set output "TEST-Omegas-2.png"
# set logscale xy 10
# set xrange [0.00001:10]
# set yrange [0.00001:10]
# set format x "10^{%T}"
# set format y "10^{%T}"
# set xlabel "$\\Omega_1$"
# set ylabel "$\\Omega_2$"
# set pointsize 2
# plot NaN title "0.09<$\\Omega$<0.15", "output-mO.dat" using 16:17 with points ls 4 notitle

#    set xrange [64:80]
#    set yrange [60:200]

    # set xtics 2
    # set ytics 20
    # set mxtics 2
    # set mytics 2

if (id == 3) {
    set output "out/test.png"   
    set ylabel "XMax"
    set xlabel "N_{/Symbol m}"
    plot "data/test.dat" u 2:1 with points pt 1 ps 1.5 lw 0.6 title "Correlation Plot"
}



if (id == 1) {
    set output "TEST-Masses.png"
    set xrange [64:80]
    set yrange [60:200]
    set xtics 2
    set ytics 20
    set mxtics 2
    set mytics 2
    set xlabel "m_{1} (GeV)"
    set ylabel "masses (GeV)"
    plot "MyOutput-mO.dat" u 2:4 with points pt 1 ps 1.5 lw 0.6 title "mA_{1}", \
        "MyOutput-mO.dat" u 2:5 with points pt 2 ps 1.5 lw 0.6 title "mA_{2}", \
        "MyOutput-mO.dat" u 2:6 with points pt 3 ps 1.5 lw 0.6 title "mC_{1}", \
        "MyOutput-mO.dat" u 2:7 with points pt 4 ps 1.5 lw 0.6 title "mC_{2}"
}

data_file = "Omega-OK.dat" 
column_2 = 3
column_3 = 4
column_17 = 16
column_18 = 17
color_code(col16, col17) = col16 / (col16 + col17)

if (id == 2) {
    set key at graph 1, 1
    set output "ScatterPlot.png"
    set xrange [200:600]
    set yrange [0:800]
    set xlabel "m_{2} [GeV]"
    set ylabel "m_{3} [GeV]"
    set title "Scatter Plot {/Symbol W_1}/({/Symbol W_1}+{/Symbol W_2})" # {/Symbol W}_1/({/Symbol W_1}+{/Symbol W_2})"
    plot data_file using column_2:column_3:(color_code(column(column_17), column(column_18))) with points pt 7 ps 1.2 palette notitle
}

# 

# {/Symbol W_1}/({/Symbol W_1}+{/Symbol W_2})

# {/Symbol W_1}/({/Symbol W_1}+{/Symbol W_2})

