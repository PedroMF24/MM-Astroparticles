#include "../src/include/MyRandom.h"
#include "../src/include/Shower.h"

using namespace std;

int main() {

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

    Electron ee(100); // GeV
    Shower shower(ee, 3);
    cout << ee.GetName() << " " << ee.GetCharge() << endl;
    cout << shower.GetInitEnergy() << " " << shower.GetInitMultiplicity() << endl;
    cout << ee << endl;
    shower.BuildShower();

    cout << ee.GetCrossSection();
    return 0;
}