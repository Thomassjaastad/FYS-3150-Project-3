#include "solarsystem.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

SolarSystem::SolarSystem() :
    m_kineticEnergy(0),
    m_potentialEnergy(0),
    m_angularmomentum(0),
    m_totMass(0)

{
}

void SolarSystem::createCelestialBody(vec3 position, vec3 velocity, double mass) {
    m_bodies.push_back( CelestialBody(position, velocity, mass) );
    m_totMass += mass;
}

void SolarSystem::calculateForcesAndEnergy()
{
    m_kineticEnergy = 0;
    m_potentialEnergy = 0;
    m_angularmomentum = 0;
    m_centerofmass.zeros();

    for(CelestialBody &body : m_bodies) {
        // Reset forces on all bodies
        body.force.zeros();
    }

    for(int i=0; i<numberOfBodies(); i++) {
        CelestialBody &body1 = m_bodies[i];
        m_momentumvec -= body1.mass*body1.velocity;

        for(int j=i+1; j<numberOfBodies(); j++) {
            CelestialBody &body2 = m_bodies[j];
            vec3 deltaRVector = body1.position - body2.position;
            double dr = deltaRVector.length();
            // Calculate the force and potential energy here

            vec3 F = deltaRVector *4 * M_PI*M_PI/ (dr*dr*dr*dr) * body1.mass * body2.mass;
            body1.force -= F;
            body2.force += F;
            m_potentialEnergy -= 4*M_PI*M_PI*body1.mass*body2.mass/dr;

        }

        m_centerofmass += body1.mass*body1.position;
        m_angularmomentum += body1.mass*body1.velocity.length()*body1.position.length();
        m_kineticEnergy += 0.5*body1.mass*body1.velocity.lengthSquared();

    }
    m_bodies[0].velocity = m_momentumvec/m_bodies[0].mass;
    m_centerofmass /= m_totMass;
    //cout << m_bodies[0].velocity << endl;

}

void SolarSystem::calculateNewForceMercury()
{
    m_angularmomentum = 0;
    m_centerofmass.zeros();

    for(CelestialBody &body : m_bodies) {
        // Reset forces on all bodies
        body.force_mercury.zeros();
    }

        CelestialBody &body1 = m_bodies[0];
       // m_momentumvec -= body1.mass*body1.velocity;

        //double U = 1.5*pow(10 , 11.0);
        //double c = 3*pow(10 , 8.0);
        //double year = 364.2*24*60*60;
        double c_year = 63239.72;//c*year/U;  //SPeed of light in AU/yr

        CelestialBody &body2 = m_bodies[1];
        vec3 deltaRVector = body1.position - body2.position;
        double dr = deltaRVector.length();
        // Calculate the realtivisic mercury force
        vec3 l = body2.position.cross(body2.velocity);
        double l_sq = l.length();

        vec3 F = deltaRVector*4*M_PI*M_PI/ (dr*dr*dr)*body1.mass*body2.mass*(1 + 3*l_sq*l_sq/(dr*dr*dr*c_year*c_year));

        body2.force_mercury += F;

       // m_centerofmass += body1.mass*body1.position;
       // m_angularmomentum += body1.mass*body1.velocity.length()*body1.position.length();

    }


int SolarSystem::numberOfBodies() const
{
    return m_bodies.size();
}

void SolarSystem::removeLinearMomentum()
{
    m_momentumvec.zeros();
    for(int i=0; i<numberOfBodies(); i++) {
        CelestialBody &body1 = m_bodies[i];
        m_momentumvec -= body1.mass*body1.velocity;
    }
    m_bodies[0].velocity = m_momentumvec/m_bodies[0].mass;
    cout << m_bodies[0].velocity << endl;


}

void SolarSystem::CenterOfMass()
{
    for(int i = 0; i < numberOfBodies(); i++){
        CelestialBody &body = m_bodies[i];
        body.position -= m_centerofmass;
    }
}


double SolarSystem::totalEnergy() const
{
    return m_kineticEnergy + m_potentialEnergy;
}

double SolarSystem::potentialEnergy() const
{
    return m_potentialEnergy;
}

double SolarSystem::kineticEnergy() const
{
    return m_kineticEnergy;
}
double SolarSystem::angularmomentum() const
{
    return m_angularmomentum;
}
vec3 SolarSystem::centerofmass()
{
    return m_centerofmass;
}
void SolarSystem::writeToFile(string filename)
{
    if(!m_file.good()) {
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()) {
            cout << "Error opening file " << filename << ". Aborting!" << endl;
            terminate();
        }
    }

    //m_file << numberOfBodies() << endl;
    //m_file << "Comment line that needs to be here." << endl;
    for(CelestialBody &body : m_bodies) {
        m_file  << setprecision(10) << body.position.x()<<" "<< setprecision(10) << body.position.y() << " " << setprecision(10) << body.position.z() <<" " << totalEnergy() <<" " << angularmomentum() << "\n";
        //m_file << setprecision(10) << mercury_yr << " " << setprecision(10) << theta << "/n";
    }
}

std::vector<CelestialBody> &SolarSystem::bodies()
{
    return m_bodies;
}
