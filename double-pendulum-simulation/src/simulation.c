#include "include/simulation.h"
#include <math.h>

Vector2 getBobPos(Pendulum *pendulum) {
    float x_ = pendulum->pivot.x + pendulum->length * sinf(pendulum->theta);
    float y_ = pendulum->pivot.y + pendulum->length * cosf(pendulum->theta);

    return (Vector2){x_, y_};
}


void updatePosition(Simulation *sim, float dt) {
    // updating angular accelerations
    sim->p1.alpha = (-G*(2*sim->p1.mass+sim->p2.mass)*sinf(sim->p1.theta) - sim->p2.mass*G*sinf(sim->p1.theta-2*sim->p2.theta) - 2*sinf(sim->p1.theta-sim->p2.theta)*sim->p2.mass*(sim->p2.omega*sim->p2.omega*sim->p2.length+sim->p1.omega*sim->p1.omega*sim->p1.length*cosf(sim->p1.theta-sim->p2.theta))) / (sim->p1.length*(2*sim->p1.mass+sim->p2.mass-sim->p2.mass*cosf(2*sim->p1.theta-2*sim->p2.theta)));
    sim->p2.alpha = (2*sinf(sim->p1.theta-sim->p2.theta)*(sim->p1.omega*sim->p1.omega*sim->p1.length*(sim->p1.mass+sim->p2.mass)+G*(sim->p1.mass+sim->p2.mass)*cosf(sim->p1.theta)+sim->p2.omega*sim->p2.omega*sim->p2.length*sim->p2.mass*cosf(sim->p1.theta-sim->p2.theta))) / (sim->p2.length*(2*sim->p1.mass+sim->p2.mass-sim->p2.mass*cosf(2*sim->p1.theta-2*sim->p2.theta)));

    // updating angular velocities
    sim->p1.omega += sim->p1.alpha * dt;
    sim->p2.omega += sim->p2.alpha * dt;

    // updating angular positions
    sim->p1.theta += sim->p1.omega * dt;
    sim->p2.theta += sim->p2.omega * dt;
}

void init(Simulation *sim) {
    sim->p1.theta = GetRandomValue(-90, 90) * DEG2RAD;
    sim->p1.omega = 0;
    sim->p1.alpha = 0;
    sim->p1.length = L1;
    sim->p1.mass = M1;

    sim->p2.theta = GetRandomValue(-90, 90) * DEG2RAD;
    sim->p2.omega = 0;
    sim->p2.alpha = 0;
    sim->p2.length = L2;
    sim->p2.mass = M2;

    sim->trail.head = 0;
    sim->trail.count = 0;
}
