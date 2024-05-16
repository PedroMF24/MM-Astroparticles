#include "include/Particle.h"

Particle::Particle(const Particle& other) {
    Name = other.Name;
    Energy = other.Energy;
    Mass = other.Mass;
    Charge = other.Charge;
    Weight = other.Weight;
    CrossSection = other.CrossSection;
    DecayRate = other.DecayRate;
    AtomicNumber = other.AtomicNumber;
}

Particle& Particle::operator=(const Particle &obj) {

    if (this != &obj) {
        Name = obj.Name;
        Energy = obj.Energy;
        Mass = obj.Mass;
        Charge = obj.Charge;
        Weight = obj.Weight;
        CrossSection = obj.CrossSection;
        DecayRate = obj.DecayRate;
        AtomicNumber = obj.AtomicNumber;
    }
    return *this;
}

ostream& operator<<(std::ostream& s, const Particle& p) {
    s << setprecision(3); //  << scientific;
    s << p.GetName() << ", "
        << "Energy=" << p.GetEnergy() << ", "
        << "Mass=" << p.GetMass() << ", "
        << "Charge=" << p.GetCharge();
    return s;
}

void PionM::DecayProducts(double energy, int multiplicity, vector<Particle*>& nextParticles) {
    //if (Interacts(energy/multiplicity)) {
        nextParticles.push_back(new PionP(energy / multiplicity));
        nextParticles.push_back(new PionM(energy / multiplicity));
    //}
}

void PionP::DecayProducts(double energy, int multiplicity, vector<Particle*>& nextParticles) {
    //if (Interacts(energy/multiplicity)) {
        // cout << "got here" << endl;
        nextParticles.push_back(new PionP(energy / multiplicity));
        nextParticles.push_back(new PionM(energy / multiplicity));
    //}
}

void Proton::DecayProducts(double energy, int multiplicity, vector<Particle*>& nextParticles) {
    //if (Interacts(energy/multiplicity)) {
        nextParticles.push_back(new PionP(energy / multiplicity));
        nextParticles.push_back(new PionM(energy / multiplicity));
    //}
}