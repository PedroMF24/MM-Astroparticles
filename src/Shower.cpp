#include "include/Shower.h"
#include "include/Utils.h"
#include "include/FileStream.h"

// Define a function type for the functions in the map



Shower::Shower(Particle &newParticle, int newMultiplicity, std::ofstream &outFile) : 
                InitParticle(newParticle), InitEnergy(newParticle.GetEnergy()) 
{
    if (newMultiplicity >= 3 && newMultiplicity % 3 == 0)
        Multiplicity = newMultiplicity; 
    else 
        std::cout << "Multiplicity not accepted. Should be multiple of 3" << std::endl;

    int showerFlag = 2;
    switch (showerFlag)
    {
    // Simple shower with no interactions or randomness, only decays
    case 0:
        BuildBasicShower();
        break;
    case 1:
        BuildSimpleShower(outFile);
        break;
    case 2:
        BuildBetterShower(outFile);
        break;
    
    default:
        break;
    }
};

ostream& operator<<(std::ostream& os, const Shower& ss) {
    // os << setprecision(3); //  << scientific;
    os << ss.GetInitEnergy() << " "
        << ss.GetCurrentEnergy() << " "
        << ss.GetXMax() << " "
        << ss.GetN_mu() << endl;
    return os;
}
 

// void Shower::funcElectron() {
//     cout << "Im an electron!" << endl;
// }

// void Shower::funcProton() {
//     cout << "Im an proton!" << endl;
// }

// void Shower::funcPhoton() {
//     cout << "Im an photon!" << endl;
// }

// int Shower::funcPionN() {
//     cout << "Im an Neutral Pion!" << endl;
//     return 0;
// }

// int Shower::funcPionP() {
//     cout << "Im an Pion Plus!" << endl;
//     return 1;
// }

// int Shower::funcPionM() {
//     cout << "Im an Pion Minus!" << endl;
//     return -1;
// }

// Shower::~Shower() {
//     for (auto& particlePtr : inParticleVec) {
//         delete particlePtr;
//     }
//     inParticleVec.clear();
//     for (auto& particlePtr : outParticleVec) {
//         delete particlePtr;
//     }
//     outParticleVec.clear();
// }

// void Shower::isParticle(Particle &particle) {

//     string name = particle.GetName();
//     auto it = func_map.find(name);

//     if (it != func_map.end()) {
//         int result = it->second(x);
//         std::cout << name << "(" << x << ") = " << result << std::endl;
//     } else {
//         std::cout << name << " not found" << std::endl;
//     }
// }

int Treshold(double energy) {
    double minE = 3;
    if (energy >= minE)
        return 0;
    return 1;
}

void 
Shower::BuildBasicShower() {

    std::cout << "> Begin Shower" << std::endl;

    // Utils TheUtils;

    nParticles = 0;
    double Energy = 0;

    Particle p = InitParticle;
    currentParticles.push_back(new Particle(p));

    int newXMax = 0;

    for (int i = 0; i <= InitHeight; i++) {
        // TheUtils.ProgressBar(i, InitHeight);
        // sleep_for(nanoseconds(10));
        // sleep_until(system_clock::now() + milliseconds(100));

        printHeight();
        printNParticles();
        newXMax = InitHeight-Height;
        if (newXMax > XMax) {
            XMax = newXMax;
            N_mu = nParticles;
        }
        std::cout << "current XMax " << newXMax << " , current N_mu " << N_mu << endl;
        Height--; // Decrease the height
        nParticles = 0;

        for (auto &particle : currentParticles) {
            string name = particle->GetName();
            Energy = particle->GetEnergy();
            // auto it = functionMap.find(name);
            // if (it != functionMap.end()) {
            //     it->second();

                // Generate new particles based on the current particle
                // PionN* newParticle1 = new PionN(Energy/3);
                // for (int j = 0; i < Multiplicity/3; j++)
                // {
                //     PionP* newParticle2 = new PionP(Energy/Multiplicity);
                //     PionM* newParticle3 = new PionM(Energy/Multiplicity);
                // }

                if (Treshold(Energy/Multiplicity)) { 
                // std::cout << "End" << std::endl;
                    break;
                }

                for (int j = 0; j < Multiplicity/3; j++) {
                    // std::cout << "Multi for" << std::endl;
                    nextParticles.push_back(new PionN(Energy/Multiplicity));
                    nextParticles.push_back(new PionM(Energy/Multiplicity));
                }
                
                // PionN* newParticle3 = new PionN(Energy/3);

                // Add the new particles to nextParticles

                // std::cout << "Add " << i << std::endl;
                // nextParticles.push_back(newParticle1);
                // nextParticles.push_back(newParticle2);
                // nextParticles.push_back(newParticle3);

                nParticles += 2*Multiplicity/3; // Update the particle count
            // } else {
            //     std::cout << "Function for particle " << name << " not found" << std::endl;
            // }
        }

        if(nextParticles.size() == 0) {
            std::cout << "> Shower End" << std::endl;
            break;
        }

        // Clear the current particles
        CleanParticleVector(currentParticles);
        // Swap the current and next particle vectors
        currentParticles.swap(nextParticles);
        // Clear the next particles for the next iteration
        nextParticles.clear();
    }
    // TheUtils.FinishProgressBar();
}



/**
 * @brief 
 * 
 * @param outFile 
 */
