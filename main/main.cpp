#include "../src/include/MyRandom.h"
#include "../src/include/Shower.h"

#include <cmath>

using namespace std;


// double calcXMax(double E0, int A) {
//     return log(E0/A);
// }

// double calcNMuon(double E0, int A, double β) {
//     return pow(A, 1-β)*pow(E0, β);
// }

int main() {

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

    Electron ee(180); // GeV
    Shower shower(ee, 3);
    cout << ee.GetName() << " " << ee.GetCharge() << endl;
    cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;
    cout << ee << endl;
    shower.BuildShower();

    cout << ee.GetCrossSection();
    return 0;
}