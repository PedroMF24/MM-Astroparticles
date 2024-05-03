// #ifndef __FILESTREAM__
// #define __FILESTREAM__

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <map>
// #include <iterator>
// #include <iomanip>

// using namespace std;


// void OpenFile(const string &filename) {
//     // Open and verify if it was opened correctly
//     ofstream file;
//     file.open(filename);
//     if (!file.is_open()) {
//         fprintf(stderr, "**Can not open DAT file to write\n");
//         exit(0);
//     }
// }

// void CloseFile(ofstream &file) {
//     file.close();
// }


// void WriteDat(const string &filename) {

//   // Get the size of the largest vector
//     int maxSize = 0;
//     map<string, vector<double>>::iterator it;
//     for (it = ParMap.begin(); it != ParMap.end(); ++it)
//         maxSize = max(maxSize, (int)it->second.size());

//     // Write the strings
//     for (it = ParMap.begin(); it != ParMap.end(); ++it)
//         file << it->first << " "; // \t\t
//     file << endl;
    
//     // Write each element in a column
//     for (int i = 0; i < maxSize; i++) {
//         for (it = ParMap.begin(); it != ParMap.end(); ++it) {
//         if (i < it->second.size())
//             file << it->second[i] << " "; // \t\t
//         else
//             file << "0 ";
//         }
//         file << endl;
//     }

// }

// void ReadCSV(const string &filename, map<string, vector<double>> &ParMap) {
//     // ClearParMap();
//     printf("Reading %s into Parameter Map\n", filename.c_str());

//     ifstream input(filename);

//     if (!input.is_open()) {
//         fprintf(stderr, "**Can not open CSV file to read\n");
//         exit(0);
//     }

// 	string line, col;
// 	vector<string> header;

//         getline(input, line);
// 		stringstream ss(line);
// 		while (getline(ss, col, ';')) {
// 			header.push_back(col);
// 		}

// 		// Read values
// 		while (getline(input, line)) {
// 			stringstream ss(line);
// 			int i = 0;
// 			while (getline(ss, col, ';')) {
// 				ParMap[header[i]].push_back(stod(col));
// 				i++;
// 			}
// 		}
// }

// void ReadDat(const string &filename) {

//     ifstream input(filename);

//     if (!input.is_open()) {
//         fprintf(stderr, "**Can not open DAT file to read\n");
//         exit(0);
//     }

// 	string line, col;
// 	vector<string> header;

//     getline(input, line);
// 	stringstream ss(line);
// 	while (getline(ss, col, ' ')) {
// 		header.push_back(col);
// 	}
    
// 	// Read values
// 	while (getline(input, line)) {
// 		stringstream ss(line);
// 		int i = 0;
// 		while (getline(ss, col, ' ')) { // ; para prof data
// 			ParMap[header[i]].push_back(stod(col));
//             // cout << "header " << header[i] << " Value " << ParMap[header[i]][i] << endl; 
// 			i++;
// 		}
// 	}
// }

// #endif