#ifndef __SHOWER__
#define __SHOWER__

#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers
#include <map>
#include <functional>

#include "Particle.h"

using namespace std;

#include <chrono>
#include <thread>

using namespace std::this_thread; 
using namespace std::chrono;


class Shower {
    public:
    Shower() = default;
    Shower(Particle *newParticle, int newMultiplicity, std::ofstream &outFile);
    Shower(Particle *newParticle, int newMultiplicity, const string newRandomDist, 
            string newModel, std::ofstream &outFile);

    ~Shower() {
        CleanParticleVector(currentParticles);
        currentParticles.clear();
        CleanParticleVector(nextParticles);
        nextParticles.clear();
    }
    // ~Shower() {
    //     cout << "In ddestructor" << endl;
    //     cout << "nextParticles.size " << nextParticles.size() << endl;
    //     cout << "currentParticles.size " << currentParticles.size() << endl;
    //     cout << "InitParticle " << InitParticle->GetName() << " " << InitParticle->GetEnergy() << endl;
    //     cout << "out ddestructor" << endl;
    // }
    // ~Shower() { 
    //     cout << "In ddestructor" << endl;
    //     delete InitParticle;
    //     CleanParticleVector(nextParticles);
    //     CleanParticleVector(currentParticles);
    //     cout << "out ddestructor" << endl;
    //     }

    // Getters
    double GetInitEnergy() const {return InitEnergy;}
    int GetInitMultiplicity() const {return Multiplicity;}
    int GetHeight() const {return Height;}
    int GetWeight() const {return Weight;}
    double GetXMax() const {return XMax;}
    int GetN_mu() const {return N_mu;}
    double GetCurrentEnergy() const {return CurrentEnergy;}

    friend std::ostream& operator<<(std::ostream& s, const Shower& p);

    // Main methods
    void BuildBasicShower();
    void BuildSimpleShower(std::ofstream &outFile);
    void BuildBetterShower(std::ofstream &outFile);
    void BuildContinuumShower(std::ofstream &outFile);


    // Printers
    void printNParticles() {cout << "Number of Particles: " << nParticles << endl;}
    void printNmu() {cout << "Number of muons: " << N_mu << endl;}
    void printHeight() {cout << "Height: " << Height << endl;}


    private:

    string Model = "Discrete";
    // Particle *InitParticle;
    double InitEnergy = 1; // GeV
    int Multiplicity = 3;
    int InitHeight = 10000; // In X0s
    int Weight = 1; // 1 Particle
    double CurrentEnergy = InitEnergy;

    vector<Particle*> currentParticles;
    vector<Particle*> nextParticles;

    double XMax = 0;
    int N_mu = 0;

    int nParticles = 0;
    int Height = InitHeight;

    void prepLayer(int &newXMax);
    void MakeDecays(double energy, int multiplicity, int atomn, string randDist, int &nParticles, Particle *&particle);
    void NoDecay(int &nParticles, Particle *&particle);
    void CleanParticleVector(vector<Particle*> &vec);

    string RandomDist;

};
#endif