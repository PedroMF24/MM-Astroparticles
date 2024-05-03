#ifndef __FILESTREAM__
#define __FILESTREAM__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void writeDataToFile(const string &filename, const std::vector<double>& XMaxValues, const std::vector<double>& N_muValues);

void readDataFromFile(const std::string& filename, std::vector<double>& XMaxValues, std::vector<double>& N_muValues);

#endif