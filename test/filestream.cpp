#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void writeDataToFile(const string &filename, const std::vector<double>& XMaxValues, const std::vector<double>& N_muValues) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return;
    }

    // Write headers
    outFile << "XMax N_mu" << std::endl;

    // Write data in columns
    size_t dataSize = std::min(XMaxValues.size(), N_muValues.size());
    for (size_t i = 0; i < dataSize; ++i) {
        outFile << XMaxValues[i] << " " << N_muValues[i] << std::endl;
    }

    // Close the file
    outFile.close();
}

// int main() {
//     // Example usage
//     std::vector<double> XMaxValues = {1.0, 2.0, 3.0, 4.0};
//     std::vector<double> N_muValues = {0.1, 0.2, 0.3, 0.4};
    
//     writeDataToFile("../data/shower_data.dat", XMaxValues, N_muValues);

//     return 0;
// }   


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void readDataFromFile(const std::string& filename, std::vector<double>& XMaxValues, std::vector<double>& N_muValues) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return;
    }

    // Variables for reading lines and values
    std::string line;
    double XMax, N_mu;

    // Skip the header line
    std::getline(inFile, line);

    // Read data line by line
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        if (!(iss >> XMax >> N_mu)) {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        XMaxValues.push_back(XMax);
        N_muValues.push_back(N_mu);
    }

    // Close the file
    inFile.close();
}

int main() {
    // Example usage
    std::vector<double> XMaxValues;
    std::vector<double> N_muValues;

    readDataFromFile("../data/shower_data.dat", XMaxValues, N_muValues);

    // Print the read data
    std::cout << "XMaxValues: ";
    for (const auto& value : XMaxValues) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "N_muValues: ";
    for (const auto& value : N_muValues) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
