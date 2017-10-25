#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include "solarsystem.h"
#include "euler.h"
#include "velocityverlet.h"
#include "vec3.h"
using namespace std;

int main(int numArguments, char **arguments)
{
    int numTimesteps = 100000000;
    if(numArguments >= 2) numTimesteps = atoi(arguments[1]);

    SolarSystem solarSystem;
    // We create new bodies like this. Note that the createCelestialBody function returns a reference to the newly created body
    // This can then be used to modify properties or print properties of the body if desired
    // Use with: solarSystem.createCelestialBody( position, velocity, mass );
    //Escape velocity v > sqrt(2*G*m/r)

    //solarSystem.createCelestialBody(vec3(m_centerofmass(),0,0), vec3(0,0,0), 1.0 ); //Center of mass sun
    // We don't need to store the reference, but just call the function without a left hand side
    solarSystem.createCelestialBody(vec3(0,0,0), vec3(0, 0, 0), 1.0 );                             // Sun
    //solarSystem.createCelestialBody(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );                    // Earth   with sqrt(8*pi**2) esc velocity
    //solarSystem.createCelestialBody(vec3(5.2, 0, 0), vec3(0, 2*M_PI/sqrt(5.2), 0), 1e-3);         //Jupiter
    //solarSystem.createCelestialBody(vec3(1.52, 0, 0), vec3(0, 2*M_PI/sqrt(1.52), 0), 3.3e-7);     // Mars
    //solarSystem.createCelestialBody(vec3(0.72, 0, 0), vec3(0, 2*M_PI/sqrt(0.72), 0), 2.4e-6);     //Venus
    //solarSystem.createCelestialBody(vec3(9.54, 0, 0), vec3(0, 2*M_PI/sqrt(9.54), 0), 2.75e-4);    //Saturn
    solarSystem.createCelestialBody(vec3(0.3075 , 0, 0), vec3(0, 12.44, 0), 1.65e-7);   //Mercury
    //solarSystem.createCelestialBody(vec3(19.19, 0, 0), vec3(0, 2*M_PI/sqrt(19.19) ,0), 4.4e-5);   //Uranus
    //solarSystem.createCelestialBody(vec3(30.06, 0, 0), vec3(0, 2*M_PI/sqrt(30.06), 0), 5.15e-5);  //Neptun
    //solarSystem.createCelestialBody(vec3(39.53, 0, 0), vec3(0, 2*M_PI/sqrt(39.53), 0), 6.55e-9);  //Pluto

    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
    vector<CelestialBody> & bodies = solarSystem.bodies();

    for(int i = 0; i < bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
    }
    //solarSystem.removeLinearMomentum();
    double final_time = 100.;
    double dt = final_time/((double)numTimesteps);
   // Euler integrator(dt);
    VelocityVerlet integrator(dt);
   // solarSystem.calculateForcesAndEnergy();
    solarSystem.calculateNewForceMercury();
    double r;
    double r_prev = 1000.;
    double r_prevprev = 1001.;
    double x_prev = 0;
    double y_prev = 0;
    double theta;
    double rmin = 0;
    int mercury_yr = 0;

    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.integrateOneStep(solarSystem);
        //solarSystem.writeToFile("positions.txt");
        solarSystem.writeToFile("positions_mercury.txt");
        r = sqrt(bodies[1].position.x()*bodies[1].position.x() + bodies[1].position.y()*bodies[1].position.y());
        //cout << r_prevprev << "  " << r_prev << "  " << r << endl;
        if ((r > r_prev) && (r_prevprev > r_prev)) {
            //cout << x_prev << "  " << y_prev << endl;
            theta = atan2(y_prev,x_prev);
            rmin = r_prev;
            cout << mercury_yr  <<  " "<< setprecision(16)<<  theta << " " << rmin<< endl;
            mercury_yr++;
        }

        if (r != r_prev) {
            r_prevprev = r_prev;
        } else {
            cout << timestep << endl;
        }
        r_prev = r;
        x_prev = bodies[1].position.x();
        y_prev = bodies[1].position.y();
        //solarSystem.writeToFile("angles_mercury.txt");


    }
    //cout  << setprecision(16)<< theta << endl;
    //cout  << setprecision(16)<< x_prev << "  " << y_prev << " " << rmin << endl;
   // cout <<"Total energy, Kinetic and potential"<< solarSystem.totalEnergy() <<", "<< solarSystem.kineticEnergy() <<", "<< solarSystem.potentialEnergy() << endl;
    //cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;
    //cout << "Subcrated angle per century is 43'' = 0.012 degrees " <<"," << "Angle calculated is " << endl;
    return 0;
}

