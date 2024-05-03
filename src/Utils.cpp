// Ruben Conceicao
// Thu Jun 25 15:54:01 WEST 2020

#include "include/Utils.h"

using namespace std;

// ---------------------------------------------
// Constructor
// Class with useful harmful methods
// ---------------------------------------------
Utils::Utils()
{
}

// ---------------------------------------------
// Destructor
// ---------------------------------------------
Utils::~Utils()
{
}

// -----------------------------------------
// Generated Output Filename [0.0 -> 1.0]
// -----------------------------------------

void
Utils::ProgressBar(double entry, double nentries)
{
    const double progress = entry / nentries;

    int barWidth = 70;

    cout<<"\033[80D";//move 80 space left
    std::cout << "[";
    int pos = 0;
    (entry != nentries) ? pos = barWidth * progress : pos = barWidth;

    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();

    if ( progress == 1. || entry == nentries )
        std::cout << std::endl;
}