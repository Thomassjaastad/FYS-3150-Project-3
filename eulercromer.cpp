
#include "eulercromer.h"
#include "../system.h"

EulerCromer::EulerCromer(System* system)
    : Integrator(system) {
}

void EulerCromer::integrateOneStep(std::vector<Particle*> particles) {
    m_system->computeForces();
    for (int j=0; j<particles.size(); j++) {
        Particle *p = particles.at(j);

        vec3 pos = p.getPosition();
        double xi = pos[0];
        double yi = pos[1];
        double zi = pos[2];

        vec3 vel = p.getVelocity();
        double vxi = vel[0];
        double vyi = vel[1];
        double vzi = vel[2];



        /*
        vy[i+1] = vy[i] + ay[i]*dt;
        vx[i+1] = vx[i] + ax[i]*dt;

        y[i+1] = y[i] + vy[i+1]*dt;
        x[i+1] = x[i] + vx[i+1]*dt;
        */
        /*
         * This is where you need to update the positions and the velocities
         * and the velocities of each particle according to the Euler-Cromer
         * scheme.
         *
         * You can access the position of particle number i by
         *
         *      p->getPosition()
         *
         * Remember that the positions and velocities of all the particles are
         * vec3 vectors, which you can use the +=, -=, etc. operators on.
         */
    }
}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
