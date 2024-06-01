#ifndef __UTILS__
#define __UTILS__
// Pedro Figueiredo
// Tue May 14 2024

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "ProgressBar.h"
#include "StopWatch.h"

using namespace std;

class Utils {
public:
    Utils(int totalSteps, int barWidth = 70) : totalSteps(totalSteps), progressBar(totalSteps, barWidth) {
        std::cout << "--- Begin program ---" << std::endl << endl;
    }

    Utils() : totalSteps(0), progressBar(0) {
        std::cout << "--- Begin program ---" << std::endl << endl;
    }

    // ~Utils() {
    //     std::cout << "--- End of program ---" << std::endl;
    // };

    ~Utils() = default;

    void End() {
        std::cout << endl << "--- End of program ---" << std::endl;
    }

    void SetTotalSteps(int totsteps) {
        totalSteps = totsteps;
        progressBar.SetTotalSteps(totsteps);
        if (totalSteps == 0) {
            // Reset the progress bar
            progressBar.SetTotalSteps(0);
        }
    }

    void StartTimer() {
        stopwatch.StartTimer();
    }

    void StopTimer() {
        stopwatch.StopTimer();
    }

    void ResetTimer() {
        stopwatch.ResetTimer();
    }

    void Lap() {
        stopwatch.Lap();
    }

    void PrintTime() {
        stopwatch.PrintTime();
    }

    void UpdateProgressBar(int currentStep) {
        if (totalSteps > 0) {
            progressBar.Update(currentStep);
        } else {
            std::cerr << "**Cannot update progress bar: totalSteps is 0\n";
            std::exit(EXIT_FAILURE); // Exit the program
        }
    }

    void FinishProgressBar() {
        if (totalSteps > 0) {
            progressBar.Finish();
        } else {
            std::cerr << "**Cannot finish progress bar: totalSteps is 0\n";
            std::exit(EXIT_FAILURE); // Exit the program
        }
    }

private:
    int totalSteps;
    ProgressBar progressBar;
    StopWatch stopwatch;
};
#endif