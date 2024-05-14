#include "../src/include/MyRandom.h"
#include "../src/include/Shower.h"
#include "../src/include/FileStream.h"
#include "../src/include/Utils.h"
// #include "../src/include/StopWatch.h"
// #include "../src/include/ProgressBar.h"

#include <cmath>
#include <iomanip>      // std::setprecision

using namespace std;



// double calcXMax(double E0, int A) {
//     return log(E0/A);
// }

// double calcNMuon(double E0, int A, double beta) {
//     return pow(A, 1-beta)*pow(E0, beta);
// }

// int main() {
//     Utils TheUtils;

//     int max = 300;
//     int step = 2;
//     int init = 0;
//     int totalSteps = ceil(max/step-init);
//     cout << totalSteps << endl;
//     int entry = 0;
//     for (int i = init; i < max; i+=step)
//     {
//         TheUtils.ProgressBar(entry, totalSteps);
//         sleep_for(nanoseconds(10));
//         sleep_until(system_clock::now() + milliseconds(10)); // + seconds(1)
//         entry++;
//     }
//     TheUtils.FinishProgressBar();
// }

// int main() {

//     StopWatch clock;
//     clock.StartTimer();
//     std::cout << "--- Begin program ---" << std::endl;


//     // MyRandom rng;

//     // double E0 = 1E+10;
//     // double β = 1;
//     // int A = 1;
//     // for (int i = 0; i < 1000; i++)
//     // {
//     //     E0 = rng.UniDist(1E+9, 1E+11);

//     // }
    

// // Define a map of string keys to class member function pointers



//     /* TEST RNG */
//     // MyRandom rng;

//     // for (int i = 0; i < 50; i++)
//     // {
//     //     cout << rng.UniDist(-100,100) << endl;
//     // }

//     /* TEST CLASSES */

//     // // Particle proton("Proton", 100, 1, 1); // Name, Energy, Mass, Charge
//     // // Shower shower(proton, 3);

//     // // cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;

// // THIS WORKS
//     vector<double> XMaxValues, N_muValues;
//     const string filename = "data/test.dat";
    
//     std::ofstream outFile(filename);
//     if (!outFile.is_open()) {
//         std::cerr << "Unable to open file." << std::endl;
//         exit(0);
//     }
//     // Write headers
//     outFile << "XMax N_mu" << std::endl;


//     int initE = 10;
//     int maxE = 100; // 10000 
//     int step = 3;

//     int totalSteps = (maxE - initE) / step + 1; // Adjust totalSteps calculation
//     ProgressBar PBar(totalSteps);

//     for (int en = initE; en <= maxE; en += step)
//     {
//         // entry++;
//         int currentStep = (en - initE) / step; // Calculate currentStep based on loop progress
//         PBar.Update(currentStep);
//         sleep_for(nanoseconds(10));
//         sleep_until(system_clock::now() + milliseconds(100)); // + milliseconds(10)

//         Proton pp(en); // In GeV
//         // Iron ii(en);
//         Shower shower(pp, 3, outFile);
//         // cout << pp.GetName() << " " << pp.GetCharge() << endl;
//         // cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;
//         // cout << pp << endl;
//         // shower.BuildShower();
        
//         // XMaxValues.push_back(shower.GetXMax());
//         // N_muValues.push_back(shower.GetN_mu());
//     }
//     PBar.Finish();

//     // Close the file
//     outFile.close();

//     // writeDataToFile("data/test.dat", XMaxValues, N_muValues);


//     // vector<double> XMaxValues, N_muValues;

//     // // for (int en = 1000; en < 10001; en += 10)
//     // // {
//     //     Proton pp(1000); // In GeV en
//     //     Shower shower(pp, 3);
//     //     cout << pp.GetName() << " " << pp.GetCharge() << endl;
//     //     cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;
//     //     cout << pp << endl;
//     //     // shower.BuildShower();
        
//     //     // XMaxValues.push_back(shower.GetXMax());
//     //     // N_muValues.push_back(shower.GetN_mu());

//     // // }

//     // std::cout << "Writting data file to data/test.dat" << std::endl;
//     // // writeDataToFile("data/test.dat", XMaxValues, N_muValues);


//     std::cout << "--- End of program ---" << std::endl;

//     // double A = 1;
//     // double beta = 0.5;
//     // double E0 = 0;

//     // MyRandom rng;

//     // for (int i = 0; i < 500; i++)
//     // {
//     //     E0 = rng.UniDist(1E+9, 1E+11);
//     //     XMaxValues.push_back(calcXMax(E0, A));
//     //     N_muValues.push_back(calcNMuon(E0, A, beta));
//     // }
    
//     // writeDataToFile("data/test.dat", XMaxValues, N_muValues);
    

//     // cout << ee.GetCrossSection();



//     // Utils theUtils;
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     theUtils.ProgressBar(i, 10);
//     //     sleep_for(nanoseconds(10));
//     //     sleep_until(system_clock::now() + seconds(1));
//     // }
//     // theUtils.FinishProgressBar();

//     clock.StopTimer();
//     clock.PrintTime();
    
//     return 0;
// }

int main() {

    Utils TheUtils;
    TheUtils.StartTimer();
    

    int initE = 10;
    int maxE = 100000;
    int step = 1000;

//     int initE = 10;
//     int maxE = 100; // 10000 
//     int step = 3;

    const string filename = "data/test.dat";
    
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        exit(0);
    }
    // Write headers
    outFile << "E0 Ec XMax N_mu" << std::endl;

    int totalSteps = (maxE - initE) / step + 1; // Adjust totalSteps calculation

    TheUtils.SetTotalSteps(totalSteps);


    for (int en = initE; en <= maxE; en += step) {
        int currentStep = (en - initE) / step; // Calculate currentStep based on loop progress
        TheUtils.UpdateProgressBar(currentStep);
        Iron ii(en);
        // cout << "before shower" << ii.GetEnergy() << endl;
        Shower shower(ii, 3, outFile);
        // cout << "after shower" << ii.GetEnergy() << endl;
        // sleep_for(nanoseconds(10));
        // sleep_until(system_clock::now() + milliseconds(100)); // + milliseconds(10)
    }
    TheUtils.FinishProgressBar();

    outFile.close();
    TheUtils.StopTimer();
    // std::cout << "--- End of program ---" << std::endl;

    return 0;
}