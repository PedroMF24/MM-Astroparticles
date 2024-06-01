#include "include/MyRandom.h"

double MyRandom::UniDist(double min, double max) {
    uniform_real_distribution<double> Dist(min, max);
    return Dist(rd);
}

double MyRandom::GaussDist(double mean, double stddev) {
    normal_distribution<double> Dist(mean, stddev);
    return Dist(rd);
}

// // Function to generate random numbers in a specified range
// double generateRandomNumber(double min, double max) {
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_real_distribution<> dis(min, max);
//     return dis(gen);
// }

vector<double> MyRandom::genUniProbs(int count) {
    vector<double> randomNumbers(count);
    double sum = 0.0;

    for (int i = 0; i < count; ++i) {
        randomNumbers[i] = UniDist(0.,100.);
        sum += randomNumbers[i];
    }

    for (int i = 0; i < count; ++i) {
        randomNumbers[i] /= sum;
    }

    return randomNumbers;
}

vector<double> MyRandom::genGaussProbs(int count, double mean, double stddev) {
    vector<double> randomNumbers(count);
    double sum = 0.0;

    for (int i = 0; i < count; ++i) {
        randomNumbers[i] = GaussDist(mean, stddev);
        sum += randomNumbers[i];
    }

    // Ensure the sum of the absolute values is 1 to avoid negative probabilities
    sum = accumulate(randomNumbers.begin(), randomNumbers.end(), 0.0, [](double a, double b) {
        return a + abs(b);
    });

    for (int i = 0; i < count; ++i) {
        randomNumbers[i] = abs(randomNumbers[i]) / sum;
    }

    return randomNumbers;
}