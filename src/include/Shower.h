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


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

// Define a TreeNode structure for the tree
// struct TreeNode {
//     Particle particle;
//     std::vector<std::unique_ptr<TreeNode>> children; // Using smart pointers for ownership management
// };

// class ParticleTree {
// public:
//     // Constructor
//     ParticleTree(Particle initParticle, int multiplicity) :
//         root(new TreeNode{initParticle}), multiplicity(multiplicity) {}

//     // Function to build the tree
//     void BuildTree() {
//         BuildTreeRecursive(root.get(), 1); // Start with depth 1
//     }

// private:
//     std::unique_ptr<TreeNode> root;
//     int multiplicity;

//     // Recursive function to build the tree
//     void BuildTreeRecursive(TreeNode* node, int height) {
//         if (height == 0) return; // Stop recursion when height reaches 0

//         for (int i = 0; i < multiplicity; ++i) {
//             Particle newParticle = GenerateNewParticle(node->particle); // Example function to generate new particles
//             node->children.push_back(std::make_unique<TreeNode>(TreeNode{newParticle}));
//             BuildTreeRecursive(node->children.back().get(), height - 1); // Decrement height
//         }
//     }


//     // Example function to generate new particles
//     Particle GenerateNewParticle(const Particle& parentParticle) {
//         // Generate new particle based on parent particle
//         // Example logic...
//         return Particle("NewParticle", parentParticle.GetEnergy() * 0.5, parentParticle.GetMass(), parentParticle.GetCharge());
//     }
// };





// Electron& Electron::operator=(const Electron& obj) {
//     if (this != &obj) {
//         Particle::operator=(obj);
//     }
//     return *this;
// }

// std::ostream& operator<<(std::ostream& s, const Electron& e) {
//     s << "Electron: "
//         << "Name=" << e.GetName() << ", "
//         << "Energy=" << e.GetEnergy() << ", "
//         << "Mass=" << e.GetMass() << ", "
//         << "Charge=" << e.GetCharge();
//     return s;
// }


class Shower {
    public:
    Shower() = default;
    Shower(Particle &newParticle, int newMultiplicity, std::ofstream &outFile);

    ~Shower() = default;

    // Getters
    Particle GetInitParticle() const {return InitParticle;}
    double GetInitEnergy() const {return InitEnergy;}
    int GetInitMultiplicity() const {return Multiplicity;}
    int GetHeight() const {return Height;}
    int GetWeight() const {return Weight;}
    int GetXMax() const {return XMax;}
    int GetN_mu() const {return N_mu;}
    double GetCurrentEnergy() const {return CurrentEnergy;}

    friend std::ostream& operator<<(std::ostream& s, const Shower& p);

    // Main methods
    void BuildBasicShower();
    void BuildSimpleShower(std::ofstream &outFile);
    void BuildBetterShower(std::ofstream &outFile);


    // double calcXMax() {};
    // double calcNmuons(int height) {};

    // void isParticle(Particle &particle);

    // bool isChargeConserved() {return true;}

    // Printers
    void printNParticles() {cout << "Number of Particles: " << nParticles << endl;}
    void printHeight() {cout << "Height: " << Height << endl;}


    // void funcElectron();
    // void funcProton();
    // void funcPhoton();
    // int funcPionN();
    // int funcPionP();
    // int funcPionM();

    void calcXMax(int newXMax, int height);

    void CleanParticleVector(vector<Particle*> &vec);

    private:

    Particle InitParticle;
    double InitEnergy = 1; // GeV
    int Multiplicity = 3;
    int InitHeight = 10000; // In X0s
    int Weight = 1; // 1 Particle
    double CurrentEnergy = InitEnergy;

    vector<Particle*> currentParticles;
    vector<Particle*> nextParticles;

    int XMax = 0;
    int N_mu = 0;

    int nParticles = 0;
    int Height = InitHeight;

    // Particle map
    // std::map<std::string, std::function<void()>> functionMap = {
    //     {"Electron", std::bind(&Shower::funcElectron, this)},
    //     {"Proton", std::bind(&Shower::funcProton, this)},
    //     {"Photon", std::bind(&Shower::funcPhoton, this)},
    //     {"PionN", std::bind(&Shower::funcPionN, this)},
    //     {"PionP", std::bind(&Shower::funcPionP, this)},
    //     {"PionM", std::bind(&Shower::funcPionM, this)}
    // };

    // int HandleParticle(Particle &particle);
};

// int Shower::HandleParticle(Particle &particle) {
//   return particle.GetType();
// }

// void Shower::isParticle(Particle &particle) {
//   int type = HandleParticle(particle);
//   // Do something based on the particle type
// }




// class Shower {
//     public:
//     Shower() = default;
//     Shower(Particle &newParticle, int newMultiplicity);

//     ~Shower() = default;


//     Particle GetInitParticle() const {return InitParticle;}
//     double GetInitEnergy() const {return InitEnergy;}
//     int GetInitMultiplicity() const {return Multiplicity;}
//     int GetHeight() const {return Height;}
//     int GetWeight() const {return Weight;}

//     void BuildShower();

//     double calcXMax() {};
//     double calcNmuons(int height) {};

//     void isParticle(Particle &particle);
//     int Electron() {return 0;}
//     int Proton() {return 1;}
//     int Photon() {return 2;}
//     int Iron() {return 3;}

//     private:

//     Particle InitParticle;
//     double InitEnergy = 1; // GeV
//     int Multiplicity = 3;
//     int Height = 100; // In X0s
//     int Weight = 1; // 1 Particle

//     std::map<std::string, std::function<int(int)>> func_map = {
//     {"electron", Electron},
//     {"proton", Proton},
//     {"photon", Photon},
//     {"iron", Iron},
//     };


// };
#endif