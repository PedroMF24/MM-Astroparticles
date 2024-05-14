#ifndef __PROGRESSBAR__
#define __PROGRESSBAR__

#include <iostream>
#include <cmath>

class ProgressBar {
public:
    ProgressBar(int totalSteps, int barWidth = 70) : totalSteps(totalSteps), barWidth(barWidth) {}

    inline void Update(int currentStep) {
        int progress = static_cast<int>((static_cast<double>(currentStep) / totalSteps) * 100.0);
        int pos = static_cast<int>((static_cast<double>(currentStep) / totalSteps) * barWidth);

        std::cout << "\r[";

        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }

        std::cout << "] " << progress << "%";
        std::cout.flush();
    }


    inline void Finish() {
        // Print a complete progress bar with 100% progress
        std::cout << "\r[";
        for (int i = 0; i < barWidth; ++i) {
            std::cout << "=";
        }
        std::cout << "] 100%";
        std::cout.flush(); // Flush the output stream to ensure immediate display
        std::cout << std::endl; // Move to the next line
    }

    void SetTotalSteps(int totsteps) {totalSteps = totsteps;}


private:
    int totalSteps;
    int barWidth;
};
#endif