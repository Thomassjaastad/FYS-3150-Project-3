#include "velocityverlet.h"
#include <iostream>

VelocityVerlet::VelocityVerlet(double dt)
{    
    m_dt = dt;
}

void VelocityVerlet::integrateOneStep(SolarSystem &system)
{

    for(CelestialBody &body : system.bodies()) {
        body.position = body.position + 0.5*body.velocity*m_dt;
    }

   //Change function for task f and g

    system.calculateForcesAndEnergy();
    //system.calculateNewForceMercury();
    for(CelestialBody &body : system.bodies()) {
        body.velocity = body.velocity + body.force / body.mass * m_dt;
        body.position = body.position + 0.5*body.velocity*m_dt;

    }

}

