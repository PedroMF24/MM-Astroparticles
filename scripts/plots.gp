reset
set tics front

id = 15

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

set key font ",10" 

if (id == 3) {
    set output "out/test.png"   
    set yrange [0:10]
    set xrange [0:2000]
    set ylabel "XMax [X_{0}]"
    set xlabel "N_{/Symbol m}"
    plot "data/test.dat" u 5:4 with points pt 1 ps 1.5 lw 0.6 title "Correlation Plot"
}

if (id == 4) {
    set output "out/energy_test.png"   
    set xlabel "Energy [GeV]"
    set ylabel "XMax"
    plot "data/test.dat" u 1:3 with points pt 1 ps 1.5 lw 0.6 title "Energy"
}

if (id == 5) {
    set output "out/lnE0_XMax.png"   
    set xlabel "ln(E_{0}) [GeV]"
    set ylabel "XMax [X_{0}]"
    plot "data/MClnE0_XMax.dat" u 1:2 with points pt 6 ps 1.5 lw 0.6 lc "blue" title "Energy"
}

if (id == 6) {
    set output "out/ln(N_mu)_lnE0.png"   
    set xlabel "ln(E_{0}) [GeV]"
    set ylabel "ln(N_{/Symbol m})"
    plot "data/test.dat" u 2:6 with points pt 1 ps 1.5 lw 0.6 title "Energy"
}

if (id == 7) {
    set output "out/XMax_Nmu.png"   
    set xlabel "N_{/Symbol m}"
    set ylabel "XMax [X0]"
    plot "data/XMax_Nmu.dat" u 1:2 with points pt 6 ps 1.5 lw 0.6 title "Energy"
}

if (id == 8) {
    set output "out/MClnE0_XMax_iron_proton.png"   
    set xlabel "ln(E_{0}) [GeV]"
    set xrange [6:15]
    set yrange [0:10]
    set ylabel "XMax [X_{0}]"
    set key outside # This places the legend outside the plot area
    plot "data/MC_data/MClnE0_XMax.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "red" title "Proton", \
        "data/MC_data/MClnE0_XMax.csv" u 3:4 with points pt 2 ps 1.2 lw 0.6 lc "blue" title "Iron" 
}

if (id == 9) {
    set output "out/MCN_mu_XMax_iron_proton.png"   
    set xlabel "N_{/Symbol m}"
    set logscale xy
    set xrange [3:3000]
    set yrange [1:10]
    set ylabel "XMax [X_{0}]"
    set key outside # This places the legend outside the plot area
    plot "data/MC_data/MCN_mu_XMax_proton.csv" u 2:1 with points pt 6 ps 1.2 lw 0.6 lc "red" title "Proton", \
        "data/MC_data/MCN_mu_XMax_iron.csv" u 2:1 with points pt 6 ps 1.2 lw 0.6 lc "blue" title "Iron" 
}

if (id == 10) {
    set output "out/MC_Uni_ln(E0)_XMax_proton.png"   
    set xlabel "ln(E_{0}) [GeV]"
    # set logscale xy
    set xrange [6:15]
    set yrange [0:11]
    set ylabel "XMax [X_{0}]"
    set key outside # This places the legend outside the plot area
    plot "data/MC_data/MCEDist/MC_Gauss_ln(E0)_XMax_proton.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "red" title "Gauss", \
        "data/MC_data/MCEDist/MC_Uni_ln(E0)_XMax_proton.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "green" title "Uni" , \
        "data/MC_data/MCEDist/MC_Even_ln(E0)_XMax_proton.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "blue" title "Even" 
}


if (id == 11) {
    set output "out/EFixed_N_mu_XMax_proton.png"   
    set xlabel "N_{/Symbol m}"
    # set logscale xy
    # set xrange [0:90]
    # set yrange [0:8]
    set ylabel "XMax [X_{0}]"
    set key outside # This places the legend outside the plot area
    plot "data/EFixed/EFixed_Gauss_XMax_N_mu_proton.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "red" title "Gauss", \
        "data/EFixed/EFixed_Uni_XMax_N_mu_proton.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "green" title "Uni" , \
        "data/EFixed/EFixed_Even_XMax_N_mu_proton.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "blue" title "Even" 
}

if (id == 12) {
    set output "out/EProfile_N_mu_XMax_proton.png"   
    set ylabel "N_{/Symbol m}"
    # set logscale xy
    set xrange [0:6]
    # set yrange [0:8]
    set xlabel "XMax [X_{0}]"
    set key outside # This places the legend outside the plot area
    plot "data/EProfile/Gauss_XMax_N_mu.csv" u 1:2 with points pt 6 ps 1.2 lw 0.6 lc "red" title "Gauss", \
        "data/EProfile/Uni_XMax_N_mu.csv" u 1:2 with points pt 1 ps 1.2 lw 1 lc "blue" title "Uni" , \
        "data/EProfile/Even_XMax_N_mu.csv" u 1:2 with points pt 2 ps 1.2 lw 0.6 lc "green" title "Even" 
}

if (id == 13) {
    set output "out/Continuous_lnE0_XMax.png"   
    set xlabel "ln(E_{0}) [GeV]"
    set ylabel "XMax [X_{0}]"
    plot "data/Continuous_lnE0_XMax.csv" u 1:2 with points pt 6 ps 1.5 lw 0.6 lc "blue" title "Energy"
}

if (id == 14) {
    set output "out/swapped_logEFixed_3proton_XMax_N_mu.png"  
    set key font ",10" 
    set xlabel "N_{/Symbol m}"
    # set xlabel "lnE_{0} [GeV]"
    set logscale x
    set yrange [0:8]
    set xrange [1:200]
    set ylabel "XMax [X_{0}]"
    set key outside # This places the legend outside the plot area
    plot "data/EFixed_Gauss_Xmax_N_mu_proton.csv" u 2:1 with points pt 6 ps 1.5 lw 1 lc "red" title "Gauss", \
        "data/EFixed_Uni_Xmax_N_mu_proton.csv" u 2:1 with points pt 1 ps 1.5 lw 1 lc "green" title "Uni" , \
        "data/EFixed_Even_Xmax_N_mu_proton.csv" u 2:1 with points pt 2 ps 1.5 lw 1 lc "blue" title "Even" 
}


if (id == 15) {
    set output "out/2nd_Test_Continuum_N_mu_XMax_iron_proton.png"   
    set xlabel "N_{/Symbol m}"
    set logscale x
    set xrange [5:1500]
    set yrange [2:18]
    # set xrange [10:1000]
    # set yrange [1:20]
    set ylabel "XMax [X_{0}]"
    set key outside # This places the legend outside the plot area
    plot "data/Continuum_N_mu_XMax_proton.dat" u 2:1 with points pt 6 ps 1.2 lw 0.6 lc "red" title "Proton", \
        "data/Continuum_N_mu_XMax_iron.dat" u 2:1 with points pt 6 ps 1.2 lw 0.6 lc "blue" title "Iron" 
}


if (id == 17) {
# Set the title and labels
set title "Histogram of Gaussian Distribution"
set xlabel "Value"  
set ylabel "Frequency"

# Set the output format (e.g., saving the plot as an image)
set terminal png
set output "out/histogram.png"

# Configure histogram settings
set style data histograms
set style fill solid 1.0 border -1

# Set the bin width and range
bin_width = 0.5
bin(x,width) = width * floor(x/width) + width/2.0

# Plot histogram
plot 'data/test.dat' using (bin($2,bin_width)):(1.0) smooth freq with boxes title 'Gaussian Data'

# Uncomment the following lines to display the plot in a window
# set terminal qt
# replot
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

