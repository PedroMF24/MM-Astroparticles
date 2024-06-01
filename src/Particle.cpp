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

void PionM::DecayProducts(double energy, int multiplicity, string randDist, int &nParticles, vector<Particle*>& nextParticles) {
        
        vector<double> probs;

        // Gauss
        if (randDist == RandomDists[0])
            probs = genGaussProbs(3, energy, 1.5);
        // Uni
        else if (randDist == RandomDists[1])
            probs = genUniProbs(3);
        // Even
        else if (randDist == RandomDists[2])
            probs.insert(probs.end(), 2, 1.0 / 3.0);
        else
            cerr << "**Decay Products: Unknown random distribution" << endl;

        // cout << "Gets here!!!" << endl;
        nextParticles.push_back(new PionP(energy*probs[0]));
        nextParticles.push_back(new PionM(energy*probs[1]));
        nParticles += 2; 

}

void PionP::DecayProducts(double energy, int multiplicity, string randDist, int &nParticles, vector<Particle*>& nextParticles) {
        
        vector<double> probs;

        // Gauss
        if (randDist == RandomDists[0])
            probs = genGaussProbs(3, energy, 1.5);
        // Uni
        else if (randDist == RandomDists[1])
            probs = genUniProbs(3);
        // Even
        else if (randDist == RandomDists[2])
            probs.insert(probs.end(), 2, 1.0 / 3.0);
        else
            cerr << "**Decay Products: Unknown random distribution" << endl;

        nextParticles.push_back(new PionP(energy*probs[0]));
        nextParticles.push_back(new PionM(energy*probs[1]));
        nParticles += 2; 

}

void Proton::DecayProducts(double energy, int multiplicity, string randDist, int &nParticles, vector<Particle*>& nextParticles) {
        
        vector<double> probs;

        // Gauss
        if (randDist == RandomDists[0])
            probs = genGaussProbs(3, energy, 1.5);
        // Uni
        else if (randDist == RandomDists[1])
            probs = genUniProbs(3);
        // Even
        else if (randDist == RandomDists[2])
            probs.insert(probs.end(), 2, 1.0 / 3.0);
        else
            cerr << "**Decay Products: Unknown random distribution" << endl;

        nextParticles.push_back(new PionP(energy*probs[0]));
        nextParticles.push_back(new PionM(energy*probs[1]));
        nParticles += 2; 

}

void Iron::DecayProducts(double energy, int multiplicity, string randDist, int &nParticles, vector<Particle*>& nextParticles) {

        vector<double> probs;

        // Gauss
        if (randDist == RandomDists[0])
            probs = genGaussProbs(3, energy, 1.5);
        // Uni
        else if (randDist == RandomDists[1])
            probs = genUniProbs(3);
        // Even
        else if (randDist == RandomDists[2])
            probs.insert(probs.end(), 2, 1.0 / 3.0);
        else
            cerr << "**Decay Products: Unknown random distribution" << endl;

        nextParticles.push_back(new PionP(energy*probs[0]));
        nextParticles.push_back(new PionM(energy*probs[1]));
        nParticles += 2; 
}