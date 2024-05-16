#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"

using namespace std;

void MakeFit(const char* filename, int columnX, int columnY, TF1* fitFunc) {
    // Define vectors to store data
    vector<double> xData, yData;

    // Read data from file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        double x, y;
        // Parse line
        if (sscanf(line.c_str(), "%lf %lf", &x, &y) == 2) {
            xData.push_back(x);
            yData.push_back(y);
        }
    }
    file.close();

    // Create TGraph object
    TGraph *graph = new TGraph(xData.size(), &xData[0], &yData[0]);
    // graph->SetTitle(Form("Data and Fit Plot (Column %d vs Column %d)", columnY, columnX));
    // graph->GetXaxis()->SetTitle(Form("Column %d", columnX));
    // graph->GetYaxis()->SetTitle(Form("Column %d", columnY));

    graph->SetTitle("");
    graph->GetXaxis()->SetTitle("N_{#mu}");
    graph->GetYaxis()->SetTitle("XMax [X0]");
    graph->GetXaxis()->CenterTitle();
    graph->GetYaxis()->CenterTitle();

    // Fit function to the data
    graph->Fit(fitFunc);

    // Create canvas
    TCanvas *canvas = new TCanvas("canvas", "Data and Fit Plot", 800, 600);
    graph->SetMarkerStyle(20);
    graph->Draw("AP");

    // Show canvas
    canvas->Draw();
    canvas->SaveAs("../out/fit.png");
}

// This is the main function of the script
void fit() {

    // Input file name and columns to plot
    const char* filename = "../data/shower_proton2.dat"; // Change this to your data file
    int columnX = 1; // Change this to the desired X column
    int columnY = 2; // Change this to the desired Y column
    
    // Create a fitting function (change "pol2" to the desired fit function)
    TF1 *fitFunc = new TF1("fitFunc", "[0]+[1]*log(x)");

    // Fit and plot data
    MakeFit(filename, columnX, columnY, fitFunc);
}