void Shower::BuildSimpleShower(std::ofstream &outFile) {

    // std::cout << "> Begin Shower" << std::endl;

    // Utils TheUtils;

    nParticles = 0;
    double Energy = 0;
    int AtomN = 0;
    Particle p = InitParticle;
    currentParticles.push_back(new Particle(p));

    int newXMax = 0;
    double CrossSection = 0;
    double DecayRate = 0;

    for (int i = 0; i < InitHeight; i++) {

        // printHeight();
        // printNParticles();
        newXMax = InitHeight-Height;
        if (newXMax > XMax) {
            XMax = newXMax;
            N_mu = nParticles;
            // std::cout << "N_mu: " << N_mu << std::endl;
        }

        // std::cout << "current XMax " << newXMax << " , current N_mu " << N_mu << endl;
        Height--; // Decrease the height
        nParticles = 0;

        for (auto &particle : currentParticles) {
            string name = particle->GetName();
            // cout << "Name: " << name << endl;
            Energy = particle->GetEnergy();

            AtomN = particle->GetAtomicNumber();
            // cout << "AtomN: " << AtomN << endl;
            CrossSection = particle->GetCrossSection();
            DecayRate = particle->GetDecayRate();

            // cout << CrossSection << " " << DecayRate << endl;

            if (Treshold(Energy/Multiplicity)) { 
                // std::cout << "End" << std::endl;
                break;
            }

            for (int j = 0; j < Multiplicity/3; j++) {
                // std::cout << "Multi for" << std::endl;
                for (int k = 0; k < AtomN; k++)
                {
                    nextParticles.push_back(new PionN(Energy/(Multiplicity*AtomN)));
                    nextParticles.push_back(new PionM(Energy/(Multiplicity*AtomN)));
                    nParticles += 2; // Update the particle count
                }
            }
        }

        if(nextParticles.size() == 0) {
            CurrentEnergy = Energy;
            // Write data in columns
            // outFile << GetInitEnergy() << " " <<  Energy << " " << GetXMax() << " " << GetN_mu() << std::endl;
            outFile << *this;
            // std::cout << "Shower End" << std::endl;
            break;
        }

        // Clear the current particles
        CleanParticleVector(currentParticles);
        // Swap the current and next particle vectors
        currentParticles.swap(nextParticles);
        // Clear the next particles for the next iteration
        nextParticles.clear();
    }
    // TheUtils.FinishProgressBar();
}



/**
 * @brief 
 * 
 * @param outFile 
 */
void Shower::BuildBetterShower(std::ofstream &outFile) {
    // std::cout << "> Begin Shower" << std::endl;

    // Utils TheUtils;

    nParticles = 0;
    double Energy = 0;
    int AtomN = 0;
    Particle p = InitParticle;
    currentParticles.push_back(new Particle(p));

    int newXMax = 0;
    double CrossSection = 0;
    double DecayRate = 0;

    for (int i = 0; i < InitHeight; i++) {

        // printHeight();
        // printNParticles();
        newXMax = InitHeight-Height;
        if (newXMax > XMax) {
            XMax = newXMax;
            N_mu = nParticles;
            // std::cout << "N_mu: " << N_mu << std::endl;
        }

        // std::cout << "current XMax " << newXMax << " , current N_mu " << N_mu << endl;
        Height--; // Decrease the height
        nParticles = 0;

        for (auto &particle : currentParticles) {
            string name = particle->GetName();
            // cout << "Name: " << name << endl;
            Energy = particle->GetEnergy();

            AtomN = particle->GetAtomicNumber();
            // cout << "AtomN: " << AtomN << endl;
            CrossSection = particle->GetCrossSection();
            DecayRate = particle->GetDecayRate();

            // cout << CrossSection << " " << DecayRate << endl;

            if (particle->Interacts(Energy/Multiplicity)) { 
                // std::cout << "Interacts" << std::endl;
                break;
            }
            // cout << particle->Interacts(Energy/Multiplicity) << " " << Treshold(Energy/Multiplicity) << endl;
            // particle->Interacts(Energy/Multiplicity);
            // if (Treshold(Energy/Multiplicity)) { 
            // // std::cout << "End" << std::endl;
            //     break;
            // }

            for (int j = 0; j < Multiplicity/3; j++) {
                // std::cout << "Multi for" << std::endl;
                for (int k = 0; k < AtomN; k++)
                {
                    nextParticles.push_back(new PionP(Energy/(Multiplicity*AtomN)));
                    nextParticles.push_back(new PionM(Energy/(Multiplicity*AtomN)));
                    nParticles += 2; // Update the particle count
                }
            }
        }

        if(nextParticles.size() == 0) {
            CurrentEnergy = Energy;
            // Write data in columns
            // outFile << GetInitEnergy() << " " <<  Energy << " " << GetXMax() << " " << GetN_mu() << std::endl;
            outFile << *this;
            // std::cout << "Shower End" << std::endl;
            break;
        }

        // Clear the current particles
        CleanParticleVector(currentParticles);
        // Swap the current and next particle vectors
        currentParticles.swap(nextParticles);
        // Clear the next particles for the next iteration
        nextParticles.clear();
    }
}


void Shower::CleanParticleVector(vector<Particle*> &vec) {
    for (auto& particlePtr : vec) {
        delete particlePtr;
    }
    vec.clear();
}