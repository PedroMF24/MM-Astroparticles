#ifndef __FILESTREAM__
#define __FILESTREAM__

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <set>

using namespace std;



void writeDataToFile(const string &filename, const vector<double>& XMaxValues, const vector<double>& N_muValues);

void readDataFromFile(const string& filename, vector<double>& XMaxValues, vector<double>& N_muValues);

void extractColumns(const string &inputFile, const string &outputFile, int col1, int col2);

// bool validateConfig(const unordered_map<string, string>& config);

// void readConfigFile(const string &configFile, unordered_map<string, string> &config);


class Config {

public:
    Config(const string &configFile) {
        readConfigFile(configFile);
        if (!validateConfig()) {
            cerr << "**Invalid configuration. Exiting." << endl;
            exit(EXIT_FAILURE);
        }
    }

    const string& get(const string &key) const {
        return config.at(key);
    }

    friend ostream& operator<<(ostream& s, const Config& con);


private:
    unordered_map<string, string> config;

    void readConfigFile(const string &configFile) {
        ifstream infile(configFile);
        if (!infile.is_open()) {
            cerr << "**Unable to open config file." << endl;
            exit(EXIT_FAILURE);
        }

        string line;

        while (getline(infile, line)) {
            // Remove comments
            size_t commentPos = line.find("#");
            if (commentPos != string::npos) {
                line = line.substr(0, commentPos);
            }

            // Skip empty lines
            if (line.empty()) {
                continue;
            }

            size_t delimiterPos = line.find(": ");
            if (delimiterPos != string::npos) {
                string name = line.substr(0, delimiterPos);
                string value = line.substr(delimiterPos + 2);
                config[name] = value;
            }
        }
    }

    bool validateConfig() const {
        set<string> permittedModes = {"Normal", "MCarlo", "EFixed"};
        set<string> permittedInitParticles = {"Proton", "Iron"};
        set<string> permittedRandomDists = {"Gauss", "Uni", "Even"};
        set<string> permittedModels = {"Discrete", "Continuous"};

        // Check Mode
        if (permittedModes.find(config.at("Mode")) == permittedModes.end()) {
            cerr << "Error: Invalid Mode: " << config.at("Mode") << endl;
            return false;
        }

        // Check InitParticle
        if (permittedInitParticles.find(config.at("InitParticle")) == permittedInitParticles.end()) {
            cerr << "Error: Invalid InitParticle: " << config.at("InitParticle") << endl;
            return false;
        }

        // Check Multiplicity (ensure it's a positive integer)
        try {
            int multiplicity = stoi(config.at("Multiplicity"));
            if (multiplicity <= 0) {
                cerr << "Error: Multiplicity must be a positive integer." << endl;
                return false;
            }
        } catch (invalid_argument&) {
            cerr << "Error: Multiplicity must be a valid integer." << endl;
            return false;
        }


        // Check RandomDist
        if (permittedRandomDists.find(config.at("RandomDist")) == permittedRandomDists.end()) {
            cerr << "Error: Invalid RandomDist: " << config.at("RandomDist") << endl;
            return false;
        }


        // Check Model
        if (permittedModels.find(config.at("Model")) == permittedModels.end()) {
            cerr << "Error: Invalid Model: " << config.at("Model") << endl;
            return false;
        }


        // Check InitEnergy (ensure it's a positive integer)
        try {
            int InitEnergy = static_cast<int>(stod(config.at("InitEnergy")));
            if (InitEnergy <= 0) {
                cerr << "Error: Initial energy must be a positive integer." << endl;
                return false;
            }
        } catch (invalid_argument&) {
            cerr << "Error: Initial energy must be a valid integer." << endl;
            return false;
        }


        // Check MaxEnergy
        try {
            int MaxEnergy = static_cast<int>(stod(config.at("MaxEnergy")));
            // cout << "MaxEnergy: " << MaxEnergy << endl;
            int InitEnergy = static_cast<int>(stod(config.at("InitEnergy")));
            if (MaxEnergy <= 0 || MaxEnergy <= InitEnergy) {
                cerr << "Error: Maximum energy must be a positive double and greater than initial energy." << endl;
                return false;
            }
        } catch (invalid_argument&) {
            cerr << "Error: Maximum energy must be a valid double." << endl;
            return false;
        }


        // Check Step
        try {
            int Step = stoi(config.at("Step"));
            int MaxEnergy = static_cast<int>(stod(config.at("MaxEnergy")));
            if (Step <= 0 || Step >= MaxEnergy) {
                cerr << "Error: Energy step must be a positive integer and lower than the maximum energy." << endl;
                return false;
            }
        } catch (invalid_argument&) {
            cerr << "Error: Energy step must be a valid integer." << endl;
            return false;
        }

        return true;
    }
};

#endif