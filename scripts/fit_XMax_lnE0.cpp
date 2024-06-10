#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"

using namespace std;

void MakeFit(string filename, string name, int columnX, int columnY, TF1* fitFunc) {
    // Define vectors to store data
    vector<double> xData, yData;

    // Read data from file
    ifstream file("data/" + filename);
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
            // Use this for continuum XMax N_mu
            // xData.push_back(log(y));
            // yData.push_back(x);
        }
    }
    file.close();

    // Create TGraph object
    TGraph *graph = new TGraph(xData.size(), &xData[0], &yData[0]);
    // graph->SetTitle(Form("Data and Fit Plot (Column %d vs Column %d)", columnY, columnX));
    // graph->GetXaxis()->SetTitle(Form("Column %d", columnX));
    // graph->GetYaxis()->SetTitle(Form("Column %d", columnY));

    graph->SetTitle("");
    graph->GetXaxis()->SetTitle("ln(E_{0}) [GeV]"); // 
    graph->GetYaxis()->SetTitle("XMax [X_{0}]"); // XMax [X0]
    // graph->GetYaxis()->SetTitle("ln(N_{#mu})"); // XMax [X0]
    graph->GetXaxis()->CenterTitle();
    graph->GetYaxis()->CenterTitle();

    // 2: vermelho
    // 3: Verde
    // 4: 
    fitFunc->SetLineColor(4);

    // Fit function to the data
    graph->Fit(fitFunc);

    // Create canvas
    TCanvas *canvas = new TCanvas("canvas", "Data and Fit Plot", 800, 600);
    graph->SetMarkerStyle(20);
    graph->Draw("AP");

    // Show canvas
    canvas->Draw();
    string save_to = "out/" + name + ".png";
    canvas->SaveAs(save_to.c_str());
}

// This is the main funct   ion of the script
void fit_XMax_lnE0() {

    // Input file name and columns to plot
    // const char* filename = "../data/proton_lnE0_XMax.csv"; // Change this to your data file
    string name = "TEST_Even_XMax_lnE0_proton";

    string filename = name + ".dat";

    int columnX = 2; // Change this to the desired X column
    int columnY = 6; // Change this to the desired Y column
    
    // Create a fitting function (change "pol2" to the desired fit function)
    TF1 *fitFunc = new TF1("fitFunc", "pol1");

    // Fit and plot data
    MakeFit(filename, name, columnX, columnY, fitFunc);
}

