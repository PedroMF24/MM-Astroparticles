#include "../src/include/MyRandom.h"
#include "../src/include/Shower.h"
#include "../src/include/FileStream.h"
#include "../src/include/Utils.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <functional>
#include <stdexcept>
#include <memory> // For smart pointers

using namespace std;

void Normal(Utils &Tools, Config &Conf, ofstream &outFile, double energy, string model, Particle* particle);
void MonteCarlo(Utils &Tools, Config &Conf, ofstream &outFile, double energy, string model, Particle* particle);
void EnergyFixed(Utils &Tools, Config &Conf, ofstream &outFile, double energy, string model, Particle* particle);

void runShowerCalculations(Utils &Tools, Config &Conf,
    const function<void(Utils&, Config&, ofstream&, double, string, Particle*)> &modeFunc, 
    int totalSteps, bool useRandomEnergy = false);

int main() {
    Utils TheUtils;
    TheUtils.StartTimer();

    Config config("config.in");
    cout << config << endl;

    string mode = config.get("Mode");

    if (mode == "Normal") {
        int initE = static_cast<int>(stod(config.get("InitEnergy")));
        int maxE = static_cast<int>(stod(config.get("MaxEnergy")));
        int step = stoi(config.get("Step"));
        int totalSteps = (maxE - initE) / step + 1;
        runShowerCalculations(TheUtils, config, Normal, totalSteps);

    } else if (mode == "MCarlo") {
        runShowerCalculations(TheUtils, config, MonteCarlo, 1000, true);

    } else if (mode == "EFixed") {
        runShowerCalculations(TheUtils, config, EnergyFixed, 1000);

    } else {
        cerr << "**Mode Error: Should never get here" << endl;
    }

    TheUtils.StopTimer();
    TheUtils.End();
    TheUtils.PrintTime();

    return 0;
}

Particle* createParticle(const string &particleType, double energy) {
    if (particleType == "Proton") {
        return new Proton(energy);
    } else if (particleType == "Iron") {
        return new Iron(energy);
    } else {
        cerr << "**Particle Creation Error: Unknown particle type" << endl;
        exit(EXIT_FAILURE);
    }
}

void runShowerCalculations(Utils &Tools, Config &Conf, 
    const function<void(Utils&, Config&, ofstream&, double, string, Particle*)> &modeFunc, 
    int totalSteps, bool useRandomEnergy) 
{
    int initE = static_cast<int>(stod(Conf.get("InitEnergy")));
    int maxE = static_cast<int>(stod(Conf.get("MaxEnergy")));
    int step = stoi(Conf.get("Step"));

    const string filename = Conf.get("OutFile");
    const string extractData = Conf.get("ExtractDataTo");
    int col1 = stoi(Conf.get("Column1"));
    int col2 = stoi(Conf.get("Column2"));

    string mode = Conf.get("Mode");
    string model = Conf.get("Model");

    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Unable to open file." << endl;
        exit(EXIT_FAILURE);
    }

    // Write headers
    outFile << "E0 ln(E0) Ec XMax N_mu ln(N_mu)" << endl;

    Tools.SetTotalSteps(totalSteps);
    cout << "Calculating showers..." << endl;

    MyRandom RNG;

    try {
        for (int i = 0; i < totalSteps; i++) {
            Tools.UpdateProgressBar(i);

            double energy = 0.0;
            if (mode == "EFixed") {
                energy = initE;
            } else if (mode == "MCarlo") {
                energy = RNG.UniDist(initE, maxE);
            } else if (mode == "Normal") {
                energy = initE + i * step;
            } else {
                cerr << "Should never get here: unknown mode." << endl;
            }

            // double energy = useRandomEnergy ? RNG.UniDist(initE, maxE) : initE + i * step;
            Particle *initParticle = createParticle(Conf.get("InitParticle"), energy);
            initParticle->SetEnergy(energy);  // Set the energy for the particle

            modeFunc(Tools, Conf, outFile, energy, model, initParticle);

            if (i % 100 == 0) {
                outFile.flush(); // Periodically flush to ensure data is written
            }
        }
    } catch (const std::exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception caught" << endl;
    }

    Tools.FinishProgressBar();

    outFile.close(); // Ensure the file is closed
    cout << "Extracting data..." << endl;
    extractColumns(filename, extractData, col1, col2);
}

void Normal(Utils &Tools, Config &Conf, ofstream &outFile, double energy, string model, Particle* particle) {
    int multiplicity = stoi(Conf.get("Multiplicity"));
    string randomDist = Conf.get("RandomDist");

    Shower shower(particle, multiplicity, randomDist, model, outFile);
}

void MonteCarlo(Utils &Tools, Config &Conf, ofstream &outFile, double energy, string model, Particle* particle) {
    int multiplicity = stoi(Conf.get("Multiplicity"));
    string randomDist = Conf.get("RandomDist");

    Shower shower(particle, multiplicity, randomDist, model, outFile);
}

void EnergyFixed(Utils &Tools, Config &Conf, ofstream &outFile, double energy, string model, Particle* particle) {
    int multiplicity = stoi(Conf.get("Multiplicity"));
    string randomDist = Conf.get("RandomDist");

    Shower shower(particle, multiplicity, randomDist, model, outFile);
}
