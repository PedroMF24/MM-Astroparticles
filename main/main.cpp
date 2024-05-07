#include "../src/include/MyRandom.h"
#include "../src/include/Shower.h"
#include "../src/include/FileStream.h"
// #include "../src/include/Utils.h"

#include <cmath>

using namespace std;



// double calcXMax(double E0, int A) {
//     return log(E0/A);
// }

// double calcNMuon(double E0, int A, double beta) {
//     return pow(A, 1-beta)*pow(E0, beta);
// }

int main() {

    std::cout << "--- Begin program ---" << std::endl;


    // MyRandom rng;

    // double E0 = 1E+10;
    // double β = 1;
    // int A = 1;
    // for (int i = 0; i < 1000; i++)
    // {
    //     E0 = rng.UniDist(1E+9, 1E+11);

    // }
    

// Define a map of string keys to class member function pointers



    /* TEST RNG */
    // MyRandom rng;

    // for (int i = 0; i < 50; i++)
    // {
    //     cout << rng.UniDist(-100,100) << endl;
    // }

    /* TEST CLASSES */

    // // Particle proton("Proton", 100, 1, 1); // Name, Energy, Mass, Charge
    // // Shower shower(proton, 3);

    // // cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;

/* THIS WORKS
    vector<double> XMaxValues, N_muValues;

    for (int en = 1000; en < 10001; en += 10)
    {
        Proton pp(en); // In GeV
        Shower shower(pp, 3);
        cout << pp.GetName() << " " << pp.GetCharge() << endl;
        cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;
        cout << pp << endl;
        shower.BuildShower();
        
        XMaxValues.push_back(shower.GetXMax());
        N_muValues.push_back(shower.GetN_mu());
    }

    writeDataToFile("data/test.dat", XMaxValues, N_muValues);
*/

    vector<double> XMaxValues, N_muValues;

    // for (int en = 1000; en < 10001; en += 10)
    // {
        Proton pp(1000); // In GeV en
        Shower shower(pp, 3);
        cout << pp.GetName() << " " << pp.GetCharge() << endl;
        cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;
        cout << pp << endl;
        // shower.BuildShower();
        
        // XMaxValues.push_back(shower.GetXMax());
        // N_muValues.push_back(shower.GetN_mu());

    // }

    std::cout << "Writting data file to data/test.dat" << std::endl;
    // writeDataToFile("data/test.dat", XMaxValues, N_muValues);


    std::cout << "--- End of program ---" << std::endl;

    // double A = 1;
    // double beta = 0.5;
    // double E0 = 0;

    // MyRandom rng;

    // for (int i = 0; i < 500; i++)
    // {
    //     E0 = rng.UniDist(1E+9, 1E+11);
    //     XMaxValues.push_back(calcXMax(E0, A));
    //     N_muValues.push_back(calcNMuon(E0, A, beta));
    // }
    
    // writeDataToFile("data/test.dat", XMaxValues, N_muValues);
    

    // cout << ee.GetCrossSection();



    // Utils theUtils;
    // for (int i = 0; i < 10; i++)
    // {
    //     theUtils.ProgressBar(i, 10);
    //     sleep_for(nanoseconds(10));
    //     sleep_until(system_clock::now() + seconds(1));
    // }
    // theUtils.FinishProgressBar();
    
    return 0;
}