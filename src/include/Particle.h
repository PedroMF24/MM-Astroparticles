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

    virtual bool Decay(double energy) const {return false;};
    inline bool Interacts(double energy) const {
        // cout << energy << " CS: " << CrossSection << endl;
        bool interacts = (energy < CrossSection) ? true : false;
        // cout << "Interacts" << endl;
        return interacts;   
    }

//     int Treshold(double energy) {
//     double minE = 3;
//     if (energy >= minE)
//         return 0;
//     return 1;
// }

    Particle& operator=(const Particle &obj);
    friend std::ostream& operator<<(std::ostream& s, const Particle& p);

    string GetName() const { return Name; }
    double GetEnergy() const { return Energy; }
    double GetMass() const { return Mass; }
    double GetCharge() const { return Charge; }

    double GetCrossSection() {return CrossSection;}
    double GetDecayRate() {return DecayRate;}
    int GetAtomicNumber() {return AtomicNumber;}

protected:
    string Name;
    double Energy;
    double Mass;
    int Charge;
    int Weight = 1;
    double CrossSection = 1.;
    double DecayRate = 1.;
    int AtomicNumber = 1;
};


class Electron : public Particle {
    public:
    Electron(double energy) : Particle("Electron", energy, 0.0, -1) {
        CrossSection = 1;
        DecayRate = 1;
    }
    // int GetType() const override { return 0; }
    
    // Electron& operator=(const Electron& obj);
    // friend std::ostream& operator<<(std::ostream& s, const Electron& e);
};

class PionN : public Particle {
    public:
    PionN(double energy) : Particle("PionN", energy, 0.0, 0) {
        CrossSection = 0;
        DecayRate = 1;
    }
};

class PionP : public Particle {
    public:
    PionP(double energy) : Particle("PionP", energy, 0.0, +1) {
        CrossSection = 3;
        DecayRate = 1;
    }
    // int GetType() const override { return 0; }
    
    // Electron& operator=(const Electron& obj);
    // friend std::ostream& operator<<(std::ostream& s, const Electron& e);
};

class PionM : public Particle {
    public:
    PionM(double energy) : Particle("PionM", energy, 0.0, -1) {
        CrossSection = 3;
        DecayRate = 1;
    }
    // int GetType() const override { return 0; }
    
    // Electron& operator=(const Electron& obj);
    // friend std::ostream& operator<<(std::ostream& s, const Electron& e);
};

class Proton : public Particle {
    public:
    Proton(double energy) : Particle("Proton", energy, 0.0, +1) {
        CrossSection = 3;
        DecayRate = 2;
    }
    bool Decay(double energy) const override {
        bool decays = (energy < 1) ? true : false;
        return decays;
    }

};

class Photon : public Particle {
    public:
    Photon(double energy) : Particle("Photon", energy, 0.0, 0) {}
    
};

class Iron : public Particle {
    public:
    Iron(double energy) : Particle("Iron", energy, 0.0, 0) {
        AtomicNumber = 56;
    }
    
};

class Neutron : public Particle {
    public:
    Neutron(double energy) : Particle("Neutron", energy, 0.0, 0) {}
    
};

#endif