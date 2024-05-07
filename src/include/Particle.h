#ifndef __PARTICLE__
#define __PARTICLE__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

#include "MyRandom.h"

using namespace std;

class Particle : public MyRandom {
    public:
    // Particle() = default;
    // Particle(const Particle&) = delete; // Deleting the copy constructor
    Particle(string newName, double newEnergy, double newMass, int newCharge) :
        Name(newName), Energy(newEnergy), Mass(newMass), Charge(newCharge) {}
    // Copy constructor
    Particle(const Particle& other);
    // Destructor
    ~Particle() = default;

    // virtual int GetType() const = 0;

    Particle& operator=(const Particle &obj);
    friend std::ostream& operator<<(std::ostream& s, const Particle& p);

    string GetName() const { return Name; }
    double GetEnergy() const { return Energy; }
    double GetMass() const { return Mass; }
    double GetCharge() const { return Charge; }

    double GetCrossSection() {return CrossSection;}
    double GetDecayRate() {return DecayRate;}

protected:
    string Name;
    double Energy;
    double Mass;
    int Charge;
    int Weight = 1;
    double CrossSection = 1.;
    double DecayRate = 1.;
};

#endif