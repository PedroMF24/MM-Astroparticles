#ifndef Utils_h
#define Utils_h
// Ruben Conceicao
// Thu Jun 25 15:54:01 WEST 2020

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Utils {

    public:

        Utils();
        ~Utils();
        void ProgressBar(double entry, double nentries);
        inline void ProgressBar(int  entry, int  nentries)
        {Utils::ProgressBar(double(entry), double(nentries));}
        void FinishProgressBar()
        {Utils::ProgressBar(1.,1.);}

    private:

};
#endif