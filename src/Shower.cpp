#include "include/Shower.h"
#include "include/Utils.h"
#include "include/FileStream.h"

// Define a function type for the functions in the map

// Shower::Shower(Particle* newParticle, int newMultiplicity, std::ofstream &outFile) : 
//                 InitParticle(newParticle), InitEnergy(newParticle->GetEnergy()) 

Shower::Shower(Particle *newParticle, int newMultiplicity, std::ofstream &outFile) : 
                InitEnergy(newParticle->GetEnergy()) 
{
    if (newMultiplicity >= 3 && newMultiplicity % 3 == 0)
        Multiplicity = newMultiplicity; 
    else 
        std::cout << "Multiplicity not accepted. Should be multiple of 3" << std::endl;

    currentParticles.push_back(newParticle);

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

Shower::Shower(Particle *newParticle, int newMultiplicity, const string newRandomDist, string newModel, std::ofstream &outFile) : 
                InitEnergy(newParticle->GetEnergy()), RandomDist(newRandomDist), Model(newModel)
{
    int showerFlag = 0;

    if (newMultiplicity >= 3 && newMultiplicity % 3 == 0)
        Multiplicity = newMultiplicity; 
    else 
        std::cout << "Multiplicity not accepted. Should be multiple of 3" << std::endl;

    if (Model == "Continuous")
        showerFlag = 3;
    else if (Model == "Discrete")
        showerFlag = 2;
    else
        cerr << "**Should never get here: Unknown model" << endl;

    currentParticles.push_back(newParticle);

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
    case 3:
        BuildContinuumShower(outFile);
    
    default:
        break;
    }
};

ostream& operator<<(std::ostream& os, const Shower& ss) {
    os << setprecision(5); //  << scientific;
    os << ss.GetInitEnergy() << " "
        << log(ss.GetInitEnergy()) << " "
        << ss.GetCurrentEnergy() << " "
        << ss.GetXMax() << " "
        << ss.GetN_mu() << " "
        << log(ss.GetN_mu()) << endl;
    return os;
}

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

    // Particle p = GetInitParticle();
    // currentParticles.push_back(new Particle(p));

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
                    nextParticles.push_back(new PionP(Energy/Multiplicity));
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
    // Particle p = GetInitParticle();
    // currentParticles.push_back(new Particle(p));

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

    double Energy = 0;
    int AtomN = 0;
    int newXMax = 0;

    // cout << "GOT IN" << endl;
    nParticles = 1*currentParticles[0]->GetAtomicNumber();

    for (int i = 0; i < InitHeight; i++) {
        // printHeight();
        // printNParticles();
        prepLayer(newXMax);
        for (auto &particle : currentParticles) {
            string name = particle->GetName();
            Energy = particle->GetEnergy();
            // cout << "Energy: " << Energy << endl;
            AtomN = particle->GetAtomicNumber();
            if (!particle->Interacts(Energy/Multiplicity)) {
                // cout << "Interacted" << endl;
                break;
            }
            MakeDecays(Energy, Multiplicity, AtomN, RandomDist, nParticles, particle); 
        }
        if (nextParticles.size() == 0) {
            CurrentEnergy = Energy;
            outFile << " " << *this;
            CleanParticleVector(currentParticles);
            break;
        }
        CleanParticleVector(currentParticles);
        currentParticles.swap(nextParticles);
        nextParticles.clear();
    }
}

void Shower::prepLayer(int &newXMax) {
    newXMax = InitHeight-Height;
    // cout << "1. nParticles: " << nParticles << "  N_mu: " << N_mu << endl;
    if (nParticles > N_mu) {
        // cout << "2. nParticles: " << nParticles << "  N_mu: " << N_mu << endl;
        XMax = newXMax;
        N_mu = nParticles;
    } else {
        // cout << "here" << endl;
        // printHeight();
        // printNParticles();
        // printNmu();
        CleanParticleVector(currentParticles);
        nextParticles.clear();
        return;
    }
    Height--; // Decrease the height
    nParticles = 0;
}

void Shower::MakeDecays(double energy, int multiplicity, int atomn, string randDist, int &nParticles, Particle *&particle) {
    for (int j = 0; j < Multiplicity/3; j++) {
        for (int k = 0; k < atomn; k++) 
        {
            particle->DecayProducts(energy, multiplicity, randDist, nParticles, nextParticles);
        }
    }
}

void Shower::NoDecay(int &nParticles, Particle *&particle) {
    Particle *copyParticle = particle->clone(); // Use clone method
    nextParticles.push_back(copyParticle);
    nParticles += 1;
}

void Shower::CleanParticleVector(vector<Particle*>& vec) {
    if (!vec.empty()) {
        for (auto& particlePtr : vec) {
            delete particlePtr;
        }
        vec.clear();
    }
}

// TODO
void Shower::BuildContinuumShower(std::ofstream &outFile) {
    double Energy = 0;
    int AtomN = 0;
    double newXMax = 0;

    double dX = 0.2; // Step size

    nParticles = 1 * currentParticles[0]->GetAtomicNumber();

    for (double height = 0; height < InitHeight; height += dX) {
        // std::cout << height << std::endl;
        // printNParticles();

        // prep layer
        newXMax = static_cast<double>(InitHeight - (InitHeight-height));
        if (nParticles > N_mu) {
            XMax = newXMax;
            N_mu = nParticles;
        }
        nParticles = 0;

        for (auto &particle : currentParticles) {
            std::string name = particle->GetName();
            Energy = particle->GetEnergy();
            AtomN = particle->GetAtomicNumber();
            if (!particle->Interacts(Energy / Multiplicity)) {
                continue;
            }
            double rng_prob = particle->UniDist(0., 1.);
            double prob = 1 - exp(-log(2)*dX);
            if (rng_prob < prob)
                MakeDecays(Energy, Multiplicity, AtomN, RandomDist, nParticles, particle);
            else
                NoDecay(nParticles, particle);
        }
        if (nextParticles.empty()) {
            CurrentEnergy = Energy;
            outFile << setprecision(2) << " " << *this;
            CleanParticleVector(currentParticles);
            break;
        }
        CleanParticleVector(currentParticles);
        currentParticles.swap(nextParticles);
        nextParticles.clear();
    }
}

