#include "include/MyRandom.h"

double MyRandom::UniDist(double min, double max) {
    uniform_real_distribution<double> Dist(min, max);
    return Dist(rd);
}

// // Function to generate random numbers in a specified range
// double generateRandomNumber(double min, double max) {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_real_distribution<> dis(min, max);
//     return dis(gen);
// }