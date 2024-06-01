#include "include/FileStream.h"

void writeDataToFile(const string &filename, const vector<double>& XMaxValues, const vector<double>& N_muValues) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return;
    }

    // Write headers
    outFile << "XMax N_mu" << endl;

    // Write data in columns
    size_t dataSize = min(XMaxValues.size(), N_muValues.size());
    for (size_t i = 0; i < dataSize; ++i) {
        outFile << XMaxValues[i] << " " << N_muValues[i] << endl;
    }

    // Close the file
    outFile.close();
}

void extractColumns(const string &inputFile, const string &outputFile, int col1, int col2) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    // Skip the header line
    getline(inFile, line);
    
    while (getline(inFile, line)) {
        istringstream ss(line);
        vector<double> values;
        double value;

        // Read values from the line into the vector
        while (ss >> value) {
            values.push_back(value);
        }

        // Check if the specified columns are within the range
        if (col1 < 1 || col1 > values.size() || col2 < 1 || col2 > values.size()) {
            cerr << "**Column indices out of range." << endl;
            return;
        }

        // Write the selected columns to the output file
        outFile << values[col1 - 1] << " " << values[col2 - 1] << endl;
    }

    inFile.close();
    outFile.close();
}

void readDataFromFile(const string& filename, vector<double>& XMaxValues, vector<double>& N_muValues) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return;
    }

    // Variables for reading lines and values
    string line;
    double XMax, N_mu;

    // Skip the header line
    getline(inFile, line);

    // Read data line by line
    while (getline(inFile, line)) {
        istringstream iss(line);
        if (!(iss >> XMax >> N_mu)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        XMaxValues.push_back(XMax);
        N_muValues.push_back(N_mu);
    }

    // Close the file
    inFile.close();
}

ostream& operator<<(ostream& s, const Config& con) {
    s << setprecision(3) << scientific;
    s << "--- List Configs ---" << endl
        << "InitParticle: " << con.get("InitParticle") << endl
        << "InitEnergy: " << con.get("InitEnergy") << endl
        << "MaxEnergy: " << con.get("MaxEnergy") << endl
        << "Step: " << con.get("Step") << endl
        << "Multiplicity: " << con.get("Multiplicity") << endl
        << "RandomDist: " << con.get("RandomDist") << endl
        << "OutFile: " << con.get("OutFile") << endl
        << "ExtractDataTo: " << con.get("ExtractDataTo") << endl
        << "Column1: " << con.get("Column1") << endl
        << "Column2: " << con.get("Column2") << endl
        << " --- End Configs --- " << endl;
    return s;
}


// // Function to check if the value is within the permitted options
// bool validateConfig(const unordered_map<string, string>& config) {
//     set<string> permittedInitParticles = {"Proton", "Iron"};
//     set<string> permittedRandomDists = {"Gauss", "Uni", "Even"};

//     // Check InitParticle
//     if (permittedInitParticles.find(config.at("InitParticle")) == permittedInitParticles.end()) {
//         cerr << "Error: Invalid InitParticle: " << config.at("InitParticle") << endl;
//         return false;
//     }

//     // Check Multiplicity (ensure it's a positive integer)
//     try {
//         int multiplicity = stoi(config.at("Multiplicity"));
//         if (multiplicity <= 0) {
//             cerr << "Error: Multiplicity must be a positive integer." << endl;
//             return false;
//         }
//     } catch (invalid_argument&) {
//         cerr << "Error: Multiplicity must be a valid integer." << endl;
//         return false;
//     }

//     // Check RandomDist
//     if (permittedRandomDists.find(config.at("RandomDist")) == permittedRandomDists.end()) {
//         cerr << "Error: Invalid RandomDist: " << config.at("RandomDist") << endl;
//         return false;
//     }

//     return true;
// }

// void readConfigFile(const string &configFile, unordered_map<string, string> &config) {
//     ifstream infile(configFile);
//     if (!infile.is_open()) {
//         cerr << "**Unable to open config file." << endl;
//         return;
//     }

//     string line;

//     while (getline(infile, line)) {
//         // Remove comments
//         size_t commentPos = line.find("#");
//         if (commentPos != string::npos) {
//             line = line.substr(0, commentPos);
//         }

//         // Skip empty lines
//         if (line.empty()) {
//             continue;
//         }

//         size_t delimiterPos = line.find(": ");
//         if (delimiterPos != string::npos) {
//             string name = line.substr(0, delimiterPos);
//             string value = line.substr(delimiterPos + 2);
//             config[name] = value;
//         }
//     }

//     // Validate configuration
//     if (!validateConfig(config)) {
//         cerr << "**Invalid configuration. Exiting." << endl;
//         exit(EXIT_FAILURE);
//     }
// }

