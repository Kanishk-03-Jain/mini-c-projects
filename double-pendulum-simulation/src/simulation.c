#include "include/simulation.h"
#include "include/renderer.h"
#include <math.h>

Vector2 getBobPos(Pendulum *pendulum) {
    float x_ = pendulum->pivot.x + pendulum->length * sinf(pendulum->theta);
    float y_ = pendulum->pivot.y + pendulum->length * cosf(pendulum->theta);

    return (Vector2){x_, y_};
}

void updateAngularVelocity(Pendulum *pendulum, float dt) {
    pendulum->omega += pendulum->alpha * dt;
}

void updateAngularPosition(Pendulum *pendulum, float dt) {
    pendulum->theta += pendulum->omega * dt;
}

void updateSimulationState(Simulation *sim, float dt) {
    // updating angular accelerations
    float delta = sim->p1.theta - sim->p2.theta;
    float common_denominator =
        (2 * sim->p1.mass + sim->p2.mass -
        sim->p2.mass * cosf(2 * sim->p1.theta - 2 * sim->p2.theta));

    sim->p1.alpha =
        (-G * (2 * sim->p1.mass + sim->p2.mass) * sinf(sim->p1.theta) -
        sim->p2.mass * G * sinf(sim->p1.theta - 2 * sim->p2.theta) -
        2 * sinf(delta) * sim->p2.mass *
            (sim->p2.omega * sim->p2.omega * sim->p2.length +
                sim->p1.omega * sim->p1.omega * sim->p1.length * cosf(delta))) /
        (sim->p1.length * common_denominator);

    sim->p2.alpha = 
            (2 * sinf(delta) *
            (sim->p1.omega * sim->p1.omega * sim->p1.length *
                (sim->p1.mass + sim->p2.mass) +
            G * (sim->p1.mass + sim->p2.mass) * cosf(sim->p1.theta) +
            sim->p2.omega * sim->p2.omega * sim->p2.length *
                sim->p2.mass * cosf(delta))) /
            (sim->p2.length * common_denominator);

    // updating angular velocities
    updateAngularVelocity(&sim->p1, dt);
    updateAngularVelocity(&sim->p2, dt);

    // updating angular positions
    updateAngularPosition(&sim->p1, dt);
    updateAngularPosition(&sim->p2, dt);

    // updating bob and pivot points
    sim->p1.bob = getBobPos(&sim->p1);
    sim->p2.pivot = sim->p1.bob;
    sim->p2.bob = getBobPos(&sim->p2);

    // updating trail points
    sim->trail.points[sim->trail.head] = sim->p2.bob;
    sim->trail.head = (sim->trail.head + 1) % MAX_TRAIL;

    if (sim->trail.count < MAX_TRAIL)
        sim->trail.count++;
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

    sim->p1.pivot = (Vector2){WIDTH / 2, 0};
}
