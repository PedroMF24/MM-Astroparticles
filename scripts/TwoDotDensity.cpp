#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "TH2F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"

using namespace std;

void ReadData(const string& filename, vector<double>& xData, vector<double>& yData) {
    ifstream file("data/" + filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        double x, y;
        if (sscanf(line.c_str(), "%lf %lf", &x, &y) == 2) {
            xData.push_back(x);
            yData.push_back(y);
        }
    }
    file.close();
}

void MakeHist(const string& name) {

    // Define vectors to store data
    vector<double> xData1, yData1;
    vector<double> xData2, yData2;

    // Read data from files
    ReadData("Continuum_N_mu_XMax_proton.dat", yData1, xData1);
    ReadData("Continuum_N_mu_XMax_iron.dat", yData2, xData2);

    if (xData1.empty() || yData1.empty() || xData2.empty() || yData2.empty()) {
        cerr << "Error: No data read from files" << endl;
        return;
    }

    // Combine data
    vector<double> xData(xData1);
    xData.insert(xData.end(), xData2.begin(), xData2.end());
    vector<double> yData(yData1);
    yData.insert(yData.end(), yData2.begin(), yData2.end());

    // Determine the range for the histogram
    double xmin = *min_element(xData.begin(), xData.end());
    double xmax = *max_element(xData.begin(), xData.end());
    double ymin = *min_element(yData.begin(), yData.end());
    double ymax = *max_element(yData.begin(), yData.end());

    // double xmin = 20;
    // double xmax = 600;
    // double ymin = 1.5;
    // double ymax = 12;

    cout << "X range: " << xmin << " to " << xmax << endl;
    cout << "Y range: " << ymin << " to " << ymax << endl;

    // Define number of bins
    int nbinsx = 100;
    int nbinsy = 100;

    TH2F *hist = new TH2F("hist", ";N_{#mu}; XMax [X_{0}]; #rho", 
                            nbinsx, xmin, xmax, nbinsy, ymin, ymax);

    // Fill the histogram with data points
    for (size_t i = 0; i < xData.size(); ++i) {
        hist->Fill(xData[i], yData[i]);
    }

    // Draw Hist
    hist->SetStats(0);
    TCanvas *c = new TCanvas("canvas", "Canvas", 700, 500);
    c->cd();
    // gPad->SetLogz();
    gPad->SetLogx();
    // gPad->SetLogy();
    gStyle->SetPalette(kRainBow);
    c->SetRightMargin(c->GetRightMargin()*2);
    hist->Draw("COLZ");
    // c->WaitPrimitive();

    // Save plot
    string save_to = "out/" + name + ".png";
    c->SaveAs(save_to.c_str());
}

// This is the main function of the script
void TwoDotDensity() {
    // Plot the combined data sets
    MakeHist("proton_iron_Test_Combined_Continuum_N_mu_XMax");
}
