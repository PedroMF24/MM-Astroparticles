#include "include/Shower.h"

// Define a function type for the functions in the map



Shower::Shower(Particle &newParticle, int newMultiplicity) : 
                InitParticle(newParticle), InitEnergy(newParticle.GetEnergy()) 
{
    if (newMultiplicity >= 3 && newMultiplicity % 3 == 0)
        Multiplicity = newMultiplicity; 
    else 
        std::cout << "Multiplicity not accepted. Should be multiple of 3" << std::endl;

};


void Shower::funcElectron() {
    cout << "Im an electron!" << endl;
}

void Shower::funcProton() {
    cout << "Im an proton!" << endl;
}

void Shower::funcPhoton() {
    cout << "Im an photon!" << endl;
}



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

void Shower::BuildShower() {
    nParticles = 0;
    Particle p = InitParticle;
    currentParticles.push_back(new Particle(p));

    for (int i = 0; i <= InitHeight; i++) {
        for (auto &particle : currentParticles) {
            string name = particle->GetName();
            auto it = functionMap.find(name);
            if (it != functionMap.end()) {
                // it->second();
                // Generate new particles based on the current particle
                Electron* newParticle1 = new Electron(200);
                Electron* newParticle2 = new Electron(500);
                // Add the new particles to nextParticles
                nextParticles.push_back(newParticle1);
                nextParticles.push_back(newParticle2);
                nParticles += 2; // Update the particle count

            } else {
                std::cout << "Function for particle " << name << " not found" << std::endl;
            }
        }
        printNParticles();
        nParticles = 0;
        printHeight();
        Height--; // Decrease the height
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