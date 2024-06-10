# MM-Astroparticles

Code for Multi-Messengers and Astroparticle physics course to study the correlation between the XMax of Extensive Air Showers and the Number of Muons that arrives at the station detectors.

The model used is an extension of the Heitler-Mathews model with more complex and advanced features. 

The code is presented in such a way that updates on new particles or interactions are made easy for the user.

All initial conditions can be edited in the config file.

## Models

### Discrete (Advanced HM)
The discrite HM model was implemented and can be accessed with minor changes to the Shower class constructor. The default discrete models available have options on the steps, initial and final energy of each scan, initial particle, interaction multiplicity and interaction energy distribution.

### Continuous model
A continuous model is also available besides the "by the book" HM model, in which the layers are divided into steps dX and the particles have an interaction probability for each step. The model tends to the discrete HM in the limit. The model also uses the energy distribution between interaction layers, implemented with a uniform and gaussian distribution.

## Energy distribution Modes 

### 1. Normal (Energy Sweep) 
This mode calculates the evolution of particle showers from an initial to a final energy.

### 2. Monte Carlo
This mode generates a uniform distribution of energies and calculates the evolution of showers.

### 3. Fixed Energy
This mode starts with a fixed initial energy and calculates all showers with it. 
