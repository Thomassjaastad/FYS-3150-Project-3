#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "celestialbody.h"
#include <vector>
#include <string>
#include <fstream>

class SolarSystem
{
public:
    SolarSystem();
    void createCelestialBody(vec3 position, vec3 velocity, double mass);
    void calculateForcesAndEnergy();
    void BetaFunction();
    int numberOfBodies() const;
    void removeLinearMomentum();
    void CenterOfMass();
    void calculateNewForceMercury();


    double totalEnergy() const;
    double potentialEnergy() const;
    double kineticEnergy() const;
    double angularmomentum() const;
    vec3 centerofmass();
    vec3 momentumvec();
    void writeToFile(std::string filename);
    std::vector<CelestialBody> &bodies();

private:
    std::vector<CelestialBody> m_bodies;
    std::ofstream m_file;
    double m_kineticEnergy;
    double m_potentialEnergy;
    double m_angularmomentum;
    double m_totMass;
    vec3 m_centerofmass;
    vec3 m_momentumvec;
};

#endif // SOLARSYSTEM_H
